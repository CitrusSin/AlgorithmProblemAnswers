#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    array<queue<int>, 10> arr;
    int n;
    cin >> n;
    int pat_id = 1;
    while (n--) {
        string op;
        int priority;
        cin >> op;
        if (op == "IN") {
            cin >> priority;
            priority--;
            arr[priority].push(pat_id++);
        } else if (op == "OUT") {
            bool sig = false;
            for (int p=9; p>=0; p--) {
                if (!arr[p].empty()) {
                    cout << arr[p].front() << endl;
                    arr[p].pop();
                    sig = true;
                    break;
                }
            }
            if (!sig) {
                cout << "EMPTY" << endl;
            }
        }
    }
    return 0;
}