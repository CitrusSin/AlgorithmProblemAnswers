#include <bits/stdc++.h>

using namespace std;
const int N = 1000;

inline int fast_read() {
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }

    int res = 0;

    while (ch >= '0' && ch <= '9') {
        res *= 10;
        res += ch & 0x0f;
        ch = getchar();
    }

    return res;
}

inline void fast_write(int x) {
    if (x == 0) {
        putchar('0');
        return;
    }
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    char buf[21], *ptr = buf;
    while (x) {
        *ptr++ = (x%10) | 0x30;
        x /= 10;
    }
    while (ptr > buf) {
        putchar(*--ptr);
    }
}

char mat[N][N];
int dst2d[N][N][2], rst[N][N];
int n;

void set_count_mat(const vector< vector<char> >& matrix) {
    n = matrix.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            mat[i][j] = matrix[i][j];
            dst2d[i][j][0] = dst2d[i][j][1] = -1;
            rst[i][j] = -1;
        }
    }
}

int count_block(int x, int y) {
    static const int offset_x[4] = {1, 0, 0, -1}, 
                     offset_y[4] = {0, -1, 1, 0};
    
    if (dst2d[x][y][0] != -1) {
        int res = count_block(dst2d[x][y][0], dst2d[x][y][1]);
        dst2d[x][y][0] = dst2d[x][y][1] = -1;
        rst[x][y] = res;
        return res;
    }

    if (rst[x][y] != -1) {
        return rst[x][y];
    }

    vector< vector<char> > marks(n, vector<char>(n, 0));

    int cnt = 1;
    char status = 0;
    queue< pair<int, int> > bfsq;
    bfsq.emplace(x, y);
    marks[x][y] = 1;

    while (!bfsq.empty()) {
        size_t s = bfsq.size();
        for (size_t k=0; k<s; k++) {
            pair<int, int> pos0 = bfsq.front();
            bfsq.pop();
            char sign = mat[pos0.first][pos0.second];

            for (int i=0; i<4; i++) {
                int x2 = pos0.first + offset_x[i];
                int y2 = pos0.second + offset_y[i];
                if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < n
                    && !marks[x2][y2] && mat[x2][y2] != sign) {
                    bfsq.emplace(x2, y2);
                    dst2d[x2][y2][0] = x;
                    dst2d[x2][y2][1] = y;
                    marks[x2][y2] = 1;
                    cnt++;
                }
            }
        }
    }

    rst[x][y] = cnt;
    return cnt;
}

int main() {
    int n = fast_read(), m = fast_read();

    vector< vector<char> > matrix(n, vector<char>(n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            matrix[i][j] = getchar()=='1';
        }
        while (getchar() != '\n');
    }

    set_count_mat(matrix);

    while (m--) {
        int x = fast_read(), y = fast_read();
        //cout << count_block(x-1, y-1) << endl;
        fast_write(count_block(x-1, y-1));
        putchar('\n');
    }
    return 0;
}