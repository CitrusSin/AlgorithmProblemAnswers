#include <iostream>

using namespace std;

int main() {
    int p, e, i, d;
    cin >> p >> e >> i >> d;

    int q=0;
    for (; (q-p)%23!=0; q++);
    for (; (q-e)%28!=0; q+=23);
    for (; (q-i)%33!=0; q+=23*28);

    cout << q-d << endl;
    return 0;
}