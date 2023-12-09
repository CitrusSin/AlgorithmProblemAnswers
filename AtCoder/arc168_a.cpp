#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;
    
    int64_t cnt = 0;
    int64_t j = 0;
    for (int i=0; i<n-1; i++) {
        if (s[i] == '>') {
            j++;
        } else {
            cnt += j * (j+1) / 2;
            j = 0;
        }
    }
    cnt += j * (j+1) / 2;
    cout << cnt << endl;

    return 0;
}