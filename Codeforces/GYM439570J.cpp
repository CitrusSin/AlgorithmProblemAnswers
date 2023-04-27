#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    map<int, int> occur_count;
    int max_number = 0;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        occur_count[p]++;
        max_number = max(max_number, p);
    }

    int final_result = 0;
    for (auto iter = occur_count.begin(); iter != occur_count.end(); iter++) {
        auto& p = *iter;
        if (p.second == 0) continue;

        int total_count_1 = 0, total_count_2 = 0;
        int k = p.first;
        bool flag = true;
        while (k <= max_number) {
            if (occur_count.count(k) && occur_count[k] > 0) {
                if (flag) {
                    total_count_1 += occur_count[k];
                } else {
                    total_count_2 += occur_count[k];
                }
                occur_count[k] = 0;
                flag = !flag;
                k *= 2;
            } else break;
        }

        final_result += min(total_count_1, total_count_2);
    }
    cout << final_result << endl;
    return 0;
}