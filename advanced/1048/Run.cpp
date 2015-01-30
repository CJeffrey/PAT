#include <iostream>
#include <set>

using namespace std;
struct Coin{
	int value;

	bool operator<(const Coin & c)const{
		return value < c.value;
	}
};

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	set<Coin> allCoins;
	set<Coin> notUnitCoins;
	Coin tmpCoin;
	set<Coin>::iterator cit;
	for(int i = 0;i<n;i++){
		scanf("%d",&tmpCoin.value);
		cit = allCoins.find(tmpCoin);
		if (cit == allCoins.end()){
			allCoins.insert(tmpCoin);
		} else {
			notUnitCoins.insert(tmpCoin);
		}
	}

	int outPut1(-1),outPut2(-1);
	const set<Coin>::const_iterator citEnd(allCoins.end()),notUnitEnd(notUnitCoins.end());
	set<Coin>::const_iterator cit2;
	for(cit=allCoins.begin();cit!=citEnd;cit++){
		tmpCoin.value = m - cit->value;
		if (tmpCoin.value < cit->value){
			break;
		} else if (tmpCoin.value == cit->value){
			cit2 = notUnitCoins.find(tmpCoin);
			if (cit2 != notUnitEnd){
				outPut1 = outPut2 = cit->value;
				break;
			}
		} else {
			cit2 = allCoins.find(tmpCoin);
			if (cit2!=citEnd){
				outPut1 = cit->value;
				outPut2 = cit2->value;
				break;
			}
		}
	}

	if (outPut1 > 0){
		printf("%d %d",outPut1,outPut2);
	} else {
		printf("%s","No Solution");
	}

	return 0;
}