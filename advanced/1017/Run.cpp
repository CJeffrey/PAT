#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
struct Time{
	Time(){};
	Time(const int h,const int m,const int s)
		:hh(h),mm(m),ss(s){};
	int hh,mm,ss;

	bool operator<(const Time & t)const{
		if (hh == t.hh){
			if (mm == t.mm){
				return ss < t.ss;
			} else {
				return mm < t.mm;
			}
		} else {
			return hh < t.hh;
		}
	}

	Time operator+(const int plusMin){
		mm += plusMin;
		if (mm > 59){
			mm -= 60;
			hh++;
		}
		return *this;
	}

	int getSecond()const{
		return 3600 * hh + 60 * mm + ss;
	}

	int operator-(Time t2)const{
		return getSecond() - t2.getSecond();
	}
};

struct Customer{
	Time enterTime;
	int usingTime;
	Time outTime;
	int waitingTime;

	void getData(){
		scanf("%d:%d:%d %d",&enterTime.hh,&enterTime.mm,&enterTime.ss,&usingTime);
	}
};

bool comCustomerEnter(const Customer & c1,const Customer & c2){
	return c1.enterTime < c2.enterTime;
}

bool comCustomerOut(const Customer & c1,const Customer & c2){
	return c1.outTime < c2.outTime;
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);

	Time startTime(8,0,0),endTime(17,0,1);
	vector<Customer> allCustomers;
	for (int i = 0;i<n;i++){
		Customer tmpCus;
		tmpCus.getData();
		if (tmpCus.usingTime > 60){
			tmpCus.usingTime = 60;
		}
		if (!(tmpCus.enterTime < endTime)){
			continue;
		} else {
			allCustomers.push_back(tmpCus);
		}
	}
	sort(allCustomers.begin(),allCustomers.end(),comCustomerEnter);

	int totalTime=0;
	vector<Customer> workingCustomer;
	vector<Customer>::const_iterator allCusEnd = allCustomers.end();
	for(vector<Customer>::iterator cit = allCustomers.begin();cit<allCusEnd;cit++){
		Time nowTime;
		if (workingCustomer.size() < k){
			nowTime = startTime;
		} else {
			nowTime = workingCustomer.front().outTime;
			workingCustomer.erase(workingCustomer.begin());
		}
		if (cit->enterTime < nowTime){
			cit->waitingTime = nowTime - cit->enterTime;
			cit->outTime = nowTime + cit->usingTime;
		} else {
			cit->waitingTime = 0;
			cit->outTime = cit->enterTime + cit->usingTime;
		}
		
		totalTime += cit->waitingTime;
		workingCustomer.push_back(*cit);
		sort(workingCustomer.begin(),workingCustomer.end(),comCustomerOut);
	}

	double averageTime = double(totalTime) /60/allCustomers.size();
	printf("%.1lf",averageTime);

	return 0;
}