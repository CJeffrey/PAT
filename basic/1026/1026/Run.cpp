#include <iostream>

int main(){
	const int CLK_TCK = 100;
	int c1,c2;
	scanf("%d%d",&c1,&c2);

	int totalSec = int ((double(c2-c1))/(CLK_TCK) + 0.5);

	int showSec = totalSec%60;
	int totalMin = totalSec/60;
	int shouMin = totalMin%60;
	int totalHou = totalMin/60;
	int showHou = totalHou;

	printf("%02d:%02d:%02d",showHou,shouMin,showSec);

	return 0;
}