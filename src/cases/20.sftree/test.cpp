#include "../../jungle/jungle.h"
#include "../../jungle/datas.h"
#include <string.h>
typedef string TA;
typedef string TB;

int main()
{
	Dinout<TA>* dii=new Dinout<TA>("in");
	Dinout<TB>* doo=new Dinout<TB>("out");
	Jungle<TA,TB> jun(dii,doo);
	jun.Run();

	delete dii;
	delete doo;
	return 0;
}

TB m1(const TA& d);
TB m2(const TA& d);
TB Travel(const TA& d)
{	
	return m1(d);
}

int len(SuffixTree* sf)
{
	int l=0;
	while(sf->parent)l++,sf=sf->parent;
	return l;
}

TB m1(const TA& dat)
{
	SuffixTree a;
	int l=dat.length();
	SuffixTree** c= a.insertPfx((dat+"$").c_str(),l+1);
//    for(int i=0;i<l;i++)c[i]->BackPrint();
	string dat2=string(dat.rbegin(),dat.rend());
	SuffixTree** d= a.insertPfx((dat2+"#").c_str(),l+1);
//    for(int i=0;i<l;i++)d[i]->BackPrint();
	int ma=0;
	int mp=-1;
	int tp=0;
	for(int i=1;i<l;i++){
		int l1=len(find_low_ancestor(c[i],d[l-1-i]));
		if(2*l1-1>ma){ma=l1;mp=i;tp=1;}
		l1=len(find_low_ancestor(c[i],d[l-i]));
		if(2*l1>ma){ma=l1;mp=i;tp=0;}
	}

	printf("%d %d %d",ma,mp,tp);
	int l2=2*ma-tp;
	return dat.substr(mp+tp-ma,l2);
}

