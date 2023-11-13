#include <bits/stdc++.h>

using namespace std;

array<array<int, 4>, 3> input_cube() {
    array<array<int, 4>, 3> arr;
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            cin >> arr[i][j];
        }
    }
    return arr;
}

void process_array(array<array<int, 4>, 3>& arr) {
    for (int i=0; i<4; i++) {
        int n0 = 0, c0 = 0;
        for (int j=0; j<3; j++) {
            if (arr[j][i] == 0) {
                c0++;
            } else {
                n0 = j;
            }
        }
        if (n0 != 1 && c0 == 2) {
            swap(arr[n0][i], arr[1][i]);
            break;
        }
    }
    for (int i=1; i<4; i++) {
        if (arr[0][i]) swap(arr[0][0], arr[0][i]);
        if (arr[2][i]) swap(arr[2][0], arr[2][i]);
    }
}

map<int, int> analyze_array(array<array<int, 4>, 3>& arr) {
    process_array(arr);
    map<int, int> result;
    result[arr[0][0]] = arr[2][0];
    result[arr[2][0]] = arr[0][0];
    result[arr[1][0]] = arr[1][2];
    result[arr[1][2]] = arr[1][0];
    result[arr[1][1]] = arr[1][3];
    result[arr[1][3]] = arr[1][1];
    return result;
}

template <typename T>
bool operator==(const set<T>& s1, const set<T>& s2) {
    for (const T& p : s1) {
        if (!s2.count(p)) return false;
    }
    for (const T& p : s2) {
        if (!s1.count(p)) return false;
    }
    return true;
}

template <typename T, typename U>
bool operator==(const map<T, U>& m1, const map<T, U>& m2) {
    for (const pair<T, U>& p1 : m1) {
        const T& k = p1.first;
        const U& v = p1.second;
        if (m2.count(k)) {
            if (m2.at(k) != v) {
                return false;
            }
        } else {
            return false;
        }
    }
    for (const pair<T, U>& p1 : m2) {
        const T& k = p1.first;
        const U& v = p1.second;
        if (m1.count(k)) {
            if (m1.at(k) != v) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    auto arr1 = input_cube(), arr2 = input_cube();

    cout << (analyze_array(arr1) == analyze_array(arr2) ? "YES" : "NO") << endl;
    return 0;
}