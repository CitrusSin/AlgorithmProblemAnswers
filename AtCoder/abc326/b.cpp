#include <algorithm>
#include <iostream>
#include <array>

const std::array<int, 32> nums = {
    100, 111, 122, 133, 144,
    155, 166, 177, 188, 199,
    200, 212, 224, 236, 248,
    300, 313, 326, 339, 400,
    414, 428, 500, 515, 600,
    616, 700, 717, 800, 818,
    900, 919
};

int main() {
    int n;
    std::cin >> n;

    int val = *std::lower_bound(nums.begin(), nums.end(), n);
    std::cout << val << std::endl;
    return 0;
}