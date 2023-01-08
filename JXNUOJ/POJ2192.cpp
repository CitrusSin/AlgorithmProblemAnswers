#include <iostream>
#include <string>

using namespace std;

bool check_string(const string &a, const string &b, const string &c) {
    int a_len = a.length(), b_len = b.length(), c_len = c.length();
    bool dp[a_len+1][b_len+1];
    for (int i=0; i<a_len+1; i++) {
        for (int j=0; j<b_len+1; j++) {
            dp[i][j] = i == 0 && j == 0;
            if (i >= 1 && dp[i-1][j]) {
                dp[i][j] = dp[i][j] || a[i-1] == c[i+j-1];
            }
            if (j >= 1 && dp[i][j-1]) {
                dp[i][j] = dp[i][j] || b[j-1] == c[i+j-1];
            }
        }
    }
    return dp[a_len][b_len];
}

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        string a, b, c;
        cin >> a >> b >> c;

        cout << "Data set " << i+1 << ": " << (check_string(a, b, c)?"yes":"no") << endl;
    }
    return 0;
}