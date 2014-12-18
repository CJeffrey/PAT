#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

char outputType[4] = {'A','C','M','E'};

class Rank{
public:
	int score;
	int id;
	bool operator<(const Rank &r)const{
		return score < r.score;
	}
};

Rank ** oriRanks;
map<int,int> idIndex;
int n,m;
int findRank(Rank * rankList,int id,int scoreType){
	map<int,int>::iterator mit = idIndex.find(id);
	if (mit == idIndex.end()){
		return -1;
	}
	int oriPos = mit->second;
	int score = oriRanks[scoreType][oriPos].score;

	int tmpBegin = 0;
	int tmpEnd = n-1;
	int tmpMid=(tmpBegin + tmpEnd)/2;
	/*for(int i = 0;i<n;i++){
		cout<<rankList[i].score << endl;
	}*/
	while(score != rankList[tmpMid].score){
		if (score > rankList[tmpMid].score){
			tmpBegin = tmpMid+1;
		} else {
			tmpEnd = tmpMid-1;
		}
		tmpMid=(tmpBegin + tmpEnd)/2;
	}
	for(;tmpMid<n;tmpMid++){
		if (rankList[tmpMid].score != score){
			break;
		}
	}
	tmpMid--;
	return (n-(tmpMid));
}

int findBest(int * singleRank){
	int ret = 0;
	for(int i = 1;i<4;i++){
		if (singleRank[i] < singleRank[ret]){
			ret = i;
		}
	}
	return ret;
}

int main(){
	
	scanf("%d%d",&n,&m);

	oriRanks = new Rank * [4];
	for(int i = 0;i<4;i++){
		oriRanks[i] = new Rank [n];
	}
	
	
	int tmpC,tmpM,tmpE,tmpID;
	int tmpA;
	for(int i = 0;i<n;i++){
		scanf("%d%d%d%d",&tmpID,&tmpC,&tmpM,&tmpE);
		tmpA = (tmpC + tmpM + tmpE);
		oriRanks[0][i].id = tmpID;
		oriRanks[1][i].id = tmpID;
		oriRanks[2][i].id = tmpID;
		oriRanks[3][i].id = tmpID;

		oriRanks[0][i].score = tmpA;
		oriRanks[1][i].score = tmpC;
		oriRanks[2][i].score = tmpM;
		oriRanks[3][i].score = tmpE;

		idIndex.insert(pair<int,int>(tmpID,i));
	}

	int * checkList  = new int[m];
	for(int i = 0;i<m;i++){
		scanf("%d",&(checkList[i]));
	}

	Rank ** newRanks;
	newRanks = new Rank * [4];
	for(int i = 0;i<4;i++){
		newRanks[i] = new Rank [n];
		for(int j = 0;j<n;j++){
			newRanks[i][j]=oriRanks[i][j];
		}
	}

	for (int i = 0;i<4;i++){
		std::sort(newRanks[i],newRanks[i]+n);
	}

	int tmpCheck;
	int checkResult[4];
	int tmpBest;
	for(int i = 0;i<m;i++){
		tmpCheck = checkList[i];
		for(int j = 0;j<4;j++){
			checkResult[j] = findRank(newRanks[j],tmpCheck,j);
		}
		tmpBest = findBest(checkResult);
		if (checkResult[tmpBest] < 0){
			printf("%s","N/A");
		} else {
			printf("%d %c",checkResult[tmpBest],outputType[tmpBest]);
		}
		if (i+1 != m){
			printf("%c",'\n');
		}
	}


	for(int i = 0;i<4;i++){
		delete []newRanks[i];
	}
	delete[]newRanks;
	delete[]checkList;
	for(int i = 0;i<4;i++){
		delete []oriRanks[i];
	}
	delete[]oriRanks;
	return 0;
}