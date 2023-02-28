#include <bits/stdc++.h>

using namespace std;

template <typename Child>
bool vector_equal(const vector<Child>& vec1, const vector<Child>& vec2) {
    if (vec1.size() != vec2.size()) {
        return false;
    }
    for (int i=0; i<vec1.size(); i++) {
        if (vec1[i] != vec2[i]) {
            return false;
        }
    }
    return true;
}

vector<int> find_longest_child(const vector<int>& arr1, const vector<int>& arr2) {
    int len1 = arr1.size(), len2 = arr2.size();
    if (len1 > 0 && len2 > 0) {
        vector<int> dp[len1+1][len2+1];
        for (int i=1; i<=len1; i++) {
            for (int j=1; j<=len2; j++) {
                if (arr1[i-1] == arr2[j-1]) {
                    vector<int> null_vec(0), *max_len_vec = &null_vec;
                    for (int i2=0; i2<i; i2++) {
                        for (int j2=0; j2<j; j2++) {
                            if (dp[i2][j2].size() > max_len_vec->size() && *(dp[i2][j2].end()-1) < arr1[i-1]) {
                                max_len_vec = &dp[i2][j2];
                            }
                        }
                    }
                    dp[i][j] = *max_len_vec;
                    dp[i][j].push_back(arr1[i-1]);
                } else {
                    if (dp[i][j-1].size() > dp[i-1][j].size()) {
                        dp[i][j] = dp[i][j-1];
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        vector<int> *res = &dp[0][0];
        for (int i=1; i<=len1; i++) {
            for (int j=1; j<=len2; j++) {
                if (dp[i][j].size() > res->size()) {
                    res = &dp[i][j];
                }
            }
        }
        return *res;
    } else {
        return vector<int>(0);
    }
}

int main() {
    int n1, n2;

    cin >> n1;
    vector<int> arr1(n1);
    for (int i=0; i<n1; i++) {
        cin >> arr1[i];
    }

    cin >> n2;
    vector<int> arr2(n2);
    for (int i=0; i<n2; i++) {
        cin >> arr2[i];
    }

    vector<int> lc = find_longest_child(arr1, arr2);
    cout << lc.size() << endl;
    for (auto iter = lc.begin(); iter < lc.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << endl;
    return 0;
}