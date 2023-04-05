#include <bits/stdc++.h>

using namespace std;
using u64 = uint64_t;

const u64 MOD = 998244353;

u64 fact(u64 x) {
    u64 r = 1;
    while (x > 1) {
        r *= x--;
        r %= MOD;
    }
    return r;
}

u64 fact_div(u64 x, u64 y) {
    u64 a = max(x, y), b = min(x, y);
    u64 r = 1;
    while (a>b) {
        r *= a--;
        r %= MOD;
    }
    return r;
}

u64 combinate_num(u64 m, u64 n) {
    return fact_div(n, n-m)/fact(m);
}

u64 combine_sort(u64 al, u64 bl, u64 at, u64 bt) {
    if (al > bl) {
        swap(al, bl);
        swap(at, bt);
    }
    u64 cn = combinate_num(bl, al+1);
    cn *= at;
    cn %= MOD;
    cn *= bt;
    cn %= MOD;
}

struct ast {
    char value;
    vector<shared_ptr<ast>> childs;

    ast() : value('+') {}
    ast(char op) : value(op) {}
    ast(const string& str) {
        build(str);
    }

    void add_child(shared_ptr<ast> tr) {
        childs.push_back(move(tr));
    }

    void simplify() {
        vector<shared_ptr<ast>> buffer;
        for (auto iter = childs.begin(); iter != childs.end();) {
            shared_ptr<ast>& ch = *iter;
            ch->simplify();
            if (ch->value == value) {
                for (shared_ptr<ast>& ch2 : ch->childs) {
                    buffer.push_back(ch2);
                    ch2.reset();
                }
                iter = childs.erase(iter);
            } else iter++;
        }
        for (shared_ptr<ast>& p : buffer) {
            childs.push_back(p);
        }
    }

    u64 count_types() {
        if (value >= '0' && value <= '9') {
            return 1;
        }
        vector<u64> steps, types;
        for (auto& p : childs) {
            steps.push_back(p->count_steps());
            types.push_back(p->count_types());
        }
        size_t n = childs.size();
        
    }

    u64 count_steps() {
        if (value >= '0' && value <= '9') {
            return 0;
        }
        u64 total = childs.size()-1;
        for (shared_ptr<ast>& t : childs) {
            total += t->count_steps();
        }
        return total;
    }

    static int operator_priority(char c) {
        switch (c) {
            case '+':
                return 1;
            case '*':
                return 2;
        }
        return 0;
    }


    static shared_ptr<ast> build(const string& str) {
        stack<shared_ptr<ast>> num;
        stack<char> op;
        for (char c : str) {
            if (c >= '0' && c <= '9') {
                num.push(make_shared<ast>(c));
            } else if (c == '*' || c == '+') {
                int prio = operator_priority(c);
                while (!op.empty() && op.top() != '(' && operator_priority(op.top()) > prio) {
                    char op2 = op.top();
                    op.pop();
                    shared_ptr<ast> n2 = num.top();
                    num.pop();
                    shared_ptr<ast> n1 = num.top();
                    num.pop();
                    shared_ptr<ast> na = make_shared<ast>(op2);
                    na->add_child(n1);
                    na->add_child(n2);
                    num.push(na);
                }
                op.push(c);
            } else if (c == '(') {
                op.push(c);
            } else if (c == ')') {
                while (!op.empty() && op.top() != '(') {
                    char op2 = op.top();
                    op.pop();
                    shared_ptr<ast> n2 = num.top();
                    num.pop();
                    shared_ptr<ast> n1 = num.top();
                    num.pop();
                    shared_ptr<ast> na = make_shared<ast>(op2);
                    na->add_child(n1);
                    na->add_child(n2);
                    num.push(na);
                }
                op.pop();
            }
        }
        while (!op.empty()) {
            char op2 = op.top();
            op.pop();
            shared_ptr<ast> n2 = num.top();
            num.pop();
            shared_ptr<ast> n1 = num.top();
            num.pop();
            shared_ptr<ast> na = make_shared<ast>(op2);
            na->add_child(n1);
            na->add_child(n2);
            num.push(na);
        }
        return num.top();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string ex;
        cin >> ex;
        shared_ptr<ast> tree = ast::build(ex);
        tree->simplify();
        u64 res = tree->count_types();
        cout << res << endl;
    }
    return 0;
}