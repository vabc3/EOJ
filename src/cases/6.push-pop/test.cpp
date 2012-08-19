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

#include <stack>
int Travel(const DIF& d)
{
	stack<char> sk;
	string b1=d.all;
	string b2=d.pat;
	int l=b1.length();
	int p1=0;
	int p2=0;
	cout<<"len="<<l<<endl;
	while(p2<l){
		while((sk.empty())||(b2[p2]!=sk.top())&&(p1<l))sk.push(b1[p1++]);
		cout<<"p1="<<p1<<";p2="<<p2<<endl;
		cout<<"top="<<sk.top()<<";b2[p2]="<<b2[p2]<<endl;
		if(sk.top()!=b2[p2]) return 0;
		sk.pop();p2++;
	}

	return 1;
}
