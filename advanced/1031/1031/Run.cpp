#include <iostream>
#include <math.h>
#include <string.h>
int main(){
	char * oriChar = new char[81];
	memset(oriChar,0,81);

	scanf("%s",oriChar);
	int n;
	for(n = 0;n<81;n++){
		if(oriChar[n] == 0){
			break;
		}
	}

	int myType = n % 3;
	int myNum = n / 3;

	int n1,n2;
	switch(myType){
		case 0:
			n1 = myNum - 1;
			break;
		case 1:
			n1 = myNum;
			break;
		case 2:
			n1 = myNum;
			break;
	}
	n2 = n-n1*2;

	for(int i = 0;i<n1;i++){
		printf("%c",oriChar[i]);
		for(int j = 0;j<n2-2;j++){
			printf("%c",' ');
		}
		printf("%c\n",oriChar[n-1-i]);
	}
	for(int i = 0;i<n2;i++){
		printf("%c",oriChar[n1+i]);
	}

	delete []oriChar;
	return 0;
}