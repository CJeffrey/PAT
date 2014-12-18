#include <iostream>
#include <math.h>
int main(){
	double gs[3][3];

	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			scanf("%lf",&(gs[i][j]));
		}
	}

	double * bestPtr[3];

	int bestIndex[3];

	for(int i = 0;i<3;i++){
		bestPtr[i] = (NULL);
		for(int j = 0;j<3;j++){
			if (!bestPtr[i] || (gs[i][j] > *(bestPtr[i]))){
				bestPtr[i] = &(gs[i][j]);
				bestIndex[i] = j;
			}
		}
	}
	double result = 1;
	int position;
	for(int i = 0;i<3;i++){
		switch(bestIndex[i]){
			case 0:
				printf("%c",'W');
				break;
			case 1:
				printf("%c",'T');
				break;
			case 2:
				printf("%c",'L');
		}
		printf("%c",' ');
		result *= *(bestPtr[i]);
	}
	result = (result*0.65-1)*2;

	//result = ceil(result * 100)/100;
	printf("%.2lf",result);

	return 0;
}