#include <bits/stdc++.h>

using namespace std;

int quick_pow_last4(int base, int exp) {
    if (exp == 0) {
        return 1;
    } else if (exp == 1) {
        return base;
    }

    long long r = quick_pow_last4(base, exp/2);
    return r*r*((exp%2==1)?base:1) % 10000;
}

int pow_log10_last4(int base, int lgexp) {
    int result = base;
    for (int i=0; i<lgexp; i++) {
        result = quick_pow_last4(result, 10);
    }
    return result;
}

int main() {
    int k;
    cin >> k;

    for (int i=0; i<k; i++) {
        string n;
        cin >> n;

        vector<int> sequence;

        int digit = 0;
        for (auto iter = n.end()-1; iter >= n.begin(); iter--) {
            int seqnum = quick_pow_last4(2011, (*iter)&0x0f);
            seqnum = pow_log10_last4(seqnum, digit);
            sequence.push_back(seqnum);
            digit++;
        }

        int result = 1;
        for (auto iter = sequence.begin(); iter < sequence.end(); iter++) {
            result = (result * (*iter)) % 10000;
        }
        cout << result << endl;
    }
    return 0;
}