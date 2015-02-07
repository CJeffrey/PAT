#include <iostream>
#include <string.h>
#include <math.h>
#define MAX_DIGIT 11

long long findDigit(const char * oriValue){
	long long num;
	for(long long i = 0;i<MAX_DIGIT;i++){
		if(oriValue[i] == 0){
			num = i;
			break;
		}
	}
	return num;
}

long long char2Int(const char tmpChar){
	long long tmpValue=0;
	if (tmpChar > 96){
		tmpValue = tmpChar - 87;
	} else {
		tmpValue = tmpChar - 48;
	}
	return tmpValue;
}

long long change(const char * oriValue,const long long myRadix){
	long long num = findDigit(oriValue);
	long long ret=0;
	long long tmpValue;
	int tmpChar;
	for(long long i = 0;i<num;i++){
		tmpChar = oriValue[i];
		tmpValue = char2Int(tmpChar);
		ret+= tmpValue * pow(double(myRadix),int(num-i-1));
	}
	return ret;
}

long long findMinRadix(const char * oriValue){
	long long num=findDigit(oriValue);

	long long ret = 2;
	long long tmpValue;
	long long tmpChar;
	for(long long i = 0;i<num;i++){
		tmpChar = oriValue[i];
		tmpValue = char2Int(tmpChar);
		ret = std::max(tmpValue+1,ret);
	}
	return ret;
}

long long findStartRadix(const char * oriValue,const long long referenceValue){
	long long ret;
	long long num=findDigit(oriValue);
	if (num <= 1){
		ret = -1;
	} else {
		long long firstDig = char2Int(oriValue[0]);
		ret = pow(double(referenceValue)/(firstDig+1),1.0/(num-1));
	}
	return ret;
}

long long findEndRadix(const char * oriValue,const long long referenceValue){
	long long ret;
	long long num=findDigit(oriValue);
	
	long long firstDigNum=0;
	long long firstDig;
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

long long findEndRadix2(const char * oriValue,const long long referenceValue){
	long long ret = 1;
	long long tmpResult(-1),lastResult(-1);
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

long long standardValue = -1;
char * calculateCharPtr;

long long checkChange(const long long myRadix){
	long long ret = change(calculateCharPtr,myRadix);
	return (standardValue - ret);
}

void binarySearch(long long (*myFun)(const long long midValue),const long long headValue,const long long tailValue,long long & retValue){
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
	long long tmpHead = headValue;
	long long tmpTail = tailValue;
	long long midValue;
	long long tmpResult;
	long long lastResult = -1;
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
	long long tag,tagRadix;
	scanf("%s %s %d %d",oriValue1,oriValue2,&tag,&tagRadix);
	
	if (tag == 2){
		std::swap(oriValue1,oriValue2);
	}

	long long changeValue1 = change(oriValue1,tagRadix);
	standardValue = changeValue1;
	calculateCharPtr = oriValue2;
	long long changeValue2;
	long long changeResult = -1;
	long long lastChangeValue2=-1;

	long long minRadix = findMinRadix(oriValue2);
	//long long startRadix = findStartRadix(oriValue2,changeValue1);

	long long runStartRadix = minRadix;

	long long endRadix = findEndRadix2(oriValue2,changeValue1);
	long long runEndRadix = std::max(runStartRadix+1,endRadix);

	bool binarySearchResult(false);
	binarySearch(checkChange,runStartRadix,runEndRadix,changeResult);
	if (changeResult > 0){
		binarySearchResult = true;
	}

	if (!binarySearchResult){
		printf("%s","Impossible");
	} else {
		printf("%d",changeResult);
	}
	return 0;
}