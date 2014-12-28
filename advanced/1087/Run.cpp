#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
using namespace std;

struct Tour{
	vector<string> paths;
	int totalHappiness;
};

class City{
public:
	City()
		:happiness(0),totalCost(-1){}
	int happiness;
	int totalCost;
	vector<Tour> myTour;
};

class CityWithName{
public:
	CityWithName(const string & s,const City & c){
		name=s;
		ci=c;
	}
	string name;
	City ci;
};

class Road{
public:
	string name1,name2;
	int cost;

	int getCost(const string & s1,string & s2)const{
		if (s1 == name1){
			s2 = name2;
			return cost;
		}
		if (s1 == name2){
			s2 = name1;
			return cost;
		}
		return -1;
	}
};

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	City startCity;
	string startCityName;
	cin >> startCityName;
	startCity.totalCost=0;
	startCity.myTour.push_back(Tour());
	startCity.myTour[0].paths.push_back(startCityName);
	startCity.myTour[0].totalHappiness = 0;

	map<string,City> allCity;
	vector<Road> allRoads;

	for(int i = 0;i<n-1;i++){
		City tmpCity;
		string tmpCityName;
		cin >> tmpCityName >> tmpCity.happiness;
		allCity.insert(pair<string,City>(tmpCityName,tmpCity));
	}
	for(int i = 0;i<k;i++){
		Road tmpRoad;
		cin >> tmpRoad.name1 >> tmpRoad.name2 >> tmpRoad.cost;
		allRoads.push_back(tmpRoad);
	}

	vector<CityWithName> visitedCity;
	CityWithName startCityWithName(startCityName,startCity);
	visitedCity.push_back(startCityWithName);

	map<string,City>::iterator cit;
	vector<Road>::iterator rit;
	int romTotalCost(-1);
	while(!allCity.empty()){
		CityWithName & tmpCity = visitedCity.back();
		
		int tmpCost;
		string tmpS;
		for(rit = allRoads.begin();rit!=allRoads.end();rit++){
			tmpCost = rit->getCost(tmpCity.name,tmpS);
			if (tmpCost>0){
				cit = allCity.find(tmpS);
				if (cit!=allCity.end()){
					bool update = false;
					if (cit->second.totalCost < 0 || cit->second.totalCost > (tmpCity.ci.totalCost+rit->cost)){
						update = true;
						cit->second.totalCost = tmpCity.ci.totalCost + rit->cost;
						cit->second.myTour.clear();
					} else if (cit->second.totalCost == (tmpCity.ci.totalCost+rit->cost)){
						update = true;
					}
					if (update){
						for(vector<Tour>::iterator vtit = tmpCity.ci.myTour.begin();vtit<tmpCity.ci.myTour.end();vtit++){
							Tour newTour = *vtit;
							newTour.paths.push_back(cit->first);
							newTour.totalHappiness+=cit->second.happiness;
							cit->second.myTour.push_back(newTour);
						}
					}
				}
			}
		}
		if (tmpCity.name == "ROM"){
			break;
		}

		int minCost = -1;
		map<string,City>::iterator minCIT = allCity.end();
		for(cit = allCity.begin();cit!=allCity.end();cit++){
			if(cit->second.totalCost<0){
				continue;
			}
			if (minCIT == allCity.end() || minCIT->second.totalCost > cit->second.totalCost){
				minCIT = cit;
			}
		}
		CityWithName newCWN(minCIT->first,minCIT->second);
		visitedCity.push_back(newCWN);
		allCity.erase(minCIT);
	}

	CityWithName & rom = visitedCity.back();
	vector<Tour> & romTour = rom.ci.myTour;
	vector<Tour>::iterator bestTourIT=romTour.end(),tourIT;
	for(tourIT = romTour.begin();tourIT<romTour.end();tourIT++){
		if ((bestTourIT == romTour.end()) || (bestTourIT->totalHappiness < tourIT->totalHappiness) || ((bestTourIT->totalHappiness == tourIT->totalHappiness) && (bestTourIT->paths.size()>tourIT->paths.size()))){
			bestTourIT = tourIT;
		}
	}
	printf("%d %d %d %d\n",romTour.size(),rom.ci.totalCost,bestTourIT->totalHappiness,bestTourIT->totalHappiness/(bestTourIT->paths.size()-1));
	for(unsigned int i = 0;i<bestTourIT->paths.size();i++){
		printf("%s",bestTourIT->paths[i].c_str());
		if (i+1 < bestTourIT->paths.size()){
			printf("%s","->");
		}
	}

	return 0;
}