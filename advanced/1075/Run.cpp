#include <iostream>
#include <algorithm>

int n,k,m;
int * pp;
struct User{
	User()
		:p(NULL),perfectNum(0),willShow(false){
			p = new int [k+1];
			for(int i = 0;i<=k;i++){
				p[i] = -1;
			}
	}
	~User(){
		if (p)
			delete [] p;
	}
	User(const User & u){
		willShow = u.willShow;
		id = u.id;
		perfectNum = u.perfectNum;
		sum = u.sum;
		p = new int[k+1];
		for(int i = 0;i<=k;i++){
			p[i] = u.p[i];
		}
	}
	int id;
	int * p;

	int perfectNum;
	int sum;
	bool willShow;

	int getSum(){
		int ret = 0;
		bool hasSum(false);
		for(int i = 1;i<=k;i++){
			if (p[i] >= 0){
				hasSum=true;
				ret += p[i];
				if (p[i] == pp[i])
					perfectNum++;
			}
		}
		if (!hasSum)
			return -1;
		else
			return ret;
	}

	User operator=(const User & u){
		willShow = u.willShow;
		id = u.id;
		perfectNum = u.perfectNum;
		sum = u.sum;
		for(int i = 0;i<=k;i++){
			p[i] = u.p[i];
		}
		return *this;
	}

	bool operator<(const User & u)const{
		if (sum == u.sum){
			if (perfectNum == u.perfectNum){
				return id > u.id;
			} else {
				return perfectNum < u.perfectNum;
			}
		} else {
			return sum < u.sum;
		}
	}

	void print()const{
		printf("%05d %d",id,sum);
		for(int i = 1;i<=k;i++){
			printf(" ");
			if (p[i]>=0)
				printf("%d",p[i]);
			else
				printf("-");
		}
		printf("\n");
	}
};

int main(){
	scanf("%d%d%d",&n,&k,&m);

	pp = new int[k+1];
	for(int i = 1;i<=k;i++){
		scanf("%d",pp+i);
	}

	User * allUser = new User[n+1];
	for(int i = 1;i<=n;i++){
		allUser[i].id = i;
	}

	int userID,probID,score;
	for (int i = 0;i<m;i++){
		scanf("%d%d%d",&userID,&probID,&score);
		if (score >= 0){
			allUser[userID].willShow = true;
		}
		if (score < 0)
			score = 0;

		int oriScore = allUser[userID].p[probID];
		if (oriScore < score){
			allUser[userID].p[probID] = score;
		}
	}

	for(int i = 1;i<=n;i++){
		allUser[i].sum = allUser[i].getSum();
	}

	std::sort(&allUser[1],&allUser[n+1]);
/*

	for(int i = 1;i<=n;i++){
		allUser[i].print();
	}*/

	int rank = 1;
	int lastScore = allUser[n].sum;
	for(int i = n;i>=1;i--){
		if (!allUser[i].willShow)
			continue;
		if (allUser[i].sum != lastScore){
			rank = n - i + 1;
			lastScore = allUser[i].sum;
		}
		printf("%d ",rank);
		allUser[i].print();
	}

	delete []allUser;
	delete []pp;
	return 0;
}