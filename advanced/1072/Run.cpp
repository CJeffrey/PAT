#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

#define MAXSIZE	1012

int road[MAXSIZE][MAXSIZE];
int n,m,k,ds;

struct StationInfo{
	int totalDistance;
	int minDistance;
	int id;
};

int getID(string s){
	int ret;
	if (s[0] == 'G'){
		s = s.substr(1,s.size()-1);
		ret = n + atoi(s.c_str());
	} else {
		ret = atoi(s.c_str());
	}
	return ret;
}

pair<int,int> runSearch(const int stationID){
	const int totalSize = n+m;
	map<int,int> unOrganized;
	vector<pair<int,int>> organized;
	for(int i = 0;i<totalSize;i++ ){
		if (i != stationID){
			unOrganized.insert(pair<int,int>(i,-1));
		} else {
			organized.push_back(pair<int,int>(i,0));
		}
	}
	vector<pair<int,int>>::iterator vit,vitEnd;
	map<int,int>::iterator mit,mitEnd,mitMin;
	while(!unOrganized.empty()){
		mitEnd = unOrganized.end();
		vit = organized.end() - 1;
		for(int i = 0;i<totalSize;i++){
			if (road[vit->first][i]>0){
				mit = unOrganized.find(i);
				if (mit != mitEnd){
					if (mit->second < 0){
						mit->second = road[vit->first][i] + vit->second;
					} else {
						mit->second = min(mit->second,road[vit->first][i] + vit->second);
					}
				}
			}
		}

		mitMin = unOrganized.begin();
		for(mit=unOrganized.begin();mit!=mitEnd;mit++){
			if (mit->second < 0)
				continue;
			else {
				if (mitMin->second<0)
					mitMin = mit;
				else if(mit->second < mitMin->second){
					mitMin = mit;
				}
			}
			
		}
		
		organized.push_back(*mitMin);
		unOrganized.erase(mitMin);
	}

	int minDistance(-1);
	int totalDistance(0);
	bool allSafeDistance(true);

	for(vit=organized.begin(),vitEnd=organized.end();vit!=vitEnd;vit++){
		if (vit->first<n){
			if (minDistance<0){
				minDistance = vit->second;
			} else {
				minDistance = min(minDistance,vit->second);
			}
			totalDistance += vit->second;

			if (vit->second > ds){
				allSafeDistance = false;
				break;
			}
		}
	}

	if (!allSafeDistance){
		minDistance = -1;
	}

	return pair<int,int>(minDistance,totalDistance);
}

int main(){
	memset(road,-1,sizeof(int)*MAXSIZE*MAXSIZE);
	scanf("%d%d%d%d",&n,&m,&k,&ds);

	string tmpS1,tmpS2;
	int i1,i2,value;
	for(int i = 0;i<k;i++){
		cin >> tmpS1 >> tmpS2 >> value;
		i1 = getID(tmpS1);
		i2 = getID(tmpS2);
		i1--;
		i2--;
		road[i1][i2] = value;
		road[i2][i1] = value;
	}

	vector<StationInfo> answer;
	for(int i = 0 ;i<m;i++){
		pair<int,int> tmpAns = runSearch(n+i);
		if (tmpAns.first < 0)
			continue;
		StationInfo si;
		si.id = i;
		si.minDistance = tmpAns.first;
		si.totalDistance = tmpAns.second;
		answer.push_back(si);
	}

	vector<StationInfo>::iterator bestAnswer = answer.begin(),vit,vitEnd(answer.end());
	for(vit=answer.begin();vit!=vitEnd;vit++){
		if (bestAnswer->minDistance < vit->minDistance){
			bestAnswer = vit;
		} else if (bestAnswer->minDistance == vit->minDistance){
			if (bestAnswer->totalDistance > vit->totalDistance)
				bestAnswer = vit;
			else if (bestAnswer->totalDistance == vit->totalDistance){
				if (bestAnswer->id > vit->id)
					bestAnswer = vit;
			}
		}
	}

	if (bestAnswer==vitEnd){
		printf("No Solution");
	} else {
		printf("G%d\n",bestAnswer->id+1);
		printf("%.1lf %.1lf",double(bestAnswer->minDistance),bestAnswer->totalDistance / double(n) );
	}


	return 0;
}