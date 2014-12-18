#include <iostream>

using namespace std;

void reverseInt(int * is,const int num){
	int tmp;
	for(int i = 0;i<num/2;i++){
		tmp = is [i];
		is [i]=is[num-1-i];
		is[num-1-i]=tmp;
	}
}

int main(){

	int n,m;
	cin>>n>>m;

	int * is = new int[n];
	for(int i = 0;i<n;i++){
		cin >> is[i];
	}
	m = m%n;
	reverseInt(is,n);
	reverseInt(is,m);
	reverseInt(is+m,(n-m));

	for(int i = 0;i<n;i++){
		cout << is[i];
		if ((i+1) < n)
			cout << " ";
	}

	return 0;
}