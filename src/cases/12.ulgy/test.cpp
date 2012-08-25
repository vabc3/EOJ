#include "../../jungle/jungle.h"
#include "../../jungle/datas.h"

int main()
{

	Jungle<int,int> jun(new Dinout<int>("in"),new Dinout<int>("out"));
	jun.Run();
	return 0;
}

int m1(const int& d);
int m2(const int& d);
void mid();
int Travel(const int& d)
{	
	mid();
	return m2(d);
}

#define min2(a,b) ((a)<(b)?(a):(b))
#define min3(a,b,c) min2(min2(a,b),c)

int m1(const int& d)
{
	int * pg =new int [d];
	pg[0]=1;
	int nex=1;
	int *pg2=pg;
	int *pg3=pg;
	int *pg5=pg;
	while(nex<d){
		int mi=min3(*pg2*2,*pg3*3,*pg5*5);
		pg[nex]=mi;
		while(*pg2*2<=pg[nex])++pg2;
		while(*pg3*3<=pg[nex])++pg3;
		while(*pg5*5<=pg[nex])++pg5;
		++nex;
	}
	int ulg=pg[nex-1];
	delete [] pg;
	return ulg;
}

#define N 1500;
int s[1600];

void mid(){
	s[0]=2;s[1]=3;s[2]=3;
	int cou=3;
	while(cou<=N){

	}

}

int m2(const int& d){

	return 1;
}

