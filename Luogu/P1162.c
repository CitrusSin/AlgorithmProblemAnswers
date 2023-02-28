#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

bool detect_border(
    const int *square, bool *flags, 
    int n, int x, int y
) {
    static const int offset_x[4] = {1, 0, 0, -1};
    static const int offset_y[4] = {0, 1, -1, 0};

    flags[x*n+y] = true;
    bool final_result = true;
    for (int d=0; d<4; d++) {
        int x2 = x+offset_x[d], y2 = y+offset_y[d];
        if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < n) {
            if (!flags[x2*n+y2] && square[x2*n+y2] == 0) {
                final_result = detect_border(square, flags, n, x2, y2);
            }
        } else {
            final_result = false;
        }
    }
    return final_result;
}

int main() {
    int n;
    scanf("%d", &n);

    int *square = (int *)malloc(n*n*sizeof(int));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &square[i*n+j]);
        }
    }

    bool *det_area = (bool *)malloc(n*n*sizeof(bool));
    bool border_result = false;
    for (int i=0; i<n && !border_result; i++) {
        for (int j=0; j<n && !border_result; j++) {
            if (square[i*n+j] == 0) {
                memset(det_area, 0, n*n*sizeof(bool));
                border_result = detect_border(square, det_area, n, i, j);
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (det_area[i*n+j]) {
                square[i*n+j] = 2;
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", square[i*n+j]);
        }
        putchar('\n');
    }

    free(det_area);
    free(square);
    return 0;
}