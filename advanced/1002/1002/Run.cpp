#include <iostream>

int main(){
	double values[1001];
	for(int i = 0;i<1001;i++){
		values[i] = 0;
	}
	int k;
	int ni;
	double ani;
	for(int i = 0;i<2;i++){
		scanf("%d",&k);
		for(int j = 0;j<k;j++){
			scanf("%d %lf",&ni,&ani);
			values[ni] += ani;
		}
	}
	int nonZeroCounter=0;
	for(int i = 1001 -1;i>=0;i--){
		if (values[i]!=0){
			nonZeroCounter++;
		}
	}
	
	printf("%d",nonZeroCounter);
	for(int i = 1001 -1;i>=0;i--){
		if (values[i]!=0){
			printf(" %d %.1lf",i,values[i]);
		}
	}

	return 0;
}