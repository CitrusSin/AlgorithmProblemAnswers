#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ll xb, yb, xc, yc;
    cin >> xb >> yb >> xc >> yc;

    ll dp[xb+1][yb+1];
    dp[0][0] = 1;
    for (ll x=0; x<=xb; x++) {
        for (ll y=0; y<=yb; y++) {
            ll sum = 0;
            if (x==0 && y==0) {
                sum = 1;
            }
            ll sq_dist = (x-xc)*(x-xc)+(y-yc)*(y-yc);
            if (sq_dist != 5 && sq_dist != 0) {
                if (x > 0) {
                    sum += dp[x-1][y];
                }
                if (y > 0) {
                    sum += dp[x][y-1];
                }
            } else {
                sum = 0;
            }
            dp[x][y] = sum;
        }
    }
    cout << dp[xb][yb] << endl;
    return 0;
}