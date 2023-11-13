#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    while (cin.peek() != '\n') cin.get();
    cin.get();

    int interrupt, overlap;

    set<int> numbers;
    for (int i=0; i<n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int p;
        while (ss >> p) {
            if (numbers.count(p)) {
                overlap = p;
            } else {
                numbers.insert(p);
            }
        }
    }

    int last = -1;
    for (int p : numbers) {
        if (last >= 0 && p != last+1) {
            interrupt = last+1;
            break;
        } else {
            last = p;
        }
    }

    cout << interrupt << " " << overlap << endl;
    return 0;
}