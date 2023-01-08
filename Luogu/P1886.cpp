#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> seq(n);
    for (int i=0; i<n; i++) {
        cin >> seq[i];
    }

    deque<int> dec, asc;
    for (int i=0; i<k; i++) {
        while (!dec.empty() && seq[dec.back()] <= seq[i]) {
            dec.pop_back();
        }
        dec.push_back(i);
        while (!asc.empty() && seq[asc.back()] >= seq[i]) {
            asc.pop_back();
        }
        asc.push_back(i);
    }

    vector<int> max_seq, min_seq;
    min_seq.push_back(seq[asc.front()]);
    max_seq.push_back(seq[dec.front()]);
    for (int i=k; i<n; i++) {
        if (!dec.empty() && dec.front() <= i-k) {
            dec.pop_front();
        }
        while (!dec.empty() && seq[dec.back()] <= seq[i]) {
            dec.pop_back();
        }
        dec.push_back(i);

        if (!asc.empty() && asc.front() <= i-k) {
            asc.pop_front();
        }
        while (!asc.empty() && seq[asc.back()] >= seq[i]) {
            asc.pop_back();
        }
        asc.push_back(i);

        min_seq.push_back(seq[asc.front()]);
        max_seq.push_back(seq[dec.front()]);
    }

    for (int x : min_seq) {
        cout << x << ' ';
    }
    cout << endl;
    for (int x : max_seq) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}