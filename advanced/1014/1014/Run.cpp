#include <iostream>
#include <list>

using namespace std;


class Customer{
public:
	int usingTime;
	int index;
};

class Clock{
public:
	int hour;
	int minute;
	bool operator<(const Clock & c)const{
		if (hour<c.hour){
			return true;
		} else if (hour > c.hour){
			return false;
		} else {
			return minute < c.minute;
		}
	}
	bool operator==(const Clock &c)const{
		return (hour == c.hour && minute == c.minute);
	}
	void plus1minute(){
		minute++;
		if (minute == 60){
			hour++;
			minute=0;
		}
	}
};


int N,M,K,Q;
int yellowLineCustomer(0);
list<Customer> * windows;
int * waitingTime;
int * requierList;
Clock * resultTime;
bool addCustomFlag(true);

int findOpenWindow(){
	int ret = -1;
	int minNum = M;
	for(int i = 0;i<N;i++){
		if (windows[i].size() < minNum){
			minNum = windows[i].size();
			ret = i;
		}
	}
	return ret;
};

void pushCustomer(){
	while(yellowLineCustomer < K && addCustomFlag){
		int openWindow = findOpenWindow();
		if (openWindow >= 0){
			Customer tmpC;
			tmpC.index = yellowLineCustomer;
			tmpC.usingTime = waitingTime[yellowLineCustomer];
			windows[openWindow].push_back(tmpC);
			yellowLineCustomer++;
		} else {
			break;
		}
	}
};

int main(){
	scanf("%d%d%d%d",&N,&M,&K,&Q);

	windows = new list<Customer>[N];
	waitingTime = new int[K];
	requierList = new int[Q];
	resultTime = new Clock[K];

	for(int i = 0;i<K;i++){
		scanf("%d",&(waitingTime[i]));
	}
	for(int i = 0;i<Q;i++){
		scanf("%d",&(requierList[i]));
	}
	for(int i = 0;i<K;i++){
		resultTime[i].hour = -1;
		resultTime[i].minute = -1;
	}
	Clock startTime,endTime,nowTime;
	startTime.hour = 8;startTime.minute=0;
	endTime.hour = 16;endTime.minute=59;
	nowTime = startTime;
	bool hasWork = true;
	pushCustomer();
	while(hasWork){
		//printf("%02d:%02d\n",nowTime.hour,nowTime.minute);
		Clock time1700;time1700.hour=17;time1700.minute=0;
		if (nowTime == time1700){
			int i5=5;i5++;
		}
		if (endTime < nowTime){
			addCustomFlag=(false);
			for(int i = 0;i<N;i++){
				while(windows[i].size()>1){
					windows[i].pop_back();
				}
			}
		}
		hasWork = false;
		for(int i = 0;i<N;i++){
			if (windows[i].empty()){
				continue;
			}
			//std::cout << windows[i].front().usingTime<<endl;
			if (windows[i].front().usingTime == 0){
				resultTime[windows[i].front().index] = nowTime;
				windows[i].pop_front();
			}
		}
		pushCustomer();
		for(int i = 0;i<N;i++){
			if (windows[i].empty()){
				continue;
			}
			hasWork = true;
			windows[i].front().usingTime--;
		}
		nowTime.plus1minute();
	}

	int requireIndex;
	for(int i = 0;i<Q;i++){
		requireIndex = requierList[i] - 1;
		if (resultTime[requireIndex].hour < 0){
			printf("%s\n","Sorry");
		} else {
			printf("%02d:%02d\n",resultTime[requireIndex].hour,resultTime[requireIndex].minute);
		}
	}

	delete []resultTime;	
	delete []requierList;
	delete []waitingTime;
	delete []windows;
	return 0;
}