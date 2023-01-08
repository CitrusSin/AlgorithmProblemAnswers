#include <bits/stdc++.h>

using namespace std;
using u64 = unsigned long long;

struct exit_info {
    int position;
    int person_limit;
};

struct exit_record {
    int person_id;
    int exit_id;
    int timestamp;
};

int main() {
    int n, m, l;
    cin >> n >> m >> l;

    vector<exit_info> exits(m);
    exits[0] = exit_info{0, 0};
    for (int i=1; i<m; i++) {
        cin >> exits[i].position;
    }
    for (int i=0; i<m; i++) {
        cin >> exits[i].person_limit;
    }

    list<exit_record> exit_records;
    for (int i=1; i<=n; i++) {
        int s, b;
        cin >> s >> b;
        for (int exit_id=0; exit_id<m; exit_id++) {
            const exit_info &exit = exits[exit_id];
            int pos = exit.position;
            int distance = 0;
            if (s == 0) {
                if (pos < b) pos += l;
                distance = pos - b;
            } else {
                if (pos > b) pos -= l;
                distance = b - pos;
            }
            exit_records.emplace_back(exit_record{i, exit_id, distance});
        }
    }

    exit_records.sort([](const exit_record &a, const exit_record &b){
        //return a.timestamp < b.timestamp;
        if (a.timestamp == b.timestamp) {
            return a.person_id < b.person_id;
        }
        return a.timestamp < b.timestamp;
    });

    set<int> removed_person;
    for (auto it = exit_records.begin(); it != exit_records.end();) {
        if (removed_person.find(it->person_id) == removed_person.end()
            && exits[it->exit_id].person_limit > 0) {
            exits[it->exit_id].person_limit--;
            removed_person.insert(it->person_id);
            it++;
        } else {
            it = exit_records.erase(it);
        }
    }

    u64 sum = 0;
    for (const exit_record &rec : exit_records) {
        u64 r = u64(rec.person_id) * u64(rec.exit_id+1);
        sum ^= r;
    }
    cout << sum << endl;
    return 0;
}