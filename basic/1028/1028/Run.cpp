#include <iostream>
#include <string.h>
class Person{
public:
	Person(){
		memset(name,0,5);
	}
	Person(int _year,int _month,int _day)
		:year(_year),month(_month),day(_day){
		memset(name,0,5);
	}
	char name[5];
	int year;
	int month;
	int day;

	bool operator<(const Person &p){
		if (year < p.year){
			return true;
		} else if (year>p.year){
			return false;
		} else if (month < p.month){
			return true;
		} else if (month > p.month){
			return false;
		} else {
			return (day < p.day);
		}
	}
};

int main(){
	int num;
	scanf("%d",&num);
	
	Person * allPeople = new Person[num];

	for(int i = 0;i<num;i++){
		scanf("%s %d/%d/%d",&(allPeople[i].name),&(allPeople[i].year),&(allPeople[i].month),&(allPeople[i].day));
	}

	int counter(0);
	Person minPerson(1814,9,5);
	Person maxPerson(2014,9,7);

	Person *tmpMinPerson = &maxPerson;
	Person *tmpMaxPerson = &minPerson;

	Person * tmpPerson(NULL);
	for(int i = 0;i<num;i++){
		tmpPerson = &(allPeople[i]);
		if (minPerson < *tmpPerson && *tmpPerson < maxPerson){
			counter++;
			if (*tmpPerson < *tmpMinPerson){
				tmpMinPerson = tmpPerson;
			}
			if (*tmpMaxPerson < *tmpPerson){
				tmpMaxPerson = tmpPerson;
			}
		}
	}

	if (counter == 0){
		printf("%d",0);
	} else {
		printf("%d %s %s",counter,tmpMinPerson->name,tmpMaxPerson->name);
	}
	



	delete [] allPeople;
	return 0;
}