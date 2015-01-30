#include <iostream>
#include <string>
#include <set>
#include <list>
#include <map>
using namespace std;

struct Person{
	Person()
		:time(0){
			name.resize(3,0);
	}
	string name;
	int time;

	bool operator<(const Person & p)const{
		return name < p.name;
	}
};

struct Gang{
	Gang()
		:totalTime(0){};
	map<string,int> allPeople;
	int totalTime;
	
	void addPeople(const Person &p1,const Person &p2){
		_newPeople(p1);
		_newPeople(p2);
		totalTime+=p1.time;
	}

	void merge(const Gang & g){
		allPeople.insert(g.allPeople.begin(),g.allPeople.end());
	}

	Person findHead()const{
		Person ret;
		map<string,int>::const_iterator itEnd(allPeople.end());
		map<string,int>::const_iterator it1;
		for(it1 = allPeople.begin();it1!=itEnd;it1++){
			if (it1->second > ret.time){
				ret.name = it1->first;
				ret.time = it1->second;
			}
		}
		return ret;
	}

private:
	void _newPeople(const Person & p1){
		map<string,int>::const_iterator itEnd(allPeople.end());
		map<string,int>::iterator it1;
		it1 = allPeople.find(p1.name);
		if (it1 == itEnd){
			allPeople.insert(pair<string,int>(p1.name,p1.time));
		} else {
			it1->second += p1.time;
		}
	}
};

struct Society{
	list<Gang> allGans;

	list<Gang>::iterator getPerson(const Person & p){
		list<Gang>::const_iterator itEnd(allGans.end());
		list<Gang>::iterator git;
		map<string,int>::const_iterator sitEnd,sit;
		for(git=allGans.begin();git!=itEnd;git++){
			sit = git->allPeople.find(p.name);
			sitEnd = git->allPeople.end();
			if (sit != sitEnd)
				return git;
		}
		return allGans.end();
	}
};

int main(){
	int n,k;
	scanf("%d %d",&n,&k);

	Society soc;
	list<Gang>::iterator git1,git2,gitEnd;
	for(int i = 0;i<n;i++){
		Person p1,p2;
		int time;
		scanf("%s %s %d",&p1.name[0],&p2.name[0],&time);
		p1.time = time;
		p2.time = time;
		gitEnd = soc.allGans.end();
		git1 = soc.getPerson(p1);
		git2 = soc.getPerson(p2);
		if (git1 == gitEnd && git2 == gitEnd){
			Gang tmpGan;
			tmpGan.addPeople(p1,p2);
			soc.allGans.push_back(tmpGan);
		} else if (git1 != gitEnd && git2 == gitEnd){
			git1->addPeople(p1,p2);
		} else if (git1 == gitEnd && git2 != gitEnd){
			git2->addPeople(p1,p2);
		} else {
			if (git1 == git2){
				git1->addPeople(p1,p2);
			} else {
				git1->merge(*git2);
				git1->addPeople(p1,p2);
				soc.allGans.erase(git2);
			}
		}
	}

	map<Person,int> headOfGans;
	list<Gang>::const_iterator lgitEnd = soc.allGans.end(),lgit;
	for(lgit = soc.allGans.begin();lgit!=lgitEnd;lgit++){
		if (lgit->totalTime > k && lgit->allPeople.size() > 2){
			Person tmpHead = lgit->findHead();
			headOfGans.insert(pair<Person,int>(tmpHead,lgit->allPeople.size()));
		}
	}

	printf("%d\n",headOfGans.size());
	map<Person,int>::const_iterator mpiitEnd(headOfGans.end()),mpiit;
	for(mpiit = headOfGans.begin();mpiit!=mpiitEnd;mpiit++){
		printf("%s %d\n",mpiit->first.name.c_str(),mpiit->second);
	}

	return 0;
}