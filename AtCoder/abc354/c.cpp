#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    vector<pair<int, int>> cards(n);
    for (int i=0; i<n; i++) {
        cin >> cards[i].first >> cards[i].second;
    }
    sort(ind.begin(), ind.end(), [&](int a, int b) {return cards[a].first < cards[b].first;} );

    vector<int> cdv(n);
    deque<int> rvq;
    for (int u=n-1; u>=0; u--) {
        cdv[u] = rvq.empty() ? n : rvq.front();
        while (!rvq.empty() && cards[ind[rvq.back()]].second >= cards[ind[u]].second) {
            rvq.pop_back();
        }
        rvq.push_back(u);
    }

    vector<int> remain_cards;
    for (int r = rvq.front(); r < n; r = cdv[r]) {
        remain_cards.push_back(ind[r]);
    }

    sort(remain_cards.begin(), remain_cards.end());

    cout << remain_cards.size() << '\n';
    for (int i : remain_cards) cout << (i+1) << ' ';
    cout << '\n';
    return 0;
}