#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

template <typename iter> bool calculate_lvl0(iter &cursor, iter end);

template <typename iter>
bool calculate_lvl3(iter &cursor, iter end) {
    while (cursor < end && *cursor == ' ') cursor++;
    if (*cursor == '(') {
        cursor++;
        while (cursor < end && *cursor == ' ') cursor++;
        bool expr = calculate_lvl0(cursor, end);
        while (cursor < end && *cursor == ' ') cursor++;
        cursor++;
        return expr;
    } else {
        bool expr = *cursor == 'V';
        cursor++;
        while (cursor < end && *cursor == ' ') cursor++;
        return expr;
    }
}

template <typename iter>
bool calculate_lvl2(iter &cursor, iter end) {
    if (*cursor == '!') {
        cursor++;
        while (cursor < end && *cursor == ' ') cursor++;
        return !calculate_lvl3(cursor, end);
    } else {
        while (cursor < end && *cursor == ' ') cursor++;
        return calculate_lvl3(cursor, end);
    }
}

template <typename iter>
bool calculate_lvl1(iter &cursor, iter end) {
    bool b1 = calculate_lvl2(cursor, end);
    while (cursor < end && *cursor == ' ') cursor++;
    if (cursor != end && *cursor == '&') {
        cursor++;
        while (cursor < end && *cursor == ' ') cursor++;
        bool b2 = calculate_lvl2(cursor, end);
        return b1 && b2;
    }
    return b1;
}

template <typename iter>
bool calculate_lvl0(iter &cursor, iter end) {
    while (cursor < end && *cursor == ' ') cursor++;
    bool b1 = calculate_lvl1(cursor, end);
    while (cursor < end && *cursor == ' ') cursor++;
    if (cursor != end && *cursor == '|') {
        cursor++;
        while (cursor < end && *cursor == ' ') cursor++;
        bool b2 = calculate_lvl1(cursor, end);
        return b1 || b2;
    }
    return b1;
}

bool calculate_expression(const char *ptr) {
    int len = strlen(ptr);
    const char *p = ptr;
    return calculate_lvl0(p, ptr+len);
}

int main() {
    int counter = 1;
    char s[1001];
    while (gets(s)) {
        cout << "Expression " << counter << ": " << (calculate_expression(s)?"V":"F") << endl;
        counter++;
    }
    return 0;
}