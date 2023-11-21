#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<list<int>> grp(n);
    vector<int> deg(n);
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        deg[a]++;
        deg[b]++;
        grp[a].push_back(b);
        grp[b].push_back(a);
    }

    if (n == 2) {
        cout << "Bob" << endl;
        return 0;
    }

    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (deg[i] > 1) cnt++;
    }
    if (cnt%2 == 0) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
    return 0;
}