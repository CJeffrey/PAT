#include <iostream>
#include <algorithm>
using namespace std;

void getNum(const int num,int &num1,int &num2){
	char num2char[5];num2char[4]=0;
	char rnum2char[5];rnum2char[4]=0;

	sprintf(num2char,"%04d",num);
	sort(num2char,num2char+4);
	
	for(int i=0;i<4;i++){
		rnum2char[i] = num2char[3-i];
	}

	num1 = atoi(rnum2char);
	num2 = atoi(num2char);
}

int main(){
	int num;
	scanf("%d",&num);

	int num1,num2;
	int result=num;
	for (;;){
		getNum(result,num1,num2);
		result = num1 - num2;
		printf("%04d - %04d = %04d",num1,num2,result);
		if (result == 0 || result == 6174)
			break;
		printf("%c",'\n');
	}

	return 0;
}