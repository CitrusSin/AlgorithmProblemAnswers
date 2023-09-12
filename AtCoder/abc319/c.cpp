#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);

    array<int, 9> c;
    for (int i=0; i<9; i++) cin >> c[i];

    array<int, 9> rk = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int satis_count = 0;
    for (int r=0; r<362880; r++) {
        bool flag = true;
        for (int i=0; i<3 && flag; i++) {
            array<pair<int, int>, 3> ap;
            for (int j=0; j<3; j++) ap[j] = pair<int, int>(rk[3*i+j], c[3*i+j]);
            sort(ap.begin(), ap.end(), [](auto& a, auto& b) {return a.first < b.first;});
            if (ap[0].second == ap[1].second) {
                flag = false;
            }
        }
        for (int j=0; j<3 && flag; j++) {
            array<pair<int, int>, 3> ap;
            for (int i=0; i<3; i++) ap[i] = pair<int, int>(rk[3*i+j], c[3*i+j]);
            sort(ap.begin(), ap.end(), [](auto& a, auto& b) {return a.first < b.first;});
            if (ap[0].second == ap[1].second) {
                flag = false;
            }
        }
        if (flag) {
            array<pair<int, int>, 3> ap;
            for (int i=0; i<3; i++) ap[i] = pair<int, int>(rk[3*i+i], c[3*i+i]);
            sort(ap.begin(), ap.end(), [](auto& a, auto& b) {return a.first < b.first;});
            if (ap[0].second == ap[1].second) {
                flag = false;
            }
        }
        if (flag) {
            array<pair<int, int>, 3> ap;
            for (int i=0; i<3; i++) ap[i] = pair<int, int>(rk[3*i+(2-i)], c[3*i+(2-i)]);
            sort(ap.begin(), ap.end(), [](auto& a, auto& b) {return a.first < b.first;});
            if (ap[0].second == ap[1].second) {
                flag = false;
            }
        }
        if (flag) satis_count++;
        next_permutation(rk.begin(), rk.end());
    }

    double rst = satis_count / 362880.0;
    cout << rst << endl;
    return 0;
}