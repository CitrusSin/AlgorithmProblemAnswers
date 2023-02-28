#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int x) {
    int upper = (int)sqrt(x);
    for (int i=2; i<=upper; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(const int *nums, int before_sum, int n, int k, int &count) {
    if (k==0) {
        if (is_prime(before_sum)) {
            count++;
        }
        return;
    } else if (n < k || n <= 0) {
        return;
    }
    dfs(nums+1, before_sum + *nums, n-1, k-1, count);
    dfs(nums+1, before_sum, n-1, k, count);
}

int prime_count(const int *nums, int n, int k) {
    int count = 0;
    dfs(nums, 0, n, k, count);
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << prime_count(arr, n, k) << endl;
    return 0;
}