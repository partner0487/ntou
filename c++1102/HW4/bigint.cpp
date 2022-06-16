/*
Author: Xiaoyo
num: 01057020
time: 2022 / 06 / 16
//*/
#include "iostream"
#include "bigint.h"
#include "malloc.h"
#include "string.h"
#include "algorithm"
#include "math.h"
#include <fstream>
using namespace std;

int bigint::total = 0;
bigint::bigint() {
	cap = 100;
	digit = new char[cap + 10];
	zero();
	total++;
}
bigint::bigint(int v, int size = 100) {
	digit = 0; cap = numdigit = 0;

	int temp = v, sz = 0;
	while (temp) {
		temp /= 10;
		sz++;
	}
	if (sz > size) size = sz;
	cap = 100;
	digit = new char[cap + 10];
	zero();

	v < 0 ? sign = -1, v = -v : sign = 1;

	numdigit = sz; int n = 0;
	while (v) {
		digit[n] = v % 10 + 48;
		v /= 10; n++;
	}
	total++;
}
bigint::bigint(const char* const s, int size = 100) {
	digit = 0; cap = numdigit = 0;

	int sz = strlen(s), i;
	sz = s[0] == '-' ? sz - 1 : sz;
	sz = s[0] == '+' ? sz - 1 : sz;
	if (sz > size) size = sz;
	cap = 100;
	digit = new char[cap + 10];
	zero();

	if (s[0] == '+' || s[0] == '-')
		i = 1, sign = (s[0] == '+' ? 1 : -1);
	else i = 0;

	numdigit = sz;
	for (int k = sz - 1; i <= sz; i++, k--) {
		if (s[i] < '0' || s[i] > '9') continue;
		digit[k] = s[i];
	}
	total++;
}
bigint::bigint(bigint& x) {
	cap = 100; numdigit = x.numdigit; sign = x.sign;
	digit = new char[cap];
	for (int i = 0; i < cap; i++) digit[i] = x.digit[i];
	total++;
}
bigint::~bigint() {
	if (cap) {
		if (cap == 1) delete digit;
		else         delete[] digit;
	}
	total--;
}
bigint::bigint(char* n, int x, int y, int z) {
	numdigit = x, cap = y, sign = z;
	digit = new char[cap];
	for (int i = 0; i < cap; i++) digit[i] = n[i];
	total++;
}

bool check(char digit[], int numdigit, char num[], int n){
	if(numdigit < n) return 0;
	else if(numdigit == n){
		for(int i = numdigit - 1; i >= 0; i--){
			if(digit[i] < num[i]) return 0;
			else if(digit[i] == num[i]) continue;
			else return 1;
		}
	}
	return 1;
}

