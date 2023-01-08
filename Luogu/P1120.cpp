#include <bits/stdc++.h>

using namespace std;

bool take_group(multiset<int> &set, multiset<int>::iterator b, multiset<int>::iterator e, int test_len) {
    if (test_len == 0) {
        return true;
    } else if (b == e) {
        return false;
    }

    for (auto it = b; it != e; it++) {
        if (*it <= test_len) {
            int val = *it;
            auto it2 = it;
            it2++;
            bool result = take_group(set, it2, e, test_len - val);
            if (result) {
                set.erase(it);
                return true;
            }
        }
    }
    return false;
}

bool check_sticks(const vector<int> &vec, int test_len) {
    multiset<int> groups;
    for (int i : vec) {
        groups.insert(i);
    }

    while (groups.size() > 0) {
        if (!take_group(groups, groups.begin(), groups.end(), test_len)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    int l = *max_element(a.begin(), a.end()), r = accumulate(a.begin(), a.end(), 0);

    /*
    while (l<r) {
        int mid = l+(r-l)/2;
        if (check_sticks(a, mid)) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    */
    for (int t=l; t<=r; t++) {
        if (check_sticks(a, t)) {
            cout << t << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}