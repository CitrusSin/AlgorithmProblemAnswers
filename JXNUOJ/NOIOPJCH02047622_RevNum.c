#include <stdio.h>

long long rev_num_with_sort(int arr[], int len) {
    if (len <= 1) {
        return 0;
    } else if (len == 2) {
        if (arr[0] > arr[1]) {
            int sw = arr[0];
            arr[0] = arr[1];
            arr[1] = sw;
            return 1;
        } else return 0;
    }

    long long counter = 0;
    int spliter = len / 2;
    counter += rev_num_with_sort(arr, spliter);
    counter += rev_num_with_sort(arr+spliter, len-spliter);

    int temp_arr[len];
    int *ptr_a = arr, *ptr_b = arr+spliter;
    int temp_index = 0;
    while (ptr_b < arr+len && temp_index < len) {
        while (ptr_a < arr+spliter && *ptr_a <= *ptr_b) {
            temp_arr[temp_index] = *ptr_a;
            ptr_a++;
            temp_index++;
        }
        if (temp_index < len) {
            temp_arr[temp_index] = *ptr_b;
            ptr_b++;
            if (ptr_a < arr+spliter) counter += ptr_b-(arr+spliter)+1;
            temp_index++;
        }
    }
    while (ptr_a < arr+spliter) {
        temp_arr[temp_index] = *ptr_a;
        ptr_a++;
        counter += ptr_b-(arr+spliter)+1;
    }
    for (int i=0; i<len; i++) {
        arr[i] = temp_arr[i];
    }
    return counter;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", rev_num_with_sort(arr, n));

    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}