#include <iostream>
#include <string>
using namespace std;
void proverka(double a)
{
	while (!(cin >> a))
	{
		cout << "error\n";
		cin.clear();
		fflush(stdin);
	}
}
int main()
{
	double c,a1=0,a2=0;
	char e;
	cout << "Enter the first number: ";
	proverka(a1);
	cout << "Enter the second number: ";
	proverka(a2);
	cout << "Enter action (+,-,*,/): ";
	cin >> e;
	switch (e)
	{
	case '+':
		c = a1 + a2;
		cout << "The resulting value: " << c;
		break;
	case '-':
		c = a1 - a2;
		cout << "The resulting value: " << c;
		break;
	case '*':
		c = a1 * a2;
		cout << "The resulting value: " << c;
		break;
	case '/':
		if (a2 != 0)
		{
			c = a1 / a2;
			cout << "The resulting value: " << c;
			break;
		}
		else
		{
			cout << "Division by 0 is not possible";
			return 0;
			break;
		}
	default:
		cout << "Incorrect action value entered";
	}
}
