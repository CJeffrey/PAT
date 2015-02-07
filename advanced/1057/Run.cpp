#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string.h>
#include <algorithm>
using namespace std;

const char actPop[4] = "Pop";
const char actPush[5] = "Push";
const char actMedian[11] = "PeekMedian";

int main(){
	int n ;
	scanf("%d",&n);

	vector<int> data;
	data.reserve(n);

	multiset<int> orderedList;
	multiset<int>::iterator lit,litMid(orderedList.begin()),litEnd(orderedList.end());

	char buff[11];
	int tmpValue;
	bool isError;
	int counter;
	for(int i = 0;i<n;i++){
		memset(buff,0,11);
		scanf("%s",buff);

		isError = false;
		if (strcmp(buff,actPop) == 0){
			if (data.empty()){
				isError = true;
			} else {
				tmpValue = data.back();
				lit = orderedList.lower_bound(tmpValue);
				printf("%d\n",tmpValue);

				bool isOdd = data.size() % 2 == 1;
				data.pop_back();
				
				if (litMid == lit){
					litMid = orderedList.erase(lit);
					if (isOdd){
						if (orderedList.empty())
							litMid = litEnd;
						else 
							litMid--;
					}
				} else {
					orderedList.erase(lit);
					if (*litMid < tmpValue && isOdd){
						litMid--;
					} else if (*litMid >= tmpValue && !isOdd){
						litMid++;
					}
				}
			}
		} else if (strcmp(buff,actPush) == 0){
			scanf("%d",&tmpValue);

			bool isOdd = data.size() % 2 == 1;
			data.push_back(tmpValue);

			lit = orderedList.lower_bound(tmpValue);
			orderedList.insert(lit,tmpValue);
			if (litMid == litEnd){
				litMid = orderedList.begin();
			} else {
				if (*litMid < tmpValue && !isOdd){
					litMid++;
				} else if (*litMid >= tmpValue && isOdd){
					litMid--;
				}
			}
		} else {
			if (data.empty()){
				isError = true;
			} else {
				printf("%d\n",*litMid);
			}
		}
		if (isError)
			printf("Invalid\n");
	}

	return 0;
}