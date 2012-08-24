#include "../../jungle/jungle.h"
#include "../../jungle/datas.h"

class DIF
{

public:
	DIF(){}
	DIF(int p1,int p2):start(p1),len(p2){}
	int start,len;
	friend bool operator==(const DIF& a,const DIF& b);
	friend istream& operator<<(istream& is,DIF df);
};

bool operator==(const DIF& a,const DIF& b){
	return (a.start==b.start && a.len==b.len);
}

ostream& operator<<(ostream& os,DIF df)
{
	os<<"<"<<df.start<<","<<df.len<<">";
	return os;
}


class Din :public FileDataSource<string>
{
	public:
		Din():FileDataSource("in"){}
		string _do(istream& is){
			string a;
			getline(is,a);
			return a;
		}
};

class Dou :public FileDataSource<DIF>
{
	public:
		Dou():FileDataSource("out"){}
		DIF _do(istream& is){
			int a,b;
			is>>a>>b;
		
			return DIF(a,b);
		}
};

DIF Travel(const string& u);
class Proc
{
	public:
		DIF deal(const string& dif){
			return Travel(dif);
		}

};

int main()
{
	Jungle<string,DIF,Proc> jun(new Din,new Dou);
	jun.Run();
	return 0;
}

DIF m1(const string& d);
DIF Travel(const string& d)
{	
	return m1(d);
}


#include<map>
DIF m1(const string& d)
{
	map<char,int> data;
	string::const_iterator it;
	for(it=d.begin();it<d.end();it++){
		data[*it]++;
	}

	map<char,int>::iterator mit;
	//for(mit=data.begin();mit!=data.end();mit++)
	//	cout<<mit->first<<" ->"<<mit->second<<endl;
	
	int len	= d.length();
	int min = len;
	int mip	= 0;
	map<char,int> jisuan;
	int i;
	for(i=0;i<len;i++){
		jisuan	= data;
		int fr	= (len+len-1+i) % len;
		int of  =fr;
		bool fst=true;
//cout<<"i="<<i<<";fr="<<fr<<endl;		
		while(fst||fr!=of){
			fst=false;
//printf("d[%d]=%c\n",fr,d[fr]);			
			if(--jisuan[d[fr]]==0){
				int lx=(len+fr-i)%len+1;
//cout<<"Found lx="<<lx<<endl;				
				if(lx<min){
					mip=i;min=lx;
				}
				break;
			}
			if(--fr<0)fr+=len;
		}
	}

	return DIF(mip,min);
}






