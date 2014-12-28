#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
int main(){
	int n;
	double p,r;
	scanf("%d%lf%lf",&n,&p,&r);

	multimap<int,int> supplyMap;
	int tmpS;
	for(int i = 0;i<n;i++){
		scanf("%d",&tmpS);
		supplyMap.insert(pair<int,int>(tmpS,i));
	}

	vector<int> supplyLevel;
	supplyLevel.resize(n,-1);
	queue<int> tmpSupplier;
	multimap<int,int>::iterator mit;
	
	mit = supplyMap.find(-1);
	supplyLevel[mit->second] = 0;
	tmpSupplier.push(mit->second);

	while(!tmpSupplier.empty()){
		const int supplierIndex = tmpSupplier.front();
		mit=supplyMap.find(supplierIndex);
		while(mit!=supplyMap.end()){
			supplyLevel[mit->second] = supplyLevel[supplierIndex]+1;
			tmpSupplier.push(mit->second);
			supplyMap.erase(mit);
			mit = supplyMap.find(supplierIndex);
		}
		tmpSupplier.pop();
	}

	int maxLevel=-1;
	int counter=1;
	for(int i = 0;i<n;i++){
		if (maxLevel < supplyLevel[i]){
			counter=1;
			maxLevel = supplyLevel[i];
		} else if (maxLevel == supplyLevel[i]){
			counter++;
		}
	}

	double highestPrice = pow(1+r/100,maxLevel);
	highestPrice*=p;
	printf("%.2lf %d",highestPrice,counter);

	return 0;
}