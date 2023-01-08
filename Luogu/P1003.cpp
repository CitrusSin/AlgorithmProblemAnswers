#include <iostream>
#include <vector>

using namespace std;

struct carpet {
    int a, b, g, k;
};

int main() {
    int n;
    cin >> n;

    vector<carpet> carpets(n);
    for (int i=0; i<n; i++) {
        carpet &c = carpets[i];
        cin >> c.a >> c.b >> c.g >> c.k;
    }

    int x, y;
    cin >> x >> y;

    int carpet_index = -1;
    for (int i=0; i<n; i++) {
        carpet &c = carpets[i];
        if (c.a<=x&&c.b<=y&&(c.a+c.g)>=x&&(c.b+c.k)>=y) {
            carpet_index = i+1;
        }
    }

    cout << carpet_index << endl;
    return 0;
}