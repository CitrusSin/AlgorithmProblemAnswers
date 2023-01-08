#include <bits/stdc++.h>

using namespace std;

class unsigned_decimal_int {
public:
	unsigned_decimal_int();
	unsigned_decimal_int(unsigned long long n);
	unsigned_decimal_int(const std::string& s);

	void set(unsigned long long n);
	void set(const std::string& s);

	void inc(const unsigned_decimal_int& x);
	void dec(const unsigned_decimal_int& x);

	void mul(const unsigned_decimal_int& x);
	void div(const unsigned_decimal_int& x);
	void remainder(const unsigned_decimal_int& x);
	void remainder(const unsigned_decimal_int& x, unsigned_decimal_int& div);

	std::string to_string() const;

	unsigned_decimal_int& operator+=(const unsigned_decimal_int& x);
	unsigned_decimal_int operator+(const unsigned_decimal_int& x) const;
	unsigned_decimal_int& operator-=(const unsigned_decimal_int& x);
	unsigned_decimal_int operator-(const unsigned_decimal_int& x) const;
	unsigned_decimal_int& operator*=(const unsigned_decimal_int& x);
	unsigned_decimal_int operator*(const unsigned_decimal_int& x) const;
	unsigned_decimal_int& operator/=(const unsigned_decimal_int& x);
	unsigned_decimal_int operator/(const unsigned_decimal_int& x) const;
	unsigned_decimal_int& operator%=(const unsigned_decimal_int& x);
	unsigned_decimal_int operator%(const unsigned_decimal_int& x) const;
	unsigned_decimal_int operator++(int);
	unsigned_decimal_int& operator++();
	unsigned_decimal_int operator--(int);
	unsigned_decimal_int& operator--();

	bool operator<(const unsigned_decimal_int& x) const;
	bool operator<=(const unsigned_decimal_int& x) const;
	bool operator>(const unsigned_decimal_int& x) const;
	bool operator>=(const unsigned_decimal_int& x) const;
	bool operator==(const unsigned_decimal_int& x) const;

	static int compare(const unsigned_decimal_int& a, const unsigned_decimal_int& b);

	void check_zero();
private:
	std::vector<unsigned char> nums;
};

class decimal_int {
public:
	decimal_int();
	decimal_int(long long n);
	decimal_int(const std::string& s);
	decimal_int(const unsigned_decimal_int& dec);

	void set(long long n);
	void set(const std::string& s);
	void set(const unsigned_decimal_int& dec);

	void add(const decimal_int& x);
	void sub(const decimal_int& x);
	void sub(decimal_int&& x);

	void mul(const decimal_int& x);
	void div(const decimal_int& x);
	void remainder(const decimal_int& x);
	void remainder(const decimal_int& x, decimal_int& div);

	std::string to_string() const;

	decimal_int& operator+=(const decimal_int& x);
	decimal_int operator+(const decimal_int& x) const;
	decimal_int& operator-=(const decimal_int& x);
	decimal_int& operator-=(decimal_int&& x);
	decimal_int operator-(const decimal_int& x) const;
	decimal_int operator-(decimal_int&& x);
	decimal_int& operator*=(const decimal_int& x);
	decimal_int operator*(const decimal_int& x) const;
	decimal_int& operator/=(const decimal_int& x);
	decimal_int operator/(const decimal_int& x) const;
	decimal_int& operator%=(const decimal_int& x);
	decimal_int operator%(const decimal_int& x) const;
	decimal_int operator++(int);
	decimal_int& operator++();
	decimal_int operator--(int);
	decimal_int& operator--();

	bool operator<(const decimal_int& x) const;
	bool operator<=(const decimal_int& x) const;
	bool operator>(const decimal_int& x) const;
	bool operator>=(const decimal_int& x) const;
	bool operator==(const decimal_int& x) const;

	static int compare(const decimal_int& a, const decimal_int& b);
	void check_zero();
private:
	bool negative_sign;
	unsigned_decimal_int abs_value;
};

unsigned_decimal_int::unsigned_decimal_int() {
	set(0);
}

unsigned_decimal_int::unsigned_decimal_int(unsigned long long n) {
	set(n);
}

unsigned_decimal_int::unsigned_decimal_int(const std::string& s) {
	set(s);
}

void unsigned_decimal_int::set(unsigned long long n) {
	if (n == 0) {
		nums.resize(0);
	} else {
		char str[21];
		sprintf(str, "%llu", n);
		set(str);
	}
}

