#include <iostream>
using namespace std;
#include <string.h>

class BigInteger {
	char *digit;
	int sz;
	void set(const char *data);
	void set(BigInteger &data);
	int plusOne();
	char *createStringWhenPlus();
	char *createStringWhenMinus();
	static char *covertSign(const char *data);
	void setDigitsFromPlusString(const char *data);
	void setDigitsFromMinusString(const char *data);
	static bool isPlus(const char *data);
	bool isPlus();
	int accumulateNumber(BigInteger &data);
	void trimSign();
	bool equalsZero();
	void shiftLeft();
public:
	BigInteger();
	BigInteger(const char *data);
	BigInteger(BigInteger &data);
	BigInteger(int n,const char *data);
	BigInteger(int n,BigInteger &data);
	BigInteger(int n);
	~BigInteger() {
		delete digit;
	}
	char *toString();
	void operator=(const char *data);
	void operator=(BigInteger &data);
	BigInteger operator+(const char *data);
	BigInteger operator+(BigInteger &data);
	BigInteger operator-(const char *data);
	BigInteger operator-(BigInteger &data);
	BigInteger operator*(const char *data);
	BigInteger operator*(BigInteger &data);
	BigInteger divide(const char *data);
	bool operator>(const char *data);
	bool operator>(BigInteger &data);
	bool operator<(const char *data);
	bool operator<(BigInteger &data);
	bool operator==(const char *data);
	bool operator==(BigInteger &data);
	bool operator>=(const char *data);
	bool operator>=(BigInteger &data);
	bool operator<=(const char *data);
	bool operator<=(BigInteger &data);
	friend ostream& operator<<(ostream &out,BigInteger &num);
};

BigInteger::BigInteger() {
	set("0");
}

BigInteger::BigInteger(const char *data)
{
	set(data);
}

BigInteger::BigInteger(BigInteger &data)
{
	set(data);
}

BigInteger::BigInteger(int n)
{
	sz = n;
	digit = new char[n];

	for(int i = 0; i < sz; i++) {
		digit[i] = 0;
	}
}

BigInteger::BigInteger(int n,const char *data)
{
	sz = n;
	digit = new char[n];

	for(int i = 0; i < sz; i++) {
		digit[i] = 0;
	}
	int j = sz - 1;
	for(int i = strlen(data)-1; i >= 0; i--) {
		digit[j] = data[i] - '0';
		j--;
	}
}

BigInteger::BigInteger(int n,BigInteger &data)
{
	sz = n;
	digit = new char[n];

	for(int i = 0; i < sz; i++) {
		digit[i] = data.digit[0];
	}
	int j = sz - 1;
	for(int i = data.sz-1; i >= 0; i--) {
		digit[j] = data.digit[i];
		j--;
	}
}

void BigInteger::set(BigInteger &data)
{
	sz = data.sz;
	digit = new char[sz];
	for(int i = 0; i < sz; i++) digit[i] = data.digit[i];
}

bool BigInteger::operator>(const char *data)
{
	BigInteger tmp;

	tmp = (*this) - data;
	if (tmp.isPlus()) return true;
	return false;
}

bool BigInteger::operator>(BigInteger &data)
{
	char *s = data.toString();
	
	return *this > s;
}

bool BigInteger::operator<(const char *data)
{
	BigInteger tmp;

	tmp = (*this) - data;
	if (tmp.isPlus()) return false;
	return true;
}

bool BigInteger::operator<(BigInteger &data)
{
	char *s = data.toString();
	
	return *this < s;
}

void BigInteger::operator=(const char *data)
{
	set(data);
}

void BigInteger::operator=(BigInteger &data)
{
	set(data);
}

bool BigInteger::isPlus()
{
	if (digit[0] == 0) return true;
	else return false;
}

bool BigInteger::isPlus(const char *data)
{
	if (*data == '-') return false;
	else return true;
}

void BigInteger::trimSign()
{
	if (sz <= 2) return;
	int signCount = 1;

	for(int i = 1; i < sz; i++) {
		if (digit[i] == digit[0]) signCount++;
		else break;
	}
	
	if (signCount == 1) return;

	char *buf = new char[sz - signCount + 1];
	int j = sz - signCount;

	for(int i = sz-1; i >= signCount-1; i--) {
		buf[j] = digit[i];
		j--;
	}
	sz = sz - signCount + 1;
	digit = buf;
}

