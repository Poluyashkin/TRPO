#include <iostream>
#include <ctime>
#include <iomanip>
const int SIZE = 4;
using namespace std;

bool isNumberNumeric()
{
	if (cin.get() == '\n')
		return true;
	else
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}
}

int inputNumber()
{
	int number;
	while (true)
	{
		cin >> number;
		if (isNumberNumeric())
		{
			return number;
		}
		else
		{
			cout << "Incorrect input!\n" << "Try again: ";
		}
	}
}

void showMatrix(int numbersLine, int numbersColumn, int** matrix)
{
	for (int counterLine = 0; counterLine < numbersLine; counterLine++)
	{
		for (int counterColumn = 0; counterColumn < numbersColumn; counterColumn++)
		{
			cout << setw(4) << matrix[counterLine][counterColumn];
		}
		cout << "\n";
	}
}

void byKeyboard(int numbersLine, int numbersColumn, int** matrix)
{
	for (int counterLine = 0; counterLine < numbersLine; counterLine++)
	{
		for (int counterColumn = 0; counterColumn < numbersColumn; counterColumn++)
		{
			cout << "Enter item [" << counterLine + 1 << "][" << counterColumn + 1 << "]: ";
			cin >> matrix[counterLine][counterColumn];
		}
	}
}

void byRandom(int numbersLine, int numbersColumn, int** matrix)
{
	int left_value, right_value;
	cout << "Enter the start of the line segment: ";
	cin >> left_value;

	do {
		cout << "Enter the end of the line segment: ";
		cin >> right_value;
		if (right_value <= left_value) cout << "The left value must be less than the right one!" << endl;
	} while (right_value <= left_value);

	for (int counterLine = 0; counterLine < numbersLine; counterLine++)
	{
		for (int counterColumn = 0; counterColumn < numbersColumn; counterColumn++)
		{
			int znak = rand() % 3;
			int sign;
			if (znak == 1)
				sign = -1;
			else
				sign = 1;
			matrix[counterLine][counterColumn] = (rand() % (right_value - left_value + 1) + left_value) * sign;
		}
	}
}

void buildMatrix(int numbersLine, int numbersColumn)
{
	int code;
	int** matrix = new int* [numbersLine];
	for (int i = 0; i < numbersLine; i++)
	{
		matrix[i] = new int[numbersColumn];
	}

	cout << "\nChoose a way to define an integer matrix: ";
	do {
		cout << "\n-1- By keyboard\n-2- By random\nYour choise: ";
		cin >> code;
	} while (code > 2 || code < 1);
	switch (code)
	{
	case 1: byKeyboard(numbersLine, numbersColumn, matrix); break;
	case 2: byRandom(numbersLine, numbersColumn, matrix); break;
	default: cout << "You can use only 1 or 2"; break;
	}
	showMatrix(numbersLine, numbersColumn, matrix);

	for (int counter = 0; counter < numbersLine; counter++)
	{
		delete[] matrix[counter];
	}
	delete[] matrix;
	matrix = NULL;
}

void printMatrix()
{
	int numbersLine, numbersColumn;
	do {
		cout << "Enter the number of items per line(1-25): ";
		cin >> numbersLine;
	} while (numbersLine > 25 || numbersLine < 1);
	do {
		cout << "Enter the number of items in the column(1-25): ";
		cin >> numbersColumn;
	} while (numbersColumn > 25 || numbersColumn < 1);

	buildMatrix(numbersLine, numbersColumn);
}