void unsigned_decimal_int::set(const std::string& s) {
	nums.resize(s.length());
	int i = 0;
	for (auto iter = s.end() - 1; iter >= s.begin();) {
		nums[i] = (*iter) & 0x0f;
		++i;
		if (iter > s.begin()) {
			--iter;
		} else break;
	}
	check_zero();
}

void unsigned_decimal_int::inc(const unsigned_decimal_int& x) {
	size_t result_size = max(x.nums.size(), nums.size());
	nums.resize(result_size);

	char forward = 0;
	for (int i = 0; i < result_size; i++) {
		char digit_result = forward;
		if (i < x.nums.size()) digit_result += x.nums[i];
		if (i < nums.size()) digit_result += nums[i];
		nums[i] = digit_result % 10;
		forward = digit_result / 10;
	}
	if (forward > 0) {
		nums.push_back(forward);
	}
}

void unsigned_decimal_int::dec(const unsigned_decimal_int& x) {
	int cmp = compare(*this, x);
	if (cmp <= 0) {
		nums.resize(0);
		return;
	}
	char borrow = 0;
	for (int i = 0; i < nums.size(); i++) {
		char a = nums[i], b = (i < x.nums.size())?x.nums[i]:0;
		char digit_result = a - b - borrow;
		borrow = 0;
		while (digit_result < 0) {
			digit_result += 10;
			borrow++;
		}
		nums[i] = digit_result;
	}
	// Delete 0 in high digits
	int t = nums.size() - 1;
	for (; t >= 0; t--) {
		if (nums[t] != 0) {
			break;
		}
	}
	nums.resize(t + 1);
}

void unsigned_decimal_int::mul(const unsigned_decimal_int& x) {
	/*
	unsigned_decimal_int inc_tmp = *this;
	set(0);
	for (int dshift = 0; dshift < x.nums.size(); dshift++) {
		char d = x.nums[dshift];
		for (; d > 0; d--) {
			inc(inc_tmp);
		}
		inc_tmp.nums.insert(inc_tmp.nums.begin(), 0);
	}
	*/
	size_t n = x.nums.size();
	size_t m = nums.size();
	vector<unsigned char> r_nums = nums;
	set(0);
	for (size_t i = 0; i < n; i++) {
		if (x.nums[i] != 0) {
			unsigned_decimal_int adder;
			adder.nums.resize(i + m, 0);
			unsigned char forward = 0;
			for (size_t j = 0; j < m; j++) {
				unsigned char digit_result = r_nums[j] * x.nums[i] + forward;
				forward = digit_result / 10;
				adder.nums[i + j] = digit_result % 10;
			}
			if (forward > 0) {
				adder.nums.push_back(forward % 10);
			}

			inc(adder);
		}
	}
}

void unsigned_decimal_int::div(const unsigned_decimal_int& x) {
	unsigned_decimal_int p = *this;
	p.remainder(x, *this);
}

void unsigned_decimal_int::remainder(const unsigned_decimal_int& x) {
	unsigned_decimal_int p;
	remainder(x, p);
}

void unsigned_decimal_int::remainder(const unsigned_decimal_int& x, unsigned_decimal_int& div) {
	div = 0;
	while (*this >= x) {
		dec(x);
		div.inc(1);
	}
}

string unsigned_decimal_int::to_string() const {
	string s;
	for (auto iter = nums.end() - 1; iter >= nums.begin();) {
		s.push_back((*iter) | 0x30);
		if (iter > nums.begin()) {
			--iter;
		} else break;
	}
	if (nums.size() == 0) s.push_back('0');
	return s;
}

unsigned_decimal_int& unsigned_decimal_int::operator+=(const unsigned_decimal_int& x) {
	inc(x);
	return *this;
}

unsigned_decimal_int unsigned_decimal_int::operator+(const unsigned_decimal_int& x) const
{
	unsigned_decimal_int result = *this;
	result.inc(x);
	return result;
}

unsigned_decimal_int& unsigned_decimal_int::operator-=(const unsigned_decimal_int& x)
{
	dec(x);
	return *this;
}

unsigned_decimal_int unsigned_decimal_int::operator-(const unsigned_decimal_int& x) const
{
	unsigned_decimal_int result = *this;
	result.dec(x);
	return result;
}

unsigned_decimal_int& unsigned_decimal_int::operator*=(const unsigned_decimal_int& x) {
	mul(x);
	return *this;
}

unsigned_decimal_int unsigned_decimal_int::operator*(const unsigned_decimal_int& x) const {
	unsigned_decimal_int a = *this, b = x;
	unsigned_decimal_int &a2 = (a > b) ? a : b, &b2 = (a > b) ? b : a;
	a2.mul(b2);
	return a2;
}

