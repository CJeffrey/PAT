#include <iostream>
#include <string.h>
using namespace std;

#define MAXSIZE 1024

int main(){
	char oriChar[MAXSIZE];
	memset(oriChar,0,MAXSIZE);
	scanf("%s",oriChar);

	int result[10];
	for(int i = 0;i<10;i++){
		result[i] = 0;
	}
	for(int i = 0;i<MAXSIZE;i++){
		if (oriChar[i]==0)
			break;
		else {
			result[oriChar[i]-48]+=1;
		}
	}
	
	for(int i = 0;i<10;i++){
		if (result[i] != 0){
			printf("%d:%d\n",i,result[i]);
		}
	}

	return 0;
}