void arrays()
{
	int amount, code;
	do {
		cout << "Entem a number of items: ";
		cin >> amount;
		if (amount < 1) cout << "Array size must be above one!\n";
	} while (amount < 1);
	int* array = new int[amount];

	cout << "\nChoose a way to define an integer matrix: ";
	do {
		cout << "\n-1- By keyboard\n-2- By random\nYour choise: ";
		cin >> code;
		switch (code)
		{
		case 1:
		{
			for (int counter = 0; counter < amount; ++counter)
			{
				cout << "Enter item: ";
				cin >> array[counter];
			}
			break;
		}
		case 2:
			int left_value, right_value;
			cout << "Enter the start of the line segment: ";
			cin >> left_value;
			do {
				cout << "Enter the end of the line segment: ";
				cin >> right_value;
				if (left_value >= right_value) cout << "The left value must be less than the right one!\n";
			} while (left_value >= right_value || right_value < 0);

			for (int i = 0; i < amount; ++i)
			{
				int znak = rand() % 3;
				int a;
				if (znak == 1)
					a = -1;
				else
					a = 1;
				array[i] = (rand() % ((right_value - left_value + 1) + left_value)) * a;
			}
			cout << "\n";
			for (int i = 0; i < amount; ++i)
			{
				cout << array[i] << " ";
			}
			cout << "\n";
			break;
		default:
			cout << "You can use only '1' or '2'\n";
			break;
		}
	} while (code < 1 || code > 2);

	int maxNumberOfArray = array[0];
	for (int i = 0; i < amount; ++i)
	{
		if (array[i] > maxNumberOfArray)
		{
			maxNumberOfArray = array[i];
		}
	}
	cout << "Max number = " << maxNumberOfArray << "\n";

	int minNumberOfArray = array[0];
	for (int i = 0; i < amount; ++i)
	{
		if (array[i] < minNumberOfArray)
		{
			minNumberOfArray = array[i];
		}
	}
	cout << "Min number = " << minNumberOfArray << "\n";

	int sum = 0;
	for (int counter = 0; counter < amount; counter++)
	{
		sum = sum + array[counter];
	}
	cout << "Sum of array = " << sum;

	double mediumValue = sum / amount;
	cout << "\nMedium value = " << mediumValue << "\n";

	cout << "Sorted array: ";
	for (int startIndex = 0; startIndex < amount - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < amount; ++currentIndex)
		{
			if (array[currentIndex] < array[smallestIndex])
				smallestIndex = currentIndex;
		}
		swap(array[startIndex], array[smallestIndex]);
	}
	cout << "\n";

	for (int counter = 0; counter < amount; ++counter)
		cout << array[counter] << " ";

	double median;
	if (amount % 2 == 0)
		median = (array[(amount / 2 - 1)] + array[(amount / 2)]) / 2;
	else
		median = array[(amount / 2)];
	cout << "\nMedian = " << median << "\nArray without recurring items:\n";

	int k = 0;
	for (int startIndex = 0; startIndex < amount; ++startIndex)
	{
		if (array[startIndex] != array[startIndex + 1])
		{
			cout << array[startIndex] << " ";
		}
	}

	cout << "\n\n";
	delete[] array;
}

