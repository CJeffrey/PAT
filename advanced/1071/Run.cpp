#include <iostream>
#include <map>
#include <string>

using namespace std;

bool isChar(const char c){
	if (('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c < 'z')){
		return true;
	} else {
		return false;
	}
}

char changeCase(char c){
	if ('A' <= c && c < 'Z'){
		c += 32;
	}
	return c;
}

void changeCase(string & s){
	for(unsigned int i = 0;i<s.size();i++){
		s[i] = changeCase(s[i]);
	}
}

int main(){
	string oriS;
	getline(cin,oriS);
	oriS.append(1,'\n');

	map<string,int> record;
	map<string,int>::iterator mit;
	bool startWord(false);
	string tmpS;
	for(unsigned int i = 0;i<oriS.size();i++){
		if (isChar(oriS[i])){
			if (!startWord){
				startWord = true;
				tmpS.clear();				
			}
			tmpS.append(1,oriS[i]);
		} else {
			if (startWord){
				startWord = false;
				changeCase(tmpS);
				mit = record.find(tmpS);
				if (mit == record.end()){
					record.insert(pair<string,int>(tmpS,1));
				} else {
					mit->second++;
				}
			}			
		}
	}

	pair<string,int> answer;
	answer.second = 0;
	const map<string,int>::const_iterator mitEnd(record.end());
	for(mit = record.begin();mit!=mitEnd;mit++){
		if (mit->second > answer.second){
			answer = *mit;
		}
	}

	printf("%s %d",answer.first.c_str(),answer.second);

	return 0;
}