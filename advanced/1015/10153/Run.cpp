#include <iostream>
#include <math.h>
#include <string.h>
#define MAX_CHANGE_DIGIT 32

int findDigit(const char * oriValue){
	int num;
	for(int i = 0;i<MAX_CHANGE_DIGIT;i++){
		if(oriValue[i] == 0){
			num = i;
			break;
		}
	}
	return num;
}

int change(const char * oriValue,const int myRadix){
	int num = findDigit(oriValue);
	int ret=0;
	int tmpValue;
	int tmpChar;
	for(int i = 0;i<num;i++){
		tmpChar = oriValue[i];
		tmpValue = tmpChar - 48;
		ret+= tmpValue * pow(double(myRadix),num-i-1);
	}
	return ret;
}

void reChange(int oriValue,char * result,const int myRadix){
	char * tmpChar = new char[MAX_CHANGE_DIGIT];
	memset(tmpChar,0,MAX_CHANGE_DIGIT);
	int quotient,remainder;
	int counter=0;
	while(true){
		quotient = oriValue / myRadix;
		remainder = oriValue % myRadix;
		tmpChar[counter++] = remainder+48;
		if (quotient == 0){
			break;
		} else {
			oriValue = quotient;
		}
	}
	memset(result,0,MAX_CHANGE_DIGIT);
	for(int i = 0;i<counter;i++){
		result[i] = tmpChar[counter - 1 - i];
	}
}

void reverseChar(const char * oriChar,char * newChar){
	int num = findDigit(oriChar);
	for(int i = 0;i<num;i++){
		newChar[i] = oriChar[num-1-i];
	}
}

bool * primes;

void generatePrimes(){
	int maxPrime = 100000;
	primes = new bool [maxPrime];
	primes[0] = false;
	primes[1] = false;
	for(int i = 2;i<maxPrime;i++){
		primes[i] = true;
	}
	int tmpValue;
	int j;
	for(int i = 2;i<maxPrime;i++){
		if (!primes[i]){
			continue;
		}
		//std::cout << i << std::endl;
		tmpValue = i + i;
		while(tmpValue<maxPrime){
			primes[tmpValue] = false;
			tmpValue += i;
		}
	}
}

int main(){
	generatePrimes();
	int num,myRadix;
	char oriNum[MAX_CHANGE_DIGIT];
	char reverseNum[MAX_CHANGE_DIGIT];
	int num1,num2;

	while(true){
		scanf("%d",&num);
		if (num < 0)
			break;
		scanf("%d",&myRadix);
		memset(oriNum,0,MAX_CHANGE_DIGIT);
		memset(reverseNum,0,MAX_CHANGE_DIGIT);
		reChange(num,oriNum,myRadix);
		reverseChar(oriNum,reverseNum);
		num1 = change(oriNum,myRadix);
		num2 = change(reverseNum,myRadix);
		if (primes[num1] && primes[num2]){
			printf("%s\n","Yes");
		} else {
			printf("%s\n","No");
		}
	}
	return 0;
}