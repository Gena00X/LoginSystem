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
};

#endif //USERDATA_H