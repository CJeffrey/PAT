#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct User{
	vector<int> upUser;

	bool inUser(const set<int> & setInt)const{
		set<int>::const_iterator sit,sitEnd(setInt.end());
		for(vector<int>::const_iterator iit(upUser.begin()),iitEnd(upUser.end());iit!=iitEnd;iit++){
			sit = setInt.find(*iit);
			if (sit != sitEnd)
				return true;
		}
		return false;
	}
};

int main(){
	int n,l;
	scanf("%d%d",&n,&l);

	vector<User> allUsers;
	allUsers.resize(n+1);

	int upSize;
	for(int i = 1;i<=n;i++){
		scanf("%d",&upSize);
		allUsers[i].upUser.resize(upSize);
		for(int j = 0;j<upSize;j++){
			scanf("%d",&allUsers[i].upUser[j]);
		}
	}

	int k,firstUser;
	scanf("%d",&k);
	set<int> upLevel,downLevel;
	set<int>::iterator vit,vitEnd;
	set<int> allReadyIn;
	set<int>::iterator sit,sitEnd;
	int counter;
	for(int i=0;i<k;i++){
		scanf("%d",&firstUser);
		counter=0;
		upLevel.clear();
		downLevel.clear();
		allReadyIn.clear();
		upLevel.insert(firstUser);
		allReadyIn.insert(firstUser);
		for(int i = 0;i<l;i++){
			sitEnd=allReadyIn.end();
			vitEnd=upLevel.end();
			for(int j = 1;j<=n;j++){
				sit=allReadyIn.find(j);
				if (sit != sitEnd){
					continue;
				}
				if (allUsers[j].inUser(upLevel)){
					downLevel.insert(j);
					allReadyIn.insert(j);
					counter++;
				}
			}
			swap(upLevel,downLevel);
		}
		printf("%d\n",counter);
	}

	return 0;
}