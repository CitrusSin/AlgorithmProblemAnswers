#include <iostream>
#include <cstdio>

using namespace std;

bool is_leap_year(int year) {
    bool result = year % 4 == 0;
    if (result % 100 == 0 && result % 400 != 0) {
        result = false;
    }
    return result;
}

int get_month_length(int y, int m) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(y)) {
        days[1]++;
    }
    if (m >= 1 && m <= 12) {
        return days[m-1];
    } else {
        return 0;
    }
}

int main() {
    int y, m, d;
    while (scanf("%d/%d/%d", &y, &m, &d) == 3) {
        int days = 0;
        for (int i=1; i<m; i++) {
            days += get_month_length(y, i);
        }
        days += d;
        cout << days << endl;
    }
    return 0;
}