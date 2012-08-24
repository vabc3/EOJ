#include "../../jungle/jungle.h"
#include "../../jungle/datas.h"

int main()
{

	Jungle<string,string> jun(new Dinout<string>("in"),new Dinout<string>("out"));
	jun.Run();
	return 0;
}

string m1(const string& d);
string Travel(const string& d)
{	
	return m1(d);
}


string m1(const string& di)
{
	string d=di;
	int len	= d.length();
	int p1=0;
	int p2=len-1;
	while(d[p1]%2==1)p1++;
	while(d[p2]%2==0)p2--;
	while(p1<p2){
		char tp=d[p1];
		d[p1]=d[p2];
		d[p2]=tp;
		while(d[p1]%2==1)p1++;
		while(d[p2]%2==0)p2--;
	}

	return d;
}






