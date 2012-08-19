#include "../../jungle/jungle.h"
#include "../../jungle/datas.h"

class Din :public FileDataSource<LinklistNode*>
{
	public:
		Din():FileDataSource("in"){}
		LinklistNode* _do(istream& is){
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
			return h;
		}
};

class Dou :public FileDataSource<string>
{
	public:
		Dou():FileDataSource("out"){}
		string _do(istream& is){
			string k;
			getline(is,k);
			return k;
		}
};
void Travel(LinklistNode* root,string&);
class Proc
{
	public:
		string deal(LinklistNode* tn){
			string tk;
			Travel(tn,tk);
			return tk;
		}

};

int main()
{
	Jungle<LinklistNode*,string,Proc> jun(new Din,new Dou);
	jun.Run();
	return 0;
}


void NoRes(LinklistNode* root)
{	
	LinklistNode* h=root;
	LinklistNode* p=h->next;
	LinklistNode* q=NULL;
	LinklistNode* r;
	while(p){
		r=p->next;
		p->next=q;
		q=p;
		p=r;
	}

	h->next=q;
}

LinklistNode* Rev(LinklistNode* p,LinklistNode* exist)
{
	if(p->next){
		LinklistNode* q=p->next;
		p->next=exist;
		exist=p;
		return Rev(q,exist);
	}else{
		p->next=exist;
		return p;
	}
}

void Res(LinklistNode* root)
{
	root->next=Rev(root->next,NULL);
}

void Travel(LinklistNode* root,string& st){
	Res(root);
	LinkTT(root,st);
}