void multiplicatMatrix()
{
	int numbersLineFirstMatrix, numbersColumnFirstMatrix, numbersLineSecondMatrix, numbersColumnSecondMatrix;
	do {
		do {
			cout << "Enter the number of items per line for first matrix(1-25): ";
			cin >> numbersLineFirstMatrix;
		} while (numbersLineFirstMatrix > 25 || numbersLineFirstMatrix < 1);
		do {
			cout << "Enter the number of items in the column for first matrix(1-25): ";
			cin >> numbersColumnFirstMatrix;
		} while (numbersColumnFirstMatrix > 25 || numbersColumnFirstMatrix < 1);

		do {
			cout << "Enter the number of items per line for second matrix(1-25): ";
			cin >> numbersLineSecondMatrix;
		} while (numbersLineSecondMatrix > 25 || numbersLineSecondMatrix < 1);
		do {
			cout << "Enter the number of items in the column for second matrix(1-25): ";
			cin >> numbersColumnSecondMatrix;
		} while (numbersColumnSecondMatrix > 25 || numbersColumnSecondMatrix < 1);
	} while (numbersColumnFirstMatrix != numbersLineSecondMatrix);

	int** matrix1 = new int* [numbersLineFirstMatrix];
	for (int i = 0; i < numbersLineFirstMatrix; i++)
	{
		matrix1[i] = new int[numbersColumnFirstMatrix];
	}

	int** matrix2 = new int* [numbersLineSecondMatrix];
	for (int i = 0; i < numbersLineSecondMatrix; i++)
	{
		matrix2[i] = new int[numbersColumnFirstMatrix];
	}

	int code;
	for (int i = 0; i < numbersLineFirstMatrix; i++)
	{
		matrix1[i] = new int[numbersColumnFirstMatrix];
	}
	cout << "\nChoose a way to define an integer matrix: ";
	do {
		cout << "\n-1- By keyboard\n-2- By random\nYour choise: ";
		code = inputNumber();
	} while (code > 2 || code < 1);

	switch (code)
	{
	case 1: byKeyboard(numbersLineFirstMatrix, numbersColumnFirstMatrix, matrix1); break;
	case 2: byRandom(numbersLineFirstMatrix, numbersColumnFirstMatrix, matrix1); break;
	default: cout << "You can use only 1 or 2"; break;
	}
	cout << "\nFirst matrix:\n";
	showMatrix(numbersLineFirstMatrix, numbersColumnFirstMatrix, matrix1);

	code = 0;
	for (int i = 0; i < numbersLineSecondMatrix; i++)
	{
		matrix2[i] = new int[numbersColumnSecondMatrix];
	}
	cout << "\nChoose a way to define an integer matrix: ";
	do {
		cout << "\n-1- By keyboard\n-2- By random\nYour choise: ";
		code = inputNumber();
	} while (code > 2 || code < 1);

	switch (code)
	{
	case 1: byKeyboard(numbersLineSecondMatrix, numbersColumnSecondMatrix, matrix2); break;
	case 2: byRandom(numbersLineSecondMatrix, numbersColumnSecondMatrix, matrix2); break;
	default: cout << "You can use only 1 or 2"; break;
	}
	cout << "\nSecond matrix:\n";
	showMatrix(numbersLineSecondMatrix, numbersColumnSecondMatrix, matrix2);

	int** newMatrix;
	newMatrix = new int* [numbersLineFirstMatrix];
	for (int i = 0; i < numbersLineFirstMatrix; i++)
	{
		newMatrix[i] = new int[numbersColumnSecondMatrix];
		for (int j = 0; j < numbersColumnSecondMatrix; j++)
		{
			newMatrix[i][j] = 0;
			for (int k = 0; k < numbersColumnFirstMatrix; k++)
				newMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
		}
	}

	cout << "New matrix:\n";
	for (int i = 0; i < numbersLineFirstMatrix; i++)
	{
		for (int j = 0; j < numbersColumnSecondMatrix; j++)
		{
			cout << setw(4) << newMatrix[i][j];
		}
		cout << "\n";
	}

	for (int i = 0; i < numbersLineFirstMatrix; i++)
	{
		delete[] newMatrix[i];
	}
	delete[] newMatrix;
	newMatrix = NULL;

	for (int i = 0; i < numbersLineFirstMatrix; i++)
	{
		delete[] matrix1[i];
	}
	delete[] matrix1;
	matrix1 = NULL;

	for (int i = 0; i < numbersLineSecondMatrix; i++)
	{
		delete[] matrix2[i];
	}
	delete[] matrix2;
	matrix1 = NULL;
}

