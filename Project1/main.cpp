#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

void addData()
{
	string path = "Data.txt";
	ofstream add;
	string newData;
	add.open(path, ofstream::app|ofstream::ate);
	if (!add.is_open()) cout << "Ошибка открытия файла";
	else
	{
		cin.get();
		cout << "Введите данные: <имя студента> - <список оценок>" << endl;
		getline(cin, newData);
		add << newData<<endl;
	}
	add.close();
}
void readData()
{
	string path = "Data.txt";
	string msg;
	ifstream read;
	read.open(path,iostream::in);
	if (!read.is_open()) cout << "Ошибка чтения файла";
	else
	{
		while (!read.eof())
		{
			msg = "";
			getline(read, msg);
			cout << msg << endl;
		}
	}
	read.close();
}
void deleteData()
{
	string path = "Data.txt";
	ofstream destroy(path);
	destroy.open(path, ofstream::out | ofstream::trunc);
	if(!destroy.is_open())cout << "Ошибка удаления файла";
	destroy.close();
}
void searchData()
{
	string path = "Data.txt";
	map<string, string> data;
	string msg;
	string value;
	string dataSearch;
	ifstream search;
	search.open(path, iostream::in);
	if (!search.is_open()) cout << "Ошибка открытия файла";
	else
	{
		cout << "Ввведите имя студента: " << endl;
		cin >> dataSearch;
		while (search >> msg >> value)
		{
			data[msg] = value;
		}
		for (auto it = data.begin(); it != data.end(); ++it)
		{
			if (dataSearch==it->first) cout << it->first << "\t" << it->second << endl;
		}
	}
	search.close();
}
map<string,string> importData()  //запись данных в программу
{
	string path = "Data.txt";
	map<string, string> data;
	string msg;
	string value;
	ifstream importData;
	importData.open(path, iostream::in);
	if (!importData.is_open()) cout << "Ошибка импорта данных";
	else if (importData.peek() == EOF) cout << "Этот файл пустой" << endl;
	else
	{
		while (importData>>msg>>value)
		{
			data[msg] = value ;	
		}
		for (auto it = data.begin(); it != data.end(); ++it)
		{
			cout << it->first <<"\t" << it->second << endl;
		}
	}
	importData.close();
	return data;
}
void exportData(map<string,string> &studentData2)  
{
	string path = "Data.txt";
	ofstream exportData;
	exportData.open(path, ofstream::app | ofstream::ate);
	if (!exportData.is_open()) cout << "Ошибка открытия файла";
	else
	{
		for (auto it = studentData2.begin(); it != studentData2.end(); ++it)
		{
			exportData << it->first <<"\t" << it->second << "\n";
		}
	}
	exportData.close();
}

int main()
{
	setlocale(LC_ALL, "Rus");
	map<string, string> studentData;
	map<string, string> studentData2 = {
		{"Oleg","5454532"},
		{"Vadim","4455335"},
		{"Dimitry","3454432"},
		{"Alekcandr","4454535"},
		{"Nilolay","4454432"},
	};
	int choise;
	bool flag = false;
	do
	{
		cout << "Выберите необходимое действие" << endl
			<< "1 - Чтение данных" << endl
			<< "2 - Добавление данных" << endl
			<< "3 - Удаление данных" << endl
			<< "4 - Поиск данных" << endl
			<< "5 - Экспорт данных"<<endl
			<< "6 - Импорт данных"<<endl
			<< "7 - Выход" << endl;
		cin >> choise;
		system("pause");
		system("cls");
		switch (choise)
		{
		case 1:
			readData();
			system("pause");
			system("cls");
			break;
		case 2:
			addData();
			system("pause");
			system("cls");
			break;
		case 3:
			deleteData();
			system("pause");
			system("cls");
			break;
		case 4:
			searchData();
			system("pause");
			system("cls");
			break;
		case 5:
			exportData(studentData2);
			system("pause");
			system("cls");
			break;
		case 6:
			importData();
			system("pause");
			system("cls");
			break;
		case 7:
			flag = true;
			break;
		default:
			cout << "Ошибка! Такой операции не существует!" << endl;
			break;
		}
	} while (!flag);

	
}