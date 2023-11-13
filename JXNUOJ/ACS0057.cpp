#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

void swap_double(double *a, double *b) {
    double swap = *a;
    *a = *b;
    *b = swap;
}

void swap(int *a, int *b) {
    int swap = *a;
    *a = *b;
    *b = swap;
}

void binded_sort(double *arr_standard, int *arr1, int *arr2, int n) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr_standard[i] < arr_standard[j]) {
                swap_double(&arr_standard[i], &arr_standard[j]);
                swap(&arr1[i], &arr1[j]);
                swap(&arr2[i], &arr2[j]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int d, v;
    cin >> d >> v;
    int m;
    cin >> m;
    int a;
    cin >> a;

    int prices[a], damages[a];
    double efficients[a];
    for (int i=0; i<a; i++) {
        cin >> prices[i] >> damages[i];
        efficients[i] = damages[i] / (double)prices[i];
    }

    binded_sort(efficients, prices, damages, a);

    int damage_counter = 0;
    for (int i=0; i<a; i++) {
        int buy_count = m / prices[i];
        m = m % prices[i];

        damage_counter += damages[i] * buy_count;
    }

    int kill_count = damage_counter / v;
    int remain_count = d - kill_count;
    int remain_life = n - remain_count;

    if (remain_life > 0) {
        cout << "Yep!" << endl;
    } else {
        cout << "so sorry..." << endl;
    }
    return 0;
}