#include <iostream>
#include <vector>

using namespace std;

int main(){
	int size;
	cin >> size;

	bool * nums = new bool[size + 1];
	vector<int> primeNums;
	for(int i = 0;i<=size;i++){
		nums[i]=true;
	}
	nums[0]=false;
	nums[1]=false;
	for(int i = 2;i<=size;i++){
		if (nums[i]){
			primeNums.push_back(i);
			int j = 2;int mulValue = i*j;
			for(;mulValue<=size;mulValue = i*(++j)){
				nums[mulValue] = false;
			}
		}		
	}

	int counter = 0;
	for(vector<int>::const_iterator cit1 = primeNums.begin();cit1<primeNums.end();cit1++){
		vector<int>::const_iterator cit2 = cit1+1;
		if (cit2 < primeNums.end()){
			int diff = *cit2 - *cit1;
			if (diff == 2)
				counter++;
		}
	}
	cout << counter;


	delete []nums;

	return 0;
}