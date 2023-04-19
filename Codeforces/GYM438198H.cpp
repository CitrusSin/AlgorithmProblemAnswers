#include <bits/stdc++.h>

using namespace std;

vector<int> process(const string& str) {
    size_t n = str.size();
    stack<int> stk;
    vector<int> result;
    result.reserve(n);
    for (int i=0; i<n; i++) {
        switch (str[i]) {
        case '(':
            stk.push(i+1);
            break;
        case '-':
            result.push_back(i+1);
            break;
        case ')':
            result.push_back(i+1);
            result.push_back(stk.top());
            stk.pop();
            break;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;
    
    vector<int> res = process(s);
    for (int p : res) {
        cout << p << ' ';
    }
    cout << endl;
    return 0;
}