#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "Vector.h"
#include "Student1.h"
using namespace std;


int main()
{


	Student st1("Ivan", 20);
	Student st2("Petur", 20);

	Vector<Student> students;
	students.push_back(st1);
	students.push_back(st2);

	Vector<int> v1;

	v1.push_back(1);
	v1.push_back(13);
	v1.push_back(37);
	v1.push_back(73);
	v1.push_back(121);
	v1.push_back(181);
	v1.push_back(253);

	cout << v1.back() << endl; //253

	v1.pop_back();

	cout << v1.back() << endl; //181
	cout << v1[4] << endl; //121
	v1.push_back(777);

	//Извежда 1 13 37 73 121 181 777
	for (auto it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	Vector<string> v2;
	v2.push_back("Aut viam");
	v2.push_back("inveniam");
	v2.push_back("aut faciam");

	//Извежда Aut viam inveniam aut faciam
	for (auto it = v2.begin(); it != v2.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	Vector<string> v3;
	v3.push_back("Aut");
	v3.push_back("vincere");
	v3.push_back("mori");

	v3.insert(2, "aut");

	//Извежда Aut vincere aut mori
	for (auto it = v3.begin(); it != v3.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	v3.erase(0);

	//Извежда vincere aut mori
	for (auto it = v3.begin(); it != v3.end(); ++it)
	{
		cout << *it << " ";
	}
	v3.clear();

	system("pause");
	return 0;
}
