#include <iostream>
int main(){
	int oriData[10];
	for(int i = 0;i<10;i++){
		scanf("%d",&(oriData[i]));
	}

	for(int i = 1;i<10;i++){
		if (oriData[i] != 0){
			printf("%d",i);
			oriData[i]--;
			break;
		}
	}
	for(int i = 0;i<10;i++){
		while(oriData[i] >0){
			printf("%d",i);
			oriData[i]--;
		}
	}

	return 0;
}