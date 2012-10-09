#include "datas.h"
#include "jungle.h"
#include <iostream>
#include <cstring>
using namespace std;

void Travel1(TreeNode* root,string&);
string Travel(TreeNode* root)
{
	string f;
	Travel1(root,f);
	return f;
}
/*
class Proc
{
public:
	string deal(TreeNode* tn){
		string tk;
		Travel(tn,tk);
		return tk;
	}
};
*/
class Din:public FileDataSource<TreeNode*>
{
public:
	Din():FileDataSource("tree.in"){}
	TreeNode* _do(istream& is){
		string s1,s2;
		is>>s1;
		is>>s2;
		return TreeBuild(s1.c_str(),s2.c_str(),s1.length());
	}
};

class Dox:public FileDataSource<string>
{
public:
	Dox():FileDataSource("tree.in"){}
	string _do(istream& is){
		string s1,s2;
		is>>s1;
		is>>s2;
		TreeNode* k=TreeBuild(s1.c_str(),s2.c_str(),s1.length());
		string rt;
		TreeBT(k,rt);
		return rt;
	}
};

int main()
{
//	Jungle<TreeNode*,string,Proc> jun(new Din,new Dox);
	Jungle<TreeNode*,string> jun(new Din,new Dox);
	jun.Run();
	return 0;
}
#include <stack>
void Travel1(TreeNode* root,string& rt)
{
	//if(root=NULL)return;
	//PT
	/*
	stack<TreeNode*> sk;
	sk.push(root);
	while(!sk.empty()){
		TreeNode* p	= sk.top();
		sk.pop();
		rt+=p->data;
		if(p->right)sk.push(p->right);
		if(p->left)sk.push(p->left);
	}
*/
	/*MT
	stack<TreeNode*> sk;
	TreeNode* p=root;
	while(p){
		sk.push(p);p=p->left;}
	while(!sk.empty()){
		p=sk.top();
		sk.pop();
		rt+=p->data;
		p=p->right;
		while(p){   
			sk.push(p);p=p->left;}
	}
	*/
	stack<TreeNode*> sk;
	TreeNode* p=root;
	TreeNode* pre=NULL;
	while(p||!sk.empty()){
		if(p){
			while(p){sk.push(p);p=p->left;}
		}
		p=sk.top();
		if((!p->right)||(pre==p->right)){
			rt+=p->data;pre=p;sk.pop();p=NULL;
		}else
			p=p->right;
	}
	/* sol1
	while(p){sk.push(p);p=p->left;}
	while(!sk.empty()){
		p=sk.top();

		if(p->right){
			p=p->right;
			while(p){   
				sk.push(p);p=p->left;
			}
		}else{
			rt+=p->data;
			sk.pop();
			while((!sk.empty()) && (sk.top()->right==p) ){
				p=sk.top();rt+=p->data;sk.pop();
			}
		}
	}
*/
	/*2
	while(p){sk.push(p);p=p->left;}
	TreeNode* pre=NULL;
	while(!sk.empty()){
		p=sk.top();
		if((!p->right)||(pre==p->right)){
			rt+=p->data;
			pre=p;
			sk.pop();
		}else{
			p=p->right;
			while(p){sk.push(p);p=p->left;}
		}
	}
*/



}