void medianMatrixAndMinMax()
{
	int numberLine, numberColumn;
	do {
		cout << "Enter the number of items per line(1-25): ";
		numberLine = inputNumber();
	} while (numberLine > 25 || numberLine < 1);
	do {
		cout << "Enter the number of items in the column(1-25): ";
		numberColumn = inputNumber();
	} while (numberColumn > 25 || numberColumn < 1);

	int code, columnIndex, lineIndex, k = 0;
	int** matrix = new int* [numberLine];
	int* array = new int[numberLine * numberColumn];
	for (int i = 0; i < numberLine; i++)
	{
		matrix[i] = new int[numberColumn];
	}

	cout << "\nChoose a way to define an integer matrix: ";
	do {
		cout << "\n-1- By keyboard\n-2- By random\nYour choise: ";
		cin >> code;
	} while (code > 2 || code < 1);
	switch (code)
	{
	case 1: byKeyboard(numberLine, numberColumn, matrix); break;
	case 2:
		int left_value, right_value;
		cout << "Enter the start of the line segment: ";
		cin >> left_value;

		do {
			cout << "Enter the end of the line segment: ";
			cin >> right_value;
			if (right_value <= left_value) cout << "The left value must be less than the right one!" << endl;
		} while (right_value <= left_value);

		for (int counterLine = 0; counterLine < numberLine; counterLine++)
		{
			for (int counterColumn = 0; counterColumn < numberColumn; counterColumn++)
			{
				int znak = rand() % 3;
				int a;
				if (znak == 1)
					a = -1;
				else
					a = 1;
				matrix[counterLine][counterColumn] = (rand() % (right_value - left_value + 1) + left_value) * a;
				array[k] = matrix[counterLine][counterColumn];
				k++;
			}
		}
		break;
	default: cout << "You can use only 1 or 2"; break;
	}
	showMatrix(numberLine, numberColumn, matrix);

	for (int startIndex = 0; startIndex < (numberLine * numberColumn) - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < (numberLine * numberColumn); ++currentIndex)
		{
			if (array[currentIndex] < array[smallestIndex])
				smallestIndex = currentIndex;
		}
		swap(array[startIndex], array[smallestIndex]);
	}
	cout << "\n";

	k = 0;
	for (int i = 0; i < numberLine; i++)
	{
		for (int j = 0; j < numberColumn; j++)
		{
			matrix[i][j] = array[k];
			k++;
		}
	}

	cout << "Sorted matrix:""\n\n";
	showMatrix(numberLine, numberColumn, matrix);

	double median;
	if (numberLine % 2 == 1 && numberColumn % 2 == 1)
	{
		median = matrix[numberLine / 2][numberColumn / 2];
	}
	else if (numberLine % 2 == 1 && numberColumn % 2 == 0)
	{
		median = (matrix[numberLine / 2][numberColumn / 2] + matrix[numberLine / 2][numberColumn / 2 - 1]) / 2.;
	}
	else if (numberLine % 2 == 0 && numberColumn % 2 == 1)
	{
		median = (matrix[numberLine / 2][numberColumn / 2] + matrix[numberLine / 2 - 1][numberColumn / 2]) / 2.;
	}
	else
	{
		median = (matrix[numberLine / 2][numberColumn / 2] + matrix[numberLine / 2][numberColumn / 2 - 1] +
			matrix[numberLine / 2][numberColumn / 2] + matrix[numberLine / 2 - 1][numberColumn / 2]) / 4.;
	}
	cout << "Median of matrix = " << median << "\n";

	
	cout << "Max number = " << array[0] << "\n";
	cout << "Min number = " << array[numberLine * numberColumn - 1] << "\n";

	for (int i = 0; i < numberLine; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] array;
	matrix = NULL;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int toggle;
	while (true) {
		do {
			cout << "________________________________________________________________________________________________________________________\n" <<
				"Press key to continue(1-4)\n" << "-1- Print matrix\n" << "-2- All tasks with arrays\n"
				<< "-3- Multiplication matrices\n" << "-4- Matrix median and Max Min element\n" << "-0- Exit\n" << "Your choise: ";
			toggle = inputNumber();
		} while (toggle > 5 || toggle < 0);
		cout << "\n";
		switch (toggle)
		{
		case 0:
			return 0;
		case 1:
			printMatrix();
			break;
		case 2:
			arrays();
			break;
		case 3:
			multiplicatMatrix();
			break;
		case 4:
			medianMatrixAndMinMax();
			break;
		default:
			cout << "You can use only 0-4! Try again\n";
		}
	}
	system("pause");
	return 0;
}