#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> allNames;
bool mySort(const unsigned int i1,const unsigned int i2){
	return allNames[i1] < allNames[i2];
}

int main(){
	unsigned int n,k;
	unsigned int i,j;
	scanf("%d%d",&n,&k);
	map<unsigned int,vector<unsigned int>> courseMap;
	pair<unsigned int,vector<unsigned int>> initUnit = pair<unsigned int,vector<unsigned int>>(0,vector<unsigned int>());
	for(i = 1;i<= k;i++){
		initUnit.first = i;
		courseMap.insert(initUnit);
	}
	
	allNames.resize(n);
	unsigned int classSize;
	unsigned int className;
	map<unsigned int,vector<unsigned int>>::iterator mit;
	for(i = 0;i<n;i++){
		allNames[i].resize(4);
		scanf("%s",&allNames[i][0]);
		scanf("%d",&classSize);
		for(j=0;j<classSize;j++){
			scanf("%d",&className);
			mit = courseMap.find(className);
			mit->second.push_back(i);
		}
	}

	unsigned int studentSize;
	for(i = 1;i<=k;i++){
		mit = courseMap.find(i);
		studentSize = mit->second.size();
		printf("%d %d\n",i,studentSize);
		sort(mit->second.begin(),mit->second.end(),mySort);
		for(j = 0;j<studentSize;j++){
			printf("%s\n",allNames[mit->second[j]].c_str());
		}
	}
	

	return 0;
}