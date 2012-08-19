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

#include<deque>
void m1(TreeNode* root,string& st)
{
	if(NULL==root)return;
	deque<TreeNode*> qu;
	qu.push_back(root);
	while(!qu.empty()){
		TreeNode* t=qu.front();
		qu.pop_front();
		st+=t->data;
		if(t->left)qu.push_back(t->left);
		if(t->right)qu.push_back(t->right);
	}
}

void Travel(TreeNode* root,string& st)
{
	m1(root,st);	
}
