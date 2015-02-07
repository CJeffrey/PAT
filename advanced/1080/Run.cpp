#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Student;

unsigned int n,m,k;
unsigned int * quota = new unsigned int[m];
vector<vector<int>> admissions;

class Student{
public:
	int ge,gi,sum,id;
	vector<unsigned int> applys;
	unsigned int rank;

	void getData(){
		scanf("%d%d",&ge,&gi);
		sum = ge + gi;
		
		unsigned int tmpValue;
		for(unsigned int i = 0;i<k;i++){
			scanf("%d",&tmpValue);
			applys.push_back(tmpValue);
		}
	}

	bool operator<(const Student & s)const{
		if (sum == s.sum){
			return ge < s.ge;
		} else {
			return sum < s.sum;
		}
	}

	bool operator==(const Student & s)const{
		return (sum == s.sum && ge == s.ge);
	}

	int getSchool()const{
		int schoolID;
		for(unsigned int i = 0;i<k;i++){
			schoolID = applys[i];
			if (quota[schoolID] > admissions[schoolID].size())
				return schoolID;
		}
		return -1;
	}
};

vector<Student> allStudents;

void runAdmit(const unsigned int sBegin,const unsigned int sEnd){
	vector<pair<int,int>> admits;
	for(unsigned int i = sBegin;i<sEnd;i++){
		admits.push_back(pair<int,int>(allStudents[i].getSchool(),allStudents[i].id));
	}
	vector<pair<int,int>>::iterator pit(admits.begin()),pitEnd(admits.end());
	for(;pit!=pitEnd;pit++){
		if (pit->first >=0){
			admissions[pit->first].push_back(pit->second);
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);

	quota = new unsigned int [m];
	for(unsigned int i = 0;i<m;i++){
		scanf("%d",quota+i);
	}

	//allStudents.resize(n);
	for(unsigned int i = 0 ;i<n;i++){
		Student tmpS;
		tmpS.getData();
		tmpS.id = i;
		allStudents.push_back(tmpS);
	}

	sort(allStudents.begin(),allStudents.end());
	reverse(allStudents.begin(),allStudents.end());
	int lastRank = 0;
	Student * lastStudent = & allStudents[0];
	for(unsigned int i = 0;i<n;i++){
		if (*lastStudent == allStudents[i]){
			allStudents[i].rank = lastRank;
		} else {
			allStudents[i].rank = i;
			lastStudent = & allStudents[i];
		}
	}

	int studentBegin(0);
	int nowRank=0;
	admissions.resize(m);
	for(unsigned int i = 0;i<=n;i++){
		if ( i == n || allStudents[i].rank != nowRank){
			runAdmit(studentBegin,i);
			studentBegin = i;
		}
	}

	vector<int>::const_iterator iit,iitEnd;
	for(unsigned int i = 0;i<m;i++){
		if (!admissions[i].empty()){
			sort(admissions[i].begin(),admissions[i].end());
			iitEnd = admissions[i].end();
			iit = admissions[i].begin();
			for(;iit!=iitEnd;iit++){
				printf("%d",*iit);
				if (iit+1 != iitEnd){
					printf(" ");
				}
			}
		}
		printf("\n");
	}

	delete []quota;
	return 0;
}