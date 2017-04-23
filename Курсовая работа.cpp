// Осуществление тестирования персонала

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <conio.h> // для отчистки консоли

using namespace std;
///////////////////////////////////////////////////////////////////////
int Logon(){ // вход в систему
	string answer;
	cout << "ВВЕДИТЕ ИМЯ ПОЛЬЗОВАТЕЛЯ (user/admin): "; cin >> answer;
	system("cls");
	if (answer == "user"){return 1;}
	else if (answer == "admin"){return 2;}
	else {return 0;} // ошибка при вводе
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
	char sex; // пол (ж/м)
public:
	Person(){ //конструктор
		cout << "ВВОД ЛИЧНЫХ ДАННЫХ" << endl;
		cout << " Введите фамилию: "; cin >> full_name.surname;
		cout << " Введите имя: "; cin >> full_name.name;
		cout << " Введите отчество: "; cin >> full_name.patronymic;
		cout << " Введите свой возраст: "; cin >> age;
		cout << " Введите пол (м/ж): "; cin >> sex;
		system("cls");
		cout << "Добро пожаловать, " << full_name.name << ' ' << full_name.patronymic << '!' << endl;
	};

	virtual int Menu(){
		cout << "\nМЕНЮ" << endl;
		cout << " 1. Пройти тест \"Какова ценность Вас как работника?\"" << endl;
		cout << " 2. Пройти тест  \"Динамичный ли Вы человек?\"" << endl;
		cout << " 3. Пройти тест  \"Обладаете ли Вы наблюдательностью?\"" << endl;

		cout << " 4. Не проходить тесты." << endl;

		int answer;
		cout << "Ответ: "; cin >> answer;
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
				cout << "\nВАШ ОТВЕТ: "; cin >> answer;
				if (answer == 1){points +=first_answer_point;}
				else if (answer == 2){points +=second_answer_point;}
				else if (answer == 3){points +=third_answer_point;}
				else {points +=0;};
				count = 0;
				system("cls");
			}
		}
		cout << "Результат: " << points;
		test.close();
		return points;
	}

	int TestResults(){
		cout << "Как вы хотите вывести результаты теста?" << endl;
		cout << " 1. Показать результаты в консоли" << endl;
		cout << " 2. Сохранить результаты в файл" << endl;
		cout << " 3. Закончить тест без вывода/сохранения результатов" << endl;
		cout << "\nОтвет: "; cin >> answer;
		return answer;
	}

	void YourResults(){ //Вывод результатов из файла в консоль
		while (getline(result, line)){
			cout << "ВАШИ РЕЗУЛЬТАТЫ\n" << endl;
			cout << line << endl;
		}
		result.close();
	}
};

//////////////////////////////////////////////////////////////////////
class Test1: public Test{ //прохождение первого теста (1 пункт пользовательского меню)

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
	
	if (answer == 0) {cout << "Ошибка в имени пользователя." << endl;}
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
