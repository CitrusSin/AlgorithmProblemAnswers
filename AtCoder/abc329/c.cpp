#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

int main() {
    std::map<char, size_t> max_continuous_length;
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;
    
    std::vector<size_t> fallback(n);
    fallback[0] = 0;
    for (size_t i=1; i<s.size(); i++) {
        if (s[i] == s[i-1]) {
            fallback[i] = fallback[i-1];
        } else {
            fallback[i] = i;
        }
    }

    for (size_t i=0; i<s.size(); i++) {
        size_t l = i - fallback[i] + 1;
        max_continuous_length[s[i]] = std::max(max_continuous_length[s[i]], l);
    }

    size_t ans = 0;
    for (const std::pair<char, size_t>& p : max_continuous_length) {
        ans += p.second;
    }
    std::cout << ans << std::endl;
    return 0;
}