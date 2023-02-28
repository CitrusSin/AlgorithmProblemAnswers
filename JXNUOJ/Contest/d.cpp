#include <bits/stdc++.h>
using namespace std;

int read_int(istream& in) {
    int result = 0;
    char c;
    while (in) {
        c = in.peek();
        if (c >= '0' && c <= '9') {
            in >> c;
            result *= 10;
            result += (c&0x0f);
        } else break;
    }
    return result;
}

string expand_string_intern1(istream& in) {
    stringstream ss;
    
    int c;
    while (in) {
        c = in.peek();
        if (c == istream::traits_type::eof()) return ss.str();
        if (c == ')') return ss.str();
        if (c >= 'a' && c <= 'z') {
            in.get();
            ss << (char)c;
        } else if (c>='0' && c<='9' || c == '(') {
            int times = 1;
            if (c >= '0' && c <= '9') {
                times = read_int(in);
            }
            while (in.peek() != '(' && !(in.peek() >= 'a' && in.peek() <= 'z')) in.get();
            string segment;
            if (in.peek() == '(') {
                in.get();
                segment = expand_string_intern1(in);
                while (in.peek() != ')') in.get();
                in.get();
            } else {
                segment.push_back(in.get());
            }

            while (times--) {
                ss << segment;
            }
        } else {
            in.get();
        }
    }

    return ss.str();
}

string expand_string(const string& s) {
    stringstream ss(s);
    return expand_string_intern1(ss);
}

int main() {
    int n;
    cin >> n;
    cin.get();
    while (n--) {
        string s;
        getline(cin, s);
        cout << expand_string(s) << endl;
    }
    return 0;
}