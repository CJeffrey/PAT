#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(){
	string badKey;
	getline(cin,badKey);

	set<char> badChar;
	char tmpChar;
	for(unsigned int i = 0;i<badKey.size();i++){
		tmpChar = badKey[i];
		if (tmpChar >= 48 && tmpChar <=57){
			badChar.insert(tmpChar);
		} else if (tmpChar >=65 && tmpChar <=90){
			badChar.insert(tmpChar);
			badChar.insert(tmpChar + 32);
		} else if (tmpChar == '_'){
			badChar.insert('_');
		} else if (tmpChar == '+'){
			for (int j = 65;j<=90;j++){
				badChar.insert(j);
			}
		} else {
			badChar.insert(tmpChar);
		}
	}

	string oriData;
	getline(cin,oriData);
	for(unsigned int i = 0;i<oriData.size();i++){
		tmpChar = oriData[i];
		if (badChar.find(tmpChar) == badChar.end()){
			printf("%c",tmpChar);
		}
	}
	printf("%c",'\n');
	return 0;
}