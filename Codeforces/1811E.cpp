#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

// 本质上是进制转换，10进制转9进制，但去除的符号不是9而是4
string convert(i64 k) {
    stack<char> stc;
    while (k > 0) {
        int rem = k % 9;
        k /= 9;
        if (rem >= 4) rem++;
        stc.push(rem + '0');
    }
    string result;
    while (!stc.empty()) {
        result.push_back(stc.top());
        stc.pop();
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        i64 k;
        cin >> k;
        cout << convert(k) << endl;
    }
    return 0;
}