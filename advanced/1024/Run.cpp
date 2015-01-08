#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

bool isPalindromic(const string & s){
	const unsigned int totalSize = s.size();
	for(unsigned int i = 0;i<totalSize/2;i++){
		if (s[i] != s[totalSize-1-i]){
			return false;
		}
	}
	return true;
}

string plusString(const string & s1,const string &s2){
	const unsigned int totalSize = s1.size();
	string ret;
	ret.resize(totalSize);	
	int tmpSum(0);
	bool carryFlag(false);
	for(int i = totalSize -1;i>=0;i--){
		tmpSum = s1[i] + s2[i] - 48 -48;
		if (carryFlag)
			tmpSum+=1;
		if (tmpSum >= 10){
			tmpSum -=10;
			carryFlag = true;
		} else {
			carryFlag = false;
		}
		ret[i] = tmpSum+48;
	}
	if (carryFlag)
		ret = "1" + ret;
	return ret;
}

string plusSelf(const string &s){
	string newS = s;
	reverse(newS.begin(),newS.end());
	return plusString(s,newS);
}

int main(){
	string n;
	int k;
	cin >> n >> k;

	int time=k;
	if (isPalindromic(n)){
		time = 0;
	} else {
		for(int i = 1;i<=k;i++){
			n = plusSelf(n);
			if (isPalindromic(n)){
				time = i;
				break;
			}
		}
	}
	printf("%s\n%d",n.c_str(),time);
	return 0;
}