#include <iostream>
#include <math.h>

char symbol;

int findMax(const int total){
	int ret = sqrt(double((total+1)*2)) - 1;
	if (pow(double(ret+1),2) > (2*(total+1))){
		ret--;
	}
	if (ret %2 ==0)
		ret--;
	return ret;
}

void printLine(const int maxNum,const int lineNum){
	const int blankNum = (maxNum - lineNum)/2;
	for(int i = 0;i<blankNum;i++){
		printf("%c",' ');
	}
	for(int i = 0;i<lineNum;i++){
		printf("%c",symbol);
	}
/*
	for(int i = 0;i<blankNum;i++){
		printf("%c",' ');
	}*/
	printf("%c",'\n');
}

void printAll(const int maxNum){
	for(int i = maxNum;i>1;i-=2){
		printLine(maxNum,i);
	}
	for(int i = 1;i<=maxNum;i+=2){
		printLine(maxNum,i);
	}
}

int main(){
	int total;
	scanf("%d %c",&total,&symbol);

	int maxNum = findMax(total);
	//printf("%d%c",maxNum,symbol);
	int usedNum = (maxNum+1)*(maxNum+1)/2-1;
	printAll(maxNum);
	printf("%d",total-usedNum);

	return 0;
}