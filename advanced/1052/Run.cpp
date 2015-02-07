#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Node{
public:
	Node()
		:linked(false){};
	int address;
	int key;
	int next;

	void getData(){
		scanf("%d%d%d",&address,&key,&next);
	}

	bool operator<(const Node & n)const{
		return key < n.key;
	}

	void myPrint()const{
		printf("%05d %d ",address,key);
		if (next >= 0){
			printf("%05d",next);
		} else {
			printf("%d",next);
		}
		printf("\n");
	}

	bool linked;
};

int main(){
	int n,startAdd;
	scanf("%d%d",&n,&startAdd);

	list<Node> allNodes;
	allNodes.resize(n);

	vector<Node*> allAddress;
	allAddress.resize(100000,NULL);

	list<Node>::iterator lit,litEnd,litNext;
	for(lit=allNodes.begin(),litEnd=allNodes.end();lit!=litEnd;lit++){
		lit->getData();
		allAddress[lit->address] = &(*lit);
	}

	while(startAdd >= 0){
		allAddress[startAdd]->linked = true;
		startAdd = allAddress[startAdd]->next;
	}

	for(lit=allNodes.begin(),litEnd=allNodes.end();lit!=litEnd;){
		if (!lit->linked){
			lit = allNodes.erase(lit);
		} else {
			lit++;
		}
	}

	allNodes.sort();

	for(lit=allNodes.begin(),litEnd=allNodes.end();lit!=litEnd;lit++){
		litNext = lit;
		litNext++;
		if (litNext != litEnd){
			lit->next = litNext->address;
		} else {
			lit->next = -1;
		}
	}

	unsigned int newSize = allNodes.size();
	if (newSize == 0){
		printf("%d %d\n",newSize,-1);
	} else {
		printf("%d %05d\n",newSize,allNodes.front().address);
		for(lit=allNodes.begin(),litEnd=allNodes.end();lit!=litEnd;lit++){
			lit->myPrint();
		}
	}

	return 0;
}