void add(char digit[], int &numdigit, int &cap, char num[], int &n){
    int *ans;
    ans = new int[max(numdigit, n) + 10];
    for(int i = 0; i < max(numdigit, n) + 10; i++) ans[i] = 0;
    
    int carry = 0, i = 0;
	for (; i < numdigit && i < n; ++i) {
		ans[i] = (digit[i] + num[i] + carry) - 96;
		ans[i] / 10 ? ans[i] %= 10, carry = 1 : carry = 0;
	}
	while (i < numdigit) {
		ans[i] = (digit[i] + carry) - 48;
		ans[i] / 10 ? ans[i] %= 10, carry = 1 : carry = 0;
		++i;
	}
	while (i < n) {
		ans[i] = (num[i] + carry) - 48;
		ans[i] / 10 ? ans[i] %= 10, carry = 1 : carry = 0;
		++i;
	}
	if (carry) ans[i++] += 1;
	numdigit = i;
	cap = numdigit + 10;
	for (int j = 0; j < i; j++) digit[j] = ans[j] + 48;
    delete[] ans;
}
void sub(char digit[], int &numdigit, int &cap, char num[], int &n){
    int *ans;
    ans = new int[max(numdigit, n)];

	int i = 0, borrow = 0;
	for (; i < min(numdigit, n); i++) {
		ans[i] = digit[i] - num[i] - borrow;
		ans[i] < 0 ? ans[i] += 10, borrow = 1 : borrow = 0;
	}
	while (borrow) {
		ans[i] = digit[i] - borrow - 48;
		ans[i] < 0 ? ans[i] += 10, borrow = 1 : borrow = 0;
		i++;
	}
	while (i < max(numdigit, n)) {
		ans[i] = digit[i] - '0';
		i++;
	}
	numdigit = i;
	while(ans[numdigit - 1] == 0) numdigit--;
	for (int j = 0; j < i; j++)  digit[j] = ans[j] + 48;
	
    delete[] ans;
}
void mul(char digit[], int &numdigit, int &cap, int &sign1, char num[], int &n, int &sign2){
	sign1 *= sign2;
	int *ans;
	ans = new int[numdigit + n];
	for(int i = 0; i < numdigit + n; i++) ans[i] = 0;

	for(int i = 0; i < numdigit; i++){
		for(int j = 0; j < n; j++){
			ans[i + j] += (digit[i] - 48) * (num[j] - 48);
			if(ans[i + j] >= 10){
				ans[i + j + 1] += ans[i + j] / 10;
				ans[i + j] %= 10;
			}
		}
	}
	for(int i = 0; i < numdigit + n; i++)
		digit[i] = ans[i] + 48;
	numdigit += n;
}
bigint divide(char digit[], int &numdigit, int &cap, int &sign1, char num[], int &n, int &sign2){
	sign1 *= sign2;
	bigint ret(0);
	char now[numdigit];
	memset(now, '0', sizeof(now));
	// for(int i = numdigit - 1, j = n - 1; i >= 0, j >= 0; i--, j--) now[i] = num[j];
	int nowd = numdigit;
	
	char *mk;
	mk = new char[numdigit]; 
	for(int i = 0; i < numdigit; i++) mk[i] = '0';
	mk[numdigit - n] = '1';
	bigint nd(mk, numdigit - n + 1, numdigit, 1);
	//*
	bigint d(num, n, cap, sign2);
	bigint c = (nd * d);
	/*
	if(check(c.digit, c.numdigit, digit, numdigit)){
		mk[numdigit - n - 1] = '1';
		nd = bigint(mk, numdigit - n, numdigit, 1);
		nowd--;
		for(int i = 0; i < nowd; i++) now[i] = now[i + 1];
	}//*/
	for(int i = 0; i < c.numdigit; i++) now[i] = c.digit[i];
	nowd = c.numdigit;

	while(numdigit > n){
		while(check(digit, numdigit, now, nowd) == 0){
			nowd--;
			for(int i = nowd - 1, j = n - 1; i >= 0, j >= 0; i--, j--) now[i] = num[j];
			mk[nowd - n] = '1';
			nd = bigint(mk, nowd - n + 1, cap, 1);
		}
		sub(digit, numdigit, cap, now, nowd);
		ret += nd;
	}
	while(check(digit, numdigit, num, n)){
		sub(digit, numdigit, cap, num, n);
		// cout << ret << endl;
		ret++;
	}
	return ret;
}

void ans(char digit[], int &numdigit, int &cap, int &sign1, char num[], int &n, int &sign2) {
	if (sign1 == sign2) add(digit, numdigit, cap, num, n);
	else {
		char* num1, *num2;
		num1 = new char[max(cap, n)]; num2 = new char[max(cap, n)];
		memset(num1, 0, sizeof(num1));
		memset(num2, 0, sizeof(num2));
		while (digit[numdigit - 1] == '0') numdigit--;
		while (num[n - 1] == '0') n--;

		for (int i = 0; i < numdigit; i++) num1[i] = digit[i];
		for (int i = 0; i < n; i++) num2[i] = num[i];

		if (numdigit < n) {
			swap(num1, num2);
			swap(numdigit, n);
			swap(sign1, sign2);
		}
		else if (numdigit == n) {
			for (int i = numdigit - 1; i >= 0; i--) {
				if (num1[i] < num2[i]) {
					swap(num1, num2);
					swap(sign1, sign2);
					break;
				}
			}
		}
		sign1 = sign1 < 0 ? -1 : 1;
        sub(num1, numdigit, cap, num2, n);
		
        for(int i = 0; i < numdigit; i++) digit[i] = num1[i];
	}
}

void bigint::zero() {
	if (cap) {
		numdigit = 1;
		sign = 1;
	}
	memset(digit, '0', sizeof(digit));
}
void bigint::printvalue(ostream &out) {
	while (digit[numdigit - 1] == '0') numdigit--;
	if (!numdigit) out << 0;
	else {
		cout << (sign == -1 ? "-" : "");
		for (int i = numdigit - 1; i >= 0; i--) out << digit[i];
	}
	return;
}
void bigint::update(int v) {
	sign = v < 0 ? -1 : 1;
	v = abs(v);
	int n = 0;
	while (v) {
		digit[n] = v % 10 + 48;
		v /= 10; n++;
	}
	numdigit = n;
}
void bigint::update(bigint x) {
	cap = x.cap; numdigit = x.numdigit; sign = x.sign;
	digit = new char[cap];
	for (int i = 0; i < cap; i++) digit[i] = x.digit[i];
}

