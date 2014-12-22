#include <iostream>
#include <set>
#include <vector>

using namespace std;

double getSimilarity(const set<int> &s1,const set<int> & s2){
	int commonValue = 0;
	for(set<int>::const_iterator sit1(s1.begin()),sit2(s1.end());sit1!=sit2;sit1++){
		if (s2.find(*sit1) != s2.end()){
			commonValue++;
		}
	}

	double ret = double(commonValue) / (s1.size() + s2.size() - commonValue) * 100;
	return ret;
}

int main(){
	int n;
	scanf("%d",&n);

	vector<set<int>> allSet;
	
	int tmpNum,tmpValue;
	for(int i = 0;i<n;i++){
		allSet.push_back(set<int>());
		scanf("%d",&tmpNum);
		for(int j = 0;j<tmpNum;j++){
			scanf("%d",&tmpValue);
			allSet.back().insert(tmpValue);
		}
	}

	int k;
	scanf("%d",&k);
	int id1,id2;
	double ret;
	for(int i = 0;i<k;i++){
		scanf("%d%d",&id1,&id2);
		ret = getSimilarity(allSet[id1-1],allSet[id2-1]);
		printf("%.1lf%%\n",ret);
	}

	return 0;
}