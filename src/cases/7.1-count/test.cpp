#include "../../jungle/jungle.h"
#include "../../jungle/datas.h"


class Din :public FileDataSource<int>
{
	public:
		Din():FileDataSource("in"){}
		int _do(istream& is){
			int al;
			is>>al;
			return al;
		}
};

class Dou :public FileDataSource<int>
{
	public:
		Dou():FileDataSource("out"){}
		int _do(istream& is){
			int al1;
			is>>al1;
			return al1;
		}
};
int Travel(int);
class Proc
{
	public:
		int deal(int tn){
			return Travel(tn);
		}

};

int main()
{
	Jungle<int,int,Proc> jun(new Din,new Dou);
	jun.Run();
	return 0;
}


#include<sstream>
int dl(int num)
{
	if(num==0)
		return 0;
	else if(num<10)
		return 1;
	int b=1;
	int c=0;
	while(b<=num)b*=10,c++;
	b/=10;c--;

	int h=num/b;
	int y=num%b;
	printf("%d,->%d,%d",num,h,y);
//y+1 -> fsdjl
//21345: dl(1345)  1346->11345  11346->21345
//10000
//
//c=2
//100 1, 00
//01->100
	int cou=0;	

	if(h==1)
		cou+=y+1;
	else
		cou+=b;
	int d=1;

	int cc=c-1;
	while(cc-->0)
		d*=10;

	cou+=h*c*d;
	return cou+dl(y);
}

int Travel(int pre)
{
	return dl(pre);
}

