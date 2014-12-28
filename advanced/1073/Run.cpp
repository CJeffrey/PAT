#include <iostream>
#include <string.h>
#define MAXSIZE 10001
int main(){
	char * oriValue = new char[MAXSIZE];
	memset(oriValue,0,MAXSIZE);

	scanf("%s",oriValue);

	int i1Begin(-1);
	int i1End(-1);
	int dotPosition(-1);
	int i2Begin(-1);
	int i2End(-1);
	bool i2isPositive;
	int tmpCharValue;
	for(int i = 1;i<MAXSIZE;i++){
		tmpCharValue = oriValue[i];
		if (tmpCharValue == 0){
			i2End = i -1;
			break;
		}
		if (tmpCharValue == '.')
			dotPosition = i;
		else if (tmpCharValue >=48 && tmpCharValue < 58){
			if (i1Begin == -1)
				i1Begin = i;
			else if (i1End == -1)
				;
			else if (i2Begin == -1)
				i2Begin = i;
		} else if (tmpCharValue == '+'){
			i2isPositive = true;
		} else if (tmpCharValue == '-'){
			i2isPositive = false;
		} else if (tmpCharValue == 'E'){
			i1End = i-1;
		}
	}

	if (i2End == -1)
		i2End = i2Begin;

	int indexValue = atoi(oriValue+i2Begin);
	int newDot=dotPosition;
	if (i2isPositive){
		newDot += indexValue;
	} else {
		newDot -= indexValue;
	}

	if ((oriValue[0]) == '-')
		printf("%c",oriValue[0]);

	if (newDot <= i1Begin){
		printf("%s","0.");
		for(int i = 0;i<i1Begin - newDot;i++){
			printf("%d",0);
		}
		for(int i = i1Begin;i<=i1End;i++){
			if(i == dotPosition)
				continue;
			else
				printf("%c",oriValue[i]);
		}
	} else if (i1Begin < newDot && newDot <=i1End){
		int adjust = 0;
		bool printDotFlag(false);
		for(int i = i1Begin;i<=i1End;i++){
			if ((i == (newDot + adjust)) && !printDotFlag){
				printf("%c",'.');
				printDotFlag = true;
			}
			if (i == dotPosition){
				adjust = 1;
				continue;
			} else {
				printf("%c",oriValue[i]);
			}
		}
	} else if (newDot > i1End){
		for(int i = i1Begin;i<=i1End;i++){
			if (i == dotPosition)
				continue;
			else {
				printf("%c",oriValue[i]);
			}
		}
		for(int i = 0;i<newDot - i1End;i++){
			printf("%c",48);
		}
	}
	


	delete []oriValue;
	return 0;
}