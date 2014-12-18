#include <iostream>

int main(){
	int n;
	scanf("%d",&n);

	int * floors = new int[n];
	for(int i = 0;i<n;i++){
		scanf("%d",&(floors[i]));
	}

	int totalTime = 0;
	int currentFloor = 0;
	int tmpdiff;
	for(int i = 0;i<n;i++){
		tmpdiff = floors[i] - currentFloor;
		if (tmpdiff >= 0){
			totalTime += 6*tmpdiff;
		} else {
			totalTime -= 4*tmpdiff;
		}
		currentFloor = floors[i];
	}
	totalTime += 5 * n;
	printf("%d",totalTime);

	return 0;
}