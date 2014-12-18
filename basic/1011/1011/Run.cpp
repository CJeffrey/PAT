#include <iostream>

using namespace std;

bool judge(long  a,long  b,long  c){
	long tmp = a + b;
	if (a > 0 && b>0 && (a+b)<0)
		return true;
	if (a < 0 && b<0 && (a+b)>0)
		return false;
	return (tmp > c);
}

int main(){
	/*long l1(-2147483648L);
	long l2(-2147483648L);
	cout << l1 << " " << l2 << endl;
	cout << l1+l2 << endl;*/
	int num;
	cin >> num;

	long a,b,c;
	bool flag;
	for(int i = 0;i<num;i++){
		cin >> a >> b >> c;
		flag = judge(a,b,c);
		cout << "Case #" << i+1 << ": ";
		if (flag)
			cout << "true";
		else
			cout << "false";
		cout << endl;
	}

	return 0;
}