#include <iostream>

using namespace std;

int main() {
    unsigned long long timestamp;
    cin >> timestamp;

    timestamp += 28800;

    int secs = timestamp % 86400;
    int hrs = secs / 3600;
    secs = secs % 3600;
    int min = secs / 60;
    secs = secs % 60;

    cout << hrs << ":" << min << ":" << secs << endl;
    return 0;
}