#include <iostream>

using namespace std;

class Win{
public:
	Win()
		:c(0),j(0),b(0){}
	int c;
	int j;
	int b;

	void addCounter(const char tmpC){
		switch(tmpC){
			case 'C':
				c++;
				break;
			case 'J':
				j++;
				break;
			case 'B':
				b++;
				break;
			default:
				cout << "error";
		}
	}
	int getTotalCounter()const{
		return c+j+b;
	}
	void printMostCounter()const{
		int maxCounter = max(c,j);
		maxCounter = max(maxCounter,b);
		if (maxCounter == b){
			cout << "B";
			return;
		} else if (maxCounter == c){
			cout << "C";
			return;
		} else {
			cout << "J";
			return;
		}
	}
};

int judge(char c1,char c2){
	//0 ping,1 c1 win,2 c2 win
	if (c1=='J' && c2=='J')
		return 0;
	if (c1=='J' && c2=='C')
		return 2;
	if (c1=='J' && c2=='B')
		return 1;
	if (c1=='C' && c2=='J')
		return 1;
	if (c1=='C' && c2=='C')
		return 0;
	if (c1=='C' && c2=='B')
		return 2;
	if (c1=='B' && c2=='J')
		return 2;
	if (c1=='B' && c2=='C')
		return 1;
	if (c1=='B' && c2=='B')
		return 0;

	cout << "error";
	return -1;
}

int main(){
	int num;
	scanf("%d",&num);

	char * ori1 = new char[num];
	char * ori2 = new char[num];
	char tmpChar;
	for(int i = 0;i<num;i++){
		scanf("%c",&tmpChar);
		scanf("%c",&ori1[i]);
		scanf("%c",&tmpChar);
		scanf("%c",&ori2[i]);
	}
	scanf("%c",&tmpChar);

	Win win1,win2;
	int result;
	int tieNum=0;
	for(int i=0;i<num;i++){
		result = judge(ori1[i],ori2[i]);
		switch(result){
			case 0:
				tieNum++;
				break;
			case 1:
				win1.addCounter(ori1[i]);
				break;
			case 2:
				win2.addCounter(ori2[i]);
				break;
			default:
				cout << "error" << endl;
		}
	}
	cout << win1.getTotalCounter() << " " << tieNum << " " << win2.getTotalCounter() << endl;
	cout << win2.getTotalCounter() << " " << tieNum << " " << win1.getTotalCounter() << endl;

	win1.printMostCounter();
	cout << " ";
	win2.printMostCounter();

	delete[]ori1;
	delete[]ori2;
	return 0;
}