#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,k;
int *allNodes;
vector<int> * allRodes;
int * allRequires;
queue<int> waitingList;
void initAllNodes(const int occupiedCity){
	for(int i = 1;i<n+1;i++){
		allNodes[i] = -1;
	}
	allNodes[occupiedCity] = 0;
}

bool paintCity(const int mark){
	bool ret = false;
	int firstCity;
	for(firstCity = 1;firstCity<n+1;firstCity++){
		if (allNodes[firstCity] < 0){
			allNodes[firstCity] = mark;
			waitingList.push(firstCity);
			ret = true;
			break;
		}
	}
	int tmpCity;
	vector<int> * tmpRodes;
	vector<int>::iterator iit;
	if (ret){
		while(!waitingList.empty()){
			tmpCity = waitingList.front();
			waitingList.pop();
			tmpRodes = &(allRodes[tmpCity]);
			for(iit=tmpRodes->begin();iit<tmpRodes->end();iit++){
				if (allNodes[*iit] < 0){
					allNodes[*iit] = mark;
					waitingList.push(*iit);
				}
			}
		}
	}


	return ret;
}

int main(){
	
	scanf("%d%d%d",&n,&m,&k);

	allNodes = new int[n+1];
	allRodes = new vector<int>[n+1];
	allRequires = new int[k];

	int node1,node2;
	for(int i = 0;i<m;i++){
		scanf("%d%d",&node1,&node2);
		allRodes[node1].push_back(node2);
		allRodes[node2].push_back(node1);
	}
	for(int i = 0;i<k;i++){
		scanf("%d",&(allRequires[i]));
	}

	int occupiedCity,mark;
	for(int i = 0;i<k;i++){
		occupiedCity = allRequires[i];
		initAllNodes(occupiedCity);
		for(mark = 1;;mark++){
			if (!paintCity(mark)){
				break;
			}
		}
		if (mark >= 2){
			mark -=2;
		} else {
			mark = 0;
		}
		printf("%d",mark);
		if (i+1 != k){
			printf("%c",'\n');
		}
	}



	delete [] allRequires;
	delete [] allRodes;
	delete [] allNodes;
	return 0;
}