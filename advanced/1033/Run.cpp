#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double c,d,davg;
int n;

struct Station{
  Station()
    :price(0),beginPos(0){}
  double price;
  double beginPos;

  double endPos;

  void init(const double fullDistance){
    scanf("%lf%lf",&price,&beginPos);
    endPos = beginPos + fullDistance;
  }
  bool inside(const double dis)const{
    return (beginPos <= dis && dis <= endPos);
  }
};

bool comparePrice(const Station & s1,const Station & s2){
  return s1.price < s2.price;
}

bool compareDistance(const Station & s1,const Station & s2){
  return s1.beginPos < s2.beginPos;
}

struct Road{
  double d1,d2;

  bool inside(const double d)const{
    return (d1 <= d && d <= d2);
  }

  void leftMerge(const Road & r){
    d1 = r.d1;
  }

  void rightMerge(const Road & r){
    d2 = r.d2;
  }
};

class RoadManager{
public:
  RoadManager()
    :price(0){};
  vector<Road> allRoads;
  double price;

  void addRoad(const Station & s){
    vector<Road>::iterator beginIt(allRoads.begin()),endIt(allRoads.end());
    vector<Road>::iterator it1,it2;
    for(it1 = beginIt;it1<endIt;it1++){
      if (it1->inside(s.beginPos))
        break;
    }
    for(it2 = beginIt;it2<endIt;it2++){
      if (it2->inside(s.endPos))
        break;
    }
    double pos1,pos2;
    if (it1==endIt){
      pos1 = s.beginPos;
    } else {
      pos1 = it1->d2;
    }
    if (it2==endIt){
      pos2 = s.endPos;
    } else {
      pos2 = it2->d1;
    }

    if (pos2 <= pos1)
      return;
    price += (pos2-pos1)/davg * s.price;

    Road newRoad;
    newRoad.d1 = pos1;
    newRoad.d2 = pos2;
    if (it1==endIt && it2==endIt){
      allRoads.push_back(newRoad);
    } else if (it1==endIt && it2 != endIt){
      it2->leftMerge(newRoad);
    } else if (it1!=endIt && it2 == endIt){
      it1->rightMerge(newRoad);
    } else {
      it1->rightMerge(*it2);
      allRoads.erase(it2);
    }
  }
};

int main(){
  scanf("%lf%lf%lf%d",&c,&d,&davg,&n);
  const double fullTankDistance = c * davg;
  vector<Station> allStations;
  //allStations.resize(n);
  for(int i = 0;i<n;i++){
    Station tmpStation;
    tmpStation.init(fullTankDistance);
    if (tmpStation.beginPos < d){
      allStations.push_back(tmpStation);
    }
  }
  sort(allStations.begin(),allStations.end(),comparePrice);

  RoadManager rm;
  double distance(0),price(0);
  vector<Station> tmpSort;
  vector<Station>::const_iterator sit;
  const vector<Station>::const_iterator sitBegin(allStations.begin()),sitEnd(allStations.end());
  Road r1,r2;
  r1.d1 = -fullTankDistance*2;
  r1.d2 = 0;
  r2.d1 = d;
  r2.d2 = d + fullTankDistance * 2;
  rm.allRoads.push_back(r1);rm.allRoads.push_back(r2);
  for(sit = sitBegin;sit<sitEnd;sit++){
    rm.addRoad(*sit);
  }

  if (rm.allRoads.size() == 1){
    printf("%.2lf",rm.price);
  } else {
    printf("The maximum travel distance = %.2lf",rm.allRoads[0].d2);
  }

  return 0;
}