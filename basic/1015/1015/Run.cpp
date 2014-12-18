#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Student{
public:
	long number;
	int scoreD;
	int scoreC;

	int scoreTotal()const{
		return scoreD + scoreC;
	}

	friend istream& operator>>(istream & in,Student & s){
		in >> s.number >> s.scoreD >> s.scoreC;
		return in;
	}

	bool operator<(const Student & s)const{
		if (scoreTotal() < s.scoreTotal())
			return true;
		else if (scoreTotal() > s.scoreTotal())
			return false;
		else {
			if (scoreD < s.scoreD)
				return true;
			else if (scoreD > s.scoreD){
				return false;
			} else {
				return number > s.number;
			}
		}
	}

	void print()const{
		//cout << '\n'<< number << " " << scoreD << " " << scoreC;
		printf("\n%d %d %d",number,scoreD,scoreC);
	}
};


bool compareStuPtr(const Student* p1,const Student* p2){
	return ((*p1) < (*p2));
}


int main(){
	ios::sync_with_stdio(true);
	int num,L,H;
	scanf("%d %d %d",&num,&L,&H);

	vector<Student> vs;

	for(int i = 0;i<num;i++){
		Student tmpS;
		scanf("%d %d %d",&tmpS.number,&tmpS.scoreD,&tmpS.scoreC);
		vs.push_back(tmpS);
	}

	vector<const Student*> class1,class2,class3,class4;
	for(vector<Student>::const_iterator sit = vs.begin();sit<vs.end();sit++){
		if (sit->scoreC>=H && sit->scoreD>=H){
			class1.push_back(&(*sit));
		} else if (sit->scoreD >= H && sit->scoreC>=L){
			class2.push_back(&(*sit));
		} else if (sit->scoreD >= sit->scoreC && sit->scoreC>=L){
			class3.push_back(&(*sit));
		} else if (sit->scoreD >= L && sit->scoreC>=L){
			class4.push_back(&(*sit));
		}
	}

	sort(class1.begin(),class1.end(),compareStuPtr);
	sort(class2.begin(),class2.end(),compareStuPtr);
	sort(class3.begin(),class3.end(),compareStuPtr);
	sort(class4.begin(),class4.end(),compareStuPtr);

	cout << (class1.size() + class2.size() + class3.size() + class4.size());
	for (vector<const Student*>::const_reverse_iterator srit =class1.rbegin();srit!=class1.rend();srit++){
		(*srit)->print();
	}
	for (vector<const Student*>::const_reverse_iterator srit =class2.rbegin();srit!=class2.rend();srit++){
		(*srit)->print();
	}
	for (vector<const Student*>::const_reverse_iterator srit =class3.rbegin();srit!=class3.rend();srit++){
		(*srit)->print();
	}
	for (vector<const Student*>::const_reverse_iterator srit =class4.rbegin();srit!=class4.rend();srit++){
		(*srit)->print();
	}

	return 0;
}