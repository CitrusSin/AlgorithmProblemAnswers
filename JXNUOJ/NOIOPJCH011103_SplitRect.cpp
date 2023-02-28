#include <iostream>

using namespace std;

struct Rectangle {
    int x;
    int y;
    int w;
    int h;
};

typedef long long ll;

ll get_square_on_left(Rectangle *recs, int n, int pos) {
    ll sq = 0;
    for (int i=0; i<n; i++) {
        if (recs[i].x < pos) {
            int right_side = min(recs[i].x+recs[i].w, pos);
            sq += (ll)(right_side - recs[i].x)*(ll)recs[i].h;
        }
    }
    return sq;
}

int search_split(Rectangle *recs, int n, int m) {
    ll target_sq = 0;
    ll total_sq = 0;
    for (int i=0; i<n; i++) {
        total_sq += (ll)recs[i].w*(ll)recs[i].h;
    }
    int l=0, r=m;
    while (r>l) {
        int pos = l+(r-l)/2;
        ll left_sq = get_square_on_left(recs, n, pos);
        ll right_sq = total_sq-left_sq;
        target_sq = left_sq;
        if (left_sq > right_sq) {
            r = pos;
        } else if (left_sq < right_sq) {
            l = pos;
        } else {
            break;
        }
    }
    while (get_square_on_left(recs, n, ++l));
    return --l;
}

int main() {
    int r, n;
    cin >> r >> n;

    Rectangle rectangles[n];
    for (int i=0; i<n; i++) {
        cin >> rectangles[i].x >> rectangles[i].y
            >> rectangles[i].w >> rectangles[i].h;
    }

    int pos = search_split(rectangles, n, r);
    cout << pos << endl;
    return 0;
}