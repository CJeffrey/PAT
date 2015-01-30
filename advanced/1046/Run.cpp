#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<int>> data;

unsigned int getPower(const unsigned int value){
	unsigned int testV = 1;
	while(value > testV){
		testV <<= 1;
	}
	return testV;
}


int getLength(const unsigned int pos){
	int ret = 0;
	const int maxLevel = data.size();
	for(unsigned int level = maxLevel;level >= 1;level--){
		unsigned int standardPos = 1;
		standardPos <<= (level-1);
		if (pos & standardPos){
			unsigned int tmpPos = pos;
			tmpPos >>= (level-1);
			ret += data[level-1][tmpPos-1];
		}
	}
	return ret;
}

int main(){
	unsigned int n,m;
	scanf("%d",&n);
	const unsigned int powerN = getPower(n);

	data.push_back(vector<int>());
	data[0].resize(n);
	for(unsigned int i = 0;i<n;i++){
		scanf("%d",&data[0][i]);
	}
	scanf("%d",&m);
	vector<pair<int,int>> query;
	query.resize(m);
	for(unsigned int i = 0 ;i<m;i++){
		scanf("%d%d",&query[i].first,&query[i].second);
	}

	for(unsigned int i = n;i<powerN;i++){
		data[0].push_back(0);
	}

	int level = 0;
	int levelNext;
	while(data[level].size() > 1){
		data.push_back(vector<int>());
		levelNext=level+1;
		const unsigned int circleSize =data[level].size()/2;
		for(unsigned int i = 0;i<circleSize;i++){
			data[levelNext].push_back(data[level][i*2] + data[level][i*2+1]);
		}
		level = levelNext;
	}

	const int fullLength = data.back()[0];

	vector<pair<int,int>>::const_iterator pit(query.begin()),pitEnd(query.end());
	for(;pit<pitEnd;pit++){
		int i1 = pit->first,i2 = pit->second;
		if (i1 > i2)
			swap(i1,i2);
		int length1 = getLength(i1-1);
		int length2 = getLength(i2-1);
		int diffLength = length2 - length1;
		diffLength = min(diffLength,fullLength-diffLength);
		printf("%d\n",diffLength);
	}

	return 0;
}