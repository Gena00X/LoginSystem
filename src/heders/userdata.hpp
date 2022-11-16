#ifndef USERDATA_H
#define USERDATA_H
#include <iostream>
#include <string>
using namespace std;
class userdata{
string name;
string pass;
public:
	userdata(string nm="user", string ps="0000") : name(nm), pass(ps){
		
	}
	
	string showname()
	{
		return name;
	};
	string showpass()
	{
		return pass;
	};
	
	void setname(const string &n)
	{
		name=n;
	};
	void setpass(const string &p)
	{
		pass=p;
	};
	
	void show(){
		cout<<"name: "<<showname()<<"pass: "<<showpass()<<endl;
	}
	
	friend ofstream &operator<<(ofstream &fs, userdata &ud);
	friend ifstream &operator>>(ifstream &fs, userdata &ud);
};
ofstream &operator<<(ofstream &fs, userdata &ud){
	fs<<"name: "<< ud.showname()<<'\n'<<"pass: "<<ud.showpass()<<"\n\n";
}

ifstream &operator>>(ifstream &fs, userdata &ud){
	string temp;
	fs>>temp;
	if(temp==string("name:")){
		fs>>temp;
		ud.setname(temp);
		temp="";
		return fs;
	}else{
		ud.setname("name");
		ud.setpass("0000");
		return fs;
	}
	fs>>temp;
	if(temp==string("pass:")){
		fs>>temp;
		ud.setpass(temp);
		temp="";
		return fs;
	}else{
		ud.setname("name");
		ud.setpass("0000");
		return fs;
	}
}


#endif //USERDATA_H