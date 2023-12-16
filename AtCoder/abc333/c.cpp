#include <iostream>
#include <string>

using namespace std;

void step(string& st) {
    if (st.empty()) {
        st = "3";
        return;
    }

    if (st.front() == '3') {
        size_t n = st.size();
        st.clear();
        for (size_t i=0; i<=n; i++) {
            st.push_back('1');
        }
        st.back() = '3';
        return;
    }

    char last = '\0';
    for (auto it = st.rbegin(); it != st.rend(); it++) {
        if (*it < '3') {
            (*it)++;
            for (auto it2 = it; it2 != st.rbegin(); it2--) {
                *it2 = *it;
            } 
            break;
        }
        last = *it;
    }
} 

int main() {
    string s;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        step(s);
    }
    cout << s << endl;
    return 0;
}