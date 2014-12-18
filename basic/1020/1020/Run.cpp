#include <iostream>
#include <algorithm>
using namespace std;

class Cake{
public:
	double storage;
	double price;
	double ratio;
	bool operator<(const Cake cak)const{
		return ratio < cak.ratio;
	}
	void getRatio(){
		ratio = double(price) / double(storage);
	}
};

int main(){
	int num,total;
	scanf("%d %d",&num,&total);

	Cake * cakes = new Cake[num];

	for(int i = 0;i<num;i++){
		scanf("%lf",&(cakes[i].storage));
	}
	for(int i = 0;i<num;i++){
		scanf("%lf",&(cakes[i].price));
	}

	for(int i = 0;i<num;i++){
		cakes[i].getRatio();
	}

	double totalPrice=0;

	if (num!=0){
		sort(cakes,cakes+num);
		for(int i = num - 1;i>=0;i--){
			if (total>cakes[i].storage){
				totalPrice += cakes[i].price;
				total -=cakes[i].storage;
			} else {
				double tmpPrice = (double)cakes[i].price / cakes[i].storage * total;
				totalPrice += tmpPrice;			
				break;
			}
		}
	}	
	printf("%.2lf\n",totalPrice);
	
	delete []cakes;
	return 0;
}