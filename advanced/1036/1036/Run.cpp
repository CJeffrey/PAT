#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student{
public:
	string name;
	string id;
	int grade;
	//bool gender;//true male, false female

	bool operator<(const Student & s)const{
		return grade < s.grade;
	}
};

int main(){
	int num;
	scanf("%d",&num);
	
	vector<Student> boys,girls;

	string tmpName,tmpID;
	char tmpGender;
	int tmpGrade;
	for(int i = 0;i<num;i++){
		cin >> tmpName >> tmpGender >> tmpID >> tmpGrade;
		Student tmpStudent;
		tmpStudent.name = tmpName;
		tmpStudent.id = tmpID;
		tmpStudent.grade = tmpGrade;
		switch(tmpGender){
			case 'M':
				boys.push_back(tmpStudent);
				break;
			default:
				girls.push_back(tmpStudent);
				break;
		}
	}
	sort(boys.begin(),boys.end());
	sort(girls.begin(),girls.end());
	if (!girls.empty()){
		cout << girls.back().name << " " << girls.back().id;
	} else {
		cout << "Absent";
	}
	cout << endl;
	if (!boys.empty()){
		cout << boys.front().name << " " << boys.front().id;
	} else {
		cout << "Absent";
	}
	cout << endl;
	if (!boys.empty() && !girls.empty()){
		cout << girls.back().grade - boys.front().grade;
	} else {
		cout << "NA";
	}

	return 0;
}