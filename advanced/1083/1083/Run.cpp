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

	bool operator<(const Student & s)const{
		return grade < s.grade;
	}
};

int main(){
	int num;
	scanf("%d",&num);

	vector<Student> students;

	string tmpName,tmpID;
	int tmpGrade;
	for(int i = 0;i<num;i++){
		cin >> tmpName >> tmpID >> tmpGrade;
		Student tmpStudent;
		tmpStudent.name = tmpName;
		tmpStudent.id = tmpID;
		tmpStudent.grade = tmpGrade;
		students.push_back(tmpStudent);
	}

	int grade1,grade2;
	scanf("%d %d",&grade1,&grade2);

	sort(students.begin(),students.end());

	bool hasPrint = false;
	for(vector<Student>::const_reverse_iterator sit = students.rbegin();sit < students.rend();sit++){
		if (sit->grade >= grade1 && sit->grade <= grade2){
			hasPrint = true;
			cout << sit->name << " " << sit->id << endl;
		}
	}
	if (!hasPrint){
		cout << "NONE" << endl;
	}

	return 0;
}