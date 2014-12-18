#include <iostream>

int findGCD(int n,int m){
	//intput n,m>=0
	//ensure n>=m
	if (n<m){
		std::swap(n,m);
	}
	int tmp;
	while(m!=0){
		tmp = m;
		m = n%m;
		n = tmp;
	}
	return n;
}

void changeGCD(const int n,const int m,int & resultN,int & resultM){
	//n m must >=0 ; not n,m all equal 0;
	int gcd = findGCD(n,m);
	if (gcd == 0){
		resultN = n;
		resultM = m;
	} else {
		resultN = n / gcd;
		resultM = m / gcd;
	}
	
}

class RationalNumber{
public:
	RationalNumber()
		:n(0),m(0),l(0),symbolType(0){}
	RationalNumber(int nn,int mm){
		if (nn < 0){
			symbolType = -1;
		} else {
			symbolType = 1;
		}
		if (mm < 0){
			symbolType *= -1;
		}
		mm = abs(mm);
		nn = abs(nn);
		changeGCD(nn,mm,n,m);
		if (m == 0){
			new(this)RationalNumber();
			return;
		} else {
			l = n / m;
			n = n % m;
		}		
	}
	int n,m,l;
	int symbolType;
	void print()const{
		if (m == 0){
			printf("%s","Inf");
			return;
		}
		if (n == 0 && l == 0){
			printf("%d",0);
			return;
		}
		if (symbolType<0){
			printf("%s","(-");
		}
		if (l != 0){
			printf("%d",l);
		}
		if (l != 0 && n != 0){
			printf("%c",' ');
		}
		if (n != 0){
			printf("%d/%d",n,m);
		}
		if (symbolType<0){
			printf("%c",')');
		}
	}

	RationalNumber operator*(const RationalNumber &rnOri)const{
		int l1(l),l2(rnOri.l),n1(n),n2(rnOri.n),m1(m),m2(rnOri.m);
		int newN = m1*m2*l1*l2 + n1*n2 + n1*l2*m2 + n2*l1*m1;
		int newM = m1*m2;

		RationalNumber ret(newN,newM);
		ret.symbolType = symbolType * rnOri.symbolType;

		return ret;
	}

	RationalNumber operator/(const RationalNumber &rnOri)const{
		RationalNumber newRN2(rnOri.m,(rnOri.l*rnOri.m + rnOri.n));
		newRN2.symbolType = rnOri.symbolType;

		return *this * newRN2;
	}

	RationalNumber operator+(const RationalNumber &rnOri)const{
		int l1(l),l2(rnOri.l),n1(n),n2(rnOri.n),m1(m),m2(rnOri.m);
		
		l1 *= symbolType;
		n1 *= symbolType;
		l2 *= rnOri.symbolType;
		n2 *= rnOri.symbolType;

		
		int newM = m1*m2;
		int newN = n1*m2+n2*m1 + (l1+l2) * newM;

		RationalNumber ret(newN,newM);

		return ret;

	}

	RationalNumber operator-(const RationalNumber &rnOri)const{
		RationalNumber rn2 = rnOri;
		rn2.symbolType *= -1;
		return *this + rn2;
	}
};

int main(){
	//_controlfp(_EM_INVALID,_MCW_EM);
	int n1,m1,n2,m2;
	scanf("%d/%d %d/%d",&n1,&m1,&n2,&m2);

	RationalNumber rn1 = RationalNumber(n1,m1);
	RationalNumber rn2 = RationalNumber(n2,m2);

	RationalNumber ret(0,0);
	for(int i = 0;i<4;i++){
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