int BigInteger::accumulateNumber(BigInteger &data)
{
	int carry = 0;

	for (int i = sz-1; i >= 0; i--) {
		digit[i] = digit[i] + data.digit[i] + carry;
		if (digit[i] >= 10) {
			digit[i] = digit[i] - 10;
			carry = 1;
		} else {
			carry = 0;
		}
	}

	return carry;
}

char *BigInteger::covertSign(const char *data)
{
	if (*data == '-') {
		return strdup(data+1);
	} else {
		char *p = new char[strlen(data) + 2];
		*p = '-';
		strcpy(p+1,data);
		return p;
	}
}

BigInteger BigInteger::operator-(BigInteger &data)
{
	char *s = data.toString();
	return (*this) - s;
}

BigInteger BigInteger::operator-(const char *data) 
{
	char *operand = covertSign(data);
	return *this + operand;
}

BigInteger BigInteger::operator+(BigInteger &data)
{
	char *s = data.toString();
	return (*this) + s;
}

bool BigInteger::equalsZero()
{
	for (int i = 0; i < sz; i++) {
		if (digit[i] != 0) return false;
	}
	return true;
}

bool BigInteger::operator==(const char *data) 
{
	BigInteger tmp;

	tmp = (*this) - data;
	if (tmp.equalsZero()) return true;
	return false;
}

bool BigInteger::operator>=(const char *data)
{
	return ((*this)>data || (*this)==data);
}

bool BigInteger::operator>=(BigInteger &data)
{
	return ((*this)>data || (*this)==data);
}

bool BigInteger::operator<=(const char *data)
{
	return ((*this)<data || (*this)==data);
}

bool BigInteger::operator<=(BigInteger &data)
{
	return ((*this)<data || (*this)==data);
}

bool BigInteger::operator==(BigInteger &data) 
{
	char *s = data.toString();
	return (*this) == s;
}

void BigInteger::shiftLeft()
{
	for (int i = 1; i < sz; i++) {
		digit[i-1] = digit[i];
	}
	digit[sz-1] = 0;
}

BigInteger BigInteger::operator*(BigInteger &data)
{
	char *s = data.toString();
	return (*this) * s;
}

BigInteger BigInteger::operator*(const char *data)
{
	BigInteger operand(data);
	int resultSign = 0; // 0 : plus 1 : minus
	if ((isPlus() == true && operand.isPlus() == true) ||
		(isPlus() == false && operand.isPlus() == false)) {
			resultSign = 0;
	} else {
			resultSign = 1;
	}

	char *data1 = toString();
	char *data2 = operand.toString();

	if (isPlus(data1) == false) {
		data1 = covertSign(data1);
	}

	if (isPlus(data2) == false) {
		data2 = covertSign(data2);
	}

	int maxLength = sz + operand.sz - 1;
	BigInteger result(maxLength);
	BigInteger addum(maxLength,data1);
	BigInteger count(data2);
	//cout << "&&&" << result << " " << addum << " " << count << endl;
	
	/*while(!count.equalsZero()) {
		result.accumulateNumber(addum);
		count = count - "1";
		cout << "result = " << result << "\n";
	}*/

	int countSize = count.sz - 1;
	for (int i = countSize; i > 0; i--) {
		for (int j = 0; j < count.digit[i]; j++) {
			result.accumulateNumber(addum);
		}
		addum.shiftLeft();
	}

	result.trimSign();

	if (resultSign == 1) {
		char *plusResult = result.toString();
		char *minusResult = covertSign(plusResult);
		return BigInteger(minusResult);
	} else {
		return result;
	}
}

