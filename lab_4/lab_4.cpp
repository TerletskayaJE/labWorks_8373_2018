#include <iostream>
using namespace std;

void power(int digit) {
	int pow, i = 0;
	float b = 1.0;
	cout << "������� �������: ";
	cin >> pow;
	if (digit != 0 && pow != 0) {
		if (pow > 0) {
			while (i != pow) {
				b *= digit;
				i++;
			}
		}
		else if (pow < 0) {
			while (i != pow) {
				b /= digit;
				i--;
			}
		}
		else {
			b = 1;
		}
		cout << "����� " << digit << " � ������� " << pow << " ����� " << b;
	}
	else {
		cout << "����� " << digit << " � ������� " << pow << " �� ����������";
	}
	cout << endl;
}

void factorial(int digit) {
	int p = 1, fac = 1;
	if (digit >= 0) {
		while (p <= digit) {
			fac *= p;
			p++;
		}
		cout << "��������� ����� " << digit << " ����� " << fac;
	}
	else {
		cout << "���������� ����� " << digit << " �� ����������";
	}
	cout << endl;
}

void root(int digit) {
	if (digit >= 0) {
		cout << "������ �� ����� " << digit << " ����� " << sqrt(digit);
	}
	else {
		cout << "����� �� ����� " << digit << " �� ����������";
	}
	cout << endl;
}

void simple(int digit) {
	if (digit <= 1) {
		cout << "����� " << digit << " �� �������";
	}
	else {
		int a = 2, k = 0;
		while (a < digit) {
			if (digit%a == 0) {
				k++;
			}
			a++;
		}
		if (k == 0) {
			cout << "����� " << digit << " �������";
		}
		else {
			cout << "����� " << digit << " �� �������";
		}
	}
	cout << endl;
}

int main() {
	setlocale(0, "");
	int digit;
	cout << "������� �����: ";
	cin >> digit;
	power(digit);
	factorial(digit);
	root(digit);
	simple(digit);
	return 0;
}