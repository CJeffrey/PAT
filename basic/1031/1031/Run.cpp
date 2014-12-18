#include <iostream>
#include <string.h>
const int dataSize = 18;
const int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
const char z2m[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
class IDCard{
public:
	IDCard(){
		memset(data,0,dataSize+1);
	}
	char data[dataSize+1];
};

int main(){
	int num;
	scanf("%d",&num);
	IDCard *cards = new IDCard[num];
	for(int i = 0;i<num;i++){
		scanf("%s",&(cards[i].data));
	}

	bool * checkResult = new bool[num];
	for(int i = 0;i<num;i++){
		int tmpSum = 0;
		checkResult[i] = true;
		char tmpChar;
		for(int j = 0;j<dataSize - 1;j++){
			tmpChar = cards[i].data[j];
			if (tmpChar < 48 || tmpChar >57){
				checkResult[i] = false;
				break;
			}
			tmpSum += int(tmpChar-48) * weight[j];
		}
		if (!checkResult[i]){
			continue;
		}
		int zValue = tmpSum%11;
		char mValue = z2m[zValue];
		char markValue = cards[i].data[17];
		if (markValue != mValue){
			checkResult[i]=false;
		}
	}

	bool allRight = true;
	for(int i = 0;i<num;i++){
		if (!checkResult[i]){
			allRight = false;
			printf("%s\n",cards[i].data);
		}
	}
	if (allRight){
		printf("%s","All passed");
	}

	delete []checkResult;
	delete []cards;
	return 0;
}