#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool intGraterThan(const int i1,const int i2){
	return i1 > i2;
}

int main(){
	int nc,np;
	vector<int> positiveC,negativeC,positiveP,negativeP;

	int tmpValue;
	scanf("%d",&nc);
	for(int i = 0;i<nc;i++){
		scanf("%d",&tmpValue);
		if (tmpValue > 0){
			positiveC.push_back(tmpValue);
		} else if (tmpValue < 0){
			negativeC.push_back(tmpValue);
		}
	}

	scanf("%d",&np);
	for(int i = 0;i<np;i++){
		scanf("%d",&tmpValue);
		if (tmpValue > 0){
			positiveP.push_back(tmpValue);
		} else if (tmpValue < 0){
			negativeP.push_back(tmpValue);
		}
	}

	sort(positiveC.begin(),positiveC.end(),intGraterThan);
	sort(negativeC.begin(),negativeC.end());
	sort(positiveP.begin(),positiveP.end(),intGraterThan);
	sort(negativeP.begin(),negativeP.end());

	int result = 0;
	int positiveSize = min(positiveC.size(),positiveP.size());
	int negativeSize = min(negativeC.size(),negativeP.size());
	for(int i = 0;i<positiveSize;i++){
		result += positiveC[i] * positiveP[i];
	}
	for(int i = 0;i<negativeSize;i++){
		result += negativeC[i] * negativeP[i];
	}

	printf("%d",result);

	return 0;
}