#include "../../jungle/jungle.h"
#include "../../jungle/datas.h"

class DIF
{

public:
	DIF(){}
	DIF(string a,string b):all(a),pat(b){}
	string all,pat;
};

class Din :public FileDataSource<DIF>
{
	public:
		Din():FileDataSource("in"){}
		DIF _do(istream& is){
			string a,b;
			getline(is,a);
			getline(is,b);
			return DIF(a,b);
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

int Travel(const DIF& d)
{
	string a=d.all;
	string b=d.pat;
	int l	= b.length();
	int la	= a.length();
	if(a.length()<b.length())
		return -1;
	int base=128;

	long sb=0;
	for(string::iterator it=b.begin();it!=b.end();it++){
		sb=sb*base+*it;
	}
//cout<<"sb="<<sb<<endl;
	int h=0;
	int e=l;
	long sa=0;
	long ps=1;
	int i;
	for(i=h;i<e;i++){
		sa=sa*base+a[i];
		ps*=base;
	}
	ps/=base;
//cout<<"sa="<<sa<<endl;
	while(e<=la){
		if(sa==sb){
			break;
		}
		sa-=ps*a[h];
		sa=sa*base+a[e];
		h++;
		e++;
	}

	if(e>la)h=-1;
	return h;
}
