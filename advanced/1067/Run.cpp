#include <iostream>

int main(){
	int n;
	scanf("%d",&n);
	int * allNums = new int[n];
	for(int i = 0;i<n;i++){
		scanf("%d",allNums+i);
	}

	bool * checkFlag = new bool[n];
	for(int i = 0;i<n;i++){
		checkFlag[i] = false;
	}
	int counter = 0;
	int pos;
	for(int i = 0;i<n;i++){
		if (!checkFlag[i] && allNums[i] != i){
			counter++;
			pos = i;
			while(!checkFlag[pos]){
				counter++;
				checkFlag[pos] = true;
				pos = allNums[pos];
			}
		}
	}
	if (allNums[0] != 0)
		counter-=2;

	printf("%d",counter);

	delete []checkFlag;
	delete []allNums;
	return 0;
}