#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxPlayTime = 2 * 60 * 60;
const int beginTime = 8 * 60 * 60;
const int endTime = 21 * 60 * 60;

#define INF 0x6FFFFFFF

class Person{
public:
	Person()
		:beginPlayTime(INF){};
	int arriveTime,playTime,isVIP;
	int beginPlayTime;

	void myPrint()const{
		if (beginPlayTime >= endTime)
			return;
		int h1, m1, s1, h2, m2, s2;  
		int t = arriveTime;  
		h1 = t/3600; t %= 3600;  
		m1 = t/60; t %= 60;  
		s1 = t;  
		t = beginPlayTime;  
		h2 = t/3600; t %= 3600;  
		m2 = t/60; t %= 60;  
		s2 = t;  
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", h1, m1, s1, h2, m2, s2, (beginPlayTime - arriveTime +30)/60);  
	} 
};

bool comPersonArrive(const Person & p1,const Person & p2){
	return p1.arriveTime < p2.arriveTime;
}

bool comPersonPlay(const Person & p1,const Person & p2){
	return p1.beginPlayTime < p2.beginPlayTime;
}

class Table{
public:
	Table()
		:isVIP(false),endTime(beginTime),servedNum(0){};
	int endTime;
	bool isVIP;
	int id;
	int servedNum;

	bool operator<(const Table & t)const{
		if (endTime == t.endTime)
			return id < t.id;
		else
			return endTime < t.endTime;
	}
};

void updateInfo(Person & p,Table & t){
	p.beginPlayTime = max(t.endTime,p.arriveTime);
	t.servedNum++;
	t.endTime = p.beginPlayTime + p.playTime;
	
}

int main(){
	int n;
	scanf("%d",&n);

	vector<Person> allPeople;
	allPeople.resize(n);

	int hh,mm,ss,tmpPT,tmpIsVip;
	for(int i = 0;i<n;i++){
		scanf("%d:%d:%d %d %d",&hh,&mm,&ss,&tmpPT,&tmpIsVip);
		allPeople[i].arriveTime = 60 * 60 * hh + 60 * mm + ss;
		allPeople[i].playTime = min(maxPlayTime,tmpPT*60);
		allPeople[i].isVIP = tmpIsVip;
	}

	int k,m;
	scanf("%d%d",&k,&m);

	vector<Table> allTables;
	allTables.resize(k);
	for(int i = 0;i<k;i++){
		allTables[i].id = i;
	}

	int tmpVIPID;
	for(int i = 0;i<m;i++){
		scanf("%d",&tmpVIPID);
		tmpVIPID--;
		allTables[tmpVIPID].isVIP = true;
	}

	sort(allPeople.begin(),allPeople.end(),comPersonArrive);
	for(int i = 0 ;i<n;i++){
		if (allPeople[i].beginPlayTime != INF)
			continue;
		int arriveTime = allPeople[i].arriveTime;
		int freeTime = INF;
		for(int j = 0;j<k;j++)
			freeTime = min(freeTime,allTables[j].endTime);
		int beginPlayTime = max(freeTime,arriveTime);
		if (beginPlayTime >= endTime)
			break;
		vector<int> waitPeople;
		vector<int> waitTable;
		for(int j = i;j<n;j++){
			if (allPeople[j].beginPlayTime == INF && allPeople[j].arriveTime <= beginPlayTime)
				waitPeople.push_back(j);
		}
		for(int j = 0;j<k;j++){
			if (allTables[j].endTime <= beginPlayTime)
				waitTable.push_back(j);
		}

		bool flag(false);
		for(unsigned int t = 0; t < waitTable.size(); ++t){  
			if(allTables[waitTable[t]].isVIP){  
				for(unsigned int u = 0; u < waitPeople.size(); ++u){  
					if(allPeople[waitPeople[u]].isVIP == 1 && allPeople[waitPeople[u]].beginPlayTime == INF){  
						flag = true;  
						updateInfo(allPeople[waitPeople[u]], allTables[waitTable[t]]);  
						break;  
					}  
				}  
			}  
		}  
		if(!flag)
			updateInfo(allPeople[waitPeople[0]], allTables[waitTable[0]]);  
		--i;  
	}

	sort(allPeople.begin(),allPeople.end(),comPersonPlay);
	for(int i = 0;i<n;i++){
		allPeople[i].myPrint();
	}

	for(int i = 0; i < k; ++i)  
	{  
		if(i != k-1)  
			printf("%d ",allTables[i].servedNum);  
		else printf("%d\n",allTables[i].servedNum);  
	}  

	return 0;
}