unsigned_decimal_int& unsigned_decimal_int::operator/=(const unsigned_decimal_int& x) {
	div(x);
	return *this;
}

unsigned_decimal_int unsigned_decimal_int::operator/(const unsigned_decimal_int& x) const {
	unsigned_decimal_int p = *this;
	p.div(x);
	return p;
}

unsigned_decimal_int& unsigned_decimal_int::operator%=(const unsigned_decimal_int& x) {
	remainder(x);
	return *this;
}

unsigned_decimal_int unsigned_decimal_int::operator%(const unsigned_decimal_int& x) const {
	unsigned_decimal_int p = *this;
	p.remainder(x);
	return x;
}

unsigned_decimal_int unsigned_decimal_int::operator++(int) {
	unsigned_decimal_int old_val = *this;
	inc(1);
	return old_val;
}

unsigned_decimal_int& unsigned_decimal_int::operator++() {
	inc(1);
	return *this;
}

unsigned_decimal_int unsigned_decimal_int::operator--(int) {
	unsigned_decimal_int old_val = *this;
	dec(1);
	return old_val;
}

unsigned_decimal_int& unsigned_decimal_int::operator--() {
	dec(1);
	return *this;
}

bool unsigned_decimal_int::operator<(const unsigned_decimal_int& x) const {
	return compare(*this, x) < 0;
}

bool unsigned_decimal_int::operator<=(const unsigned_decimal_int& x) const {
	return compare(*this, x) <= 0;
}

bool unsigned_decimal_int::operator>(const unsigned_decimal_int& x) const {
	return compare(*this, x) > 0;
}

bool unsigned_decimal_int::operator>=(const unsigned_decimal_int& x) const {
	return compare(*this, x) >= 0;
}

bool unsigned_decimal_int::operator==(const unsigned_decimal_int& x) const {
	return compare(*this, x) == 0;
}

int unsigned_decimal_int::compare(const unsigned_decimal_int& a, const unsigned_decimal_int& b) {
	if (a.nums.size() > b.nums.size()) {
		return 1;
	} else if (a.nums.size() < b.nums.size()) {
		return -1;
	} else {
		size_t size = a.nums.size(); // a.nums.size() == b.nums.size()
		for (int i = size - 1; i >= 0; i--) {
			if (a.nums[i] > b.nums[i]) {
				return 1;
			} else if (a.nums[i] < b.nums[i]) {
				return -1;
			}
		}
		return 0;
	}
	return 0;
}

void unsigned_decimal_int::check_zero() {
	bool is_zero = true;
	for (auto iter = nums.end() - 1; iter >= nums.begin(); iter--) {
		if (*iter != '0') {
			is_zero = false;
			break;
		}
	}

	if (is_zero) {
		nums.resize(0);
	}

	size_t s = nums.size(), s2 = s;
	for (long long i=s-1; i>=0; i--) {
		if (nums[i] == 0) {
			s2 = i;
		}
	}
	if (s2 != s) nums.resize(s2);
}

decimal_int::decimal_int() {
	set(0);
}

decimal_int::decimal_int(long long n) {
	set(n);
}

decimal_int::decimal_int(const std::string& s) {
	set(s);
}

decimal_int::decimal_int(const unsigned_decimal_int& dec) {
	set(dec);
}

void decimal_int::set(long long n) {
	if (n < 0) {
		negative_sign = true;
		abs_value.set(-n);
	} else {
		negative_sign = false;
		abs_value.set(n);
	}
}

void decimal_int::set(const string& s) {
	if (s.size() > 0 && s[0] == '-') {
		negative_sign = true;
		abs_value.set(s.substr(1));
	} else {
		negative_sign = false;
		abs_value.set(s);
	}
}

void decimal_int::set(const unsigned_decimal_int& dec) {
	negative_sign = false;
	abs_value = dec;
}

void decimal_int::add(const decimal_int& x) {
	if (negative_sign) {
		if (x.negative_sign) {
			abs_value.inc(x.abs_value);
		} else {
			const unsigned_decimal_int &a = x.abs_value, &b = abs_value;
			const unsigned_decimal_int &a2 = max(a, b), &b2 = min(a, b);
			abs_value = a2 - b2;
			negative_sign = a < b;
		}
	} else {
		if (x.negative_sign) {
			const unsigned_decimal_int &a = abs_value, &b = x.abs_value;
			const unsigned_decimal_int &a2 = max(a, b), &b2 = min(a, b);
			abs_value = a2 - b2;
			negative_sign = a < b;
		} else {
			abs_value.inc(x.abs_value);
		}
	}
}

