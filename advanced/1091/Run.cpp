#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int mm,nn,ll,t;

class Pixel{
public:
	Pixel()
		:stroke(false),analyzed(false){};
	bool stroke;
	bool analyzed;
};

class Slide{
public:
	vector<vector<Pixel>> data;

	void init(const int m,const int n){
		data.resize(m);
		for(int i = 0;i<m;i++){
			data[i].resize(n);
		}
	}
};

struct Position{
private:
	int data[3];
	unsigned int searchID;
public:
	Position()
		:searchID(0),l(data[0]),m(data[1]),n(data[2]){};
	Position(const Position &p)
		:searchID(0),l(data[0]),m(data[1]),n(data[2]){
			init(p);
	};
	int &l,&m,&n;

	bool nextPos(Position & p){
		p = *this;
		if (searchID >=6){
			return false;
		}
		int i1 = searchID / 2;
		int i2 = searchID % 2;
		i2 <<= 1;
		i2 -= 1;
		p.data[i1] += i2;
		p.searchID=0;

		searchID++;

		return true;
	}

	Position operator=(const Position &p){
		init(p);
		return p;
	}

	bool isLegal()const{
		return (l >=0 && m >=0 && n>=0 && l<ll && m < mm && n<nn);
	}
private:
	void init(const Position &p){
		for(int i = 0;i<3;i++)
			data[i] = p.data[i];
		searchID=p.searchID;
	}
};

class MRI{
public:
	vector<Slide> allSlides;

	int runSearch(){
		int ret(0);
		Position pit;
		
		int tmpRet;
		for(pit.l=0;pit.l<ll;pit.l++){
			for(pit.m=0;pit.m<mm;pit.m++){
				for(pit.n=0;pit.n<nn;pit.n++){
					if (allSlides[pit.l].data[pit.m][pit.n].stroke && !allSlides[pit.l].data[pit.m][pit.n].analyzed){
						allSlides[pit.l].data[pit.m][pit.n].analyzed = true;
						tmpRet = runSpread(pit);
						if (tmpRet >= t)
							ret+=tmpRet;
					}					
				}
			}
		}
		return ret;
	}
private:
	int runSpread(const Position & p){
		int ret = 0;
		stack<Position> allPos;
		allPos.push(p);

		Position tmpP;
		while(!allPos.empty()){
			if (allPos.top().nextPos(tmpP)){
				if (tmpP.isLegal()){
					if (allSlides[tmpP.l].data[tmpP.m][tmpP.n].stroke && !allSlides[tmpP.l].data[tmpP.m][tmpP.n].analyzed){
						allSlides[tmpP.l].data[tmpP.m][tmpP.n].analyzed = true;
						allPos.push(tmpP);
					}
				}
			} else {
				ret++;
				allPos.pop();
			}
		}

		return ret;
	}
};

int main(){

	scanf("%d%d%d%d",&mm,&nn,&ll,&t);

	MRI myMri;
	myMri.allSlides.resize(ll);
	int tmpC;
	for(int i = 0;i<ll;i++){
		myMri.allSlides[i].init(mm,nn);
		for(int j = 0;j<mm;j++){
			for(int k = 0;k<nn;k++){
				scanf("%d",&tmpC);
				myMri.allSlides[i].data[j][k].stroke = bool(tmpC);
			}
		}
	}

	int ret = myMri.runSearch();
	printf("%d",ret);

	return 0;
}