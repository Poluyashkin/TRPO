#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct fio
{
	string surname;
	string name;
	string patronymic;
};

struct date
{
	int day;
	int month;
	int year;
};

struct student
{
	fio snp;
	date dr;
	int group;
};

void massive(student*, int);
void fio_sort(student*, int);

int main()
{
	setlocale(0, "ru");

	// ������� ������� ���������

	int stud_number;
	cout << "������� ����� ��������� � �������: "; cin >> stud_number; cout << "\n�������� ������: \n\n";
	student* stud = new student[stud_number];
	string names[] = { "����������", "C�����", "�����", "�����", "���������", "�����", "���", "�����", "������", "����", "��������", "����������", "���������", "����������", "�����������" };
	for (int i = 0; i < stud_number; i++)
	{
		stud[i].group = rand() % 10 + 1;
		stud[i].dr.day = rand() % 29 + 1;
		stud[i].dr.month = rand() % 12 + 1;
		stud[i].dr.year = rand() % (2004 - 1999) + 1999;
		stud[i].snp.name = names[rand() % 5 + 5];
		stud[i].snp.surname = names[rand() % 5];
		stud[i].snp.patronymic = names[rand() % 5 + 10];
	}

	// ����� ������� ���������

	massive(stud, stud_number);

	// ���������� ������ ����������������� �����

	int counter = 0, max_counter = 0, m; string names_counter;
	for (int j = 0; j < 5; j++)
	{
		counter = 0, max_counter = 0;
		names_counter = stud[j].snp.name;
		for (int i = 0; i < stud_number; i++)
		{
			if (names_counter == stud[i].snp.name) counter++;
		}
		if (max_counter < counter) max_counter = counter; m = j;
	}
	cout << "\n\n" << max_counter << "\t" << stud[m].snp.name << "\n\n";

	// ����������

	cout << "������, ��������������� �� ������ ������: " << "\n\n";
	for (int b = 1; b <= 10; b++)
	{
		for (int i = 0; i < stud_number; i++)
		{
			if (stud[i].group == b)
			{
				cout << setw(10) << stud[i].snp.surname << " " << stud[i].snp.name << " " << stud[i].snp.patronymic;
				cout << setw(10) << stud[i].dr.day << "." << stud[i].dr.month << "." << stud[i].dr.year;
				cout << setw(20) << "������: " << stud[i].group << "\n";
			}
		}
	}

	// ����� ������� � ������� ������� �.�.

	cout << "\n\n" << "������ � ������� ''������� �.�.'' : " << "\n\n";

	fio_sort(stud, stud_number);

	// ���������� �������� �������� ���������

	int counter_max = 0, ycounter = 2021, years_counter = 0;
	for (int j = 0; j < stud_number; j++)
	{
		years_counter = stud[j].dr.year;
		counter_max += 2021 - years_counter;
		years_counter = 0;
	}
	cout << "\n\n������� ������� ��������� - " << counter_max / stud_number << " ���\n\n";
}

// ������� ������� 

void massive(student* stud, int stud_number)
{
	for (int i = 0; i < stud_number; i++)
	{
		cout << setw(10) << stud[i].snp.surname << " " << stud[i].snp.name << " " << stud[i].snp.patronymic;
		cout << setw(10) << stud[i].dr.day << "." << stud[i].dr.month << "." << stud[i].dr.year;
		cout << setw(20) << "������: " << stud[i].group << "\n";
	}
}

void fio_sort(student* stud, int stud_number)
{
	for (int i = 0; i < stud_number; i++)
	{
		cout << setw(10) << stud[i].snp.surname << " " << stud[i].snp.name[0] << "." << stud[i].snp.patronymic[0] << ".";
		cout << setw(10) << stud[i].dr.day << "." << stud[i].dr.month << "." << stud[i].dr.year;
		cout << setw(20) << "������: " << stud[i].group << "\n";
	}
}