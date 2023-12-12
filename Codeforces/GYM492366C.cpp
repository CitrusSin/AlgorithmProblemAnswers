#include <iostream>
#include <limits>
#include <stdexcept>
#include <string_view>
#include <vector>
#include <string>

using namespace std;

int hex_to_ch(string_view sv) {
    int val = 0;
    for (char c : sv) {
        int d;
        if (c >= '0' && c <= '9') {
            d = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            d = c - 'a' + 10;
        } else {
            continue;
        }

        val *= 16;
        val += d;
    }

    return val;
}

bool is_cstring(const vector<int>& arr) {
    size_t n = arr.size();
    size_t pos = numeric_limits<size_t>::max();
    bool contains_invalid = false;
    for (size_t i=0; pos>=n && i<n; i++) {
        if (arr[i] == 0) {
            pos = i;
            break;
        } else if (arr[i] < 0x20 || arr[i] > 0x7f) {
            contains_invalid = true;
        }
    }

    return pos < n && !contains_invalid;
}

bool is_pascal_string(const vector<int>& arr) {
    size_t nt = arr.size();
    if (nt == 0) return false;

    int n = arr[0];
    if (n >= nt) return false;
    if (n < 0) return false;

    bool contains_invalid = false;
    for (int i=0; i<n; i++) {
        char c = arr[i+1];
        if (c < 0x20 || c > 0x7f) {
            contains_invalid = true;
            break;
        }
    }

    return !contains_invalid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> arr;
    string val;
    while (cin >> val) {
        arr.push_back(hex_to_ch(val));
    }

    bool c = is_cstring(arr);
    bool pascal = is_pascal_string(arr);

    int state = (static_cast<int>(c) << 1) | static_cast<int>(pascal);

    switch (state) {
    case 0b00:
        cout << "None" << endl;
        break;
    case 0b01:
        cout << "Pascal" << endl;
        break;
    case 0b10:
        cout << "C" << endl;
        break;
    case 0b11:
        cout << "Both" << endl;
        break;
    default:
        cout << "None" << endl;
        break;
    }
    return 0;
}