#include <iostream>

using namespace std;
class Rode{
public:
	int city1;
	int city2;
	int rodeLength;
	void findLength(const int c1,int & c2,int &length){
		if (c1 == city1){
			c2 = city2;
			length = rodeLength;
			return;
		}
		if (c1 == city2){
			c2 = city1;
			length = rodeLength;
			return;
		}
		length = -1;
		return;
	}
};

class Rescue{
public:
	Rescue()
		:totalLength(-1),totalType(0),maxPeople(0){}

	int totalLength;
	int totalType;
	
	int maxPeople;
	
	void init(int tLength,int tType){
		totalLength = tLength;
		totalType=tType;
	}
};

int main(){
	int n,m,c1,c2;
	scanf("%d%d%d%d",&n,&m,&c1,&c2);

	int *people  = new int[n];
	Rode *rodes  = new Rode[m];
	for(int i = 0;i<n;i++){
		scanf("%d",&(people[i]));
	}
	for(int i = 0;i<m;i++){
		scanf("%d%d%d",&(rodes[i].city1),&(rodes[i].city2),&(rodes[i].rodeLength));
	}
	
	Rescue * allRescue = new Rescue[n];

	allRescue[c1].init(0,1);
	//allRescue[c1].totalPeople.insert(c1);
	allRescue[c1].maxPeople += people[c1];
	
	bool * okCity = new bool[n];
	for(int i = 0;i<n;i++){
		okCity[i] = false;
	}
	okCity[c1] = true;

	int startCity = c1;
	int tmpMinRes;
	int tmpMinLength;
	int nextCity;
	int nextLength;
	for(int i = 0;i<n;i++){
		if (startCity == c2){
			break;
		}
		for(int j = 0;j<m;j++){
			rodes[j].findLength(startCity,nextCity,nextLength);
			if (nextLength > 0){
				if (okCity[nextCity])
					continue;
				if (allRescue[nextCity].totalLength < 0 || allRescue[startCity].totalLength + nextLength < allRescue[nextCity].totalLength){
					allRescue[nextCity].init(allRescue[startCity].totalLength + nextLength,allRescue[startCity].totalType);
					allRescue[nextCity].maxPeople = allRescue[startCity].maxPeople + people[nextCity];
					/*allRescue[nextCity].totalPeople.clear();
					allRescue[nextCity].totalPeople.insert(allRescue[startCity].totalPeople.begin(),allRescue[startCity].totalPeople.end());
					allRescue[nextCity].totalPeople.insert(nextCity);*/
				} else if (allRescue[startCity].totalLength + nextLength == allRescue[nextCity].totalLength){
					allRescue[nextCity].totalType += allRescue[startCity].totalType;
					//allRescue[nextCity].totalPeople.insert(allRescue[startCity].totalPeople.begin(),allRescue[startCity].totalPeople.end());
					int newMaxPeople = allRescue[startCity].maxPeople + people[nextCity];
					allRescue[nextCity].maxPeople = std::max(allRescue[nextCity].maxPeople,newMaxPeople);
				}
			}
		}

		tmpMinLength = -1;
		for(int j = 0;j<n;j++){
			if (okCity[j])
				continue;
			if (allRescue[j].totalLength > 0){
				if (tmpMinLength < 0){
					tmpMinLength = allRescue[j].totalLength;
					tmpMinRes = j;
				} else {
					if (allRescue[j].totalLength < tmpMinLength){
						tmpMinLength = allRescue[j].totalLength;
						tmpMinRes = j;
					}
				}
			}
		}
		okCity[tmpMinRes] = true;
		startCity = tmpMinRes;
	}

	int sumPeople=allRescue[c2].maxPeople;

	printf("%d %d",allRescue[c2].totalType,sumPeople);

	delete []okCity;
	delete []allRescue;
	delete []people;
	delete []rodes;
	return 0;
}