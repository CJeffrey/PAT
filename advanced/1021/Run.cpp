#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int n;

class NodeRelation{
public:
	vector<int> conNodes;
};

vector<NodeRelation> allNodeRelation;

class UnionFindSets{
public:
	UnionFindSets()
		:hasCircle(false){};
	vector<int> leaders;
	bool hasCircle;

	void init(const int n){
		leaders.resize(n);
		for(int i = 0;i<n;i++){
			leaders[i]=i;
		}
	}

	int findLeader(int i1)const{
		while(i1 != leaders[i1]){
			i1 = leaders[i1];
		}
		return i1;
	}

	bool sameLeader(const int i1,const int i2){
		return findLeader(i1) == findLeader(i2);
	}

	void joinLeader(const int i1,const int i2){
		int leader1 = findLeader(i1);
		int leader2 = findLeader(i2);
		leaders[leader1] = leader2;
	}

	void run(){
		NodeRelation * nptr;
		for(int i = 0;i<n;i++){
			nptr = &allNodeRelation[i];
			vector<int>::const_iterator nit(nptr->conNodes.begin()),nitEnd(nptr->conNodes.end());
			for(;nit!=nitEnd;nit++){
				if (*nit < i)
					continue;
				if (!sameLeader(i,*nit)){
					joinLeader(i,*nit);
				} else {
					hasCircle=true;
				}
			}
		}
	}

	int findBlockNum()const{
		if (leaders.empty())
			return 0;

		set<int> differentLeaders;
		int tmpLeader;
		for(int i = 0;i<n;i++){
			tmpLeader = findLeader(i);
			differentLeaders.insert(tmpLeader);
		}

		return differentLeaders.size();
	}
};

class Node{
public:
	int myID;
	int prID;
	int depth;
};

vector<int> findLastLevel(int firstID){
	Node n;
	n.myID=firstID;
	n.prID=-1;
	n.depth=0;

	vector<int> ret;
	queue<Node> nodeQue;
	nodeQue.push(n);
	int nowLevel = n.depth;
	NodeRelation * nrPtr;
	Node * nodePtr;
	vector<int>::const_iterator iit,iitEnd;
	while(!nodeQue.empty()){
		nodePtr = &(nodeQue.front());
		nrPtr = &(allNodeRelation[nodePtr->myID]);
		for(iit=nrPtr->conNodes.begin(),iitEnd=nrPtr->conNodes.end();iit!=iitEnd;iit++){
			if (*iit != nodePtr->prID){
				Node newNode;
				newNode.myID = *iit;
				newNode.prID = nodePtr->myID;
				newNode.depth = nodePtr->depth + 1;
				nodeQue.push(newNode);
			}
		}
		if (nowLevel != nodePtr->depth){
			ret.clear();
			nowLevel = nodePtr->depth;
		}
		ret.push_back(nodePtr->myID);
		nodeQue.pop();
	}

	return ret;
}

set<int> findDeepestRoot(){
	vector<vector<int>> allBFS;
	allBFS.resize(2);
	allBFS[0] = findLastLevel(0);

	allBFS[1] = findLastLevel(allBFS[0][0]);

	//allBFS[2] = findLastLevel(allBFS[1][0]);
	//此时应该融合allBFS[1] 和allBFS[2]

	set<int> allAnswer;
	vector<int>::const_iterator iit,iitEnd;
	for(int i = 0;i<=1;i++){
		for(iit=allBFS[i].begin(),iitEnd=allBFS[i].end();iit!=iitEnd;iit++){
			allAnswer.insert(*iit);
		}
	}
	return allAnswer;
}


int main(){

	scanf("%d",&n);

	allNodeRelation.resize(n);

	int n1,n2;
	for(int i = 0;i<n-1;i++){
		scanf("%d%d",&n1,&n2);
		n1--;
		n2--;
		allNodeRelation[n1].conNodes.push_back(n2);
		allNodeRelation[n2].conNodes.push_back(n1);
	}

	UnionFindSets ufs;
	ufs.init(n);
	ufs.run();
	int leaderNum = ufs.findBlockNum();

	if (leaderNum != 1 || ufs.hasCircle){
		printf("Error: %d components",leaderNum);
	} else {
		set<int> answer = findDeepestRoot();
		set<int>::const_iterator sit(answer.begin()),sitEnd(answer.end());
		for(;sit!=sitEnd;sit++){
			printf("%d\n",*sit + 1);
		}
	}


	return 0;
}