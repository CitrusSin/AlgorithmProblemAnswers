#include <iostream>
#include <vector>

using namespace std;

vector<int> fibo_data = {1, 1};

int fibo(int x) {
    if (fibo_data.size() <= x-1) {
        int result = (fibo(x-2) + fibo(x-1)) % 1000;
        fibo_data.push_back(result);
        return result;
    } else {
        return fibo_data[x-1];
    }
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int count;
        cin >> count;
        cout << fibo(count) << endl;
    }
    return 0;
}