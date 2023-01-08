#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;
    for (int i=0; i<n; i++) {
        int fp;
        cin >> fp;
        sum = (sum + fp) % 7;
    }

    const char *chs[] = {"QSGC", "TWG", "LY", "WD", "TLW", "TH", "MSD"};
    cout << chs[sum-1] << endl;
    
    return 0;
}