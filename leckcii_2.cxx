#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void addText(string &a)
{
	string b;
	cout << "Введите текст:";
	cin.ignore();
	getline(cin, b);
	a += b;
}
int main()
{
	system("chcp 1251")
	cout << "Список действий:" << endl;
	cout << "(Что ввести - что делает)" << endl;
	cout << "1 - Выход из программы" << endl;
	cout << "2 - Добавить текст в baff" << endl;
	cout << "3 - Посмотреть что записано" << endl;
	cout << "4 - Перевести текс в верхний регистер" << endl;
	cout << "5 - Перевести текст в нижний регистер" << endl;
	cout << "6 - Удалить введенный текст из baff" << endl;
	cout << "7 - Добавить введённый текст в файл" << endl;
	cout << "8 - Вывести файл" << endl;
	string baff = "";
	while (true)
	{
		char z;
		cout << "Введите действие: ";
		cin >> z;
		switch (z)
		{
		case '1':
		{
			exit(0);
			break;
		}
		case '2':
		{
			addText(baff);
			break;
		}
		case '3':
		{
			cout << baff << endl;
			break;
		}
		case '4':
		{
			int i = 0;
			while (baff[i])
			{
				baff[i] = toupper(baff[i]);
				i++;
			}
			break;
		}
		case '5':
		{
			int i = 0;
			while (baff[i])
			{
				baff[i] = tolower(baff[i]);
				i++;
			}
			break;
		}
		case '6':
		{
			baff = "";
			break;
		}
		case '7':
		{
			string path;
			ofstream fout;
			cout << "Если не знаете какой файл указать, введите 1, будет автоматически создан File.txt" << endl;
			cout << "Введите название файла:" << endl;
			cin >> path;
			if (path == "1")
			{
				path = "File.txt";
				fout.open(path, ofstream::app);
				if (!fout.is_open())
				{
					cout << "Ошибка открытия файла" << endl;
				}
				else
				{
					fout << baff + "\n";
					fout.close();
				}
			}
			else
			{
				fout.open(path, ofstream::app);
				if (!fout.is_open())
				{
					cout << "Ошибка открытия файла" << endl;
				}
				else
				{
					fout << baff + "\n";
					fout.close();
				}
			}
			break;
		}
		case '8':
		{
			string path;
			ifstream fin;
			cout << "Введите название файла: ";
			cin >> path;
			fin.open(path);
			if (!fin.is_open())
			{
				cout << "Ошибка открытия файла" << endl;
			}
			else
			{
				string str;
				while (!fin.eof())
				{
					str = "";
					getline(fin, str);
					cout << str << endl;
				}
			}
			fin.close();
			break;
		}
		default:
			cout << "Ошибка" << endl;
		}
	}
}
