#include <bits/stdc++.h>

using namespace std;

bool judgeInternal(const vector<int> &s, vector<int> &b) {
    auto i1 = s.begin(), i2 = s.end();
    if (i1 == i2) return true;
    i2--;

    auto j1 = find(s.begin()+1, s.end(), *i1);
    auto j2 = find(s.begin(), s.end()-1, *i2);

    if (j1 == i2) {
        return false;
    }

    if (*i1 > *i2) {
        auto sw = i1;
        i1 = i2;
        i2 = sw;

        sw = j1;
        j1 = j2;
        j2 = sw;
    }

    vector<int> s1 = s, s2 = s;
    s1.erase(s1.begin() + (j1 - s.begin()));
    s2.erase(s2.begin() + (j2 - s.begin()));

    b.push_back(*i1);
    if (judgeInternal(s1, b)) {
        b.push_back(*i1);
        return true;
    }
    b.clear();
    b.push_back(*i2);
    if (judgeInternal(s2, b)) {
        b.push_back(*i2);
        return true;
    }
    b.clear();
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(2*n);
    for (int i=0; i<2*n; i++) {
        cin >> arr[i];
    }

    vector<int> result;
    if (judgeInternal(arr, result)) {
        for (int i : result) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}