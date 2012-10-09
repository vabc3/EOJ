#include "datas.h"
#include "jungle.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	SuffixTree a;
	string dat="XYMADAMHIJ";

//    char dat[]="XYMADAMHIJ$";
//    char dar[255];
//    SuffixTree* b= a.insert(dat);
//    b->BackPrint();
//    int l=strlen(dat);
//    rev(dat,dar,l);
	int l=dat.length()+1;
    SuffixTree** c= a.insertPfx((dat+"$").c_str(),l);
	for(int i=0;i<l;i++){
		c[i]->BackPrint();
	}
	string dat2=string(dat.rbegin(),dat.rend());
    SuffixTree** d= a.insertPfx((dat2+"#").c_str(),l);
	for(int i=0;i<l;i++){
		d[i]->BackPrint();
	}

//    cout<<a.match("X")<<endl;
//    cout<<a.match("X1Y")<<endl;
//    cout<<a.match("MH")<<endl;

	SuffixTree* p=find_low_ancestor(c[4],d[5]);
	cout<<p->data<<endl;
	return 0;
}
