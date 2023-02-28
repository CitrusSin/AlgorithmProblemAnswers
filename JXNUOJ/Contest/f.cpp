#include <bits/stdc++.h>
using namespace std;

string bin_expression(int x) {
    if (x == 0) {
        return "0";
    } else if (x == 2) {
        return "2";
    }

    stack<string> expressions;
    for (int i=0; i<30; i++) {
        if (x >> i & 1) {
            if (i != 1) {
                expressions.push("2(" + bin_expression(i) + ")");
            } else {
                expressions.push("2");
            }
        }
    }

    bool flag = false;
    stringstream result;
    while (!expressions.empty()) {
        if (flag) {
            result << '+';
        }
        result << expressions.top();
        flag = true;
        expressions.pop();
    }
    return result.str();
}

int main() {
    int n;
    cin >> n;
    cout << bin_expression(n) << endl;
    return 0;
}