ostream& operator << (ostream& out, bigint& x) {
	x.printvalue(out);
	return out;
}
bigint bigint::operator = (int v) {
	update(v);
	bigint y(digit, numdigit, cap, sign);
	return y;
}
bigint bigint::operator = (bigint x) {
	update(x);
	bigint y(digit, numdigit, cap, sign);
	return y;
}
bigint bigint::operator += (bigint x) {
	ans(digit, numdigit, cap, sign, x.digit, x.numdigit, x.sign);
	bigint y(digit, numdigit, cap, sign);
	return y;
}
bigint bigint::operator += (int x) {
	bigint a(x);
	ans(digit, numdigit, cap, sign, a.digit, a.numdigit, a.sign);
	bigint y(digit, numdigit, cap, sign);
	return y;
}
bigint bigint::operator + (bigint x) {
	bigint a(*this);
	a.cap = 100;
	ans(a.digit, a.numdigit, a.cap, a.sign, x.digit, x.numdigit, x.sign);
	bigint y(a.digit, a.numdigit, a.cap, a.sign);
	return y;
}
bigint bigint::operator + (int x) {
	bigint a(x);
	ans(digit, numdigit, cap, sign, a.digit, a.numdigit, a.sign);
	bigint y(digit, numdigit, cap, sign);
	return y;
}
bigint bigint::operator ++ () {
	bigint a(1);
	ans(digit, numdigit, cap, sign, a.digit, a.numdigit, a.sign);
	bigint y(digit, numdigit, cap, sign);
	return y;
}
bigint bigint::operator ++ (int x) {
	bigint a(*this);
	bigint b(1);
	ans(digit, numdigit, cap, sign, b.digit, b.numdigit, b.sign);
	return a;
}
bigint bigint::operator -= (bigint x){
    int s = -x.sign;
    ans(digit, numdigit, cap, sign, x.digit, x.numdigit, s);
    bigint y(digit, numdigit, cap, sign);
    return y;
}
bigint bigint::operator -= (int x){
    bigint a(x);
    int s = -a.sign;
    ans(digit, numdigit, cap, sign, a.digit, a.numdigit, s);
    bigint y(digit, numdigit, cap, sign);
    return y;
}
bigint bigint::operator - (bigint x){
    int s = -x.sign;
	bigint a(*this);
    ans(a.digit, a.numdigit, a.cap, a.sign, x.digit, x.numdigit, s);
    bigint y(a.digit, a.numdigit, a.cap, a.sign);
    return y;
}
bigint bigint::operator - (int x){
    bigint a(x);
    int s = -a.sign;
	bigint b(*this);
    ans(b.digit, b.numdigit, b.cap, b.sign, a.digit, a.numdigit, s);
    bigint y(b.digit, b.numdigit, b.cap, b.sign);
    return y;
}
bigint bigint::operator -- (){
    bigint a(-1);
    ans(digit, numdigit, cap, sign, a.digit, a.numdigit, a.sign);
    bigint y(digit, numdigit, cap, sign);
	return y;
}
bigint bigint::operator -- (int){
	bigint a(*this);
	bigint b(-1);
	ans(digit, numdigit, cap, sign, b.digit, b.numdigit, b.sign);
	return a;
}
bigint bigint::operator * (int x){
	bigint a(x);
	bigint b(*this);
	mul(b.digit, b.numdigit, b.cap, b.sign, a.digit, a.numdigit, a.sign);
	bigint y(b.digit, b.numdigit, b.cap, b.sign);
	return y;
}
bigint bigint::operator * (bigint x){
	bigint a(*this);
	mul(a.digit, a.numdigit, a.cap, a.sign, x.digit, x.numdigit, x.sign);
	bigint y(a.digit, a.numdigit, a.cap, a.sign);
	return y;
}
bigint bigint::operator *= (int x){
	bigint a(x);
	mul(digit, numdigit, cap, sign, a.digit, a.numdigit, a.sign);
	return *this;
}
bigint bigint::operator *= (bigint x){
	mul(digit, numdigit, cap, sign, x.digit, x.numdigit, x.sign);
	return *this;
}
bigint bigint::operator / (int x){
	bigint a(x);
	bigint b(*this);
	return divide(b.digit, b.numdigit, b.cap, b.sign, a.digit, a.numdigit, a.sign);
}
bigint bigint::operator / (bigint x){
	bigint a(*this);
	return divide(a.digit, a.numdigit, a.cap, a.sign, x.digit, x.numdigit, x.sign);
}
bigint bigint::operator /= (int x){
	bigint a(x);
	bigint b(*this);
	*this = divide(b.digit, b.numdigit, b.cap, b.sign, a.digit, a.numdigit, a.sign);
	this->sign = b.sign;
	return *this;
}
bigint bigint::operator /= (bigint x){
	bigint a(*this);
	*this = divide(a.digit, a.numdigit, a.cap, a.sign, x.digit, x.numdigit, x.sign);
	this->sign = a.sign;
	return *this;
}

