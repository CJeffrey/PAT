#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const string onLine = "on-line";
const string offLine = "off-line";
const int hourNum = 24;

int toll[24];
class Record{
public:
	int month;
	int day;
	int hour;
	int minute;
	int type;
	void getInput(){
		scanf("%d:%d:%d:%d",&month,&day,&hour,&minute);
	}
	bool operator<(const Record & r)const{
		if (month < r.month){
			return true;
		} else if (month > r.month){
			return false;
		} else if (day < r.day){
			return true;
		} else if (day > r.day){
			return false;
		} else if (hour < r.hour){
			return true;
		} else if (hour > r.hour){
			return false;
		} else if (minute < r.minute){
			return true;
		} else if (minute > r.minute){
			return false;
		} else {
			return type < r.type;
		}
	}
	bool isSameMinute(const Record & r)const{
		return (isSameHour(r) &&  minute == r.minute);
	}
	bool isSameHour(const Record & r)const{
		return (isSameDay(r) && hour == r.hour);
	}
	bool isSameDay(const Record & r)const{
		return (month == r.month && day == r.day);
	}
	/*Record minus(const Record & r)const{
		Record ret;
		Record tmpThis = *this;

		ret.minute = tmpThis.minute - r.minute;
		if (tmpThis.minute < r.minute){
			ret.minute += 60;
			tmpThis.hour--;
		}
		ret.hour = tmpThis.hour - r.hour;
		if (tmpThis.hour < r.hour){
			ret.hour+=24;
			tmpThis.day--;
		}
		ret.day = tmpThis.day - r.day;
	}*/
	void printDHM()const{
		printf("%02d:%02d:%02d",day,hour,minute);
	}

};

void getDiff(int * data,Record start,Record end){
	for(int i = 0; i < 24;i++)
		data[i] = 0;
	if (start.isSameMinute(end)){
		data[start.hour] = 1;
	}
	while ( start.month!= end.month || start.day!= end.day || start.hour!=end.hour || start.minute!=end.minute)
	{
		if( start.month == end.month && start.day == end.day && start.hour == end.hour){
			data[start.hour]+= (end.minute-start.minute);
			start.minute = end.minute;
		} else {
			data[start.hour]+= (60 - start.minute);
			start.minute = 0;
			start.hour++;
			if( start.hour == 24)
			{
				start.hour = 0;
				start.day++;
			}
		}
	}
}

int getTotalPrice(const int * data){
	int ret=0;
	for(int i = 0;i<hourNum;i++){
		ret += data[i] * toll[i];
	}
	return ret;
}

int getTotalTime(const int * data){
	int ret=0;
	for(int i = 0;i<hourNum;i++){
		ret += data[i];
	}
	return ret;
}

int main(){
	for(int i = 0;i<hourNum;i++){
		scanf("%d",toll+i);
	}
	int recordNum;
	scanf("%d",&recordNum);
	map<string,vector<Record>> allRecord;
	
	string tmpName,tmpTypeS;
	Record tmpRecord;
	char tmpTypeC;
	map<string,vector<Record>>::iterator mmit;
	for(int i = 0;i<recordNum;i++){
		cin >> tmpName;
		tmpRecord.getInput();
		cin >> tmpTypeS;
		if (tmpTypeS == onLine){
			tmpTypeC = 1;
		} else {
			tmpTypeC = 2;
		}
		tmpRecord.type = tmpTypeC;
		mmit = allRecord.find(tmpName);
		if (mmit == allRecord.end()){
			vector<Record> tmpVec;
			tmpVec.push_back(tmpRecord);
			allRecord.insert(pair<string,vector<Record>>(tmpName,tmpVec));
		} else {
			mmit->second.push_back(tmpRecord);
		}
	}

	for(mmit=allRecord.begin();mmit!=allRecord.end();mmit++){
		sort(mmit->second.begin(),mmit->second.end());
	}

	vector<Record>::iterator mit,lastMit;

	int data[24];
	bool printFirst;
	double totalPrice;
	bool hasOnline;
	for(mmit=allRecord.begin();mmit!=allRecord.end();mmit++){
		hasOnline = false;
		printFirst = true;
		totalPrice = 0;

		for(mit = mmit->second.begin();mit!=mmit->second.end();mit++){
			if (!hasOnline){
				if (mit->type == 1){
					hasOnline = true;
					lastMit = mit;
				}
				continue;
			}
			if (mit->type == 1){
				lastMit = mit;
				continue;
			} else {
				if (printFirst){
					printFirst = false;
					printf("%s %02d\n",mmit->first.c_str(),mit->month);
				}
				lastMit->printDHM();
				printf("%c",' ');
				mit->printDHM();
				printf("%c",' ');
				getDiff(data,*lastMit,*mit);
				printf("%d %c",getTotalTime(data),'$');
				double tmpPrice = double(getTotalPrice(data))/100;
				printf("%.2lf\n",tmpPrice);
				totalPrice += tmpPrice;

				hasOnline = false;
			}
		}
		if (!printFirst){
			printf("Total amount: $%.2lf\n",totalPrice);
		}
	}

	return 0;
}