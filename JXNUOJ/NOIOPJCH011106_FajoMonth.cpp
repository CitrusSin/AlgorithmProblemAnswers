#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool check_monthly_cost(int *arr, int n, int m, int monthly_cost) {
    int months = 0;
    int cost_accumulator = 0;
    for (int i=0; i<n; i++) {
        cost_accumulator += arr[i];
        if (cost_accumulator > monthly_cost) {
            months++;
            cost_accumulator = arr[i];
            if (months > m) {
                return false;
            }
        }
    }
    months++;
    return months <= m;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    int max = 0;
    for (int i=0; i<n; i++) {
        sum += arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int l = max, h = max*(int)ceil(n/(double)m);
    while (h > l) {
        int p = l+(h-l)/2;
        if (l == p || h == p) {
            if (!check_monthly_cost(arr, n, m, l)) {
                l = h;
            }
            break;
        } else if (check_monthly_cost(arr, n, m, p)) {
            h = p;
        } else {
            l = p;
        }
    }
    cout << l << endl;
    return 0;
}