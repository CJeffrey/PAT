#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct User{
	vector<int> downUser;

	double sailes;

	void addUser(vector<int> & vi)const{
		vi.insert(vi.end(),downUser.begin(),downUser.end());
	}
};

int main(){
	int n;
	double p,r;
	scanf("%d%lf%lf",&n,&p,&r);

	r = 1.0 + r / 100;

	vector<User> allUsers;
	allUsers.resize(n);

	int downSize;
	for(int i = 0;i<n;i++){
		scanf("%d",&downSize);
		if (downSize != 0){
			allUsers[i].downUser.resize(downSize);
			for(int j = 0;j<downSize;j++){
				scanf("%d",&allUsers[i].downUser[j]);
			}
		} else {
			scanf("%lf",&allUsers[i].sailes);
		}
	}

	vector<int> upLevel,downLevel;
	vector<int>::iterator vit,vitEnd;
	double price(p);
	double sumPrice(0);

	upLevel.push_back(0);
	while(!upLevel.empty()){
		downLevel.clear();
		for(vit=upLevel.begin(),vitEnd=upLevel.end();vit!=vitEnd;vit++){
			if (allUsers[*vit].downUser.empty()){
				//this is a retailers;
				sumPrice += allUsers[*vit].sailes * price;
			} else {
				allUsers[*vit].addUser(downLevel);
			}
		}
		swap(upLevel,downLevel);
		price *= r;
	}

	printf("%.1lf",sumPrice);

	return 0;
}