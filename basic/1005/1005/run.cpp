#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Num{
	Num()
		:cover(false){}
	int value;
	bool cover;

	friend istream& operator>>(istream & is,Num &n){
		is >> n.value;
		return is;
	}

	bool operator==(const int i)const{
		return (this->value==i);
	}
	bool operator==(const Num n)const{
		return (this->value==n.value);
	}
	bool operator<(const Num n)const{
		return (this->value < n.value);
	}
};

class NumFactory{
public:
	NumFactory(int size)
		:_size(size){
		nums = new Num[size];
	}
	~NumFactory(){
		delete []nums;
	}

	friend istream& operator>>(istream & is,NumFactory & nf){
		for(int i = 0;i<nf._size;i++){
			is >> nf.nums[i];
		}
		return is;
	}
	void runSearch(){
		int tmpValue;
		int thisValue;
		Num * numPtr(NULL);
		for(int i = 0;i<_size;i++){
			thisValue = nums[i].value;
			tmpValue = thisValue;
			while(tmpValue != 1){
				if (tmpValue %2 == 0){
					tmpValue = tmpValue/2;
				} else {
					tmpValue = (tmpValue * 3 + 1) /2;
				}

				numPtr = inside(tmpValue);
				if (numPtr){
					if (*numPtr == thisValue){
					}else{
						numPtr->cover = true;
					}
				}
			}
		}
		
		vn.clear();
		for(int i = 0;i<_size;i++){
			if (!nums[i].cover)
				vn.push_back(nums[i]);
		}
		std::sort(vn.begin(),vn.end());
	}
	Num * inside(int checkValue){
		Num * ret = NULL;
		for(int i = 0;i<_size;i++){
			if (nums[i] == checkValue){
				return ret = &nums[i];
				break;
			}
		}
		return ret;
	}
	void print(){
		for(vector<Num>::const_reverse_iterator nit=vn.rbegin();nit!=vn.rend();nit++){
			cout << nit->value;
			if (nit+1 < vn.rend()){
				cout << " ";
			}
		}
	}
private:
	vector<Num> vn;
	int _size;
	Num * nums;
};

int main(){
	int size;
	cin >> size;

	NumFactory nf(size);
	cin >> nf;
	nf.runSearch();
	nf.print();

	return 0;
}