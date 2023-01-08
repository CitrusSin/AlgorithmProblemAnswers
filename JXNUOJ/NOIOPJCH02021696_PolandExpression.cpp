#include <iostream>
#include <string>
#include <cstdio>
#include <assert.h>

using namespace std;

double pol_exp_recursive(string &exp) {
    size_t space_pos = exp.find(' ');
    string next = exp.substr(0, space_pos);
    exp = exp.substr(space_pos+1);

    if (next == "+") {
        double a = pol_exp_recursive(exp);
        double b = pol_exp_recursive(exp);
        return a+b;
    } else if (next == "-") {
        double a = pol_exp_recursive(exp);
        double b = pol_exp_recursive(exp);
        return a-b;
    } else if (next == "*") {
        double a = pol_exp_recursive(exp);
        double b = pol_exp_recursive(exp);
        return a*b;
    } else if (next == "/") {
        double a = pol_exp_recursive(exp);
        double b = pol_exp_recursive(exp);
        return a/b;
    } else {
        double p;
        int count = sscanf(next.c_str(), "%lf", &p);
        assert(count == 1);

        return p;
    }
}

double pol_exp(const string &exp) {
    string cl = exp;
    double result = pol_exp_recursive(cl);
    return result;
}

int main() {
    char expr_buf[201];
    gets(expr_buf);

    double result = pol_exp(expr_buf);

    printf("%lf\n", result);
    return 0;
}