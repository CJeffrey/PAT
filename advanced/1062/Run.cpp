#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Man{
public:
	Man(const int _id,const int _v,const int _t)
		:id(_id),virtue(_v),talent(_t){
			total = virtue + talent;
	}
	int virtue;
	int talent;
	int id;
	int total;

	void myPrint()const{
		printf("\n%d %d %d",id,virtue,talent);
	}
};

bool compareMan(const Man & m1,const Man & m2){
	if (m1.total == m2.total){
		if (m1.virtue == m2.virtue){
			return m1.id < m2.id;
		} else {
			return m1.virtue > m2.virtue;
		}
	} else {
		return m1.total > m2.total;
	}
}

int main(){
	int n,l,h;
	scanf("%d%d%d",&n,&l,&h);

	vector<vector<Man>> allMan;
	const int manType = 4;
	for(int i = 0;i<manType;i++){
		allMan.push_back(vector<Man>());
	}

	vector<Man> & sage = allMan[0];
	vector<Man> & noble = allMan[1];
	vector<Man> & fool = allMan[2];
	vector<Man> & small = allMan[3];
	int tmpID,tmpV,tmpT;
	for(int i = 0;i<n;i++){
		scanf("%d%d%d",&tmpID,&tmpV,&tmpT);
		if (tmpV >= l && tmpT >= l){
			Man tmpMan = Man(tmpID,tmpV,tmpT);
			if (tmpV >= h && tmpT >= h){
				sage.push_back(tmpMan);
			} else if (tmpV >= h){
				noble.push_back(tmpMan);
			} else if (tmpV >= tmpT){
				fool.push_back(tmpMan);
			} else {
				small.push_back(tmpMan);
			}
		}
	}
	
	for(int i =0;i<manType;i++){
		sort(allMan[i].begin(),allMan[i].end(),compareMan);
	}


	printf("%d",sage.size()+noble.size()+fool.size()+small.size());

	for(int i = 0;i<manType;i++){
		for(vector<Man>::const_iterator it1(allMan[i].begin()),it2(allMan[i].end());it1!=it2;it1++){
			it1->myPrint();
		}
	}

	return 0;
}