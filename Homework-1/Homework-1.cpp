#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int PatternCount(string s, string p) {
	int i, j, m, n;
	int count = 0;
	int l_s = s.length();//длина строки
	int l_p = p.length();//длина паттерна
	for (i = 0; i <= l_s - l_p; i++) {
		n = 0;
		for (j = i, m = 0; m < l_p; j++, m++) {
			if (p[m] == s[j]) n++;
		}
		if (n == l_p) count++;
	}
	return count;
}


int main()
{
	ifstream fin("input.txt");

	string str;
	string pattern;
	int result;

	if (!fin.is_open())
		cout << "Файл не может быть открыт!\n";
	else
	{
		fin >> str; // считали строку из файла

		fin >> pattern; // считали паттерн из файла

		result = PatternCount(str, pattern);

		ofstream fout("output.txt");
		fout << result; // запись в файл
		fout.close(); // закрываем файл

		fin.close();

	}
	return 0;
}


