#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void addText(string &a)
{
	string b;
	cout << "Enter text:";
	cin.ignore();
	getline(cin, b);
	a += b;
}
int main()
{
	//объявление всех переменных до switch
	string buffer = "";
	string path;
	ofstream fout;
	ifstream fin;
	string str;
	cout << "List of actions:" << endl;
	cout << "(What to enter - what does it do)" << endl;
	cout << "1 - Exiting the program" << endl;
	cout << "2 - Add text to buffer" << endl;
	cout << "3 - See what's on the record" << endl;
	cout << "4 - Translate text to uppercase" << endl;
	cout << "5 - Translate text to lowercase" << endl;
	cout << "6 - Delete entered text from baff" << endl;
	cout << "7 - Add the entered text to the file" << endl;
	cout << "8 - Output the file" << endl;
	while (true)
	{
		char z;
		cout << "Enter action: ";
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
			addText(buffer);
			break;
		}
		case '3':
		{
			cout << buffer << endl;
			break;
		}
		case '4':
		{
			int i = 0;
			while (buffer[i])
			{
				buffer[i] = toupper(buffer[i]);
				i++;
			}
			break;
		}
		case '5':
		{
			int i = 0;
			while (buffer[i])
			{
				buffer[i] = tolower(buffer[i]);
				i++;
			}
			break;
		}
		case '6':
		{
			buffer = "";
			break;
		}
		case '7':
		{
			cout << "If you do not know which file to specify, enter 1, it will be automatically created File.txt" << endl;
			cout << "Enter a file name:" << endl;
			cin >> path;
			if (path == "1")
			{
				path = "File.txt";
				fout.open(path, ofstream::app);
				if (!fout.is_open())
				{
					cout << "File opening error" << endl;
				}
				else
				{
					fout << buffer + "\n";
					fout.close();
				}
			}
			else
			{
				fout.open(path, ofstream::app);
				if (!fout.is_open())
				{
					cout << "File opening error" << endl;
				}
				else
				{
					fout << buffer + "\n";
					fout.close();
				}
			}
			break;
		}
		case '8':
		{
			cout << "Enter a file name: ";
			cin >> path;
			fin.open(path);
			if (!fin.is_open())
			{
				cout << "File opening error" << endl;
			}
			else
			{
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
			cout << "Error" << endl;
		}
	}
}
