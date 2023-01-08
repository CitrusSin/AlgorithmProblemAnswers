#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    unordered_map<string, int> word_indices;
    for (int i=0; i<n; i++) {
        string word;
        cin >> word;
        word_indices[word] = i;
    }

    int m;
    cin >> m;
    vector<int> word_data(m);
    for (int i=0; i<m; i++) {
        string w;
        cin >> w;
        if (word_indices.count(w)>0) {
            word_data[i] = word_indices[w];
        } else {
            word_data[i] = -1;
        }
    }

    vector<int> word_counts(n, 0);
    int l=0, r=0;
    int minimum_len = 2147483647, maximum_words = 0;
    while (l < m && r < m) {
        while (r < m && word_data[r] < 0) r++;
        if (r < m) {
            word_counts[word_data[r++]]++;
        }
        while (l < m && word_data[l] < 0) l++;
        while (l < m && word_counts[word_data[l]] > 1) {
            word_counts[word_data[l++]]--;
            if (r < l) r++;
        }
        int wc = 0;
        for (int c : word_counts) {
            if (c > 0) {
                wc++;
            }
        }
        if (wc > maximum_words) {
            maximum_words = wc;
            minimum_len = r-l;
        } else if (wc == maximum_words) {
            int len = r-l;
            if (len < minimum_len) {
                minimum_len = len;
            }
        }
    }

    cout << maximum_words << endl << minimum_len << endl;
    return 0;
}