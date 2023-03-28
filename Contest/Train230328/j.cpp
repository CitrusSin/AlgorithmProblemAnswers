#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323;

struct pvec {
    double x;
    double y;

    pvec() : x(0), y(0) {}
    pvec(double theta) : x(cos(theta)), y(sin(theta)) {}
    pvec(double x, double y) : x(x), y(y) {}

    pvec rotate(double dtheta) const {
        double c = cos(dtheta), s = sin(dtheta);
        double x2 = x*c-y*s;
        double y2 = x*s+y*c;
        return pvec(x2, y2);
    }

    double sqlen() const {
        return x*x+y*y;
    }

    double len() const {
        return sqrt(sqlen());
    }

    pvec operator+(const pvec& v) const {
        return pvec(x+v.x, y+v.y);
    }

    pvec operator-() const {
        return pvec(-x, -y);
    }

    pvec operator-(const pvec& v) const {
        return (*this)+(-v);
    }

    pvec operator*(double k) const {
        return pvec(k*x, k*y);
    }
    pvec& operator*=(double k) {
        x *= k;
        y *= k;
        return *this;
    }

    pvec operator/(double k) const {
        return (*this)*(1.0/k);
    }
    pvec& operator/=(double k) {
        return (*this) *= (1.0/k);
    }

    pvec normalize() const {
        double l = len();
        return (*this) / l;
    }

    double distance(const pvec& v) const {
        return ((*this)-v).len();
    }
};

array<pvec, 2> get_mids(pvec p1, pvec p2) {
    pvec x = (p2-p1)/2;
    pvec rt = x.normalize();
    double theta = acos(x.len());
    pvec r1 = p1 + rt.rotate(theta), r2 = p1 + rt.rotate(-theta);
    return {r1, r2};
}

vector<pvec> solve(int s, int t) {
    const int cri2 = 90;
    const int cri3 = 90+(int)floor(180.0/PI*acos(3.0/4.0));

    if (s == t) {
        return {pvec(PI*s/180.0)};
    }

    bool exchange = s>t;
    if (exchange) {
        int sw = s;
        s = t;
        t = sw;
    }
    double sr = PI*s/180.0, tr = PI*t/180.0;
    pvec sp = pvec(sr), tp = pvec(tr);

    int degs = t-s;
    if (degs > 180) degs = 360-degs;

    vector<pvec> mids;
    if (degs <= cri2) {
        array<pvec, 2> res = get_mids(sp, tp);
        pvec mid = res[0].len()<=1.0-(1e-6)?res[1]:res[0];
        mids.push_back(mid);
    } else if (degs <= cri3) {
        pvec t1 = sp+sp.rotate(PI/2.0), t2 = sp+sp.rotate(-PI/2.0);
        pvec p1 = t1.distance(tp)>t2.distance(tp)?t2:t1;
        mids.push_back(p1);
        array<pvec, 2> p2s = get_mids(p1, tp);
        pvec p2 = p2s[0].len()<=1.0-(1e-6)?p2s[1]:p2s[0];
        mids.push_back(p2);
    } else {
        pvec p2a = sp.rotate(PI/2.0), p2b = sp.rotate(-PI/2.0);
        pvec p2 = p2a.distance(tp)>p2b.distance(tp)?p2b:p2a;
        array<pvec, 2> p1s = get_mids(p2, sp);
        pvec p1 = p1s[0].len()<=1.0-(1e-6)?p1s[1]:p1s[0];
        mids.push_back(p1);
        mids.push_back(p2);

        array<pvec, 2> p3s = get_mids(p2, tp);
        pvec p3 = p3s[0].len()<=1.0-(1e-6)?p3s[1]:p3s[0];
        mids.push_back(p3);
    }

    if (exchange) {
        pvec sw = sp;
        sp = tp;
        tp = sw;

        size_t n = mids.size();
        for (int i=0; i<n-i-1; i++) {
            swap(mids[i], mids[n-i-1]);
        }
    }

    vector<pvec> result;

    result.push_back(sp);
    for (pvec& v : mids) {
        result.push_back(v);
    }
    result.push_back(tp);
    return result;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int s, t;
        scanf("%d%d", &s, &t);
        vector<pvec> res = solve(s, t);
        printf("%d\n", (int)(res.size()-1));
        for (pvec& p : res) {
            printf("%.10lf %.10lf\n", p.x, p.y);
        }
    }
    return 0;
}