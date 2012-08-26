#include "../../jungle/jungle.h"
#include "../../jungle/datas.h"
#include <string.h>
class IntArray
{
public:
	IntArray(){s=NULL;sz=0; 
		from=to=len=-2;
	}
	~IntArray(){
//		printf("s=%lld\n",s);
		delete [] s;
	}
	
	IntArray(IntArray& ia){
//		cout<<"Nonconst copy ia.len="<<ia.len<<endl;
		sz	= ia.sz;
		from=ia.from;
		to=ia.to;
		len=ia.len;

		s	= new int[sz];
		memcpy(s,ia.s,sz*sizeof(int));
	}

	IntArray(const IntArray& ia){
		sz	= ia.sz;
		from=ia.from;
		to=ia.to;
		len=ia.len;
		s	= new int[sz];
		memcpy(s,ia.s,sz*sizeof(int));

//		cout<<"const copy len="<<len<<endl;
	}
	
	void operator=(const IntArray& ia){

		IntArray p(ia);
		this->sz=p.sz;
		this->from=p.from;
		this->to=p.to;
		this->len=p.len;
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
	int from,to,len;
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
	is>>ia.from>>ia.to>>ia.len;
//	printf("raed:%d,%d,%d\n",ia.from,ia.to,ia.len);
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
//	IntArray z=m1(d);

//	return m1(z);i

//printf("Tra:%d,%d,%d\n",d.from,d.to,d.len);
	return m1(d);
}


IntArray m1(const IntArray& d)
{
	IntArray z(d);
	int from=z.from;
	int to=z.to;
	int len=z.len;
	int *s =z.s;
	if(to>from)
		for(int i=len-1;i>=0;i--)s[to+i]=s[from+i];
	else if(to==from)
		for(int i=0;i<len;i++)s[to+i]=s[from+i];
	return z;
}

