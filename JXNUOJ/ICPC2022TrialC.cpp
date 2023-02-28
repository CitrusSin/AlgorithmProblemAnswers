#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int last_round = 0;
    map<int, int> round_list;
    for (int i=0; i<n; i++) {
        int b, e;
        cin >> b >> e;
        round_list[b] += 1;
        round_list[e] -= 1;
        last_round = max(last_round, e);
    }

    int stack_count = 0, round_stack = 0;
    for (auto a : round_list) {
        round_stack += a.second;
        if (round_stack > stack_count) {
            stack_count = round_stack;
        }
    }

    cout << stack_count << endl;
    return 0;
}