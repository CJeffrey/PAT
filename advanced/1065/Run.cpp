#include <iostream>
#include <limits>


const long long lowLimit = std::numeric_limits<long long>::min();
const long long upLimit = std::numeric_limits<long long>::max();

int main(){
	int n;
	scanf("%d",&n);

	long long i1,i2,i3;
	long long iTmp;
	bool * resultFlag = new bool[n];
	for (int i = 0;i<n;i++){
		scanf("%lld%lld%lld",&i1,&i2,&i3);
		if (i1 < 0 && i2 < 0){
			iTmp = i1 - lowLimit;
			if (i2 < iTmp){
				resultFlag[i] = false;
				continue;
			}
		}
		if (i1 > 0 && i2 > 0){
			iTmp = upLimit - i1;
			if (i2 > iTmp){
				resultFlag[i] = true;
				continue;
			}
		}
		
		if (i1 + i2 > i3){
			resultFlag[i] = true;
		} else {
			resultFlag[i] = false;
		}
	}

	for(int i = 0 ;i<n;i++){
		printf("Case #%d: ",i+1);
		if (resultFlag[i]){
			printf("true");
		} else {
			printf("false");
		}
		printf("\n");
	}
	
	delete [] resultFlag;
	return 0;
}