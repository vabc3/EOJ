#include "../../jungle/jungle.h"
#include "../../jungle/datas.h"

class DIF
{

public:
	DIF(){}
	DIF(string p1,string p2,string dat):p1(p1),p2(p2),dat(dat){}
	string p1,p2,dat;
};

class Din :public FileDataSource<DIF>
{
	public:
		Din():FileDataSource("in"){}
		DIF _do(istream& is){
			string a,b,c;
			getline(is,a);
			getline(is,b);
			getline(is,c);
			return DIF(a,b,c);
		}
};

class Dou :public FileDataSource<int>
{
	public:
		Dou():FileDataSource("out"){}
		int _do(istream& is){
			int k;
			is>>k;
			return k;
		}
};
int Travel(const DIF&);
class Proc
{
	public:
		int deal(const DIF& dif){
			return Travel(dif);
		}

};

int main()
{
	Jungle<DIF,int,Proc> jun(new Din,new Dou);
	jun.Run();
	return 0;
}

#include <bitset>
int Travel(const DIF& d)
{
	bitset<256> bs,v;
	bs.reset();
	string p1=d.p1;
	string p2=d.p2;
	string data=d.dat;
	string::iterator it;
	for(it=p1.begin();it<p1.end();it++)bs.set(*it);
	for(it=p2.begin();it<p2.end();it++)bs.set(*it);
	for(it=data.begin();it<data.end();it++)v.set(*it);
	if((bs&v).any())
		return 1;
	else
		return 0;
}
