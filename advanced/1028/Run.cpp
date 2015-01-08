#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Student{
	Student(){
		name.resize(9,0);
	}
	int id;
	string name;
	int grade;
};

int c;

bool compareStu(const Student & s1,const Student & s2){
	switch (c){
		case 1:
			return s1.id<s2.id;
		case 2:
			if (s1.name == s2.name){
				return s1.id < s2.id;
			} else {
				return s1.name < s2.name;
			}
		case 3:
			if (s1.grade == s2.grade){
				return s1.id < s2.id;
			} else {
				return s1.grade < s2.grade;
			}
	}
}

int main(){
	int n;
	scanf("%d%d",&n,&c);
	vector<Student> allStudents;
	allStudents.resize(n);
	for(int i = 0;i<n;i++){
		scanf("%d%s%d",&allStudents[i].id,&allStudents[i].name[0],&allStudents[i].grade);//75ms
		//cin >> allStudents[i].id >> allStudents[i].name >> allStudents[i].grade;  //143ms
	}
	sort(allStudents.begin(),allStudents.end(),compareStu);
	for(int i = 0;i<n;i++){
		printf("%06d %s %d\n",allStudents[i].id,allStudents[i].name.c_str(),allStudents[i].grade);
	}
	return 0;
}