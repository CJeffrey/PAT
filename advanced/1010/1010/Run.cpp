#include <iostream>
#include <string.h>
#include <math.h>
#define MAX_DIGIT 11

int findDigit(const char * oriValue){
	int num;
	for(int i = 0;i<MAX_DIGIT;i++){
		if(oriValue[i] == 0){
			num = i;
			break;
		}
	}
	return num;
}

int char2Int(const char tmpChar){
	int tmpValue=0;
	if (tmpChar > 96){
		tmpValue = tmpChar - 87;
	} else {
		tmpValue = tmpChar - 48;
	}
	return tmpValue;
}

int change(const char * oriValue,const int myRadix){
	int num = findDigit(oriValue);
	int ret=0;
	int tmpValue;
	int tmpChar;
	for(int i = 0;i<num;i++){
		tmpChar = oriValue[i];
		tmpValue = char2Int(tmpChar);
		ret+= tmpValue * pow(double(myRadix),num-i-1);
	}
	return ret;
}

int findMinRadix(const char * oriValue){
	int num=findDigit(oriValue);

	int ret = 2;
	int tmpValue;
	int tmpChar;
	for(int i = 0;i<num;i++){
		tmpChar = oriValue[i];
		tmpValue = char2Int(tmpChar);
		ret = std::max(tmpValue+1,ret);
	}
	return ret;
}

int findStartRadix(const char * oriValue,const int referenceValue){
	int ret;
	int num=findDigit(oriValue);
	if (num <= 1){
		ret = -1;
	} else {
		int firstDig = char2Int(oriValue[0]);
		ret = pow(double(referenceValue)/(firstDig+1),1.0/(num-1));
	}
	return ret;
}

int findEndRadix(const char * oriValue,const int referenceValue){
	int ret;
	int num=findDigit(oriValue);
	
	int firstDigNum=0;
	int firstDig;
	for(;firstDigNum<num;firstDigNum++){
		firstDig = char2Int(oriValue[firstDigNum]);
		if (firstDig!=0){
			break;
		}
	}	
	if (num-firstDigNum <= 1){
		ret = -1;
	} else {
		ret = pow(double(referenceValue)/(firstDig),1.0/(num-firstDigNum-1)) + 1;
	}
	
	return ret;
}

int findEndRadix2(const char * oriValue,const int referenceValue){
	int ret = 1;
	int tmpResult(-1),lastResult(-1);
	while(tmpResult <= referenceValue){
		ret *=2;
		tmpResult = change(oriValue,ret);
		if (tmpResult == lastResult){
			return -1;
		}
		lastResult = tmpResult;
	}
	
	return ret;
}

int standardValue = -1;
char * calculateCharPtr;

int checkChange(const int myRadix){
	int ret = change(calculateCharPtr,myRadix);
	return (standardValue - ret);
}

void binarySearch(int (*myFun)(const int midValue),const int headValue,const int tailValue,int & retValue){
	if (myFun(headValue) == 0){
		if (retValue < 0){
			retValue = headValue;
		} else {
			retValue = std::min(retValue,tailValue);
		}
	}
	if (myFun(tailValue) == 0){
		if (retValue < 0){
			retValue = tailValue;
		} else {
			retValue = std::min(retValue,tailValue);
		}
	}
	int tmpHead = headValue;
	int tmpTail = tailValue;
	int midValue;
	int tmpResult;
	int lastResult = -1;
	while(tmpTail - tmpHead > 1){
		midValue = (tmpHead + tmpTail)/2;
		tmpResult = myFun(midValue);
		if (tmpResult == lastResult){
			return;
		}
		lastResult = tmpResult;
		if (tmpResult == 0){
			if (retValue < 0){
				retValue = midValue;
			} else {
				retValue = std::min(retValue,midValue);
			}
			tmpTail = midValue;
		} else if (tmpResult > 0){
			tmpHead = midValue;
		} else {
			tmpTail = midValue;
		}
	}
}

int main(){
	char * oriValue1,*oriValue2;
	oriValue1 = new char[MAX_DIGIT];
	oriValue2 = new char[MAX_DIGIT];
	memset(oriValue1,0,MAX_DIGIT);
	memset(oriValue2,0,MAX_DIGIT);
	int tag,tagRadix;
	scanf("%s %s %d %d",oriValue1,oriValue2,&tag,&tagRadix);
	
	if (tag == 2){
		std::swap(oriValue1,oriValue2);
	}

	int changeValue1 = change(oriValue1,tagRadix);
	standardValue = changeValue1;
	calculateCharPtr = oriValue2;
	int changeValue2;
	int changeResult = -1;
	int lastChangeValue2=-1;

	int minRadix = findMinRadix(oriValue2);
	//int startRadix = findStartRadix(oriValue2,changeValue1);

	int runStartRadix = minRadix;

	int endRadix = findEndRadix2(oriValue2,changeValue1);
	int runEndRadix = std::max(runStartRadix+1,endRadix);

	bool binarySearchResult(false);
	binarySearch(checkChange,runStartRadix,runEndRadix,changeResult);
	if (changeResult > 0){
		binarySearchResult = true;
	}


	/*int tmpResult(-1),lastResult(-1);
	for(changeResult = runStartRadix;;changeResult++){
		tmpResult = change(oriValue2,changeResult);
		if (tmpResult == lastResult){
			break;
		}
		lastResult = tmpResult;
		if (tmpResult > changeValue1){
			break;
		}
		if (tmpResult == changeValue1){
			binarySearchResult = true;
			break;
		}
	}*/

	if (!binarySearchResult){
		printf("%s","Impossible");
	} else {
		printf("%d",changeResult);
	}
	return 0;
}