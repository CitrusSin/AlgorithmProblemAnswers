#include <bits/stdc++.h>
using namespace std;

struct lake {
    int samplex;
    int sampley;
    int size;
};

int check_plot(int x, int y, int n, int m, bool *water, bool *checked) {
    if (!checked[x*m+y]) {
        checked[x*m+y] = true;
        if (water[x*m+y]) {
            int accu = 1;
            for (int i=max(0, x-1); i<=min(n-1, x+1); i++) {
                for (int j=max(0, y-1); j<=min(m-1, y+1); j++) {
                    if (!checked[i*m+j] && water[i*m+j] && (abs(i-x)+abs(j-y) <= 1)) {
                        int val = check_plot(i, j, n, m, water, checked);
                        if (val < 0 || accu < 0 || x == 0 || x == n-1 || y == 0 || y == n-1) {
                            accu = -1;
                        } else {
                            accu += val;
                        }
                    }
                }
            }
            return accu;
        }
    }
    return 0;
}

void fill_lake(int sx, int sy, int n, int m, bool *water) {
    if (water[sx*m+sy]) {
        water[sx*m+sy] = false;
        for (int i=max(0, sx-1); i<=min(n-1, sx+1); i++) {
            for (int j=max(0, sy-1); j<=min(m-1, sy+1); j++) {
                if (water[i*m+j] && (abs(i-sx)+abs(j-sy) <= 1)) {
                    fill_lake(i, j, n, m, water);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    cin.get();

    //bool water[n*m];
    //bool checked[n*m];
    unique_ptr<bool[]> water(new bool[n*m]), checked(new bool[n*m]);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char c = cin.get();
            water[i*m+j] = (c == '.');
            checked[i*m+j] = false;
        }
        cin.get();
    }

    vector<lake> lakes;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (water[i*m+j] && !checked[i*m+j]) {
                int lake_size = check_plot(i, j, n, m, water.get(), checked.get());
                if (lake_size > 0) {
                    lake l;
                    l.samplex = i;
                    l.sampley = j;
                    l.size = lake_size;
                    lakes.push_back(std::move(l));
                }
            }
        }
    }

    int fill_lake_count = lakes.size() - k;

    sort(lakes.begin(), lakes.end(), [](lake &a, lake &b) {return a.size < b.size;});
    int accu = 0;
    for (int i=0; i<fill_lake_count; i++) {
        accu += lakes[i].size;
        fill_lake(lakes[i].samplex, lakes[i].sampley, n, m, water.get());
    }

    cout << accu << endl;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << (water[i*m+j]?'.':'*');
        }
        cout << endl;
    }
    return 0;
}