#include <bits/stdc++.h>

using namespace std;

int main() {
	char a[201], b[201];
	cin >> a >> b;

	int a_len = strlen(a), b_len = strlen(b);
	char c[202];
	char *c_ptr = c;

	int max_len = max(a_len, b_len);
	char forward = 0;
	for (int i=0; i<max_len; i++) {
		char result = forward;
		if (i < a_len) {
			result += a[a_len-i-1]&0x0f;
		}
		if (i < b_len) {
			result += b[b_len-i-1]&0x0f;
		}
		forward = result / 10;
		result %= 10;

		*c_ptr = result | 0x30;
		c_ptr++;
	}
	if (forward > 0) {
		*c_ptr = forward | 0x30;
		c_ptr++;
	}
	*c_ptr = '\0';
	int c_len = strlen(c);
	for (int i=0; i<c_len/2; i++) {
		int j = c_len-i-1;

		char swap = c[i];
		c[i] = c[j];
		c[j] = swap;
	}

	c_ptr = c;
	while (*c_ptr == '0') c_ptr++;

	cout << c_ptr << endl;
	return 0;
}