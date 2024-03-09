#include <iostream>
#include <vector>

int max_element_index(const std::vector<int>& A) {
    int n = A.size();
    int i, j;
    j = 1;
    for (i = 2; i <= n; i++) {
        if (A[i] > A[j]) {
            j = i;
        }
    }
    return j;
}

int main() {
    int n;
    std::cout << "输入数组长度：";
    std::cin >> n;

    std::cout << "输入数组：";
    std::vector<int> A(n);
    for (int i=0; i<n; i++) {
        std::cin >> A[i];
    }

    std::cout << max_element_index(A) << '\n';
    return 0;
}