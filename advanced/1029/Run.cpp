#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	vector<int> is1,is2;

	scanf("%d",&n);
	is1.resize(n);
	for(int i = 0;i<n;i++){
		scanf("%d",&is1[i]);
	}

	scanf("%d",&n);
	is2.resize(n);
	for(int i = 0;i<n;i++){
		scanf("%d",&is2[i]);
	}

	vector<int>::const_iterator iit1(is1.begin()),iit2(is2.begin()),iitEnd1(is1.end()),iitEnd2(is2.end());
	unsigned int couter;
	const unsigned int medianPos = (is1.size() + is2.size()+1)/2;
	int result;
	for(couter = 1;couter<=medianPos;couter++){
		if (iit1 == iitEnd1){
			result = *iit2++;
		} else if (iit2 == iitEnd2){
			result = *iit1++;
		} else {
			if (*iit1 < * iit2)
				result = *iit1++;
			else
				result = *iit2++;
		}
	}
	printf("%d",result);
	return 0;
}