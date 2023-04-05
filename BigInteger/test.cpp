#include <iostream>
using namespace std;
#include <string.h>

class BigInteger {
	char *num;
	int size;
public:
	BigInteger() {
		num = NULL;
		size = 0;
	}
	void setBigInteger(char *data) {
		char buffer[BUFSIZ];
		strcpy_s(buffer, data);

		if (data[0] == '-') {
			size = strlen(data);
		} else {
			size = strlen(data) + 1;
		}
		num = new char[size];

		if (buffer[0] == '-') {
			toTensComplement(buffer);
			for (int i = 0; i < size; i++) {
				num[i] = buffer[i];
			}
		} else {
			num[0] = 0;
			for (int i = 1; i < size; i++) {
				num[i] = buffer[i-1] - '0';
			}
		}
	}
	BigInteger(char *data) {
		setBigInteger(data);
	}
	BigInteger(BigInteger &data) {
		size = data.size;
		num = new char[size];
		for (int i = 0; i < size; i++) {
			num[i] = data.num[i];
		}
	}
	void operator=(BigInteger &data) {
		size = data.size;
		num = new char[size];
		for (int i = 0; i < size; i++) {
			num[i] = data.num[i];
		}
	}
	void operator=(char *data) {
		setBigInteger(data);
	}
	BigInteger operator+(BigInteger &data) {
		BigInteger arg1(*this);
		BigInteger arg2(data);

		int len = 0;

		if (arg1.size > arg2.size) {
			len = arg1.size;
			char *tmp = arg2.num;
			int orgSize = arg2.size;
			arg2.size = arg1.size;
			arg2.num = new char[arg2.size];
			for (int i = 0; i < arg2.size; i++) {
				arg2.num[i] = tmp[0];
			}
			int i = orgSize - 1;
			int j = len - 1;
			while (i >= 0) {
				arg2.num[j] = tmp[i];
				i--;
				j--;
			}
			cout << arg1 << " " << arg2 << endl;
		} else if (arg1.size < arg2.size) {
			len = arg2.size;
			char *tmp = arg1.num;
			int orgSize = arg1.size;
			arg1.size = arg1.size;
			arg1.num = new char[arg1.size];
			for (int i = 0; i < arg1.size; i++) {
				arg1.num[i] = tmp[0];
			}
			int i = orgSize - 1;
			int j = len - 1;
			while (i >= 0) {
				arg1.num[j] = tmp[i];
				i--;
				j--;
			}
			cout << arg1 << " " << arg2 << endl;
		} else {
			len = arg2.size; 
		}

		BigInteger result;
		result.size = len + 1;
		result.num = new char[result.size];

		int carry = 0;
		for (int i = len-1; i >= 0; i--) {
			int sum = arg1.num[i] + arg2.num[i] + carry;
			if (sum >= 10) {
				sum = sum - 10;
				carry = 1;
			} else {
				carry = 0;
			}
			result.num[i+1] = sum;
		}
		if (carry == 0) 
			result.num[0] = 0;
		else result.num[0] = 9;

		return result;
	}
	BigInteger operator+(char *data) {
		BigInteger arg1(*this);
		BigInteger arg2(data);
		int len = 0;

		if (arg1.size > arg2.size) {
			len = arg1.size;
			char *tmp = arg2.num;
			int orgSize = arg2.size;
			arg2.size = arg1.size;
			arg2.num = new char[arg2.size];
			for (int i = 0; i < arg2.size; i++) {
				arg2.num[i] = tmp[0];
			}
			int i = orgSize - 1;
			int j = len - 1;
			while (i >= 0) {
				arg2.num[j] = tmp[i];
				i--;
				j--;
			}
			cout << arg1 << " " << arg2 << endl;
		} else if (arg1.size < arg2.size) {
			len = arg2.size;
			char *tmp = arg1.num;
			int orgSize = arg1.size;
			arg1.size = arg1.size;
			arg1.num = new char[arg1.size];
			for (int i = 0; i < arg1.size; i++) {
				arg1.num[i] = tmp[0];
			}
			int i = orgSize - 1;
			int j = len - 1;
			while (i >= 0) {
				arg1.num[j] = tmp[i];
				i--;
				j--;
			}
			cout << arg1 << " " << arg2 << endl;
		} else {
			len = arg2.size; 
		}

		BigInteger result;
		result.size = len + 1;
		result.num = new char[result.size];

		int carry = 0;
		for (int i = len-1; i >= 0; i--) {
			int sum = arg1.num[i] + arg2.num[i] + carry;
			if (sum >= 10) {
				sum = sum - 10;
				carry = 1;
			} else {
				carry = 0;
			}
			result.num[i+1] = sum;
		}
		if (carry == 0) 
			result.num[0] = 0;
		else result.num[0] = 9;

		return result;
	}
	void toTensComplement(char *buffer, char charZero = '0') {
		for (int i = size-1; i > 0; i--) {
			buffer[i] = 9 - (buffer[i] - charZero);
		}
		buffer[0] = 9;

		plusOne(buffer);
	}
	void plusOne(char *buffer) {
		int carry = 1;

		for (int i = size-1; i > 0; i--) {
			int sum = buffer[i] + carry;
			
			if (sum >= 10) {
				sum = sum - 10;
			} else {
				buffer[i] = sum;
				break;
			}
			buffer[i] = sum;
		}
	}
	friend ostream& operator<<(ostream& out, BigInteger &b);
};

ostream& operator<<(ostream& out, BigInteger &b) {
	if (b.num[0] == 9) {
		char buffer[BUFSIZ];
		for (int i = 0; i < b.size; i++) {
			buffer[i] = b.num[i];
			//out << (int)buffer[i];
		}
		b.toTensComplement(buffer, 0);
		out << "-";
		for (int i = 1; i < b.size; i++) {
			out << (int)buffer[i];
		}
		int i = 1;
		while (buffer[i] == 0) i++;
		for (; i < b.size; i++) {
			out << (int)buffer[i];
		}
	} else {
		int i = 0;
		cout << "size = " << b.size << endl;
		while (b.num[i] == 0) i++;
		for (; i < b.size; i++) {
			out << (int)b.num[i] << " ";
		}
	}
	return out;
}

void main()
{
	BigInteger x("-999");
	BigInteger y;
	BigInteger z;

	x = "-2";
	y = "1111";
	z = x + "-3";

	cout << "x = " << x << " y = " << y << " z = " << z <<  endl;
}