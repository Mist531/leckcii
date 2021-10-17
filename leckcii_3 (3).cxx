#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	system("chcp 1251");
	string a;
	cout << "Введите текст:";
	getline(cin, a);
	istringstream stream(a);
	map<string, int> m;
	for (string as; stream >> as; ++m[as])
		;
	vector<pair<string, int>> v;
	for (auto it = m.begin(); it != m.end(); ++it)
	{
		v.push_back(*it);
	}
	sort(v.begin(), v.end(), [](pair<string, int> first, pair<string, int> second) {
		return first.second > second.second;
	});
	cout << "Cлово: " << v.begin()->first << ", встречалось " << v.begin()->second << " раз" << endl;
}
