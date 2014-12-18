#include <string>
#include <iostream>
using namespace std;

int findNum(const string s,const int num){
	int counter = 0;
	for(unsigned int i = 0;i<s.size();i++){
		if (s[i] == num+48){
			counter++;
		}
	}
	return counter;
}

string makeNum(int num,int counter){
	string ss;
	for(int i = 0;i<counter;i++){
		ss.push_back(num+48);
	}
	return ss;
}

int main(){
	string s1,s2;
	int num1,num2;
	cin >> s1 >> num1 >> s2 >> num2;

	int counter1,counter2;
	counter1 = findNum(s1,num1);
	counter2 = findNum(s2,num2);

	string str1,str2;
	str1 = makeNum(num1,counter1);
	str2 = makeNum(num2,counter2);

	if (str1.empty())
		str1 = "0";
	if (str2.empty())
		str2 = "0";
	int i1 = atoi(str1.c_str());
	int i2 = atoi(str2.c_str());

	cout << i1+i2;

	return 0;
}