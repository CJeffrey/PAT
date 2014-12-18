#include <iostream>
#include <string>

using namespace std;

int getInt(const char & c){
	return int(c-48);
}

void print1(const string s1){
	int value=getInt(s1.c_str()[0]);
	for(int i = 1;i<=value;i++){
		cout <<i;
	}
}
void print2(const string s2){
	int value=getInt(s2.c_str()[0]);
	for(int i = 0;i<value;i++){
		cout << 'S';
	}

	string s1=s2.substr(1,1);
	print1(s1);
}
void print3(const string s3){
	int value=getInt(s3.c_str()[0]);
	for(int i = 0;i<value;i++){
		cout << 'B';
	}

	string s2=s3.substr(1,2);
	print2(s2);
}

int main(){
	string oriValue;
	cin >> oriValue;
	switch(oriValue.size()){
		case 3:
			print3(oriValue);
			break;
		case 2:
			print2(oriValue);
			break;
		case 1:
			print1(oriValue);
			break;
	}


	return 0;
}