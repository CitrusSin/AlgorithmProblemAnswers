#include <iostream>
#include <sstream>
#include <vector>
#include <list>

using namespace std;
using i64 = int64_t;

void solve() {
    int n;
    cin >> n;

    list<i64> arr1, arr2;
    for (size_t i=0; i<n; i++) {
        i64 val;
        cin >> val;
        val--;
        arr1.push_back(val);
    }
    for (size_t i=0; i<n; i++) {
        i64 val;
        cin >> val;
        val--;
        arr2.push_back(val);
    }

    vector<i64> nxt(n);
    for (auto it = arr2.begin(); it != arr2.end(); it++) {
        auto it2 = it;
        it2++;
        if (it2 == arr2.end()) it2 = arr2.begin();
        nxt[*it] = *it2;
    }

    stringstream ss;
    for (int nc = 0; nc < n; nc++) {
        if (*++arr1.begin() != nxt[arr1.front()]) {
            nc = 0;
            //cout << "Reset " << arr1.front() << endl;
        }
        while (*++arr1.begin() != nxt[arr1.front()]) {
            i64 p = *++arr1.begin();
            arr1.erase(++arr1.begin());
            arr1.push_back(p);

            ss << '2';
        }
        ss << "11";
        i64 p = arr1.front();
        arr1.pop_front();
        arr1.push_back(p);
        p = arr1.front();
        arr1.pop_front();
        arr1.push_back(p);
    }
    //cout << "Round end" << endl;
    while (arr1.front() != arr2.front()) {
        ss << '1';
        i64 p = arr1.front();
        arr1.pop_front();
        arr1.push_back(p);
    }
    //cout << "Finish" << endl;

    string result = ss.str();
    result = result.substr(0, result.size() - 2*n);
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}