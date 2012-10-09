#include "../../jungle/jungle.h"
#include "../../jungle/datas.h"
#include <string.h>

class BinString
{
public:
	string a,b;
//	friend istream& operator>>(istream& is,BinString& ia); 
//	friend ostream& operator<<(ostream& is,const BinString& ia); 
};


istream& operator>>(istream& is,BinString& ia)
{
	getline(is,ia.a);
	getline(is,ia.b);
	return is;
}

ostream& operator<<(ostream& os,const BinString& iar)
{
	os<<iar.a<<"&"<<iar.b;
	return os;
}

int main()
{
	rand_init();
	Dinout<BinString>* dii=new Dinout<BinString>("in");
	Dinout<string>* doo=new Dinout<string>("out");
	Jungle<BinString,string> jun(dii,doo);
	jun.Run();

	delete dii;
	delete doo;
	return 0;
}

string m2(const BinString& d);
string Travel(const BinString& d)
{	
	return m2(d);
}
#define MAX(a,b) ((a)>(b))?(a):(b)
string m2(const BinString& d){
	const string& a=d.a;
	const string& b=d.b;
	int la=a.length();
	int lb=b.length();
	
	int s[la][lb];
	int p[la][lb];

	int i,j;

	for(j=0;j<lb;j++){
		s[0][j]=(a[0]==b[j]);
		p[0][j]=-1;
	}
	for(i=1;i<la;i++){
		s[i][0]=(a[i]==b[0]);
		p[i][0]=-1;
	}

	for(i=1;i<la;i++){
		for(j=1;j<lb;j++){
			int ma,mp;
			if(s[i-1][j]>=s[i][j-1]){
				ma=s[i-1][j];
				mp=1;
			}else{
				ma=s[i][j-1];
				mp=2;
			}
			if(a[i]==b[j] && ma<s[i-1][j-1]+1){
				ma=s[i-1][j-1]+1;
				mp=3;
			}
			s[i][j]=ma;
			p[i][j]=mp;
		}
	}

//	cout<<s[la-1][lb-1]<<endl;
	string k;
	int pi=la-1;
	int pj=lb-1;
	while(p[pi][pj]!=-1){
//cout<<pi<<"/"<<pj<<" "<<p[pi][pj]<<endl;		
		if(p[pi][pj]==3){
		if(a[pi]==b[pj]){
//			cout<<"pj="<<pj<<endl;
			k+=a[pi];
		}
			pi--;pj--;
		}else if(p[pi][pj]==2){
			pj--;
		}else
			pi--;
	}
	if(a[pi]==b[pj])k+=a[pi];

	return string(k.rbegin(),k.rend());
}
