#include <iostream>
#include <vector>
using namespace std;

void countNum(const vector<int> & data,int * ret){
	for(vector<int>::const_iterator iit = data.begin();iit<data.end();iit++){
		ret[*iit] ++;
	}
}

int main(){
	char tmpC;
	int tmpValue;
	vector<int> data;

	tmpC = getchar();
	while(tmpC != '\n'){
		tmpValue = tmpC - 48;
		data.push_back(tmpValue);
		tmpC = getchar();
	}

	int count1[10];
	int count2[10];
	for(int i =0;i<10;i++){
		count1[i]=0;
		count2[i]=0;
	}
	countNum(data,count1);
	bool carryFlag = false;
	for(vector<int>::reverse_iterator iit = data.rbegin();iit<data.rend();iit++){
		tmpValue = *iit * 2;
		if (carryFlag){
			tmpValue++;
		}
		if (tmpValue >= 10){
			carryFlag = true;
			tmpValue -=10;
		} else {
			carryFlag =false;
		}

		*iit = tmpValue;
	}
	if (carryFlag){
		printf("%s\n","No");
		printf("%d",1);
	} else {
		countNum(data,count2);
		bool isSame=true;
		for(int i = 0;i<10;i++){
			if (count1[i] != count2[i]){
				isSame = false;
				break;
			}
		}
		if (isSame){
			printf("%s\n","Yes");
		} else {
			printf("%s\n","No");
		}
	}
	for(vector<int>::const_iterator iit = data.begin();iit<data.end();iit++){
		printf("%d",*iit);
	}
	return 0;
}