#include "../../jungle/jungle.h"
#include "../../jungle/datas.h"
#include <string.h>

class IntArray
{
public:
	IntArray(){s=NULL;sz=0;}
	~IntArray(){
//		printf("s=%lld\n",s);
		delete [] s;
	}
	
	IntArray(IntArray& ia){
		sz	= ia.sz;
		s	= new int[sz];
		memcpy(s,ia.s,sz*sizeof(int));
	}

	IntArray(const IntArray& ia){
		sz	= ia.sz;
		s	= new int[sz];
		memcpy(s,ia.s,sz*sizeof(int));
	}
	
	void operator=(const IntArray& ia){
		IntArray p(ia);
		this->sz=p.sz;
		int* tmp = this->s;
		this->s=p.s;
		p.s=tmp;
	}

	const int& operator[](int idx) const
	{
		assert(idx<sz);
		return s[idx];
	}
	int& operator[](int idx)
	{
		assert(idx<sz);
		return s[idx];
	}
	int size() const
	{
		return sz;
	}
	int *s;
	int sz;
	friend bool operator==(const IntArray& a, const IntArray& b); 
	friend istream& operator>>(istream& is,IntArray& ia); 
	friend ostream& operator<<(ostream& is,IntArray ia); 
};

bool operator==(const IntArray& a, const IntArray& b)
{
	bool rt=true;
	int l1=a.size();
	if(l1!=b.size())
		rt=false;
	else{
		for(int i=0;i<l1;i++){
			if(a[i]!=b[i]){
				rt=false;
				break;
			}
		}
	}
	return rt;
}

istream& operator>>(istream& is,IntArray& ia)
{
	int t;
	if(ia.s){
		delete [] ia.s;
	}
	is>>ia.sz;
	ia.s=new int[ia.sz];
	for(int i=0;i<ia.sz;i++){
		is>>t;
		ia.s[i]=t;
	}
	return is;
}

ostream& operator<<(ostream& os,IntArray iar)
{
	int* ia=iar.s;
	for(int* it=ia;it!=ia+iar.sz;it++){
		os<<*it<<" ";
	}
	return os;
}

int main()
{
	rand_init();
	Dinout<IntArray>* dii=new Dinout<IntArray>("in");
	Dinout<int>* doo=new Dinout<int>("out");
	Jungle<IntArray,int> jun(dii,doo);
	jun.Run();

	delete dii;
	delete doo;
	return 0;
}

int findm(int* s,int a, int b)
{
	assert(a<=b);
	while(a<b &&  s[a]>=s[b]){
//		printf("%d,%d\n",a,b);
		int m = (a+b)/2;
//		printf("%d>%d?\n",s[m],s[a]);
		
		if(s[m]>=s[a]){
			if(s[b]<s[a]){
				a=m+1;
			}else{
				for(int i=a+1;i<m;i++){
					if(s[i]!=s[a])return i;
				}
				return findm(s,m+1,b);
			}
		}else{
			b=m;
		}
	}
	return a;
}

int Travel(const IntArray& d)
{
	int len = d.sz;
	int* s	= d.s;


	return findm(s,0,len-1);
}


