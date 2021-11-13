#include <iostream>
#include <ctime>
#include <cassert>
#include <stdlib.h>
#define RAND_MAX 32767
using namespace std;

void number1()
{
	int l, h, l0, h0, p, s;
	l0 = 0;
	h0 = 0;
	cout << "Enter a length:";
	cin >> l;
	cout << "Enter a height:";
	cin >> h;

	for (int h0 = 0; h > h0; h0++)
	{
		for (int l0 = 0; l > l0; l0++)
		{
			cout << "X";
		}
		cout << "\n";
	}

	cout << "perimetr = ";
	p = 2 * (h + l);
	cout << p << "\n";
	cout << "area = ";
	s = h * l;
	cout << s << "\n";
	cout << "\nTask 1 is completed\n";
}


void number2()
{
	long int a, b;
	int n;
	a = 0;
	b = 1;
	do {
		cout << "Enter a number above zero: ";
		cin >> n;
	} while (n <= 0);

	cout << "0 ";
	while (n != 0)
	{
		a = a + b;
		b = a - b;
		n = n - 1;
		cout << a << " ";
	}
	cout << "\nTask 2 is completed\n";
}

void number3()
{
	float count1, count2;
	int fn, sn;
	count1 = 0;
	count2 = 0;
	cout << "Enter a first number: ";
	cin >> fn;
	for (int i = 2; i < fn - 1; i++)
	{
		if (fn % i == 0)
			count1++;
	}
	cout << "Enter a second number: ";
	cin >> sn;
	for (int i = 2; i < fn - 1; i++)
	{
		if (sn % i == 0)
			count2++;
	}

	if (count1 >= 1)
		cout << "num1 composite\n";
	else
		cout << "num1 simple\n";

	if (count2 >= 1)
		cout << "num2 composite\n";
	else
		cout << "num2 simple\n";

	for (int t = fn; t > 0; t--)
	{
		if (fn % t == 0 && sn % t == 0)
		{
			cout << "NOD = " << t;
			break;
		}
	}
	cout << "\nTask 3 is completed\n";
}

void number4()
{
	int number, t;
	cout << "Enter a number:";
	cin >> number;
	while (number >= 1)
	{
		t = number % 2;
		number = number / 2;

		cout << t;
	}
	cout << "\nTask 4 is completed\n";
}

struct PRNG
{
	unsigned seed = 0;
};

void initGenerator(PRNG& generator)
{
	generator.seed = unsigned(std::time(nullptr));
}

unsigned random(PRNG& generator, unsigned minValue, unsigned maxValue)
{
	assert(minValue < maxValue);
	generator.seed = (generator.seed * 73129 + 95121);
	return (generator.seed % (maxValue + 1 - minValue)) + minValue;
}

void number5()
{
	PRNG generator;
	initGenerator(generator);
	int array[100];
	int num[11];
	num[1] = 0;
	num[2] = 0;
	num[3] = 0;
	num[4] = 0;
	num[5] = 0;
	num[6] = 0;
	num[7] = 0;
	num[8] = 0;
	num[9] = 0;
	num[0] = 0;
	for (int i = 0; i < 100; i++)
	{
		array[i] = random(generator, 1, 10);
		cout << array[i] << " ";
		switch (array[i])
		{
		case 1:
			num[0]++;
			break;
		case 2:
			num[1]++;
			break;
		case 3:
			num[2]++;
			break;
		case 4:
			num[3]++;
			break;
		case 5:
			num[4]++;
			break;
		case 6:
			num[5]++;
			break;
		case 7:
			num[6]++;
			break;
		case 8:
			num[7]++;
			break;
		case 9:
			num[8]++;
			break;
		case 10:
			num[9]++;
			break;
		}
	}



	for (int t = 0; t < 10; t++)
	{
		cout << "\n-" << t + 1 << "-";

		for (int num0 = 0; num[t] > num0; num0++)
		{
			cout << "X";
		}

	}

	cout << "\n\nTask 5 is completed\n";
}

int main()
{
	int a;
	do {
		cout << "Enter a task number(1-5): ";
		cin >> a;
	} while (a > 5);
	cout << "\n";

	switch (a)
	{
	case 1:
		number1();
		break;
	case 2:
		number2();
		break;
	case 3:
		number3();
		break;
	case 4:
		number4();
		break;
	case 5:
		number5();
		break;
	}
}