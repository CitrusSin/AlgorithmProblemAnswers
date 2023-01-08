#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<pair<int, int>> rects_height;
        rects_height.reserve(n);
        for (int i=0; i<n; i++) {
            int h, w;
            cin >> h >> w;
            rects_height.emplace_back(h, w);
        }

        sort(rects_height.begin(), rects_height.end(), [](auto& a, auto& b){return a.first<b.first;});

        map<int, int> height_first_map, height_last_map;
        for (int i=0; i<n; i++) {
            pair<int, int>& rect = rects_height[i];
            if (height_first_map.count(rect.first) == 0) {
                height_first_map[rect.first] = i;
            }
            height_last_map[rect.first] = i;
        }

        for (int i=0; i<q; i++) {
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;
            auto lit = height_first_map.upper_bound(hs);
            auto rit = height_first_map.lower_bound(hb);
            int l = lit == height_first_map.end() ? n : lit->second;
            int r = rit == height_first_map.end() ? n : rit->second;
            i64 sum = 0;
            for (int p=l; p<r; p++) {
                if (rects_height[p].second < wb && rects_height[p].second > ws) {
                    sum += i64(rects_height[p].first) * i64(rects_height[p].second);
                }
            }
            cout << sum << endl;
        }
    }
    return 0;
}