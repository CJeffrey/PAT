#include <iostream>
#include <algorithm>

int * allNum;
int p;
int num;

int findPosition(const int startP){
	int firstNum = allNum[startP];	
	int beginPositon(startP);
	int endPostion(num);
	int quotient;
	int tmpPosition;
	while(endPostion - beginPositon >0){
		tmpPosition = (endPostion + beginPositon)/2;
		quotient = quotient = (allNum[tmpPosition] - 1)/firstNum;
		if (quotient >= p){
			endPostion = tmpPosition;
		} else {
			beginPositon = tmpPosition+1;
		}
	}
	return beginPositon;
}

int main(){
	scanf("%d%d",&num,&p);

	allNum = new int[num];
	for(int i = 0;i<num;i++){
		scanf("%d",&(allNum[i]));
	}

	std::sort(allNum,allNum+num);

	int counter = 0;

	int j;
	for(int i = 0;i<num;i++){
		j = findPosition(i);
		counter = std::max(counter,j-i);
	}
	
	printf("%d",counter);

	return 0;
}