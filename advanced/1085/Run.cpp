#include <iostream>
#include <algorithm>

using namespace std;

bool isOk(const int i1,const int i2){
	int ret = i1*i2;
	if (!i1 || ret/i1 == i2)
		return true;
	else 
		return false;
}

int main(){
	int pp [8] = {1,2,3,3,3,4,4,5};
	int * p1 = lower_bound(pp,pp+8,3);
	int * p2 = upper_bound(pp,pp+8,3);
	cout << p1 - pp << endl << p2 -pp;
	int n,p;
	scanf("%d%d",&n,&p);

	int * allNums = new int[n];
	for(int i = 0;i<n;i++){
		scanf("%d",allNums+i);
	}

	sort(allNums,allNums+n);
	int maximum(-1);
	int tmpMax;
	for(int i = 0;i<n;i++){
		int m = allNums[i];
		if (!isOk(m,p))
			tmpMax = n - i;
		else {
			int * ptrInt = upper_bound(allNums+i,allNums+n,m*p);
			tmpMax = ptrInt - allNums - i;
		}
		maximum = max(maximum,tmpMax);
	}
	
	printf("%d",maximum);

	delete[]allNums;
	return 0;
}