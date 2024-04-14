#include <array>
#include <iostream>
#include <numeric>
#include <vector>
#include <cstdint>

using namespace std;

void pillow_state_output(const array<vector<int>, 3>& pillows) {
    for (int i=0; i<3; i++) {
        cout << "Pillow " << i << ":";
        for (int val : pillows[i]) {
            cout << ' ' << val;
        }
        cout << '\n';
    }
}

void hanoi_operate(int n, int pillow_base, int pillow_destination, int pillow_buffer, int64_t& step_counter, array<vector<int>, 3>& pillows) {
    if (n == 0) {
        return;
    }

    hanoi_operate(n-1, pillow_base, pillow_buffer, pillow_destination, step_counter, pillows);
    cout << "Step " << step_counter << ": " << pillow_base << "->" << pillow_destination << '\n';
    pillows[pillow_destination].push_back(pillows[pillow_base].back());
    pillows[pillow_base].pop_back();
    step_counter++;

    pillow_state_output(pillows);
    cout << '\n';

    hanoi_operate(n-1, pillow_buffer, pillow_destination, pillow_base, step_counter, pillows);
}

int main() {
    array<vector<int>, 3> pillows;
    
    cout << "Input n: ";
    int n;
    cin >> n;
    cout << '\n';

    pillows[0].assign(n, 0);
    iota(pillows[0].rbegin(), pillows[0].rend(), 1);

    cout << "Initial: \n";
    pillow_state_output(pillows);
    cout << '\n';

    int64_t step_counter = 1;
    hanoi_operate(n, 0, 2, 1, step_counter, pillows);

    return 0;
}

