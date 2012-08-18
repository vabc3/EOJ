#include<cstdio>
#include <string>
#include <cassert>

using namespace std;

class TreeNode
{
public:
	char data;
	TreeNode* left;
	TreeNode* right;
};

class Tree
{
public:
	Tree(TreeNode* root):root(root){}
	TreeNode* root;
};

TreeNode* TreeBuild(const char* qx,const char* zx,int len){
//	printf("%d:[%s]--[%s]\n",len,qx,zx);
	if(len==0)return NULL;
	TreeNode* a= new TreeNode();
	a->data=*qx;
	const char* z=zx;
	while((*z) &&(  *z!=*qx))z++;
	assert(*z);
	int gap=z-zx;
//	printf("left of %c|",a->data);
	a->left=TreeBuild(qx+1,zx,gap);
//	printf("Right of %c|",a->data);
	a->right=TreeBuild(qx+1+gap,z+1,len-gap-1);
	return a;
};

void TreePT(TreeNode* root,string& data)
{
	if(root==NULL)return;
	data+=root->data;
	TreePT(root->left,data);
	TreePT(root->right,data);
}

void TreeMT(TreeNode* root,string& data)
{
	if(root==NULL)return;
	TreeMT(root->left,data);
	data+=root->data;
	TreeMT(root->right,data);
}
void TreeBT(TreeNode* root,string& data)
{
	if(root==NULL)return;
	TreeBT(root->left,data);
	TreeBT(root->right,data);
	data+=root->data;
}

struct LinklistNode
{
	int data;
	LinklistNode* next;
};
