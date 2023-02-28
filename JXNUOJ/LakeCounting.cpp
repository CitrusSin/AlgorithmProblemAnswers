#include <iostream>

using namespace std;

bool check(int x, int y, bool *water, bool *checked, int n, int m) {
    if (!checked[x*m+y]) {
        checked[x*m+y] = true;
        if (water[x*m+y]) {
            for (int i=max(0,x-1); i<=min(x+1, n-1); i++) {
                for (int j=max(0,y-1); j<=min(y+1, m-1); j++) {
                    if (i!=x || j!=y) {
                        if (!checked[i*m+j])
                            check(i, j, water, checked, n, m);
                    }
                }
            }
            return true;
        }
    } else return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    cin.get();

    bool water[n*m];
    bool checked[n*m];
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            water[i*m+j] = cin.get() == 'W';
            checked[i*m+j] = false;
        }
        cin.get();
    }

    int counter = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!checked[i*m+j]) {
                if (check(i, j, water, checked, n, m)) counter++;
            }
        }
    }

    cout << counter << endl;
    return 0;
}