#include <iostream>
#include <array>
#include <set>

bool check(const std::array<std::array<int, 9>, 9>& arr) {
    for (int i=0; i<9; i++) {
        std::set<int> row, col;
        for (int j=0; j<9; j++) {
            row.insert(arr[i][j]);
            col.insert(arr[j][i]);
        }
        if (row.size() != 9 || col.size() != 9) {
            return false;
        }
    }    
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            std::set<int> block;
            for (int k=0; k<3; k++) {
                for (int l=0; l<3; l++) {
                    int x = i*3+k, y = j*3+l;
                    block.insert(arr[x][y]);
                }
            }
            if (block.size() != 9) return false;
        }
    }
    return true;
}

int main() {
    std::array<std::array<int, 9>, 9> arr;
    for (int i=0; i<9; i++) for (int j=0; j<9; j++) std::cin >> arr[i][j];
    std::cout << (check(arr)?"Yes":"No") << std::endl;
    return 0;
}