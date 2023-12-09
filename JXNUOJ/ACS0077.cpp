#include <iostream>
#include <functional>
#include <cmath>
#include <cstdio>

using namespace std;

void convert_binary(bool *arr, unsigned long long n) {
    while (n > 0) {
        *arr = (n & 1) == 1;
        n >>= 1;
        arr++;
    }
}

unsigned long long convert_ll(const bool *arr) {
    unsigned long long result = 0;
    for (unsigned long long i=0; i<64; i++) {
        if (arr[i]) {
            result |= (1ull << i);
        }
    }
    return result;
}

void dfs(bool *arr, int n, const function<void()> &callback) {
    if (n == 0) {
        if (*arr) {
            *arr = false;
            callback();
            *arr = true;
            callback();
        } else {
            callback();
        }
        return;
    }
    if (arr[n]) {
        arr[n] = false;
        dfs(arr, n-1, callback);
        arr[n] = true;
        dfs(arr, n-1, callback);
    } else {
        dfs(arr, n-1, callback);
    }
}

int main() {
    unsigned long long n;
    scanf("%llu", &n);

    bool n_arr[64] = {false};
    convert_binary(n_arr, n);

    dfs(n_arr, 63, [&n_arr]() {printf("%llu\n", convert_ll(n_arr));});
    return 0;
}