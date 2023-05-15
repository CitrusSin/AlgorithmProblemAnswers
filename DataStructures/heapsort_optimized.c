#include <stdio.h>
#include <stdlib.h>

#define SWAP_VAR(type, a, b) {type sw = (a); (a) = (b); (b) = sw;}

void heap_sort(int* arr, int n) {
    // Build heap
    int heap_len = 0;
    while (heap_len < n) {
        int node = heap_len;
        heap_len++;
        while (node >= 1 && arr[(node+1)/2-1]<arr[node]) {
            SWAP_VAR(int, arr[(node+1)/2-1], arr[node]);
            node = (node+1)/2-1;
        }
    }
    // Pop heap
    while (heap_len > 1) {
        heap_len--;
        SWAP_VAR(int, arr[0], arr[heap_len]);
        int node = 0;
        while ((node+1)*2-1 < heap_len) {
            int lchild = (node+1)*2-1;
            int rchild = lchild+1;
            int rflag = rchild < heap_len;
            if (arr[lchild] < arr[node] && (!rflag || rflag && arr[rchild] < arr[node])) {
                break;
            }

            int exch = (rflag && arr[rchild] > arr[lchild]) ? rchild : lchild;
            SWAP_VAR(int, arr[node], arr[exch]);
            node = exch;
        }
    }
}

int main() {
    int data[256];
    int n;

    printf("Input n: ");
    scanf("%d", &n);

    printf("Input data: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &data[i]);
    }

    heap_sort(data, n);

    printf("After sorting: ");
    for (int i=0; i<n; i++) {
        printf("%4d\t", data[i]);
    }
    putchar('\n');
    return 0;
}
