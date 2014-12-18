#include <iostream>
#include <string>

using namespace std;

int day=-1;
int hour=-1;
int minute=-1;

int positionA=0;
string dayList[7] ={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int switchType(char c){
	if (c>=48&&c<=58)
		return 1;
	if (c>64 && c<=90)
		return 2;
	if (c>96 && c<=122)
		return 3;

	return -1;
}

void findA1(string s1,string s2){
	int size = min(s1.size(),s2.size());
	for(int i = 0;i<size;i++){
		if (s1[i] == s2[i]){
			char tmpChar = s1[i];
			switch(switchType(tmpChar)){
				case 2:
					day = tmpChar-64;
					break;
				default:
					continue;
			}
			if (day>7)
				continue;

			positionA = i+1;
			break;
		}
	}
}

void findA2(string s1,string s2){
	int size = min(s1.size(),s2.size());
	for(int i = positionA;i<size;i++){
		if (s1[i] == s2[i]){
			char tmpChar = s1[i];
			switch(switchType(tmpChar)){
				case 2:
					hour = tmpChar-64+9;
					break;
				case 1:
					hour = tmpChar-48;
					break;
				default:
					continue;
			}
			if (hour>23)
				continue;

			break;
		}
	}
}

void findB(string s1,string s2){
	int size = min(s1.size(),s2.size());
	for(int i = 0;i<size;i++){
		if (s1[i] == s2[i]){
			int type = switchType(s1[i]);
			if (type!=2 && type!=3)
				continue;
			minute=i;
			break;
		}
	}
}


int main(){
	string sa1,sa2,sb1,sb2;
	cin >> sa1 >> sa2 >> sb1 >> sb2;
	findA1(sa1,sa2);
	findA2(sa1,sa2);
	findB(sb1,sb2);

	cout << dayList[day-1] << " ";
	printf("%02d:",hour);
	printf("%02d",minute);

	return 0;
}