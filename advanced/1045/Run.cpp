#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

stack<int> newSequence;
vector<int> favCol,allCol;
int n,m,l;
unsigned int maxLength=0;

int * allLength;
/*
void findFav(int allIndex,int favIndex){
	int myFavIndex = favIndex;
	while(myFavIndex<m){
		for(;allIndex<l;allIndex++){
			if (myFavIndex>=0 && favCol[myFavIndex] == allCol[allIndex]){
				newSequence.push(allCol[allIndex]);
				findFav(allIndex+1,myFavIndex);
				newSequence.pop();
			}
			if (favCol[myFavIndex+1] == allCol[allIndex]){
				newSequence.push(allCol[allIndex]);
				myFavIndex++;
				findFav(allIndex+1,myFavIndex);
				myFavIndex--;
				newSequence.pop();			
			}
		}
		if (myFavIndex == m-1){
			unsigned int tmpSize = newSequence.size();
			maxLength = std::max(maxLength,tmpSize);
		}
		myFavIndex++;
	}	
}*/

int * getAllLenght(const int i,const int j){
	return (allLength + i*(l+1) + j);
}

int main(){
	
	
	int tmpValue;
	scanf("%d",&n);
	
	scanf("%d",&m);
	favCol.resize(m);
	for(int i = 0;i < m;i++){
		scanf("%d",&(favCol[i]));
	}
	scanf("%d",&l);
	allCol.resize(l);
	for(int i = 0;i< l;i++){
		scanf("%d",&(allCol[i]));
	}

	set<int> favSet;
	for(int i = 0;i<m;i++){
		favSet.insert(favCol[i]);
	}
	for(vector<int>::iterator iit = allCol.begin();iit<allCol.end();){
		if (favSet.find(*iit) == favSet.end()){
			iit = allCol.erase(iit);
		} else {
			iit++;
		}
	}
	l = allCol.size();

	int allLengthSize = (1+m) * (1+l);
	allLength = new int[allLengthSize];

	for(int i = 0;i<allLengthSize;i++){
		*(allLength+i)=0;
	}
	for(int i = 1;i<=m;i++){
		for (int j =1;j<=l;j++){
			*getAllLenght(i,j) = max(*getAllLenght(i-1,j),*(getAllLenght(i,j-1)));
			if (favCol[i-1] == allCol[j-1]){
				(*getAllLenght(i,j))++;
			}
		}
	}
	
	maxLength = *getAllLenght(m,l);
	printf("%d",maxLength);

	delete allLength;
	return 0;
}