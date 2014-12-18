#include <iostream>

class MagicCurrency{
public:
	int Galleon;
	int Sickle;
	int Knut;

	const static int KuntBase = 29;
	const static int SickleBase = 17;

	MagicCurrency operator+(const MagicCurrency & mc)const{
		MagicCurrency ret;
		ret.Knut = Knut + mc.Knut;
		ret.Sickle = Sickle + mc.Sickle;
		ret.Galleon = Galleon + mc.Galleon;

		ret.Sickle += ret.Knut / KuntBase;
		ret.Knut = ret.Knut % KuntBase;
		ret.Galleon += ret.Sickle / SickleBase;
		ret.Sickle = ret.Sickle % SickleBase;

		return ret;
	}
	void print()const{
		printf("%d.%d.%d",Galleon,Sickle,Knut);
	}
};

int main(){
	MagicCurrency mc1,mc2;
	scanf("%d.%d.%d %d.%d.%d",&(mc1.Galleon),&(mc1.Sickle),&(mc1.Knut),&(mc2.Galleon),&(mc2.Sickle),&(mc2.Knut));

	MagicCurrency sum = mc1 + mc2;
	sum.print();

	return 0;
}