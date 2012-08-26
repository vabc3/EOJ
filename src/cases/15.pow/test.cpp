#include "../../jungle/jungle.h"
#include "../../jungle/datas.h"
#include <math.h>
struct PF
{
	double base;
	int exp;
	friend istream& operator>>(istream& is,PF& pf);
};

istream& operator>>(istream& is,PF& pf)
{
	double a;
	int b;
	is>>a>>b;
	pf.base=a;
	pf.exp=b;
	return is;
}

class DBL
{

};

int main()
{

	Jungle<PF,double> jun(new Dinout<PF>("in"),new Dinout<double>("out"));
	jun.Run();
	return 0;
}

double m1(const PF& d);
double m2(const PF& d);
double Travel(const PF& d)
{	
	return m2(d);
}

double m1(const PF& d){
	
	return pow(d.base,d.exp);
}

double jf(double base,int exp){
	if(exp==0)
		return 1;
	else if(exp==1)
		return base;
	else{
		double z=jf(base,exp/2);
		return z*z*(exp%2?base:1);
	}
}

double m2(const PF& d){
	return jf(d.base,d.exp);
}
