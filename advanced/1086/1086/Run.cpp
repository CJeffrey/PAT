#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stack>
using namespace std;

vector<int> preTra,inTra;

void analyzeCMD(const string & s,int &operType,int & cmdNum){
	if (s == "Pop"){
		operType = 1;
		return;
	} else {
		operType = 2;
		string subStr = s.substr(5,s.size() - 5);
		cmdNum = atoi(subStr.c_str());
	}
}

void posTraPrint(const int preBegin,const int preEnd,const int inBegin,const int inEnd){
	if (preEnd - preBegin == 0 && inEnd - inBegin == 0)
		return;
	int root = preTra[preBegin];
	for(int i = inBegin;i<inEnd;i++){
		if (inTra[i] == root){
			int preBeginNew1 = preBegin+1;
			int preEndNew1 = preBeginNew1 + (i - inBegin);
			int inBeginNew1 = inBegin;
			int inEndNew1 = i;
			posTraPrint(preBeginNew1,preBeginNew1,inBeginNew1,inEndNew1);

			int preBeginNew2 = preEndNew1;
			int preEndNew2 = preEnd;
			int inBeginNew2 = i+1;
			int inEndNew2 = inEnd;
			posTraPrint(preBeginNew2,preBeginNew2,inBeginNew2,inEndNew2);
		}
	}
	printf("%d",preTra[preBegin]);
	if (root != preTra[0]){
		printf("%c",' ');
	}
}

int main(){
	int n;
	scanf("%d\n",&n);

	
	stack<int> valueStack;
	string tmpCMD;
	int tmpType,tmpNum;
	for(int i = 0;i<2*n;i++){
		getline(cin,tmpCMD);
		analyzeCMD(tmpCMD,tmpType,tmpNum);
		switch(tmpType){
			case 2:
				preTra.push_back(tmpNum);
				valueStack.push(tmpNum);
				break;
			case 1:
				inTra.push_back(valueStack.top());
				valueStack.pop();
				break;
		}
	}

	posTraPrint(0,n,0,n);

	return 0;
}