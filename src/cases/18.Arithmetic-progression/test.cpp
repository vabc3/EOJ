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
	return m1(d);
}

static int cmp(const void* a,const void* b){
	int ia=*(int*)a;
	int ib=*(int*)b;
	return (ia-ib);
}

class jnt
{
public:
	jnt():count(0),next(-1){}
	int count;
	int next;
};

#include <map>
IntArray m1(const IntArray& d)
{
	IntArray z(d);
	int* s	= z.s;
	int l	= z.sz;
	qsort(s,l,sizeof(int),cmp);

	map<int,jnt> tab[l];
	for(int i=l-1;i>=0;i--){
		for(int j=i+1;j<l;j++){
			int delta=s[j]-s[i];
			if(tab[i][delta].count<tab[j][delta].count+1){
				tab[i][delta].count=tab[j][delta].count+1;
				tab[i][delta].next=j;
			}
		}
	}

	int big=-1;
	int ma;
	int del;
	for(int i=0;i<l;i++){
		for(map<int,jnt>::iterator it=tab[i].begin();it!=tab[i].end();it++){
//			printf("%d=>%d\n",it->first,it->second.count);
			if(big<0 ||  ma<it->second.count){
				big=i;
				ma=it->second.count;
				del=it->first;
			}
		}
	}
	
	int* dt=new int[ma+1];
	int pt=0;
	while(big!=-1){
//printf("dt[%d]=%d\n",pt,big);		
		dt[pt++]=z.s[big];
		big=tab[big][del].next;
	}

	delete [] z.s;
	z.s=dt;
	z.sz=ma+1;
	return z;
}


