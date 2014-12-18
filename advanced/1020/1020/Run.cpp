#include <iostream>
#include <queue>
#include <map>
using namespace std;

map<int,int> value2Index;
int indexCounter(0);
class node{
public:
	node()
		:left(-1),right(-1){};
	int left;
	int right;
};

int buildTree(int * a,int * b,int tmpSize,node* tree){
	if (tmpSize <= 0)
		return -1;
	int root = a[tmpSize-1];

	int markB;
	for(markB = 0;markB<tmpSize;markB++){
		if (b[markB] == root)
			break;
	}
	int myIndex = indexCounter++;
	value2Index.insert(pair<int,int>(root,myIndex));
	tree[myIndex].left = buildTree(a,b,markB,tree);
	tree[myIndex].right = buildTree(a+markB,b+markB+1,tmpSize - 1 - markB,tree);
	return root;
}

void levelTree(node * tree,const int root){
	queue<int> outPut;
	outPut.push(root);
	int firstValue;
	while(!outPut.empty()){
		firstValue = outPut.front();
		if (firstValue >= 0){
			int tmpIndex = value2Index.find(firstValue)->second;
			if (firstValue != root){
				printf("%c",' ');
			}
			printf("%d",firstValue);
			outPut.push(tree[tmpIndex].left);
			outPut.push(tree[tmpIndex].right);
		}
		outPut.pop();
	}
}

int main(){
	int n;
	scanf("%d",&n);
	
	node * tree = new node[n];
	int * postorder = new int[n];
	int * inorder = new int[n];

	for(int i = 0;i<n;i++){
		scanf("%d",postorder+i);
	}
	for(int i = 0;i<n;i++){
		scanf("%d",inorder+i);
	}
	int root = buildTree(postorder,inorder,n,tree);
	levelTree(tree,root);

	delete []inorder;
	delete []postorder;
	delete []tree;	
	return 0;
}