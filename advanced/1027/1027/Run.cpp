#include <iostream>

void changeValue(const int decValue,const int aimRadix,char * retChar){
	int tmpValue[2];
	tmpValue[0] = decValue / aimRadix;
	tmpValue[1] = decValue % aimRadix;
	for(int i = 0;i<2;i++){
		retChar[i] = tmpValue[i] + 48;
		if (tmpValue[i] > 9){
			retChar[i] += 7;
		}
	}
}

int main(){
	int oriValue[3];
	scanf("%d%d%d",&(oriValue[0]),&(oriValue[1]),&(oriValue[2]));

	printf("%c",'#');
	char radix13Value[3];
	radix13Value[2] = 0;
	for(int i = 0;i<3;i++){
		changeValue(oriValue[i],13,radix13Value);
		printf("%s",radix13Value);
	}
	return 0;
}