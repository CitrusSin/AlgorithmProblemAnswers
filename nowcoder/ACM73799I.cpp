#include <bits/stdc++.h>

using namespace std;

string number_localize(int x) {
    if (x >= 10000) {
        string ans;
        ans += number_localize(x / 10000);
        ans += "万";
        if (x % 10000 != 0) {
            if (x % 10000 < 1000) ans += "零";
            ans += number_localize(x % 10000);
        }
        return ans;
    }
    
    int k = x / 1000;
    int h = x / 100 % 10;
    int t = x / 10 % 10;
    int n = x % 10;
    array<int, 4> p{k, h, t, n};
    const array<string, 4> unit{"仟", "佰", "拾", ""};
    const array<string, 10> nums{"", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
    
    int i = 0;
    while (i < 4 && p[i] == 0) i++;
    bool zf = false;
    string ans;
    for (; i<4; i++) {
        if (p[i] == 0) {
            zf = true;
            continue;
        }
        if (zf) {
            ans += "零";
            zf = false;
        }
        ans += nums[p[i]] + unit[i];
    }
    if (x == 0) ans = "零";
    return ans;
}

string money_localize(string x) {
    string::size_type dot_pos = x.find('.');
    int intp, np;
    stringstream ss;
    if (dot_pos == string::npos) {
        ss.str(x);
        np = 0;
    } else {
        ss.str(x.substr(0, dot_pos));
    }
    ss >> intp;
    ss.clear();
    if (dot_pos != string::npos) {
        string p = x.substr(dot_pos+1);
        if (p.size() == 1) p.push_back('0');
        ss.str(p);
        ss >> np;
    }

    string ans;
    ans += number_localize(intp);
    ans += "元";

    if (np == 0) {
        ans += "整";
    } else {
        const array<string, 10> nums{"", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
        int pen = np / 10, cent = np % 10;
        if (pen == 0) {
            ans += "零";
        } else {
            ans += nums[pen] + "角";
        }
        if (cent) {
            ans += nums[cent] + "分";
        }
    }
    return ans;
}

int main() {
    string x;
    while (cin >> x) {
        cout << money_localize(x) << endl;
    }
}