void decimal_int::sub(const decimal_int& x) {
	decimal_int tmp = x;
	tmp.negative_sign = !tmp.negative_sign;
	add(tmp);
}

void decimal_int::sub(decimal_int&& x) {
	x.negative_sign = !x.negative_sign;
	add(x);
}

void decimal_int::mul(const decimal_int& x) {
	abs_value.mul(x.abs_value);
	negative_sign = negative_sign ^ x.negative_sign;
}

void decimal_int::div(const decimal_int& x) {
	decimal_int result;
	remainder(x, result);
	*this = result;
}

void decimal_int::remainder(const decimal_int& x) {
	decimal_int p;
	remainder(x, p);
}

void decimal_int::remainder(const decimal_int& x, decimal_int& div) {
	abs_value.remainder(x.abs_value, div.abs_value);
	div.negative_sign = negative_sign ^ x.negative_sign;
}

string decimal_int::to_string() const {
	string s = abs_value.to_string();
	if (negative_sign) {
		return "-" + s;
	} else {
		return s;
	}
}

decimal_int& decimal_int::operator+=(const decimal_int& x) {
	add(x);
	return *this;
}

decimal_int decimal_int::operator+(const decimal_int& x) const {
	decimal_int result = *this;
	result.add(x);
	return result;
}

decimal_int& decimal_int::operator-=(const decimal_int& x) {
	sub(x);
	return *this;
}

decimal_int& decimal_int::operator-=(decimal_int&& x) {
	sub(x);
	return *this;
}

decimal_int decimal_int::operator-(const decimal_int& x) const {
	decimal_int result = *this;
	result.sub(x);
	return result;
}

decimal_int decimal_int::operator-(decimal_int&& x)
{
	decimal_int result = *this;
	x.negative_sign = !x.negative_sign;
	result.add(x);
	return result;
}

decimal_int& decimal_int::operator*=(const decimal_int& x) {
	mul(x);
	return *this;
}

decimal_int decimal_int::operator*(const decimal_int& x) const {
	decimal_int result = *this;
	result.mul(x);
	return result;
}

decimal_int& decimal_int::operator/=(const decimal_int& x) {
	div(x);
	return *this;
}

decimal_int decimal_int::operator/(const decimal_int& x) const {
	decimal_int result = *this;
	result.div(x);
	return result;
}

decimal_int& decimal_int::operator%=(const decimal_int& x) {
	remainder(x);
	return *this;
}

decimal_int decimal_int::operator%(const decimal_int& x) const {
	decimal_int result = *this;
	result.remainder(x);
	return result;
}

decimal_int decimal_int::operator++(int) {
	decimal_int old_val = *this;
	add(1);
	return old_val;
}

decimal_int& decimal_int::operator++() {
	add(1);
	return *this;
}

decimal_int decimal_int::operator--(int) {
	decimal_int old_val = *this;
	sub(1);
	return old_val;
}

decimal_int& decimal_int::operator--() {
	sub(1);
	return *this;
}

bool decimal_int::operator<(const decimal_int& x) const {
	return compare(*this, x) < 0;
}

bool decimal_int::operator<=(const decimal_int& x) const {
	return compare(*this, x) <= 0;
}

bool decimal_int::operator>(const decimal_int& x) const {
	return compare(*this, x) > 0;
}

bool decimal_int::operator>=(const decimal_int& x) const {
	return compare(*this, x) >= 0;
}

bool decimal_int::operator==(const decimal_int& x) const {
	return compare(*this, x) == 0;
}

int decimal_int::compare(const decimal_int& a, const decimal_int& b) {
	if (a.negative_sign == true && b.negative_sign == false) {
		return -1;
	} else if (a.negative_sign == false && b.negative_sign == true) {
		return 1;
	} else if (a.negative_sign == true && b.negative_sign == true) {
		return -unsigned_decimal_int::compare(a.abs_value, b.abs_value);
	} else {
		return unsigned_decimal_int::compare(a.abs_value, b.abs_value);
	}
}

void decimal_int::check_zero() {
	abs_value.check_zero();
	if (abs_value == 0) {
		negative_sign = false;
	}
}


int main() {
    string a, b;
    cin >> a >> b;

    unsigned_decimal_int c(a), d(b);
    cout << (c+d).to_string() << endl;

    return 0;
}