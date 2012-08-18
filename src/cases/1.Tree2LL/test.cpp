#include "../../jungle/jungle.h"
#include "../../jungle/datas.h"

class Din :public FileDataSource<TreeNode*>
{
	public:
		Din():FileDataSource("in"){}
		TreeNode* _do(istream& is){
			string s1,s2;
			is>>s1;
			is>>s2;
			return TreeBuild(s1.c_str(),s2.c_str(),s1.length());
		}
};

class Dou :public FileDataSource<string>
{
	public:
		Dou():FileDataSource("out"){}
		string _do(istream& is){
			string k;
			is>>k;
			return k;
		}
};
void Travel(TreeNode* root,string&);
class Proc
{
	public:
		string deal(TreeNode* tn){
			string tk;
			Travel(tn,tk);
			return tk;
		}

};

int main()
{
	Jungle<TreeNode*,string,Proc> jun(new Din,new Dou);
	jun.Run();
	return 0;
}


void MakeList(TreeNode* root,LinklistNode*& head)
{
	if(root==NULL)return;
	LinklistNode* p=NULL;
	MakeList(root->left,head);
	p=new LinklistNode();
	p->data=root->data;
	head->next=p;
	head=p;

	MakeList(root->right,head);
}

void Travel(TreeNode* root,string& st)
{
	LinklistNode* head=new LinklistNode();
	head->next=NULL;
	LinklistNode* p=head;
	MakeList(root,p);
	p=head->next;
	while(p){
		st+=p->data;
		p=p->next;
	}
}
