#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct Term{
	int exponent;
	double coefficient;

	bool operator<(const Term &t)const{
		return this->exponent < t.exponent;
	}
	Term operator*(const Term &t)const{
		Term tmpTerm;
		tmpTerm.exponent = this->exponent + t.exponent;
		tmpTerm.coefficient = this->coefficient * t.coefficient;
		return tmpTerm;
	}
};


int main(){
	int * nums = new int[2];
	Term ** Polynomials = new Term *[2];
	for(int i = 0;i<2;i++){
		scanf("%d",&(nums[i]));
		Polynomials[i] = new Term[nums[i]];
		for(int j = 0;j<nums[i];j++){
			scanf("%d%lf",&(Polynomials[i][j].exponent),&(Polynomials[i][j].coefficient));
		}
	}


	map<int,double> resultMap;
	map<int,double>::iterator mit;
	for(int i = 0;i<nums[0];i++){
		for(int j = 0;j<nums[1];j++){
			Term tmpResult = Polynomials[0][i] * Polynomials[1][j];
			mit = resultMap.find(tmpResult.exponent);
			if (mit == resultMap.end()){
				resultMap.insert(pair<int,double>(tmpResult.exponent,tmpResult.coefficient));
			} else {
				mit->second += tmpResult.coefficient;
			}
		}
	}

	int resultNum = resultMap.size();
	Term * result = new Term[resultNum];
	int resultCounter = 0;
	for(mit = resultMap.begin();mit!=resultMap.end();mit++){
		//cout << mit->second << endl;
		if (mit->second == 0){
			resultNum--;
			continue;
		}
		result[resultCounter].exponent = mit->first;
		result[resultCounter].coefficient = mit->second;
		resultCounter++;
	}
	sort(result,result+resultNum);

	printf("%d",resultNum);
	if (resultNum == 0){
	}
	for(int i = resultNum -1;i>=0;i--){
		printf("%c",' ');
		printf("%d %.1lf",result[i].exponent,result[i].coefficient);

	}


	delete []Polynomials[0];
	delete []Polynomials[1];
	delete []Polynomials;
	delete []nums;
	return 0;
}