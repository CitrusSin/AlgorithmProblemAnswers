#include <bits/stdc++.h>

using namespace std;

bool inc_internal(deque<char>::iterator b, deque<char>::iterator e) {
    if (b == e) return true;
    e--;
    if (*e == '1') {
        *e = '0';
        return inc_internal(b, e);
    } else {
        *e = '1';
        return false;
    }
}

void inc(deque<char>& num) {
    if (inc_internal(num.begin(), num.end())) {
        num.push_front('1');
    }
}

void dec_internal(deque<char>::iterator b, deque<char>::iterator e) {
    if (b == e) return;
    e--;
    if (*e == '1') {
        *e = '0';
    } else {
        *e = '1';
        dec_internal(b, e);
    }
}

void dec(deque<char>& num) {
    dec_internal(num.begin(), num.end());
    while (!num.empty() && num.front() == '0') num.pop_front();
    if (num.empty()) num.push_back('0');
}

int main() {
    int n, m;
    cin >> n >> m;
    string num;
    cin >> num;

    deque<char> num_op;
    for (char c : num) {
        num_op.push_back(c);
    }
    
    string opst;
    cin >> opst;
    for (char op : opst) {
        switch (op) {
            case '+':
                inc(num_op);
                break;
            case '-':
                dec(num_op);
                break;
            case '*':
                num_op.push_back('0');
                break;
            case '/':
                if (!num_op.empty()) num_op.pop_back();
                if (num_op.empty()) num_op.push_back('0');
                break;
        }
    }

    for (char c : num_op) {
        cout.put(c);
    }
    cout << endl;
    return 0;
}