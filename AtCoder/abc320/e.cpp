#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

enum event_type {
    NOODLE_FLOW, PERSON_RETURN
};

struct event {
    u64 time;
    event_type type;
    u64 value;
    optional<u64> value2;

    event(u64 time, event_type type, u64 value) : time(time), type(type), value(value) {}

    bool operator>(const event& evt2) const {
        if (time == evt2.time) {
            if (type == NOODLE_FLOW && evt2.type == PERSON_RETURN) return true;
        }
        return time > evt2.time;
    }
};

template <typename T>
using pqr = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pqr<event> event_queue;
    pqr<u64> person_queue;

    u64 n, m;
    cin >> n >> m;
    while (m--) {
        u64 t, w, s;
        cin >> t >> w >> s;
        event evt(t, NOODLE_FLOW, w);
        evt.value2 = s;
        event_queue.push(evt);
    }

    vector<u64> record(n, 0);
    for (u64 i=0; i<n; i++) person_queue.push(i);

    while (!event_queue.empty()) {
        event evt = event_queue.top();
        event_queue.pop();

        if (evt.type == NOODLE_FLOW) {
            if (!person_queue.empty()) {
                u64 person = person_queue.top();
                person_queue.pop();

                record[person] += evt.value;

                u64 t2 = evt.time + evt.value2.value();
                event_queue.emplace(t2, PERSON_RETURN, person);
            }
        } else if (evt.type == PERSON_RETURN) {
            person_queue.push(evt.value);
        }
    }

    for (u64 i=0; i<n; i++) {
        cout << record[i] << endl;
    }
    return 0;
}