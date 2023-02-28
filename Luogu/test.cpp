#include <iostream>
#include <algorithm>

using namespace std;

struct rain_screen {
    int begin;
    int end;
};

int main() {
    int n;
    cin >> n;
    
    rain_screen screens[n];
    for (int i=0; i<n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1>> x2 >> y2;
        
        screens[i].begin = min(x1, x2);
        screens[i].end = max(x1, x2);
    }
    
    sort(screens, screens+n, [](rain_screen &a, rain_screen &b) {return a.begin < b.begin;});
    
    rain_screen merged_screens[n];
    int msl = 0;
    merged_screens[0] = screens[0];
    for (int i=1; i<n; i++) {
        if (screens[i].begin <= merged_screens[msl].end) {
            merged_screens[msl].end = max(merged_screens[msl].end, screens[i].end);
        } else {
            msl++;
            merged_screens[msl] = screens[i];
        }
    }
    msl++;
    
    int total_len = 0;
    for (int i=0; i<msl; i++) {
        total_len += merged_screens[i].end - merged_screens[i].begin;
    }
    
    cout << total_len << endl;
    return 0;
}