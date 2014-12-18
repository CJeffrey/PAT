#include <iostream>
#include <vector>
using namespace std;
class PartSum{
public:
	int beginPos;
	//int endPos;
	int myValue;
	int sum;
};

int main(){
	int num;
	scanf("%d",&num);

	PartSum * allNums = new PartSum[num];
	for(int i = 0;i<num;i++){
		scanf("%d",&(allNums[i].myValue));
	}

	allNums[0].beginPos = 0;
	allNums[0].sum = allNums[0].myValue;

	int maxSum = allNums[0].sum;
	int maxIndex = 0;
	for(int i = 1;i<num;i++){
		if (allNums[i-1].sum >= 0){
			allNums[i].sum = allNums[i-1].sum + allNums[i].myValue;
			allNums[i].beginPos = allNums[i-1].beginPos;
		} else {
			allNums[i].sum = allNums[i].myValue;
			allNums[i].beginPos = i;
		}
		if (allNums[i].sum > maxSum){
			maxSum = allNums[i].sum;
			maxIndex = i;
		}
	}
	
	int beginValue,endValue;
	if (maxSum < 0){
		maxSum = 0;
		beginValue = allNums[0].myValue;
		endValue = allNums[num-1].myValue;
	} else {
		beginValue = allNums[allNums[maxIndex].beginPos].myValue;
		endValue = allNums[maxIndex].myValue;
	}
	printf("%d %d %d",maxSum,beginValue,endValue);

	
	delete[]allNums;
	return 0;
}