#include <iostream>
#include <string>
#include <fstream>
#include "rusinconsole.h"
#include "userdata.hpp"
using namespace std;
/*
1: Register
2: Login
1 - запросить username и password создать файл с именем username
	содержащий две строки в формате 
	username: строка
	password: строка
	если файл с именем username существует - выдать ошибку
2- 	запросить username и password, открыть файл с именем username
	проверить совпадает ли password с записанным в файле
	если совпадает - ок, иначе ошибка 
	если файл не существует - ошибка

данные храняться в объекте класса user который имеет методы файлового ввода-вывода (опционально)
*/


inline bool exists_test (const string& name) {
    ifstream f(name.c_str());
    return f.good();
}



int Menu();
int Register();
int Login();
int Exiting();

void getname(string &nm){
	string buf;
	cin >> buf;
	nm = buf;
	while(cin.peek()!='\n'){
		cin>>buf;
		nm = nm + " " + buf;
	}
}

int main(int argc, char* argv[]){
	if(argc==2) cout << "Hello "<<argv[1]<<"\nПривет "<<argv[1]<<endl;
	else cout << "Hello World!\nПривет Мир!\n";
	int i;
	do{
		i = Menu();
		system("cls");
		cout << "your choise: " << i << endl;
		switch(i){
			case 1:
				Register();
				break;
			case 2:
				Login();
				break;
			case 3:
				Exiting();
				break;
		}
	}while(i!=3);
	cout << "Exiting..." << endl;
	userdata ud;
	cout << "ud name: " << ud.showname() << " ud pass: " << ud.showpass() << endl;
	return 0;
}

int Menu(){
	string temp;
	do{
	cout << "Enter your choice:\n";
	cout << "\t1: Register\n";
	cout << "\t2: Login\n";
	cout << "\t3: Exit\n>>";
	cin >> temp;
	}while(!(string("1")<=temp&&temp<=string("3")));
	return stoi( temp );
}

int Register(){
	ofstream f;
	cout<<"Register work\n";
	cout<<"enter name:\n>>";
	string name, pass, path;
	//cin>>name;
	getname(name);
	path="./../data/"+name;
	if (exists_test(path)){
		cout << "user alredy registred!\n"; 
		return -1;
	}else{
		f.open(path.c_str());
	}
	cout<<"enter pass:\n>>";
	cin>>pass;
	userdata ud(name, pass);
	f<<ud;
	return 0;
}

int Login(){
	cout<<"Login work\n";
	return 0;
}

int Exiting(){
	cout<<"Exiting work\n";
	return 0;
}

