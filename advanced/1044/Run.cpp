#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<int> data;
int n,m;
vector<pair<int,int>> answer;

int searchBefore(const int ii,const int jj,int & value){
	for(int j = jj;j>=ii;j--){
		value -= data[j];
		if (value < m){
			value += data[j];
			return j;
		}
	}
	return -1;
}

int searchAfter(const int ii,const int jj,int & value){
	for(int j = jj+1;j<n;j++){
		value += data[j];
		if (value >= m){
			return j;
		}
	}
	return -1;
}

void searchRun(){
	int minSum = numeric_limits<int>::max();
	int sum=0;
	int i = -1;
	int j = -1;
	
	while(i<n){
		if (i >= 0){
			sum -= data[i];
			i++;
		} else {
			i = 0;
		}
		if (sum < m){
			j = searchAfter(i,j,sum);
		} else {
			j = searchBefore(i,j,sum);
		}
		if (j < 0){
			break;
		}
		if (sum >= m){
			if (sum < minSum){
				minSum = sum;
				answer.clear();
				answer.push_back(pair<int,int>(i,j));
			} else if (sum == minSum){
				answer.push_back(pair<int,int>(i,j));
			}
		}
	}	
}

int main(){
	
	scanf("%d%d",&n,&m);

	
	data.resize(n);
	for(int i = 0;i<n;i++){
		scanf("%d",&data[i]);
	}

	
	searchRun();

	vector<pair<int,int>>::const_iterator pit(answer.begin()),pitEnd(answer.end());
	for(;pit<pitEnd;pit++){
		printf("%d-%d\n",pit->first+1,pit->second+1);
	}

	return 0;
}