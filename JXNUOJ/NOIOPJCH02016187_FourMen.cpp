#include <iostream>

using namespace std;

void binded_sort(int *arr_std, char* arr2, int n) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr_std[i] > arr_std[j]) {
                arr_std[i] ^= arr_std[j];
                arr_std[j] ^= arr_std[i];
                arr_std[i] ^= arr_std[j];

                arr2[i] ^= arr2[j];
                arr2[j] ^= arr2[i];
                arr2[i] ^= arr2[j];
            }
        }
    }
}

int main() {
    int arr[4];
    char surnames[4] = {'z', 'q', 's', 'l'};
    for (int z=1; z<=5; z++) {
        for (int q=1; q<=5; q++) {
            for (int s=1; s<=5; s++) {
                for (int l=1; l<=5; l++) {
                    if (z+q==s+l && z+l>s+q && z+s<q) {
                        arr[0] = z;
                        arr[1] = q;
                        arr[2] = s;
                        arr[3] = l;
                        break;
                    }
                }
            }
        }
    }
    binded_sort(arr, surnames, 4);

    for (int i=0; i<4; i++) {
        printf("%c %d\n", surnames[i], arr[i]*10);
    }
    return 0;
}