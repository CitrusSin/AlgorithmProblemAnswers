#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool comp(string_view sv1, string_view sv2, int k) {
    size_t s = sv1.size();
    int tcnt = 0;
    for (size_t i=0; i<s; i++) {
        if (sv1[i] != sv2[i]) tcnt++;
        if (tcnt > k) return false;
    }
    return tcnt <= k;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> strs(n);
    for (int i=0; i<n; i++) cin >> strs[i];

    string temp;
    cin >> temp;

    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (comp(temp, strs[i], k)) cnt++;
    }

    cout << cnt << endl;
    return 0;
}