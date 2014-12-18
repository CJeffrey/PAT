#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int main(){
	char buffer[1024];
	char tmpChar;

	int counter = 0;
	memset(buffer,'\0',1024);

	vector<string> ss;

	for (;;){
		tmpChar = cin.get();
		if (tmpChar == ' '){
			if (counter == 0)
				continue;
			string s(buffer,counter);
			ss.push_back(s);
			counter = 0;
			memset(buffer,'\0',1024);
		} else if (tmpChar == '\n' || tmpChar == '\t'){
			string s(buffer,counter);
			ss.push_back(s);
			counter = 0;
			memset(buffer,'\0',1024);
			break;
		} else {
			buffer[counter++]=tmpChar;
		}
	}
	for(vector<string>::const_reverse_iterator sit = ss.rbegin();sit<ss.rend();sit++){
		cout << *sit;
		if (sit+1 < ss.rend())
			cout << " ";
	}
	

	return 0;
}