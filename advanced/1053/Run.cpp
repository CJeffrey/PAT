#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,s;
vector<vector<int>> results;
class Node{
public:
	int id;
	int weight;
	vector<Node*> son;
};

class Counter{
public:
	Counter()
		:sum(0){}
	vector<int> record;
	int sum;
};

void run(Node * myNode,Counter & c){
	if (myNode->son.empty()){
		if (c.sum == s){
			results.push_back(c.record);
		}
	} else {
		int tmpWeight;
		Node * tmpNode;
		for(int i = 0;i<myNode->son.size();i++){
			tmpNode = myNode->son[i];
			tmpWeight = tmpNode->weight;
			if (c.sum + tmpWeight <= s){
				c.record.push_back(tmpWeight);
				c.sum += tmpWeight;
				run(tmpNode,c);
				c.record.pop_back();
				c.sum -= tmpWeight;
			}
		}
	}
}

bool compairVecInt(const vector<int> & vi1,const vector<int> & vi2){
	unsigned int size = min(vi1.size(),vi2.size());
	for(unsigned int i = 0 ;i<size;i++){
		if (vi1[i] > vi2[i]){
			return true;
		} else if (vi1[i]<vi2[i]){
			return false;
		}
	}
	return false;
}

int main(){

	scanf("%d%d%d",&n,&m,&s);

	vector<Node> allNodes;
	allNodes.resize(n);
	for(int i = 0;i<n;i++){
		allNodes[i].id = i;
		scanf("%d",&(allNodes[i].weight));
	}

	int tmpID,tmpSonSize,tmpSonID;
	Node * tmpNode;
	for(int i = 0;i<m;i++){
		scanf("%d %d",&tmpID,&tmpSonSize);
		tmpNode = &(allNodes[tmpID]);
		for(int j = 0;j<tmpSonSize;j++){
			scanf("%d",&tmpSonID);
			tmpNode->son.push_back(&(allNodes[tmpSonID]));
		}
	}

	Node * root = &(allNodes[0]);
	Counter myCounter;
	myCounter.record.push_back(root->weight);
	myCounter.sum+=root->weight;

	run(root,myCounter);

	sort(results.begin(),results.end(),compairVecInt);
	for(unsigned int i = 0;i<results.size();i++){
		for(unsigned int j = 0;j<results[i].size();j++){
			printf("%d",results[i][j]);
			if (j+1 != results[i].size())
				printf("%c",' ');
			else
				printf("%c",'\n');
		}
	}

	return 0;
}