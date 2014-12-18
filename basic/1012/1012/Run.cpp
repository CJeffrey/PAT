#include <iostream>
#include <vector>

using namespace std;

void A1(int *x,int num){
	vector<int*> vi;
	for(int i =0;i<num;i++){
		if ((x[i] %10) == 0)
			vi.push_back(&x[i]);
	}
	if (vi.empty()){
		cout <<"N";
	} else {
		int sum = 0;
		for(vector<int*>::const_iterator iit = vi.begin();iit<vi.end();iit++){
			sum += **iit;
		}
		cout << sum;
	}
	cout << " ";
}

void A2(int *x,int num){
	vector<int*> vi;
	for(int i =0;i<num;i++){
		if ((x[i] %5) == 1)
			vi.push_back(&x[i]);
	}
	if (vi.empty()){
		cout <<"N";
	} else {
		int sum = 0;
		bool plusFlag = true;
		for(vector<int*>::const_iterator iit = vi.begin();iit<vi.end();iit++){
			if (plusFlag){
				sum += **iit;
			} else {
				sum -= **iit;
			}
			plusFlag=!plusFlag;
		}
		cout << sum;
	}
	cout << " ";
}

void A3(int *x,int num){
	vector<int*> vi;
	for(int i =0;i<num;i++){
		if ((x[i] %5) == 2)
			vi.push_back(&x[i]);
	}
	if (vi.empty()){
		cout <<"N";
	} else {
		cout << vi.size();
	}
	cout << " ";
}

void A4(int *x,int num){
	vector<int*> vi;
	for(int i =0;i<num;i++){
		if ((x[i] %5) == 3)
			vi.push_back(&x[i]);
	}
	if (vi.empty()){
		cout <<"N";
	} else {
		double sum=0;
		for(vector<int*>::const_iterator iit = vi.begin();iit<vi.end();iit++){
			sum += **iit;
		}
		sum = sum/vi.size();
		printf("%.1lf",sum);
	}
	cout << " ";
}

void A5(int *x,int num){
	vector<int*> vi;
	for(int i =0;i<num;i++){
		if ((x[i] %5) == 4)
			vi.push_back(&x[i]);
	}
	if (vi.empty()){
		cout <<"N";
	} else {
		int maxValue=0;
		for(vector<int*>::const_iterator iit = vi.begin();iit<vi.end();iit++){
			maxValue = max(maxValue,**iit);
		}
		cout << maxValue;
	}
}

int main(){
	int num;
	cin >> num;

	int * values = new int[num];
	for(int i = 0;i<num;i++){
		cin >> values[i];
	}

	A1(values,num);
	A2(values,num);
	A3(values,num);
	A4(values,num);
	A5(values,num);

	delete []values;
	return 0;
}