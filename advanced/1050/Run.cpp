#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);

	set<char> eraseChar;
	for(unsigned int i = 0;i<s2.size();i++){
		eraseChar.insert(s2[i]);
	}

	char tmpChar;
	set<char>::const_iterator myEnd = eraseChar.end();
	for(unsigned int i = 0;i<s1.size();i++){
		tmpChar = s1[i];
		if (eraseChar.find(tmpChar) == myEnd){
			printf("%c",tmpChar);
		}
	}


	return 0;
}