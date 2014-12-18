#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Student
{
public:
	string regNum;
	int score;
	int locationRank;
	bool operator<(const Student &s)const{
		if (score < s.score){
			return true;
		} else if (score > s.score){
			return false;
		} else {
			return regNum > s.regNum;
		}
	}
};

class Location{
public:
	Location(const int _k)
		:k(_k){
			locationStudents.resize(k);
	}
	int k;
	vector<Student> locationStudents;

	vector<Student>::const_reverse_iterator rit;
	void runSort(){
		sort(locationStudents.begin(),locationStudents.end());
		rit = locationStudents.rbegin();

		int tmpScore(-1);
		int tmpRank(0);
		int tmpStuCounter(0);
		for(vector<Student>::reverse_iterator sit = locationStudents.rbegin();sit<locationStudents.rend();sit++){
			tmpStuCounter++;
			if (tmpScore != sit->score){
				tmpScore = sit->score;
				tmpRank = tmpStuCounter;
			}
			sit->locationRank = tmpRank;
		}
	}
	const Student * getMaxStudent(){
		if (rit != locationStudents.rend()){
			const Student * ret = &(*rit);
			rit++;
			return ret;			
		} else {
			return NULL;
		}
	}
};

class StudentPtr{
public:
	StudentPtr(const Student * tmpPtr,const int tmpIndex)
		:sptr(tmpPtr),locationIndex(tmpIndex){}
	const Student * sptr;
	int locationIndex;

	bool operator<(const StudentPtr & sp)const{
		return (*sptr) < (*(sp.sptr));
	}
};

class PATest{
public:
	PATest(const int _n)
		:studentNum(0),n(_n){
			allLocations.reserve(n);
	}
	int studentNum;
	int n;
	vector<Location> allLocations;
	vector<StudentPtr> allStudents;

	void sortAll(){
		for(int i = 0;i<n;i++){
			allLocations[i].runSort();
		}
		set<StudentPtr> spMap;
		const Student * tmpStu = NULL;
		for(int i = 0;i<n;i++){
			tmpStu = allLocations[i].getMaxStudent();
			StudentPtr tmpSPtr = StudentPtr(tmpStu,i);
			spMap.insert(tmpSPtr);
		}

		allStudents.reserve(studentNum);
		set<StudentPtr>::const_reverse_iterator sit = spMap.rbegin();
		int tmplocationIndex;
		while(sit != spMap.rend()){
			tmplocationIndex = sit->locationIndex;
			allStudents.push_back(*sit);
			spMap.erase(--(sit.base()));
			tmpStu = allLocations[tmplocationIndex].getMaxStudent();
			if (tmpStu != NULL){
				StudentPtr tmpSPtr = StudentPtr(tmpStu,tmplocationIndex);
				spMap.insert(tmpSPtr);
			}
			sit = spMap.rbegin();
		}
	}

	void printAll()const{
		printf("%d\n",studentNum);
		int tmpScore(-1);
		int tmpRank(0);
		int tmpStuCounter(0);
		for(vector<StudentPtr>::const_iterator sit = allStudents.begin();sit<allStudents.end();sit++){
			tmpStuCounter++;
			if (tmpScore != sit->sptr->score){
				tmpScore = sit->sptr->score;
				tmpRank = tmpStuCounter;
			}
			printf("%s %d %d %d\n",sit->sptr->regNum.c_str(),tmpRank,sit->locationIndex+1,sit->sptr->locationRank);
		}
	}
};

int main(){
	int n,k;
	scanf("%d",&n);
	PATest myTest = PATest(n);
	for(int i = 0;i<n;i++){
		scanf("%d",&k);
		myTest.studentNum += k;
		myTest.allLocations.push_back(Location(k));
		Location & lastLocation = myTest.allLocations.back();
		for(int j = 0;j<k;j++){
			cin >> lastLocation.locationStudents[j].regNum >> lastLocation.locationStudents[j].score;
		}
	}

	myTest.sortAll();
	myTest.printAll();

	return 0;
}