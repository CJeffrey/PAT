#include <iostream>
#include <map>
using namespace std;
int main(){
	int num;
	scanf("%d",&num);
	map<int,int> schoolScore;

	int school,score;
	map<int,int>::iterator mit;
	for(int i = 0;i<num;i++){
		scanf("%d %d",&school,&score);
		mit = schoolScore.find(school);
		if (mit == schoolScore.end()){
			schoolScore.insert(pair<int,int>(school,score));
		} else {
			mit->second += score;
		}
	}

	int maxScore(-1),tmpScore;
	map<int,int>::iterator maxIt;
	for(mit = schoolScore.begin();mit!=schoolScore.end();mit++){
		tmpScore = mit->second;
		if (tmpScore > maxScore){
			maxScore = tmpScore;
			maxIt = mit;
		}
	}

	printf("%d %d",maxIt->first,maxIt->second);

	return 0;
}