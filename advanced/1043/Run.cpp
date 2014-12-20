#include <iostream>
#include <limits>
#include <vector>
using namespace std;

bool lessThen(const int i1,const int i2){
	return i1 < i2;
}

bool moreThen(const int i1,const int i2){
	return i1 >= i2;
}

class Node{
public:
	Node()
		:fatherPtr(NULL),leftSonPtr(NULL),rightSonPtr(NULL){
	}
	~Node(){
		if (!leftSonPtr)
			delete leftSonPtr;
		if (!rightSonPtr)
			delete rightSonPtr;
	}

	bool tryLeft(int newValue){
		Node * newNode = new Node;
		newNode->fatherPtr = this;
		newNode->value = newValue;
		bool flag = addLeft(newNode);
		if (!flag)
			delete newNode;
		return flag;
	}

	bool tryRight(int newValue){
		Node * newNode = new Node;
		newNode->fatherPtr = this;
		newNode->value = newValue;
		bool flag = addRight(newNode);
		if (!flag)
			delete newNode;
		return flag;
	}

	void printPostorder()const{
		if (leftSonPtr)
			leftSonPtr->printPostorder();
		if (rightSonPtr)
			rightSonPtr->printPostorder();

		printf("%d",value);
		if (fatherPtr)
			printf("%c",' ');
	}

	int leftBound,rightBound;
	bool isLeft;
	Node * fatherPtr;
	Node * leftSonPtr;
	Node * rightSonPtr;
	int value;
private:
	bool addLeft(Node * nptr){
		if (rightSonPtr){
			return false;
		}
		if (leftSonPtr == NULL){
			leftSonPtr = nptr;
			nptr->isLeft = true;
			nptr->leftBound = leftBound;
			nptr->rightBound = value;
			return true;
		} else {
			return false;
		}
	}

	bool addRight(Node * nptr){
		if (rightSonPtr == NULL){
			rightSonPtr = nptr;
			nptr->isLeft = false;
			nptr->leftBound = value;
			nptr->rightBound = rightBound;
			return true;
		} else {
			return false;
		}
	}
};

class Tree{
public:
	Tree(){
		root = new Node;
	}
	~Tree(){
		if (!root)
			delete root;
	}
	Node * root;
};

bool makeTree(const vector<int> & data,Tree & t,bool (*comfun)(const int ,const int)){
	int tmpValue;
	int size = data.size();
	Node * tmpNode = t.root;
	tmpNode->value = data[0];
	bool flag=true;
	int fatherValue,myValue;
	for(int i = 1;i<size;i++){
		tmpValue = data[i];
		while(true){
			if (tmpNode->fatherPtr == NULL){
				if (comfun(tmpValue,tmpNode->value)){
					flag = tmpNode->tryLeft(tmpValue);
					tmpNode = tmpNode->leftSonPtr;
				} else {
					flag = tmpNode->tryRight(tmpValue);
					tmpNode = tmpNode->rightSonPtr;
				}
				break;
			} else {
				if (!comfun(tmpValue,tmpNode->leftBound) && comfun(tmpValue,tmpNode->rightBound)){
					myValue = tmpNode->value;
					bool comMy = comfun(tmpValue,myValue);
					if (comMy){
						flag = tmpNode->tryLeft(tmpValue);
						tmpNode = tmpNode->leftSonPtr;
						break;
					} else {
						flag = tmpNode->tryRight(tmpValue);
						tmpNode = tmpNode->rightSonPtr;
						break;
					}
				} else {
					tmpNode = tmpNode->fatherPtr;
					continue;
				}
			}
		}
		if (!flag){
			return flag;
		}
	}
	return flag;
}

int main(){
	int n;
	scanf("%d",&n);

	vector<int> oriData;
	int tmpData;
	for(int i = 0;i<n;i++){
		scanf("%d",&tmpData);
		oriData.push_back(tmpData);
	}

	Tree t1,t2;
	t1.root->leftBound = numeric_limits<int>::min();
	t1.root->rightBound = numeric_limits<int>::max();
	t2.root->leftBound = numeric_limits<int>::max();
	t2.root->rightBound = numeric_limits<int>::min();
	int flag1 = makeTree(oriData,t1,lessThen);
	int flag2 = makeTree(oriData,t2,moreThen);

	if (flag1){
		printf("%s\n","YES");
		t1.root->printPostorder();
	} else if (flag2){
		printf("%s\n","YES");
		t2.root->printPostorder();
	} else {
		printf("%s\n","NO");
	}

	return 0;
}