bigComplexNumber::bigComplexNumber(const char* const _a, const char* const _b){
	a = bigint(_a), b = bigint(_b);
}
bigComplexNumber::bigComplexNumber(int _a, int _b){
	a = bigint(_a), b = bigint(_b);
}

void test1(){
    bigint x, y("1234"), z("00000987654321");
	cout << "x y z values: " << x << ' ' << y <<' '<< z << endl;
	bigint i(44, 2); // Array 大小 2		 
	bigint j(i);
	bigint k(10);			 
	cout << "i j k values: " << i << ' ' << j <<' '<< k << endl;
	cout << "Total BigInt Object Count: " << bigint::total << endl;

	x = "987654321098765432109876543210987654321098765432109876543210";
    y = "987654321098765432109876543210987654321098765432109876543210"; 
	cout << "x y z values: " << x << ' ' << y <<' '<< z << endl;

	y = 10; y *= -88;		cout << "y values: " << y << endl;
	y = 10; y *= i;	 		cout << "y values: " << y << endl;

	y = x / 8;		cout << "y values: " << y << endl;
	x /= -8;		cout << "x values: " << x << endl;
	x /= i;	 		cout << "x values: " << x << endl;

	y= 10; y += -88;		cout << "y values: " << y << endl;
	y= 10; y += i;	 		cout << "y values: " << y << endl;
	y= 10; y -= -88;		cout << "y values: " << y << endl;
	y= 10; y -= i;	 		cout << "y values: " << y << endl;

	x =  (j * 2 * k) + i + 3;		cout << "x values: " << x << endl;
	x =  i - 3 - (j * 2 * k);		cout << "x values: " << x << endl;
    bigint h = (k++);
	cout << "k values: " << h <<  ' ' << k  << endl;

	k = 10;	x = (++k); k++; 		cout << "x k values: " << x << ' ' << k << endl;
	k = 10;	x = (--k); k--; 		cout << "x k values: " << x << ' ' << k << endl;

	x = y = "987654321098765432109876543210"; 
	cout << "x y z values: " << x << ' ' << y <<' '<< z << endl;
}

void test2(){
	bigComplexNumber x, y("10", "20"), z(2, 4);

	cout << "x y z values: " << x << ' ' << y <<' '<< z << endl;

	x = y + z;  
	cout << "x y z values: " << x << ' ' << y <<' '<< z << endl;
	x += y;  
	cout << "x y z values: " << x << ' ' << y <<' '<< z << endl;
	y += z;   
	cout << "x y z values: " << x << ' ' << y <<' '<< z << endl;
 
	y.setValue(10, 20);
	z.setValue(4, 2);
	cout << "x y z values: " << x << ' ' << y <<' '<< z << endl;
	x = y - z;  
	cout << "x y z values: " << x << ' ' << y <<' '<< z << endl;
	x -= y;  
	cout << "x y z values: " << x << ' ' << y <<' '<< z << endl;
	z -= y;  
	cout << "x y z values: " << x << ' ' << y <<' '<< z << endl;
 
	y.setValue(2, 4);
	z.setValue(10, 20);
	cout << "x y z values: " << x << ' ' << y <<' '<< z << endl;
	//*
	x = y * z;  
	cout << "x y z values: " << x << ' ' << y << ' ' << z << endl;
	y *= z;  
	cout << "x y z values: " << x << ' ' << y <<' '<< z << endl;
	z *= y;  
	cout << "x y z values: " << x << ' ' << y <<' '<< z << endl;//*/

}

int main(){
	cout << "test bigint" << endl;
    test1();
	cout << "test big complex number" << endl;
	test2();
}