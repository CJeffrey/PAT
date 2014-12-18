#include <iostream>

struct Person{
	Person()
		:level(-1),hasChild(false){}
	int level;
	bool hasChild;
	//bool hasBeFound;
};

struct Relation{
	Relation()
		:childPtr(NULL),childNum(0){}
	Relation(int childrenNum)
		:childNum(childrenNum){
		childPtr = new int[childrenNum];
	}
	~Relation(){
		if (childPtr)
			delete []childPtr;
	}

	int fatherIndex;
	int * childPtr;
	int childNum;


};

int main(){
	int n,m;
	scanf("%d%d",&n,&m);

	Person * allPeople = new Person[n+1];
	Relation * allRelation = new Relation[m];

	int tmpFather,tmpchildNum,tmpChild;
	for(int i = 0;i<m;i++){
		scanf("%d%d",&tmpFather,&tmpchildNum);
		allRelation[i].fatherIndex = tmpFather;
		allRelation[i].childNum = tmpchildNum;
		allRelation[i].childPtr=new int[tmpchildNum];
		for(int j = 0;j<tmpchildNum;j++){
			scanf("%d",&tmpChild);
			allRelation[i].childPtr[j] = tmpChild;
		}
	}

	allPeople[1].level = 0;

	int maxLevel = 0;

	bool hasChanged = true;
	while(hasChanged){
		hasChanged = false;
		for(int i = 0;i<m;i++){
			tmpFather = allRelation[i].fatherIndex;
			if (allPeople[tmpFather].level >= 0  && !allPeople[tmpFather].hasChild){
				hasChanged = true;
				allPeople[tmpFather].hasChild = true;
				for(int j = 0;j<allRelation[i].childNum;j++){
					allPeople[allRelation[i].childPtr[j]].level = allPeople[tmpFather].level + 1;
				}
				maxLevel = std::max(maxLevel,allPeople[tmpFather].level + 1);
			}
		}
	}
	
	for(int i = 1;i<=n;i++){
		if (allPeople[i].level < 0)
			allPeople[i].level = 0;
	}

	int levelCounter;
	for(int i = 0;i<=maxLevel;i++){
		levelCounter = 0;
		for(int j = 1;j<=n;j++){
			if (allPeople[j].level == i && !allPeople[j].hasChild){
				levelCounter++;
			}
		}
		printf("%d",levelCounter);
		if (i!=maxLevel)
			printf("%c",' ');
	}

	delete []allRelation;
	delete []allPeople;
	return 0;
}