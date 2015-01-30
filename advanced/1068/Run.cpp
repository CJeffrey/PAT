#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<int> data;
stack<pair<unsigned int,unsigned int>> attempt;
unsigned int sum=0;
unsigned int n,m;
unsigned int firPos(0);
void abandonLast(){
	if (!attempt.empty()){
		sum-=data[attempt.top().first];
		attempt.pop();
	}
}

void tryNext(){
	if (!attempt.empty()){
		if (attempt.top().second + 1 < n){
			unsigned int nextPos = ++attempt.top().second;
			attempt.push(pair<unsigned int,unsigned int>(nextPos,nextPos));
			sum+=data[nextPos];
		} else {
			abandonLast();
			tryNext();
		}
	} else if (firPos < n){
		attempt.push(pair<unsigned int,unsigned int>(firPos,firPos));
		sum += data[firPos];
		firPos++;
	}
}

int main1(){
	scanf("%d%d",&n,&m);
	
	data.resize(n);
	for(unsigned int i = 0;i<n;i++){
		scanf("%d",&data[i]);
	}

	sort(data.begin(),data.end());

	while(sum != m && firPos < n){
		if (sum > m){
			abandonLast();
			abandonLast();
			tryNext();
		} else {
			tryNext();
		}
	}

	if (sum == m){
		vector<unsigned int> outPut;
		while(!attempt.empty()){
			outPut.push_back(attempt.top().first);
			attempt.pop();
		}
		for(vector<unsigned int>::const_reverse_iterator iit = outPut.rbegin();iit!=outPut.rend();iit++){
			printf("%d",data[*iit]);
			if (iit + 1 != outPut.rend())
				printf(" ");
		}
	} else {
		printf("No Solution");
	}

	return 0;
}