#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, e, f, g, h, i;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
    int moves[9] = {0};

    for (moves[0]=0; moves[0]<4; moves[0]++) {
        for (moves[1]=0; moves[1]<4; moves[1]++) {
            for (moves[2]=0; moves[2]<4; moves[2]++) {
                for (moves[3]=0; moves[3]<4; moves[3]++) {
                    for (moves[4]=0; moves[4]<4; moves[4]++) {
                        for (moves[5]=0; moves[5]<4; moves[5]++) {
                            for (moves[6]=0; moves[6]<4; moves[6]++) {
                                for (moves[7]=0; moves[7]<4; moves[7]++) {
                                    for (moves[8]=0; moves[8]<4; moves[8]++) {
                                        int a2 = (a+moves[0]+moves[1]+moves[3]) % 4;
                                        int b2 = (b+moves[0]+moves[1]+moves[2]+moves[4]) % 4;
                                        int c2 = (c+moves[1]+moves[2]+moves[5]) % 4;
                                        int d2 = (d+moves[0]+moves[3]+moves[4]+moves[6]) % 4;
                                        int e2 = (e+moves[0]+moves[2]+moves[4]+moves[6]+moves[8]) % 4;
                                        int f2 = (f+moves[2]+moves[4]+moves[5]+moves[8]) % 4;
                                        int g2 = (g+moves[3]+moves[6]+moves[7]) % 4;
                                        int h2 = (h+moves[4]+moves[6]+moves[7]+moves[8]) % 4;
                                        int i2 = (i+moves[5]+moves[7]+moves[8]) % 4;

                                        if ((a2|b2|c2|d2|e2|f2|g2|h2|i2) == 0) {
                                            bool has_output = false;
                                            for (int i=0; i<9; i++) {
                                                if (moves[i] != 0) {
                                                    for (int j=0; j<moves[i]; j++) {
                                                        if (!has_output) {
                                                            has_output = true;
                                                        } else {
                                                            cout << " ";
                                                        }
                                                        cout << i+1;
                                                    }
                                                }
                                            }
                                            cout << endl;
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }       
                    }
                }
            }       
        }
    }
    return 0;
}