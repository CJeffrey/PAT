#include <iostream>
//#include <string.h>
//using namespace std;

int main(){
	unsigned int num1,num2,mod;
	scanf("%d%d%d",&num1,&num2,&mod);

	unsigned int sum = num1 + num2;
	int result[32];
	for(int i = 0;i<32;i++){
		result[i]= -1;
	}

	unsigned int remainder;
	unsigned int quotient;
	for (int i = 0;i<32;i++){
		quotient = sum/mod;
		remainder = sum%mod;

		result[i]=remainder;
		sum=quotient;
		if (sum==0)
			break;
	}
	for(int i = 31;i>=0;i--){
		if (result[i] == -1)
			continue;
		printf("%d",result[i]);
	}

	return 0;
}