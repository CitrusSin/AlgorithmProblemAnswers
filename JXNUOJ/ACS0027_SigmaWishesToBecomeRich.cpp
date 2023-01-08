#include <iostream>
#include <cstdio>

using namespace std;

long long min_cost(int *arr, int n) {
    if (n == 0 || n == 1) {
        return 0;
    }
    long long max_val = 0, max_index = 0;
    for (int i=0;i<n;i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
            max_index = i;
        }
    }
    if (max_index == 0 || max_index == n-1) {
        return max_val + min_cost(arr, max_index) + min_cost(arr+max_index+1, n-max_index-1);
    } else {
        return max_val * 2ll + min_cost(arr, max_index) + min_cost(arr+max_index+1, n-max_index-1);
    }
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }

    long long result = min_cost(arr, n);
    printf("%ld\n", result);
    delete arr;
    return 0;
}