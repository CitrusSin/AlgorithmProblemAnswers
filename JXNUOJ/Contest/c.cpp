#include <bits/stdc++.h>
using namespace std;

vector<string> process_entrance(int n, const string &order_in, const string &order_out) {
    vector<string> res;

    stack<char> station;
    int j = 0;
    for (int i=0; i<n; i++) {
        station.push(order_in[i]);
        res.push_back("in");
        while (!station.empty() && station.top() == order_out[j]) {
            station.pop();
            res.push_back("out");
            j++;
        }
    }

    if (!station.empty()) {
        res.clear();
    }
    return res;
}

int main() {
    int n;
    string order_in, order_out;
    while (cin >> n >> order_in >> order_out) {
        vector<string> ops = process_entrance(n, order_in, order_out);
        if (!ops.empty()) {
            cout << "Yes." << endl;
            for (string s : ops) {
                cout << s << endl;
            }
            cout << "FINISH" << endl;
        } else {
            cout << "No." << endl << "FINISH" << endl;
        }
    }
    return 0;
}