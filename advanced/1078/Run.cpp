#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int getPrime(const int lowerLimit){
	vector<int> alreadyUsed;
	vector<int>::const_iterator iit,iitEnd;
	
	bool flag;
	int i = 2;
	while(i < lowerLimit){
		alreadyUsed.push_back(i);
		while(true){
			++i;
			flag = true;
			for(iit=alreadyUsed.begin(),iitEnd=alreadyUsed.end();iit!=iitEnd;iit++){
				if (*iit * *iit > i){
					flag = true;
					break;
				}
				if (i % (*iit) == 0){
					flag = false;
					break;
				}
			}
			if (flag)
				break;
		}
	}
	return i;
}

int main(){
	int n,lowerLimit;
	scanf("%d%d",&lowerLimit,&n);

	int myPrime = getPrime(lowerLimit);

	vector<bool> mark;
	mark.resize(myPrime,false);

	int tmpValue;
	int hashValue;
	for(int i = 0;i<n;i++){
		scanf("%d",&tmpValue);
		hashValue = tmpValue % myPrime;
		if (mark[hashValue]){
			bool hasPrinted(false);
			for(int i = 1;i<myPrime;i++){
				int newPos = (hashValue + i * i) % myPrime;
				if (newPos >= myPrime)
					break;
				if (mark[newPos] == false){
					mark[newPos] = true;
					printf("%d",newPos);
					hasPrinted=true;
					break;
				}
			}
			if (!hasPrinted)
				printf("-");
		} else {
			printf("%d",hashValue);
			mark[hashValue] = true;
		}
		if (i + 1 != n)
			printf(" ");
	}

	return 0;
}