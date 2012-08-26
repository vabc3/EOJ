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
		fd	= ia.fd;
		s	= new int[sz];
		memcpy(s,ia.s,sz*sizeof(int));
	}

	IntArray(const IntArray& ia){
		sz	= ia.sz;
		fd	= ia.fd;
		s	= new int[sz];
		memcpy(s,ia.s,sz*sizeof(int));
	}
	
	void operator=(const IntArray& ia){
		IntArray p(ia);
		this->sz=p.sz;
		this->fd=p.fd;
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
	int fd;
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
	is>>ia.fd;
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

int findx(int* s,int a, int b,int x)
{
	int rt=-1;
	assert(a<=b);
	while(a<=b){
//printf("a=%d,b=%d",a,b);		
		if(a==b){
			if(s[a]==x)rt=a;
			break;
		}else{
			int m=(a+b)/2;
			bool left=true;
			if(s[a]<s[b]){
				if(x>s[m])
					left=false;
			}else if(s[a]==s[b] && (s[m]==s[a])){
//	printf("%d==?%d\n",x,s[m]);			
//				if(x==s[m]){
//					rt=m;break;
//				}
//	cout<<"sxd"<<endl;
				for(int i=m+1;i<b;i++){
					if(s[i]!=s[a]){left=false;break;}
				}
			}else{
				if(s[m]>=s[a]){
					if(x>s[m] || x<=s[b])
						left=false;
				}else{
					if(x>s[m] && x<=s[b])
						left=false;
				}
			}
			if(left)
				b=m;
			else
				a=m+1;
		}
	}
	return rt;
}

int findx2(int* s,int a, int b,int x)
{
	int rt=-1;
	if(a>b)throw exception();
	while(a<b){
		bool left	= true;
		int m		= (a+b)/2;
		if(s[a]<s[b]){
			if(x>s[m])left=false;
		}else if(s[a]==s[m] && s[a]==s[b]){
				for(int i=m+1;i<=b;i++)if(s[i]!=s[a]){left=false;break;}
		}else if(s[a]>s[m]){
			if(x>s[m] && x<=s[b])left=false;
		}else{
			if(x>s[m] || x<=s[b])left=false;
		}

		if(left)
			b=m;
		else
			a=m+1;
	}

	if(a==b && s[a]==x)rt=a;

	return rt;
}

int Travel(const IntArray& d)
{
	int len = d.sz;
	int* s	= d.s;
//cout<<"fd="<<d.fd;
	return findx2(s,0,len-1,d.fd);
}


