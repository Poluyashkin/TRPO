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

	// Задание массива студентов

	int stud_number;
	cout << "Введите число студентов в массиве: "; cin >> stud_number; cout << "\nИсходный массив: \n\n";
	student* stud = new student[stud_number];
	string names[] = { "Херрингтон", "Cралин", "Вульф", "Саама", "Муссолини", "Билли", "Ван", "Иосиф", "Бенито", "Марк", "Артёмович", "Тимофеевич", "Антонович", "Георгиевич", "Григорьевич" };
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

	// Вывод массива студентов

	massive(stud, stud_number);

	// Нахождение самого распространенного имени

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

	// Сортировка

	cout << "Массив, отсортированный по номеру группы: " << "\n\n";
	for (int b = 1; b <= 10; b++)
	{
		for (int i = 0; i < stud_number; i++)
		{
			if (stud[i].group == b)
			{
				cout << setw(10) << stud[i].snp.surname << " " << stud[i].snp.name << " " << stud[i].snp.patronymic;
				cout << setw(10) << stud[i].dr.day << "." << stud[i].dr.month << "." << stud[i].dr.year;
				cout << setw(20) << "Группа: " << stud[i].group << "\n";
			}
		}
	}

	// Вывод массива в формате Фамилия И.О.

	cout << "\n\n" << "Массив в формате ''Фамилия И.О.'' : " << "\n\n";

	fio_sort(stud, stud_number);

	// Нахождение среднего возраста студентов

	int counter_max = 0, ycounter = 2021, years_counter = 0;
	for (int j = 0; j < stud_number; j++)
	{
		years_counter = stud[j].dr.year;
		counter_max += 2021 - years_counter;
		years_counter = 0;
	}
	cout << "\n\nСредний возраст студентов - " << counter_max / stud_number << " лет\n\n";
}

// Задание функций 

void massive(student* stud, int stud_number)
{
	for (int i = 0; i < stud_number; i++)
	{
		cout << setw(10) << stud[i].snp.surname << " " << stud[i].snp.name << " " << stud[i].snp.patronymic;
		cout << setw(10) << stud[i].dr.day << "." << stud[i].dr.month << "." << stud[i].dr.year;
		cout << setw(20) << "Группа: " << stud[i].group << "\n";
	}
}

void fio_sort(student* stud, int stud_number)
{
	for (int i = 0; i < stud_number; i++)
	{
		cout << setw(10) << stud[i].snp.surname << " " << stud[i].snp.name[0] << "." << stud[i].snp.patronymic[0] << ".";
		cout << setw(10) << stud[i].dr.day << "." << stud[i].dr.month << "." << stud[i].dr.year;
		cout << setw(20) << "Группа: " << stud[i].group << "\n";
	}
}