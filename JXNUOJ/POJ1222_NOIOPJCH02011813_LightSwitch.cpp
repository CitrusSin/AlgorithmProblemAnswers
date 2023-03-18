#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <memory.h>

using namespace std;

int convert_to_num(int *nums, int n) {
    int num = 0;
    for (int i=0; i<n; i++) {
        num = (num << 1) + (nums[i]?1:0);
    }
    return num;
}

string convert_to_str(int num) {
    string s;
    for (int i=0; i<6; i++) {
        s.insert(s.begin(), (char)((num&1)+'0'));
        num >>= 1;
        if (i != 5) {
            s.insert(s.begin(), ' ');
        }
    }
    return s;
}

vector<int> solve(int *matrix, int n, int s) {
    vector<int> resolution;
    int operation = s;
    for (int i=0; i<n; i++) {
        if (i+1<n) {
            matrix[i+1] ^= operation;
        }
        int rp_operation = 0;
        for (int bitr=0; bitr<6; bitr++) {
            int b = (operation >> bitr) & 1;
            if (b) {
                if (bitr == 0) {
                    rp_operation ^= 3;
                } else {
                    rp_operation ^= (7 << (bitr - 1)) & 63;
                }
            }
        }
        matrix[i] ^= rp_operation;
        if (i-1>0) {
            matrix[i-1] ^= operation;
        }

        resolution.push_back(operation);
        operation = matrix[i];
    }
    return resolution;
}

bool try_solve(const int *mat, int n, int s) {
    int matrix[n];
    memcpy(matrix, mat, n*sizeof(int));
    int operation = s;
    for (int i=0; i<n; i++) {
        if (i+1<n) {
            matrix[i+1] ^= operation;
        }
        int rp_operation = 0;
        for (int bitr=0; bitr<6; bitr++) {
            int b = (operation >> bitr) & 1;
            if (b) {
                if (bitr == 0) {
                    rp_operation ^= 3;
                } else {
                    rp_operation ^= (7 << (bitr - 1)) & 63;
                }
            }
        }
        matrix[i] ^= rp_operation;
        if (i-1>0) {
            matrix[i-1] ^= operation;
        }

        operation = matrix[i];
    }
    return matrix[n-1] == 0;
}

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int matrix[5];
        for (int j=0; j<5; j++) {
            int nums[6];
            for (int k=0; k<6; k++) {
                cin >> nums[k];
            }
            matrix[j] = convert_to_num(nums, 6);
        }
        for (int fls = 0; fls <= 63; fls++) {
            if (try_solve(matrix, 5, fls)) {
                vector<int> s = solve(matrix, 5, fls);
                cout << "PUZZLE #" << i+1 << endl;
                for (vector<int>::iterator iter = s.begin(); iter < s.end(); iter++) {
                    string str = convert_to_str(*iter);
                    cout << str << endl;
                }
                break;
            }
        }
    }
    return 0;
}