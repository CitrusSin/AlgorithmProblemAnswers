#include <iostream>
#include <chrono>
#include <unordered_set>
#include <vector>

template <typename T>
T mex(const std::unordered_set<T>& a) {
    for (T v = 0; v < a.size(); v++) {
        if (!a.count(v)) {
            return v;
        }
    }
    return a.size();
}

int64_t calculate_count = 0;
int sg(int a, int b) {
    static std::vector<std::vector<int>> mp;
    if (a < b+1) {
        return 0;
    }
    if (a >= b+1 && a < 2*b+1) {
        return 1;
    }
    if (mp.size() > a && mp[a].size() > b && mp[a][b] >= 0) {
        return mp[a][b];
    }
    if (mp.size() <= a) {
        mp.resize(a+1);
    }
    std::unordered_set<int> st;
    for (int k=b+1; k<2*b; k++) {
        st.insert(sg(a-k, k));
    }
    int ans = mex(st);
    if (mp[a].size() <= b) {
        mp[a].resize(b+1, -1);
    }
    calculate_count++;
    mp[a][b] = ans;
    return ans;
}

int main() {
    int a, b;

    std::cout << "Input a, b: ";
    std::cin >> a >> b;

    auto tp1 = std::chrono::system_clock::now();
    int ans = sg(a, b);
    auto tp2 = std::chrono::system_clock::now();
    auto duration = tp2 - tp1;
    uint64_t millisecs = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

    std::cout << "sg(" << a << ", " << b << ") = " << ans << std::endl;
    std::cout << "Calculate count: " << calculate_count << std::endl;
    std::cout << "Time used: " << millisecs << "ms" << std::endl;

    return 0;
}