// ������������� ������������ ���������

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h> // ��� �������� �������

using namespace std;
///////////////////////////////////////////////////////////////////////
int Logon(){ // ���� � �������
	string answer;
	cout << "������� ��� ������������ (user/admin): "; cin >> answer;
	system("cls");
	if (answer == "user"){return 1;}
	else if (answer == "admin"){return 2;}
	else {return 0;} // ������ ��� �����
};

///////////////////////////////////////////////////////////////////////
class Person{
private:
	struct PersonFullName{
		string surname;
		string name;
		string patronymic;
	} full_name;
	int age;
	char sex; // ��� (�/�)
public:
	Person(){ //�����������
		cout << "���� ������ ������" << endl;
		cout << " ������� �������: "; cin >> full_name.surname;
		cout << " ������� ���: "; cin >> full_name.name;
		cout << " ������� ��������: "; cin >> full_name.patronymic;
		cout << " ������� ���� �������: "; cin >> age;
		cout << " ������� ��� (�/�): "; cin >> sex;
		system("cls");
		cout << "����� ����������, " << full_name.name << ' ' << full_name.patronymic << '!' << endl;
	};

	virtual int Menu(){
		cout << "\n����" << endl;
		cout << " 1. ������ ���� \"������ �������� ��� ��� ���������?\"" << endl;
		cout << " 2. ������ ����  \"���������� �� �� �������?\"" << endl;
		cout << " 3. ������ ����  \"��������� �� �� �����������������?\"" << endl;

		cout << " 4. �� ��������� �����." << endl;

		int answer;
		cout << "�����: "; cin >> answer;
		system("cls");
		return answer;
	}
};

///////////////////////////////////////////////////////////////////////////////////////
class Test{
protected:
	string line;
	int count;
	int points;
	int answer;
	ifstream test;
	ifstream result;
	int line_number, first_answer_point, second_answer_point, third_answer_point;
public:
	Test(int a, int b, int c, int d): count(0), points(0), line_number(a), first_answer_point(b), second_answer_point(c), third_answer_point(d){
	};

	int TestOutput(){
		while (getline(test, line)){
			count++;
			cout << line << endl;
			if (count == line_number){
				cout << "\n��� �����: "; cin >> answer;
				if (answer == 1){points +=first_answer_point;}
				else if (answer == 2){points +=second_answer_point;}
				else if (answer == 3){points +=third_answer_point;}
				else {points +=0;};
				count = 0;
				system("cls");
			}
		}
		cout << "���������: " << points;
		test.close();
		return points;
	}

	int TestResults(){
		cout << "��� �� ������ ������� ���������� �����?" << endl;
		cout << " 1. �������� ���������� � �������" << endl;
		cout << " 2. ��������� ���������� � ����" << endl;
		cout << " 3. ��������� ���� ��� ������/���������� �����������" << endl;
		cout << "\n�����: "; cin >> answer;
		return answer;
	}

	void YourResults(){ //����� ����������� �� ����� � �������
		while (getline(result, line)){
			cout << "���� ����������\n" << endl;
			cout << line << endl;
		}
		result.close();
	}
};

//////////////////////////////////////////////////////////////////////
class Test1: public Test{ //����������� ������� ����� (1 ����� ����������������� ����)

public:
	Test1():Test(4,3,2,1){	
	}
	void TestOutput(){ 
		test.open("test1.txt");
		points = Test::TestOutput();
		test.close();
	};

	void Results1(){
		answer  = Test::TestResults();
		if (answer == 1){
			if (points >=0 && points <=15){
				result.open("rtest1result1.txt");
				Test::YourResults();
			}
			else if (points >=16 && points <=21){
				result.open("rtest1result2.txt");
				Test::YourResults();
			}
			else if (points >=22 && points <=27){
				result.open("rtest1result3.txt");
				Test::YourResults();
			}

		}
	
	}

};


 
///////////////////////////////////////////////////////////////////////
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int answer = Logon();
	
	if (answer == 0) {cout << "������ � ����� ������������." << endl;}
	else if (answer == 1) {
		Person user;
		Test* ptr[2];
		Test1 obj1;
		ptr[1]=&obj1;
		if (user.Menu() == 1) {
			obj1.TestOutput();
			obj1.Results1();
		}
	};



	cout << endl;
	system ("pause");
}
