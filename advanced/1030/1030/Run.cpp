#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define MAXNUMBER		1000000

template <class T>
class myGraph{
public:
	myGraph(const int size)
		:_size(size){
			int totalSize = _size*_size;
			data = new T [totalSize];
	}

	void init(const T & standardValue){
		int totalSize = _size*_size;
		for(int i = 0;i<totalSize;i++){
			data[i] = standardValue;
		}
	}

	void setData(const int i,const int j,const T & value){
		data[i * _size + j] = value;
	}
	T getData(const int i,const int j)const{
		return data[i * _size + j];
	}
private:
	int _size;
	T * data;
};

struct myRoad{
public:
	myRoad()
		:distance(MAXNUMBER),cost(MAXNUMBER){}
	int distance;
	int cost;
};

struct myCity{
public:
	myCity(int id)
		:cityID(id),totalDistance(MAXNUMBER),totalCost(MAXNUMBER){}

	int cityID;
	vector<int> plan;
	int totalDistance;
	int totalCost;

	bool operator<(const myCity & mc)const{
		return cityID < mc.cityID;
	}
};

struct myPlane{
	myPlane()
		:totalDistance(MAXNUMBER),totalCost(MAXNUMBER){};
	vector<int> plan;
	int totalDistance;
	int totalCost;
};

int main(){
	int n,m,s,d;
	scanf("%d%d%d%d",&n,&m,&s,&d);

	myGraph<myRoad> roads = myGraph<myRoad>(n);

	int c1,c2;
	myRoad tmpRoad;
	for(int i = 0;i<m;i++){
		scanf("%d%d%d%d",&c1,&c2,&(tmpRoad.distance),&(tmpRoad.cost));
		roads.setData(c1,c2,tmpRoad);
		roads.setData(c2,c1,tmpRoad);
	}

	//set<myCity> cities2;
	map<int,myPlane> cities2;
	vector<myCity> cities1;
	myCity startCity(s),destCity(d);
	startCity.totalCost = 0;
	startCity.totalDistance=0;
	startCity.plan.push_back(s);
	cities1.push_back(startCity);
	for(int i = 0;i<n;i++){
		if (i == s)
			continue;
		myPlane tmpPlane;
		cities2.insert(pair<int,myPlane>(i,tmpPlane));
	}

	map<int,myPlane>::iterator cityIT;
	while(true){
		myCity lastCity = cities1.back();
		int lastCityID = lastCity.cityID;

		if (lastCityID == d){
			for(vector<int>::const_iterator iit = lastCity.plan.begin();iit<lastCity.plan.end();iit++){
				printf("%d ",*iit);
			}
			printf("%d %d",lastCity.totalDistance,lastCity.totalCost);
			break;
		}

		for(int i = 0;i<n;i++){
			if (roads.getData(lastCityID,i).distance == MAXNUMBER)
				continue;

			cityIT = cities2.find(i);
			if (cityIT == cities2.end())
				continue;

			int newDistance = roads.getData(lastCityID,i).distance + lastCity.totalDistance;
			int newCost = roads.getData(lastCityID,i).cost + lastCity.totalCost;

			myPlane & changCity = cityIT->second;
			if (newDistance < cityIT->second.totalDistance){
				changCity.totalDistance = newDistance;
				changCity.totalCost = newCost;
				changCity.plan = lastCity.plan;
				changCity.plan.push_back(i);
			} else if (newDistance == cityIT->second.totalDistance && newCost < cityIT->second.totalCost){
				changCity.totalDistance = newDistance;
				changCity.totalCost = newCost;
				changCity.plan = lastCity.plan;
				changCity.plan.push_back(i);
			}
		}

		int minDistance = MAXNUMBER;
		int minCityID = MAXNUMBER;
		map<int,myPlane>::iterator minCityIT;
		for(cityIT = cities2.begin();cityIT != cities2.end();cityIT++){
			if (cityIT->second.totalDistance < minDistance){
				minCityIT = cityIT;
				minDistance = minCityIT->second.totalDistance;
				minCityID = minCityIT->first;
			}
		}
		
		myCity minCity(minCityID);
		minCity.plan = minCityIT->second.plan;
		minCity.totalCost = minCityIT->second.totalCost;
		minCity.totalDistance = minCityIT->second.totalDistance;
		cities1.push_back(minCity);
		cities2.erase(minCityIT);
	}

	return 0;
}