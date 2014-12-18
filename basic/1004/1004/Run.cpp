#include <iostream>
#include <string>

using namespace std;

struct Data{
	string name;
	string number;
	int score;
	
};

istream& operator>>(istream& input,Data &d){
	input >> d.name >> d.number >> d.score;
	return input;
}

int main(){
	int num;
	cin >> num;

	Data * datas = new Data[num];
	for(int i = 0;i<num;i++){
		cin >> datas[i];
	}

	int min;
	int max;
	Data * minPtr =NULL;
	Data * maxPtr =NULL;
	Data * tmpPtr =NULL;

	for(int i = 0;i<num;i++){
		tmpPtr = &datas[i];
		if (i==0){
			min = tmpPtr->score;
			max = tmpPtr->score;
			minPtr = tmpPtr;
			maxPtr = tmpPtr;
		} else {
			if (tmpPtr->score < min){
				min = tmpPtr->score;
				minPtr = tmpPtr;
			}
			if (tmpPtr->score > max){
				max = tmpPtr->score;
				maxPtr = tmpPtr;
			}
		}
	}

	cout << maxPtr->name << " " << maxPtr->number << endl;
	cout << minPtr->name << " " << minPtr->number << endl;

	delete [] datas;
}