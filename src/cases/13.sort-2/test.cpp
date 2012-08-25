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
	Dinout<IntArray>* doo=new Dinout<IntArray>("out");
	Jungle<IntArray,IntArray> jun(dii,doo);
	jun.Run();

	delete dii;
	delete doo;
	return 0;
}

IntArray m1(const IntArray& d);
IntArray m2(const IntArray& d);
IntArray Travel(const IntArray& d)
{	
	IntArray z=m1(d);
	return m2(z);
}


IntArray m1(const IntArray& d)
{
	IntArray z=d;
	int l=z.size();
	for(int i=l-1;i>=0;i--){
		int dn=rand_n(l);
		if(dn<i){
			int tmp=z[i];
			z[i]=z[dn];
			z[dn]=tmp;
		}
	}
	return z;
}

/*	  0
 *   1 2 
 * 3 4 5 6
 *
 */



void siftup(int *s,int x)
{
	assert(s!=NULL);
	int up	= (x-1)/2;
	int tmp;
	if(x<=0)return;
	do{
		up	= (x-1)/2;
		if(s[up]<s[x]){
			tmp=s[up];s[up]=s[x];s[x]=tmp;
		}
		x	= up;
	}while(x>0);
}

void siftdown(int*s, int l, int x)
{
	assert(s!=NULL);
	int a=x*2+1;
	int tmp;
	if(a>=l)return;
	do{
		int chg=x;
		if(s[a]>s[x])chg=a;
		if(a+1<l && s[a+1]>s[chg])chg=a+1;
		if(chg!=x){
			tmp=s[chg];s[chg]=s[x];s[x]=tmp;
		}else{
			break;
		}
		x=chg;
		a=x*2+1;
	}while(a<l);
}

#define N 12

void build_heap(int* s,int n)
{
	assert(s && n>0);
	int fr=(n-1)/2;
	for(int i=fr;i>=0;i--)
		siftdown(s,n,i);
}

void heap_sort(int *s,int n)
{
	int tmp;
	for(int i=n-1;i>=0;i--){
		tmp=s[0];s[0]=s[i];s[i]=tmp;
		siftdown(s,i,0);
	}
}

IntArray m2(const IntArray& d)
{
	IntArray z=d;
	int* s=z.s;
	int n=z.sz;
	build_heap(s,N);
	for(int i=N+1;i<n;i++){
		if(s[i]>=s[0])continue;
		int tmp=s[0];s[0]=s[i];s[i]=tmp;
		siftdown(s,N,0);

	}
	heap_sort(s,n);
	return z;
}