BigInteger BigInteger::divide(const char *data)
{
	BigInteger operand(data);
	int resultSign = 0; // 0 : plus 1 : minus
	if ((isPlus() == true && operand.isPlus() == true) ||
		(isPlus() == false && operand.isPlus() == false)) {
			resultSign = 0;
	} else {
			resultSign = 1;
	}

	char *data1 = toString();
	char *data2 = operand.toString();

	if (isPlus(data1) == false) {
		data1 = covertSign(data1);
	}

	if (isPlus(data2) == false) {
		data2 = covertSign(data2);
	}

	BigInteger numerator(data1);
	BigInteger denominator(data2);
	BigInteger result(sz, "0");
	
	while (numerator >= denominator) {
		numerator = numerator - denominator;
		result = result + "1";
	}

	result.trimSign();

	if (resultSign == 1) {
		char *plusResult = result.toString();
		char *minusResult = covertSign(plusResult);
		return BigInteger(minusResult);
	} else {
		return result;
	}
	return result;
}

BigInteger BigInteger::operator+(const char *data)
{
	BigInteger operand(data);

	int maxLength = 0;
	int sz1 = sz;
	int sz2 = operand.sz;

	if ((isPlus() == true && operand.isPlus() == true) ||
		(isPlus() == false && operand.isPlus() == false)) {
			if (sz1 > sz2) maxLength = sz1 + 1;
			else maxLength = sz2 + 1;
	} else {
			if (sz1 > sz2) maxLength = sz1;
			else maxLength = sz2;
	}

	BigInteger result(maxLength,*this);
	BigInteger data2(maxLength,operand);

	result.accumulateNumber(data2);
	result.trimSign();
	return result;
}

char *BigInteger::createStringWhenPlus()
{
	char *buf = new char[sz];

	for(int i = 1; i < sz; i++) {
		buf[i-1] = digit[i] + '0';
	}
	buf[sz-1] = '\0';
	return buf;
}

char *BigInteger::createStringWhenMinus()
{
	char *buf = new char[sz+1];

	buf[0] = '-';
	for(int i = 1; i < sz; i++) {
		buf[i] = 9 - digit[i];
	}

	int carry = 1;

	for(int i = sz-1; i > 0; i--) {
		if (carry == 0) break;
		buf[i] = buf[i] + carry;
		if (buf[i] >= 10) {
			buf[i] = buf[i] - 10;
			carry = 1;
		} else {
			carry = 0;
		}
	}
	buf[sz] = '\0';

	for(int i = 1; i < sz; i++) {
		buf[i] = buf[i] + '0';
	}

	return buf;
}

char *BigInteger::toString()
{
	if (isPlus()) {
		return createStringWhenPlus();
	} else {
		return createStringWhenMinus();
	}
}

void BigInteger::setDigitsFromPlusString(const char *data)
{
	int len = strlen(data);
	sz = len + 1;
	digit = new char[len+1];
	digit[0] = 0;
	for (int i = 1; i < len+1; i++) {
		digit[i] = data[i-1] - '0';
	}
}

int BigInteger::plusOne()
{
	int carry = 1;

	for(int i = sz-1; i >= 0; i--) {
		if (carry == 0) break;
		digit[i] = digit[i] + carry;
		if (digit[i] >= 10) {
			digit[i] = digit[i] - 10;
			carry = 1;
		} else {
			carry = 0;
		}
	}
	return carry;
}

void BigInteger::setDigitsFromMinusString(const char *data)
{
	int len = strlen(data);
	sz = len;
	digit = new char[len];
	digit[0] = 9;
	for (int i = 1; i < len; i++) {
		digit[i] = 9 - (data[i] - '0');
	}
	plusOne();
}

void BigInteger::set(const char *data)
{
	if (BigInteger::isPlus(data)) {
		setDigitsFromPlusString(data);
	} else {
		setDigitsFromMinusString(data);
	}
}


ostream& operator<<(ostream &out,BigInteger &num)
{
	char *s = num.toString();
	
	out << s;
	return out;
}

void main()
{
	BigInteger x;
	BigInteger y("-1234");
	BigInteger z(y);

	x = "1234";
	y = "33";
//	z = x + "65";
	z = x + y;

	x = "999";
	y = "9999";
	z = x * y;

	/*if (x > "1") {
		cout << "greater than" << endl;
	} else {
		cout << "less than" << endl;
	}*/

	x = "23";
	z = x.divide("1");
	cout << x << ", " << y << ", " << z << endl;
}