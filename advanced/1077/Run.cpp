#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string findCommon(const string & s1, const string &s2){
	//int minSize = min(s1.size(),s2.size());
	int counter1,counter2;
	for(counter1 = int(s1.size())-1,counter2=int(s2.size())-1;counter1>=0 && counter2>=0;counter1--,counter2--){
		if (s1[counter1] != s2[counter2])
			break;
	}
	string ret = s1.substr(counter1+1,s1.size()-counter1);
	return ret;
}

int main(){
	int n;
	scanf("%d\n",&n);
	string tmpS;
	queue<string> data;
	for(int i = 0;i<n;i++){
		getline(cin,tmpS);
		data.push(tmpS);
	}

	string s1,s2;
	while(data.size() > 1){
		s1 = data.front();
		data.pop();
		s2 = data.front();
		data.pop();
		tmpS = findCommon(s1,s2);
		data.push(tmpS);
	}

	tmpS = data.front().c_str();
	if (tmpS.empty()){
		printf("%s","nai");
	} else {
		printf("%s",tmpS.c_str());
	}
	
	return 0;
}