#include "../../jungle/jungle.h"
#include "../../jungle/datas.h"

class DT
{
public:
	DT(){}
	DT(LinklistNode* ln,int dt):ln(ln),dt(dt)
	{
//		cout<<"new"<<endl;
//		cout<<ln<<endl;
	}
	LinklistNode* ln;
	int dt;
};

class Din :public FileDataSource<DT>
{
	public:
		Din():FileDataSource("in"){}
		DT _do(istream& is){
			int al;
			is>>al;
			LinklistNode* h = new LinklistNode();
			LinklistNode* p = h;
			while(al--){
				int t;
				is >>t;
				LinklistNode* q= new LinklistNode();
				q->data=t+'0';
				p->next=q;
				p=q;
			}
			p->next=NULL;
			is>>al;
			return DT(h,al);
		}
};

class Dou :public FileDataSource<char>
{
	public:
		Dou():FileDataSource("out"){}
		char _do(istream& is){
			string k;
			getline(is,k);
			return k[0];
		}
};
char Travel(LinklistNode* root,int);
class Proc
{
	public:
		int deal(DT tn){
//			cout<<"tn.ln="<<tn.ln<<endl;
			return Travel(tn.ln,tn.dt);
		}

};

int main()
{
	Jungle<DT,char,Proc> jun(new Din,new Dou);
	jun.Run();
	return 0;
}



char m1(LinklistNode* root,int pre)
{
	if(NULL==root)return 'X';
	LinklistNode* p;
	int c=0;
//	cout<<"root="<<root<<endl;
//cout<<"c="<<c<<";pre="<<pre<<endl;

//	cout<<root->data<<endl;
//	cout<<root->next->data<<endl;
	for(p=root->next;p!=NULL;c++,p=p->next);
	if(pre>c)return 'Y';
//cout<<"c="<<c<<";pre="<<pre<<endl;
	int i=c-pre;
	p=root->next;
	while(i--)p=p->next;
	return p->data;
}

char m2(LinklistNode* root,int pre)
{
	if(NULL==root)return 'X';
	LinklistNode* p=root;
	LinklistNode* q=root;
	while(--pre){
		p=p->next;

//cout<<"pre="<<pre<<endl;
		if(NULL==p)
			return 'Y';
	}
	while(p){
		q=q->next;p=p->next;
	}

	return q->data;

}
char Travel(LinklistNode* root,int pre)
{
//	cout<<"Travel root="<<root<<endl;
	return m2(root,pre);
}

