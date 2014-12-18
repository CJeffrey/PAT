#include <iostream>
#include <string.h>
using namespace std;

#define MAX 1024

int main(){
	char oriData[MAX];
	memset(oriData,0,MAX);
	int divisor;
	scanf("%s %d",&oriData,&divisor);

	char quotient[MAX];
	memset(quotient,0,MAX);

	int remainder=0;
	int tmpQuo=0;
	for(int i = 0;i<MAX;i++){
		if (oriData[i] == 0)
			break;
		remainder = remainder*10+(oriData[i]-48);
		tmpQuo = remainder/divisor;
		remainder = remainder%divisor;
		quotient[i]=tmpQuo+48;
	}

	bool firstFlag=true;
	for(int i = 0;i<MAX;i++){
		if (quotient[i]==0)
			break;
		if (firstFlag && quotient[i]==48)
			continue;
		cout << quotient[i];
		firstFlag = false;
	}
	if (firstFlag)
		cout << 0;
	cout << " " << remainder;
	//cout << oriData << i;
	return 0;
}