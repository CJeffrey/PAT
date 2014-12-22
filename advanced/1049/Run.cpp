#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
	const int maxDigit = 9;
	vector<int> ones;
	vector<int> amount;
	for(int i = 0;i<=maxDigit;i++){
		if (i == 0){
			ones.push_back(0);
		} else {
			ones.push_back(ones.back()*10 + amount.back());
		}
		amount.push_back(int(pow(10.0,i)));	
	}

	reverse(ones.begin(),ones.end());
	reverse(amount.begin(),amount.end());

	int n;
	scanf("%d",&n);

	int a,b;
	int counter=0;
	for(int i = 0;i<=maxDigit;i++){
		a = n / amount[i];
		b = n % amount[i];
		switch(a){
			case 0:
				break;
			case 1:
				counter += ones[i];
				counter += (b+1);
				break;
			default:
				counter += a * ones[i];
				counter += amount[i];
				break;
		}
		n = b;
	}
	
	printf("%d",counter);

	return 0;
}