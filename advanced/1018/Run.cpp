#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define INF 0x6fffffff

int roads[501][501];
int cmax,n,sp,m;


class Nodes{
public:
	int cap;
};

vector<Nodes> allStations;

class Way{
public:
	Way()
		:visited(false),distance(INF){};
	Nodes thisNode;

	int distance;
	vector<vector<int>> allPath;
	bool visited;

	bool operator<(const Way & w)const{
		return distance < w.distance;
	}

	void addSelf(const int id){
		for(vector<vector<int>>::iterator vvit(allPath.begin()),vvitEnd(allPath.end());vvit!=vvitEnd;vvit++){
			vvit->push_back(id);
		}
	}
};

Way runDijkstra(const int endID){
	vector<Way> allWays;
	allWays.resize(n+1);
	for(int i = 1;i<=n;i++){
		allWays[i].thisNode = allStations[i];
	}

	allWays[0].distance = 0;
	allWays[0].visited = true;
	allWays[0].allPath.push_back(vector<int>());
	allWays[0].addSelf(0);
	
	int minPos = 0;

	while(true){
		for(int i = 0;i<=n;i++){
			if (!allWays[i].visited && roads[minPos][i] > 0){
				if (roads[minPos][i] + allWays[minPos].distance < allWays[i].distance){
					allWays[i].distance = roads[minPos][i] + allWays[minPos].distance;
					allWays[i].allPath.clear();
					allWays[i].allPath = allWays[minPos].allPath;
					allWays[i].addSelf(i);
				} else if (roads[minPos][i] + allWays[minPos].distance == allWays[i].distance){
					vector<vector<int>> newPaths = allWays[minPos].allPath;
					for(vector<vector<int>>::iterator vvit(newPaths.begin()),vvitEnd(newPaths.end());vvit!=vvitEnd;vvit++){
						vvit->push_back(i);
					}
					allWays[i].allPath.insert(allWays[i].allPath.end(),newPaths.begin(),newPaths.end());
				}
			}
		}

		if (minPos == endID)
			break;
		
		int minDistance = INF;
		for(int i = 0;i<=n;i++){
			if (!allWays[i].visited && allWays[i].distance < minDistance){
				minDistance=allWays[i].distance;
				minPos = i;
			}
		}

		allWays[minPos].visited=true;
	}

	Way ret = allWays[minPos];
	return ret;
}

void findBestPath(int & takeOut,int & takeIn,vector<int> & bestPath,Way minWay){
	takeIn = takeOut = INF;
	bestPath.clear();
	int tmpOut,tmpIn;
	vector<vector<int>> & allPaths = minWay.allPath;

	const int halfCap = cmax/2;
	vector<vector<int>>::iterator vvit(allPaths.begin()),vvitEnd(allPaths.end());
	vector<int>::iterator vit,vitEnd;
	for(;vvit!=vvitEnd;vvit++){
		vector<int> & tmpPath = *vvit;
		vit = tmpPath.begin();
		
		vitEnd = tmpPath.end();
		tmpOut = tmpIn = 0;
		for(vit++;vit!=vitEnd;vit++){
			int tmpCap = allStations[*vit].cap;
			tmpIn += (tmpCap - halfCap);
			if (tmpIn < 0){
				tmpOut -= tmpIn;
				tmpIn = 0;
			}
		}
		if (tmpOut < takeOut){
			takeOut = tmpOut;
			takeIn = tmpIn;
			bestPath = tmpPath;
		} else if (tmpOut == takeOut && tmpIn < takeIn){
			takeIn = tmpIn;
			bestPath = tmpPath;
		}
	}
}

int main(){
	memset(roads,-1,sizeof(roads));

	scanf("%d%d%d%d",&cmax,&n,&sp,&m);


	allStations.resize(n+1);
	for(int i = 1;i<=n;i++){
		scanf("%d",&allStations[i].cap);
	}
	allStations[0].cap = 0;

	int si,sj,tij;
	for(int i = 0;i<m;i++){
		scanf("%d%d%d",&si,&sj,&tij);
		roads[si][sj] = tij;
		roads[sj][si] = tij;
	}

	Way minWay = runDijkstra(sp);

	int takeOut,takeIn;
	vector<int> bestPath;
	findBestPath(takeOut,takeIn,bestPath,minWay);

	printf("%d ",takeOut);
	for(vector<int>::iterator vit(bestPath.begin()),vitEnd(bestPath.end());vit!=vitEnd;vit++){
		if (vit != bestPath.begin())
			printf("->");
		printf("%d",*vit);
	}
	printf(" %d",takeIn);

	return 0;
}