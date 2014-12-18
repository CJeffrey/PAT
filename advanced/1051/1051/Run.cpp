#include <iostream>
#include <stack>
using namespace std;

int main(){
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);

	int * popSequence = new int[n];
	stack<int> testStack;
	for(int i =0;i<k;i++){
		for(int i = 0;i<n;i++){
			scanf("%d",popSequence + i);
		}
		
		while(!testStack.empty()){
			testStack.pop();
		}
		
		bool passTest = true;
		int popValue;
		int pushedValue = 0;
		for(int i = 0;i<n;i++){
			popValue = popSequence[i];
			if (popValue > pushedValue){
				for(int j = pushedValue + 1; j <= popValue;j++){
					testStack.push(j);
				}
				pushedValue = popValue;
			}
			
			if (testStack.size() <= m && testStack.top() == popValue){
				testStack.pop();
			} else {
				passTest = false;
				break;
			}
		}

		if (passTest){
			printf("%s","YES\n");
		} else {
			printf("%s","NO\n");
		}
	}


	delete [] popSequence;
	return 0;
}