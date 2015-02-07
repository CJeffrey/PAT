#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

class Person{
public:
	Person(){
		memset(name,0,9);
	}
	char name[9];
	int age;
	int worth;

	bool operator<(const Person & p)const{
		return age<p.age;
	}

	void print()const{
		printf("%s %d %d\n",name,age,worth);
	}
};

bool comPerson(const Person & p1,const Person & p2){
	if (p1.worth == p2.worth){
		if (p1.age == p2.age){
			return strcmp(p1.name,p2.name) < 0;
		} else {
			return p1.age < p2.age;
		}
	} else {
		return p1.worth > p2.worth;
	}
}

bool comPersonPtr(const Person * p1,const Person * p2){
	return comPerson(*p1,*p2);
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);

	vector<Person> allPeople;
	allPeople.resize(n);
	for(int i = 0;i<n;i++){
		scanf("%s%d%d",&allPeople[i].name[0],&allPeople[i].age,&allPeople[i].worth);
	}
	sort(allPeople.begin(),allPeople.end(),comPerson);

	int filterNum = 0;
	vector<int> filter;
	filter.resize(n);
	int ageCounter[201] = {0};
	for(int i = 0;i<n;i++){
		filter[filterNum++] = i;
	}

	int m,amin,amax,num,tmpAge;
	Person pmin,pmax;
	for(int i = 1;i<=k;i++){
		scanf("%d%d%d",&m,&amin,&amax);
		printf("Case #%d:\n",i);
		num = 0;
		for(int j = 0;j<filterNum && num<m;j++){
			tmpAge = allPeople[filter[j]].age;
			if (tmpAge >= amin && tmpAge <= amax){
				num++;
				allPeople[filter[j]].print();
			}
		}
		if (num==0)
			printf("None\n");
	}

	return 0;
}