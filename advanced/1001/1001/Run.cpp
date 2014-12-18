#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int i1,i2;
	scanf("%d%d",&i1,&i2);
	int i3=i1+i2;

	char buffer[10];
	char outputBuffer[20];
	memset(buffer,0,10);
	memset(outputBuffer,0,20);
	sprintf(buffer,"%d",i3);

	//printf("%s",buffer);

	int lastP;
	for(lastP = 0;lastP<10;lastP++){
		if (buffer[lastP]==0){
			break;
		}
	}
	int firstP=0;
	if (buffer[0] == '-'){
		firstP = 1;
	}

	//cout << "firstP " << firstP << endl;
	//cout << "lastP " << lastP << endl;

	int commaCounter = 0;
	int outputCounter = 0;
	for(int i = lastP -1;i>firstP;i--){
		outputBuffer[outputCounter++]=buffer[i];
		commaCounter++;
		if (commaCounter == 3){
			commaCounter=0;
			outputBuffer[outputCounter++] = ',';
		}
	}
	for(int i = firstP;i>=0;i--){
		outputBuffer[outputCounter++]=buffer[i];
	}
	for(int i =20-1 ;i>=0;i--){
		if(outputBuffer[i] != 0){
			printf("%c",outputBuffer[i]);
		}
	}


	return 0;
}