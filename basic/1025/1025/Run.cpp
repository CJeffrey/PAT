#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class MyNode{
public:
	int address;
	int data;
	int next;
	void print(){
		printf("%05d %d ",address,data);
		if (next == -1)
			printf("%d",next);
		else
			printf("%05d",next);
		printf("%c",'\n');
	}
};

MyNode * allNodes;
int * index;

/*
void reverse(int nodeIndex,int k,int nextGroupAddress){
	allNodes[index[nodeIndex]].next = nextGroupAddress;
	for(int i = 1;i<k;i++){
		allNodes[index[nodeIndex + i]].next = allNodes[index[nodeIndex + i -1]].address;
	}
}
*/

int main(){
	int first,num,k;
	scanf("%d%d%d",&first,&num,&k);

	allNodes = new MyNode[num];
	index = new int[num];
	map<int,int> nodeIndex;//address:position in allNodes;
	for(int i = 0;i<num;i++){
		scanf("%d%d%d",&(allNodes[i].address),&(allNodes[i].data),&(allNodes[i].next));
		nodeIndex.insert(pair<int,int>(allNodes[i].address,i));
	}

	int tmpAddress = first;
	int counter=0;
	for(int i = 0;i<num;i++){
		index[i] = nodeIndex.find(tmpAddress)->second;
		tmpAddress = allNodes[index[i]].next;
		if (tmpAddress == -1){
			counter = i+1;
			break;
		}
	}

	num = counter;
	int circleTime = num / k;

	for(int i = 0;i<circleTime;i++){
		reverse(index + i*k,index + (i+1)*k);
	}
	int nextAddress;
	for(int i = 0;i<circleTime;i++){
		for(int j = 0;j<k;j++){
			if (i*k+j == num - 1)
				nextAddress = -1;
			else
				nextAddress = allNodes[index[i*k+j+1]].address;
			allNodes[index[i*k+j]].next = nextAddress;
		}
	}

	for(int i = 0;i<num;i++){
		allNodes[index[i]].print();
	}

	delete [] allNodes;
	delete [] index;
	return 0;
}