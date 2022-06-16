/*
Author: Xiaoyo
num: 01057020
time: 2022 / 06 / 16
//*/
#pragma once
#ifndef bigint_h
#define bigint_h
#include "iostream"
#include "string"
using namespace std;

class bigint {
public:
	char* digit;
	int cap, numdigit, sign;
	static int total;
	~bigint();
	bigint();
	bigint(int value, int size);
	bigint(const char* const, int size);
	bigint(bigint&);
	bigint(char*, int, int, int);
	void zero();
	void printvalue(ostream &);
	void update(int);
	void update(bigint);
	int getCount(){
		return total;
	}
	
	friend ostream& operator << (ostream&, bigint&);
	// bigint operator = (bigint);
	bigint operator = (int);
	bigint operator = (bigint);
	bigint operator += (bigint);
	bigint operator += (int);
	bigint operator + (bigint);
	bigint operator + (int);
	bigint operator ++ ();
	bigint operator ++ (int);
    bigint operator -= (bigint);
    bigint operator -= (int);
    bigint operator - (bigint);
    bigint operator - (int);
    bigint operator -- ();
    bigint operator -- (int);
    bigint operator * (int);
    bigint operator * (bigint);
    bigint operator *= (int);
    bigint operator *= (bigint);
    bigint operator / (int);
    bigint operator / (bigint);
    bigint operator /= (int);
    bigint operator /= (bigint);
};
class bigComplexNumber{
public:
	bigint a, b;
	bigComplexNumber(){
		a = b = 0;
	}
	bigComplexNumber(int _a, int _b);
	bigComplexNumber(const char* const _a, const char* const _b);
	bigComplexNumber(bigint _a, bigint _b){
		a = _a, b = _b;
	}
	bigComplexNumber(bigComplexNumber &_a){
		a = _a.a, b = _a.b;
	}
	void setValue(int _a, int _b){
		a = _a, b = _b;
	}
	friend ostream& operator << (ostream &out, bigComplexNumber &x);
	bigComplexNumber operator = (bigComplexNumber x){
		a = x.a, b = x.b;
		return *this;
	}
	bigComplexNumber operator + (bigComplexNumber x){
		bigComplexNumber t(*this);
		return bigComplexNumber(t.a + x.a, t.b + x.b);
	}
	bigComplexNumber operator += (bigComplexNumber x){
		a += x.a, b += x.b;
		return *this;
	}
	bigComplexNumber operator - (bigComplexNumber x){
		bigComplexNumber t(*this);
		return bigComplexNumber(t.a - x.a, t.b - x.b);
	}
	bigComplexNumber operator -= (bigComplexNumber x){
		this->a -= x.a, this->b -= x.b;
		return *this;
	}
	bigComplexNumber operator * (bigComplexNumber x){
		bigComplexNumber t(*this);
		bigComplexNumber y(t.a * x.a - t.b * x.b, t.a * x.b + t.b * x.a);
		return y;
	}
	bigComplexNumber operator *= (bigComplexNumber x){
		bigComplexNumber t(*this);
		bigComplexNumber y(t.a * x.a - t.b * x.b, t.a * x.b + t.b * x.a);
		this->a = y.a, this->b = y.b;
		return *this;
	}
};


ostream& operator << (ostream&, bigint&);
ostream& operator << (ostream &out, bigComplexNumber &x){
	out << x.a << (x.b.sign < 0 ? "" : "+") << x.b << "i";
	return out;
}

#endif