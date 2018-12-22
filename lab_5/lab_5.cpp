#include <iostream>
using namespace std;

void multy(int *beg_mat1, int *beg_mat2, int *beg_mat3, int str1, int col1, int str2) {
	int sum = 0;
	for (int i = 0; i < str1; i++) {
		for (int j = 0; j < col1; j++) {
			for (int k = 0; k < str2; k++) {
				sum = sum + (*(beg_mat1 + i*str1 + k) * *(beg_mat2 + k * str2 + j));
			}
			*(beg_mat3 + i * str1 +j) = sum;
			sum = 0;
		}
	}
}

void plu(int *beg_mat1, int *beg_mat2, int *beg_mat3, int str1, int col1) {
	for (int i = 0; i < str1; i++) {
		for (int j = 0; j < col1; j++) {
				*(beg_mat3 + i * str1 + j) = *(beg_mat1 + i * str1 + j) + *(beg_mat2 + i * str1 + j);
		}
	}
}

void mi(int *beg_mat1, int *beg_mat2, int *beg_mat3, int str1, int col1) {
	for (int i = 0; i < str1; i++) {
		for (int j = 0; j < col1; j++) {
			*(beg_mat3 + i * str1 + j) = (*(beg_mat1 + i*str1 + j) - *(beg_mat2 + i * str1 + j));
		}
	}
}

int main()
{
	setlocale(0, "");
	int *beg_mat1, *beg_mat2, *beg_mat3, mat1[100], mat2[100], mat3[100] = { 0 }, str1, str2, col1, col2;
	cout << "������� ���-�� ����� 1 �������: ";
	cin >> str1;
	cout << "������� ���-�� �������� 1 �������: ";
	cin >> col1;
	cout << "������� ���-�� ����� 2 �������: ";
	cin >> str2;
	cout << "������� ���-�� �������� 2 �������: ";
	cin >> col2;
	cout << "������� 1 �������: " << endl;
	for (int i = 0; i < str1; i++) {
		for (int j = 0; j < col1; j++) {
			cin >> mat1[i * str1 + j];
		}
	}
	cout << "������� 2 �������: " << endl;
	for (int i = 0; i < str2; i++) {
		for (int j = 0; j < col2; j++) {
			cin >> mat2[i * str2 + j];
		}
	}
	beg_mat1 = &mat1[0];
	beg_mat2 = &mat2[0];
	beg_mat3 = &mat3[0];
	char choise = {};
	int check = 0;
	while (check != 1) {
		cout << "�������� ��������: *, +, -, E (�����)" << endl;
		cin >> choise;
		switch (choise) {
		case '*':
			if (col1 == str2) {
				multy(beg_mat1, beg_mat2, beg_mat3, str1, col1, str2);
				for (int i = 0; i < str1; i++) {
					for (int j = 0; j < col2; j++) {
						cout << *(beg_mat3 + i * str1 + j) << " ";
					}
					cout << endl;
				}
			}
			else {
				cout << "��������� ����������!" << endl;
			}
			break;
		case '+':
			if (str1 == str2 && col1 == col2) {
				plu(beg_mat1, beg_mat2, beg_mat3, str1, col1);
				for (int i = 0; i < str1; i++) {
					for (int j = 0; j < col2; j++) {
						cout << *(beg_mat3 + i * str1 + j) << " ";
					}
					cout << endl;
				}
			}
			else {
				cout << "�������� ����������!" << endl;
			}
			break;
		case '-':
			if (str1 == str2 && col1 == col2) {
				mi(beg_mat1, beg_mat2, beg_mat3, str1, col1);
				for (int i = 0; i < str1; i++) {
					for (int j = 0; j < col1; j++) {
						cout << *(beg_mat3 + i * str1 + j) << " ";
					}
					cout << endl;
				}
			}
			else {
				cout << "��������� ����������!" << endl;
			}
			break;
		case 'E':
			check = 1;
			break;
		default:
			cout << "������ �� ���������� ����!";
		}
	}
	return 0;
}
