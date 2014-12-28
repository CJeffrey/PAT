#include <iostream>
#include <math.h>
#include <algorithm>
char buff[5] = {'\0','\0','\0','\0','\0'};
bool minusAndPrint(int & value){
	int oriV,newV;
	sprintf(buff,"%04d",value);
	std::sort(&(buff[0]),&(buff[4]));
	oriV = atoi(buff);
	std::swap(buff[0],buff[3]);
	std::swap(buff[1],buff[2]);
	newV = atoi(buff);

	value = newV - oriV;

	printf("%04d - %04d = %04d\n",newV,oriV,value);
	if (value == 0 || value ==6174){
		return true;
	} else {
		return false;
	}
}

int main(){
	int value;
	scanf("%d",&value);

	while(!minusAndPrint(value))
		;

	return 0;
	
}