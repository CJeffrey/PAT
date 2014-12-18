#include <iostream>
#include <algorithm>
int n;
int * oriData;
int * myTree;

int myCounter(0);

void buildTree(const int root){
	if (root > n){
		return;
	}
	int leftSon(root<<1),rightSon(leftSon + 1);
	buildTree(leftSon);
	myTree[root]=oriData[myCounter++];
	buildTree(rightSon);
}


void printTreeLevel(){
	printf("%d",myTree[1]);
	for(int i = 2;i<=n;i++){
		printf(" %d",myTree[i]);
	}
}

int main(){
	scanf("%d",&n);
	oriData = new int[n];
	myTree = new int[n+1];
	for(int i = 0;i<n;i++){
		scanf("%d",oriData+i);
	}
	std::sort(oriData,oriData + n);
	buildTree(1);

	printTreeLevel();

	delete []myTree;
	delete []oriData;
	return 0;
}