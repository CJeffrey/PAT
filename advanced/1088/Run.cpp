#include <iostream>

long long findGCD(long long n,long long m){
	if (n==0 || m==0)return n > m ? n : m;

	long long tmp;
	while(m!=0){
		tmp = m;
		m = n%m;
		n = tmp;
	}
	return n;
}

void simplify1(long long & a,long long &b){
	long long x = findGCD(a,b);
	a /= x;
	b /= x;
}

class RationalNumber{
public:
	RationalNumber()
		:n(0),m(0),symbolType(false){}
	RationalNumber(long long nn,long long mm)
		:n(nn),m(mm),symbolType(false){
		if (m == 0)
			return;

		if (m < 0){
			m = -m,n=-n;
		}

		if (n < 0){
			symbolType = true;
			n = -n;
		}
		simplify1(n,m);				
	}
	long long n,m;
	bool symbolType;//false+, true -
	void print()const{
		if (m == 0){
			printf("%s","Inf");
			return;
		}

		if (symbolType){
			printf("%s","(-");
		}

		if (n % m == 0)
			printf("%lld",n/m);
		else if (n < m)
			printf("%lld/%lld",n,m);
		else
			printf("%lld %lld/%lld",n/m,n%m,m);

		if (symbolType){
			printf("%c",')');
		}
	}

	RationalNumber operator*(const RationalNumber &rnOri)const{
		long long newN = n * rnOri.n;
		long long newM = m * rnOri.m;

		RationalNumber ret(newN,newM);
		ret.symbolType = symbolType ^ rnOri.symbolType;

		return ret;
	}

	RationalNumber operator/(const RationalNumber &rnOri)const{
		RationalNumber newRN2(rnOri.m,rnOri.n);
		newRN2.symbolType = rnOri.symbolType;

		return *this * newRN2;
	}

	RationalNumber operator+(const RationalNumber &rnOri)const{
		long long flag1(1),flag2(1);
		if (symbolType)
			flag1 = -1;
		if (rnOri.symbolType)
			flag2 = -1;
		long long newN = flag1 * n * rnOri.m + flag2 * rnOri.n * m;
		long long newM = m *rnOri.m;

		RationalNumber ret(newN,newM);

		return ret;

	}

	RationalNumber operator-(const RationalNumber &rnOri)const{
		RationalNumber rn2 = rnOri;
		rn2.symbolType = !rn2.symbolType;
		return *this + rn2;
	}
};

int main(){
	long long n1,m1,n2,m2;
	scanf("%lld/%lld %lld/%lld",&n1,&m1,&n2,&m2);

	RationalNumber rn1 = RationalNumber(n1,m1);
	RationalNumber rn2 = RationalNumber(n2,m2);

	RationalNumber ret(0,0);
	for(long long i = 0;i<4;i++){
		rn1.print();
		printf("%c",' ');
		switch(i){
			case 0:
				printf("%c",'+');
				ret = rn1 + rn2;
				break;
			case 1:
				printf("%c",'-');
				ret = rn1 - rn2;
				break;
			case 2:
				printf("%c",'*');
				ret = rn1 * rn2;
				break;
			case 3:
				printf("%c",'/');
				ret = rn1 / rn2;
				break;
		}
		printf("%c",' ');
		rn2.print();
		printf("%s"," = ");
		ret.print();
		printf("%c",'\n');
	}

	return 0;
}