#include <Windows.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

struct ServiceUsageRecord
{
	int number;           // номер телефона
	int code;            // кода услуги
	time_t dateTime;
	int duration;     // продолжительсность использования
};

void fillWithFileData(vector<ServiceUsageRecord> records)
{
	fstream fin = fstream("tretie.txt", ios::in);
	while (!fin.eof())
	{
		ServiceUsageRecord record;
		fin >> record.number;
		fin >> record.code;
		records.push_back(record);	
	}
}

void Write_txt(vector<ServiceUsageRecord>& MAS, int& n)
{
	fstream fout = fstream("students.txt", ios::out);
	if (fout.good())
	{
	
			fout << n << endl;
			for (int i = 0; i < n; i++) 
			{
				fout << MAS[i].number << ' ' << MAS[i].code << ' ' << MAS[i].dateTime << endl;
			}
			cout << "Список сохранен в файл!" << endl;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	int n = 0;
	int C;
	vector<ServiceUsageRecord> usage;

		Write_txt(usage, n);
		cout << endl;
 
}
