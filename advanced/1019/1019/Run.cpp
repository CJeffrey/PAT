#include <iostream>
#include <vector>
using namespace std;

void changeData(int n,const int b,vector<int> & data){
	data.clear();
	while( n != 0){
		int tmpData = n % b;
		n = n/b;
		data.push_back(tmpData);
	}
	if (data.empty()){
		data.push_back(n);
	}
}

bool checkData(const vector<int> & data){
	int dataSize = data.size();
	bool ret = true;
	for(int i = 0;i<= dataSize/2;i++){
		if (data[i] != data[dataSize-1-i]){
			ret = false;
			break;
		}
	}
	return ret;
}

int main(){
	int n,b;
	scanf("%d%d",&n,&b);

	vector<int> changeResult;
	changeData(n,b,changeResult);
	bool isPalindromic = checkData(changeResult);

	if (isPalindromic){
		printf("%s\n","Yes");
	} else {
		printf("%s\n","No");
	}
	for(vector<int>::const_reverse_iterator iit = changeResult.rbegin();;iit++){
		printf("%d",*iit);
		if (iit + 1 != changeResult.rend()){
			printf("%c",' ');
		} else {
			break;
		}
	}


	return 0;
}