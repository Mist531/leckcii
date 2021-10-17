#include <iostream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	string a1, b2;
	double a, b, c;
	char e;
	cout << "Введите первое число: ";
	cin >> a1;
	try
	{
		a = stod(a1);
	}
	catch (invalid_argument)
	{
		cout << "Введено неверное значение" << endl;
		exit(0);
	}
	cout << "Введите второе число: ";
	cin >> b2;
	try
	{
		b = stod(b2);
	}
	catch (invalid_argument)
	{
		cout << "Введено неверное значение" << endl;
		exit(0);
	}
	cout << "Введите дейтсвие (+,-,*,/): ";
	cin >> e;
	switch (e)
	{
	case '+':
		c = a + b;
		cout << "Полученное значение: " << c;
		break;
	case '-':
		c = a - b;
		cout << "Полученное значение: " << c;
		break;
	case '*':
		c = a * b;
		cout << "Полученное значение: " << c;
		break;
	case '/':
		if (b != 0)
		{
			c = a / b;
			cout << "Полученное значение: " << c;
			break;
		}
		else
		{
			cout << "Деление на 0 невозможно";
			return 0;
			break;
		}
	default:
		cout << "Введено неверное значение действия";
	}
}