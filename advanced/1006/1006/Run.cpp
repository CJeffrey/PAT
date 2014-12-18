#include <iostream>
#include <string.h>

class Time{
public:
	int hour;
	int minute;
	int second;

	bool operator<(const Time & t)const{
		if (hour < t.hour){
			return true;
		} else if (hour > t.hour){
			return false;
		} else if (minute < t.minute){
			return true;
		} else if (minute > t.minute){
			return false;
		} else {
			return second < t.second;
		}
	}
};

class Record{
public:
	Record(){
		name = new char[15];
		memset(name,0,15);
	}
	~Record(){
		delete []name;
	}
	char * name;
	Time inTime;
	Time outTime;
};

/*
bool compareRecordInTime(const Record & r1,const Record & r2){
	return r1.inTime < r2.inTime;
}

bool compareRecordOutTime(const Record & r1,const Record & r2){
	return r1.outTime < r2.outTime;
}*/

int main(){
	int num;
	scanf("%d",&num);

	Record * allRecords = new Record[num];
	for(int i = 0;i<num;i++){
		scanf("%s %d:%d:%d %d:%d:%d",allRecords[i].name,&(allRecords[i].inTime.hour),&(allRecords[i].inTime.minute),&(allRecords[i].inTime.second),
			&(allRecords[i].outTime.hour),&(allRecords[i].outTime.minute),&(allRecords[i].outTime.second));
	}

	Record * firstIn, *lastOut;
	firstIn = &(allRecords[0]);
	lastOut = &(allRecords[0]);

	for(int i = 0;i<num;i++){
		if (allRecords[i].inTime < firstIn->inTime){
			firstIn = &(allRecords[i]);
		}
		if (lastOut->outTime < allRecords[i].outTime){
			lastOut = &(allRecords[i]);
		}
	}
	
	printf("%s %s",firstIn->name,lastOut->name);

	delete [] allRecords;
	return 0;
}