#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void findANDreplace(char* str, char* resault);
void convert(float y, float z, char* str);

int main()
{
	setlocale(LC_ALL, "RUS");
	float y, z;
	cout << "Введите y: ";
	cin >> y;
	cout << "Введите z: ";
	cin >> z;
	char res[50];
	convert(y, z, res);
	cout << res << endl;
	char* str1 = new char[100];
	char* str2 = new char[110];
	strcpy(str1, "Мир пока");
	findANDreplace(str1, str2);
	cout << str1 << endl;
	cout << str2 << endl;
	delete[]str1;
	delete[]str2;
}

void convert(float y, float z, char* str)
{
	double x = log(y+3*z);
	sprintf(str, "%03.5f = log10(%03.5f+3*%03.5f)", x, y, z);
}

void findANDreplace(char* str_l, char* resault_l) {
	memset(resault_l, 0, sizeof(char) * 100);
	char str[250] = {};
	for (int i = 0; i < strlen(str_l); i++) {
		str[i] = str_l[i];
	}
	char resault[100] = { "'" };
	char res[20] = {};
	short i = 0;
	short ii = strlen(str);
	char str1[250];
	short iii;
	short addres = 0;
	int n = 0;
	for (; i < ii - 1;) {
		strncpy(str1, i + str, 50);
		iii = strcspn(str1, " ");
		i = i + iii + 1;
		memset(res, 0, sizeof(char) * 20);
		strncpy(res, addres + str, i-1 - addres); 
		strcat(resault, res);
		strcat(resault, "' ");
		n++;
		addres = i;
		
		if (i > ii) break;
		strcat(resault, "'");
	}
	char ss[100] = {};
	sprintf(ss, "Было произведено %0.0d вставок: ", n);
	strcat(ss, resault);
	strncpy(resault, ss, 100);
	for (int i = 0; i < strlen(resault); i++) {
		resault_l[i] = resault[i];
	}
	
}