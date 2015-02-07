#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Node{
public:
	int address;
	char key;
	int next;

	void getData(){
		scanf("%d %c %d",&address,&key,&next);
	}

};

int main(){
	int stardAdd[2];
	int n;
	scanf("%d%d%d",stardAdd,stardAdd+1,&n);

	list<Node> allNodes;
	allNodes.resize(n);

	vector<Node*> allAddress;
	allAddress.resize(100000,NULL);

	list<Node>::iterator lit,litEnd,litNext;
	for(lit=allNodes.begin(),litEnd=allNodes.end();lit!=litEnd;lit++){
		lit->getData();
		allAddress[lit->address] = &(*lit);
	}

	list<int> words[2];
	list<int> & word0 = words[0];
	list<int> & word1 = words[1];
	for(int i = 0;i<2;i++){
		while(true){
			words[i].push_back(stardAdd[i]);
			if (stardAdd[i] < 0 || allAddress[stardAdd[i]] == NULL)
				break;
			else 
				stardAdd[i]=allAddress[stardAdd[i]]->next;
		}
	}

	list<int>::const_reverse_iterator lit0(word0.rbegin()),lit1(word1.rbegin()),litEnd0(word0.rend()),litEnd1(word1.rend());
	for(;lit0!=litEnd0,lit1!=litEnd1;lit0++,lit1++){
		if (*lit0 != *lit1)
			break;
	}

	int answer;
	if (lit0 == word0.rbegin())
		answer = -1;
	else 
		answer = *(--lit0);

	if (answer<0)
		printf("%d",answer);
	else 
		printf("%05d",answer);

	return 0;
}