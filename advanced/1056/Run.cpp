#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

struct Mice{
	int weight;
	int order;
	int rank;
};

bool CompareMicePtr(const Mice * m1,const Mice * m2){
	return m1->weight < m2->weight;
}

int main(){
	int np,ng;
	scanf("%d%d",&np,&ng);

	vector<int> order;
	vector<Mice> mouse;
	vector<Mice*> workMouse;
	mouse.resize(np);
	order.resize(np);

	for(int i = 0;i<np;i++){
		scanf("%d",&(mouse[i].weight));
	}
	for(int i = 0;i<np;i++){
		scanf("%d",&(order[i]));
		workMouse.push_back(&(mouse[order[i]]));
	}

	vector<Mice*> swapMouse;
	vector<Mice*>::iterator mitBegin,mitEnd;
	vector<Mice*>::iterator mitMark;
	vector<Mice*>::iterator maxMark;
	stack<Mice*> result;
	int counter(0);
	while(!workMouse.empty()){
		swapMouse.clear();
		const int groupNum = workMouse.size() / ng;
		mitBegin = workMouse.begin();
		for(int i = 0;i<=groupNum;i++){
			if (mitBegin == workMouse.end())
				break;
			if (i<groupNum){
				mitEnd = mitBegin + ng;
			} else {
				mitEnd = workMouse.end();
			}
			maxMark = max_element(mitBegin,mitEnd,CompareMicePtr);
			swapMouse.push_back(*maxMark);
			for(mitMark=mitBegin;mitMark<mitEnd;mitMark++){
				if (mitMark != maxMark){
					(*mitMark)->order=counter;
					result.push(*mitMark);
				}
			}
			mitBegin = mitEnd;
		}
		
		if (swapMouse.size() == workMouse.size()){
			swapMouse.front()->order = counter;
			result.push(swapMouse.front());
			counter++;
			break;
		}
		counter++;
		swap(swapMouse,workMouse);
	}

	int lastRank;
	for(int i = 1;i<=np;i++){
		if (result.top()->order != counter){
			result.top()->rank = i;
			lastRank = i;
			counter=result.top()->order;
		} else {
			result.top()->rank=lastRank;
		}
		result.pop();
	}

	for(int i = 0;i<np;i++){
		printf("%d",mouse[i].rank);
		if (i+1 != np){
			printf("%c",' ');
		}
	}

	return 0;
}