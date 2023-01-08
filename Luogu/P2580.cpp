#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    unordered_set<string> person_names;
    for (int i=0; i<n; i++) {
        string name;
        cin >> name;
        person_names.insert(std::move(name));
    }

    unordered_set<string> called_names;
    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        string name;
        cin >> name;
        if (called_names.count(name)) {
            cout << "REPEAT" << endl;
        } else if (!person_names.count(name)) {
            cout << "WRONG" << endl;
        } else {
            called_names.insert(std::move(name));
            cout << "OK" << endl;
        }
    }
    return 0;
}