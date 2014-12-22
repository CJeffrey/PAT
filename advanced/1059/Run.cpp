#include <iostream>
#include <math.h>
int main(){
	int n;
	scanf("%d",&n);
	const int oriN = n;

	printf("%d%c",n,'=');

	int counter;
	int maxTry = int(sqrt(float(n)));
	for(int i = 2;i<=maxTry;i++){
		counter = 0;
		while(n % i == 0 && n >= i){
			counter++;
			n = n/i;
		}
		if (counter != 0){
			printf("%d",i);
			if (counter != 1){
				printf("%c%d",'^',counter);
			}
			if (n!=1)
				printf("%c",'*');
		}
	}
	if (n!=1 || oriN == 1)
		printf("%d",n);


	return 0;
}