#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    list<int> a, b;

    cin >> n;
    for (int i=0; i<n; i++) {
        int r;
        cin >> r;
        a.push_back(r);
    }
    for (int i=0; i<n; i++) {
        int r;
        cin >> r;
        b.push_back(r);
    }

    int max_counter = 0;
    int size = n;
    while (size > n/2) {
        int counter = 0;
        auto it1 = a.begin(), it2 = b.begin();
        while (it1 != a.end()) {
            if (*it1 == *it2) {
                auto itb1 = it1, itb2 = it2;
                it1++;
                it2++;
                a.erase(itb1);
                b.erase(itb2);
                counter++;
            } else {
                it1++;
                it2++;
            }
        }
        if (counter > max_counter) max_counter = counter;
        size = a.size();

        // Circulation move
        int s = b.back();
        b.pop_back();
        b.push_front(s);
    }
    cout << max_counter << endl;
    return 0;
}