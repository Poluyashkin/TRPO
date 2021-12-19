#include <iostream>
#include <string>
using namespace std;

enum Exercise {
	pass,
	transfer,
	overloadTransfer,
	againsNumber,
	overloadAgainsNumber,

};

int transferStrToInt(string& number);
int transferStrToInt(string& number, int maxCountElement);
int maxAgainNumber(int array[9]);
int maxAgainNumber(char array[9]);

int main() {

	cout << "Ex-ce exit  0\n 1  transfer number string to int\n 2  transfer max count of number string to int\n 3  find max again number\n 4  (char) find max again number" << endl;
	int exercise;
	while (true) {
		do {
			cout << "Enter exercise    ";
			cin >> exercise;
		} while (exercise < 1 || exercise > 4);


		switch (exercise) {
		case transfer: {
			string number;
			cout << "Enter number   ";
			cin >> number;
			cout << "Number type of INT  " << transferStrToInt(number) << endl;
			break;
		}
		case overloadTransfer: {
			string number;
			int count, length;
			do {
				cout << "Enter number | max count of number    ";
				cin >> number>> count;
				length = number.length();
			} while (count < 1 || count > length);
			cout << "Number type of INT with max count element  " << transferStrToInt(number, count) << endl;
			break;
		}
		case againsNumber: {
			int array[9] = { 1,2,3,4,5,5,5,6,7 };
			cout << "Max agains element in array is " << maxAgainNumber(array) << endl;
			break;
		}
		case overloadAgainsNumber: {
			char array[9] = { '1', '2', '3', '4', '5', '5', '5', '6', '7' };
			cout << "(char) Max agains element in array is " << array[maxAgainNumber(array)] << endl;
			break;
		}
		}
	}
	return 0;
}

int transferStrToInt(string& number)
{
	int countDigit = number.length();
	int* num = new int[countDigit];
	int newNumber = 0;
	for (int i = 0; i < countDigit; i++) num[i] = number[i] - 48;
	for (int j = 0; j < countDigit; j++) newNumber += num[j] * pow(10, countDigit - 1 - j);

	delete[]num;
	return newNumber;
}

int transferStrToInt(string& number, int maxCountElement)
{
	int* num = new int[maxCountElement];
	int newNumber = 0;
	for (int i = 0; i < maxCountElement; i++) num[i] = number[i] - 48;
	for (int j = 0; j < maxCountElement; j++) newNumber += num[j] * pow(10, maxCountElement - 1 - j);

	delete[]num;
	return newNumber;
}

int maxAgainNumber(int array[9])
{
	int maxNum;
	int count = 0, count1 = 0;
	int index, j;

	for (int i = 0; i < 8; i++)
	{
		maxNum = array[i];
		for (j = i + 1; j < 9; j++) {
			if (maxNum == array[j]) count++;

			if (count > count1) {
				count1 = count;
				index = j;
			}
		}
	}

	return array[index];
}

int maxAgainNumber(char array[9])
{
	int maxNum;
	int count = 0, count1 = 0;
	int index, j;

	for (int i = 0; i < 8; i++)
	{
		maxNum = array[i];
		for (j = i + 1; j < 9; j++) {
			if (maxNum == array[j]) count++;

			if (count > count1) {
				count1 = count;
				index = j;
			}
		}
	}

	return index;
}