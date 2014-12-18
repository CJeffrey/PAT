#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define MAXSIZE 54
int main(){
	int times;
	int shufflingOrder[MAXSIZE];

	scanf("%d",&times);
	for(int i = 0;i<MAXSIZE;i++){
		scanf("%d",&shufflingOrder[i]);
	}
	for(int i = 0;i<MAXSIZE;i++){
		shufflingOrder[i]--;
	}

	string cards[MAXSIZE];
	string tmpS;
	for(int i =0;i<MAXSIZE - 2;i++){
		tmpS = "";
		int flag = i/13;
		stringstream ss;
		ss << int((i%13 + 1));
		ss >> tmpS;
		switch(flag){
			case 0:
				tmpS = "S" + tmpS;
				break;
			case 1:
				tmpS = "H" + tmpS;
				break;
			case 2:
				tmpS = "C" + tmpS;
				break;
			case 3:
				tmpS = "D" + tmpS;
				break;
		}
		cards[i] = tmpS;
	}
	cards[MAXSIZE-2] = "J1";
	cards[MAXSIZE-1] = "J2";

	int record[MAXSIZE];
	for (int i = 0;i<MAXSIZE;i++){
		record[i] = i;
	}

	int backUPRecord[MAXSIZE];
	for(int i = 0;i<times;i++){
		for(int j = 0;j<MAXSIZE;j++){
			backUPRecord[j] = record[j];
		}
		for(int j = 0;j<MAXSIZE;j++){
			record[shufflingOrder[j]] = backUPRecord[j];
		}
	}
	for(int i = 0;i<MAXSIZE;i++){
		printf("%s",cards[record[i]].c_str());
		//cout << cards[record[i]];
		if (i+1 != MAXSIZE){
			printf("%c",' ');
		}
	}

	return 0;
}