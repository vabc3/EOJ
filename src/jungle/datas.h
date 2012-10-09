#include <cstdio>
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
}

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

void LinkTT(LinklistNode* head,string& st)
{
	if(!head)return;
	LinklistNode* p=head->next;
	while(p){
		st+=p->data;p=p->next;
	}
}


void rev(char* s1,char* s2,int len){
	for(int i=0;i<len;i++)
		s2[len-1-i]=s1[i];
	s2[len]='\0';
}


#include <map>
template<typename TType>
struct Trie
{
	Trie(){
		data='0';
		parent=NULL;
	}
	TType data;
	map<TType,Trie*> childs;
	Trie* parent;

	bool match(char* str){
//        printf("ch[%c]\n",*str);
		if(!*str)
			return true;
		else{
			typename map<TType,Trie*>::iterator it=childs.find(*str);
//if(it==childs.end())printf("NULL!");	
			if(it==childs.end()){
				return false;
			}else{
				return it->second->match(str+1);
			}
		}
			
	}

	Trie** insertPfx(const TType* data,int len){
		Trie** dat=new Trie*[len];
		for(int i=0;i<len;i++){
			dat[i]=insert(data+i);
		}
		return dat;
	}

	Trie* insert(const TType* data){
		typename map<TType,Trie*>::iterator it=childs.find(*data);
		Trie* p;
		Trie* rt;

		if(*data){
			if(it!=childs.end()){
				p=it->second;
			}else{
				p = new Trie();
				p->parent=this;
				p->data=*data;
				childs[*data]=p;
			}
//            printf("x+1 %c %d\n",*(data),*(data));		
//            printf ( "this\n" );
			rt=p->insert(data+1);
//            printf ( "Got: %c\n",rt->data );
		}else{
//            printf("ret!");
			rt=this;
		}
		return rt;
	}

	void BackPrint(){
		Trie* p=this;
		while(p->parent){
			printf("%c ->",p->data);	
			p=p->parent;
		};
		printf ("]\n");
	}
};


typedef Trie<char> SuffixTree;



template<typename T>
T* find_low_ancestor (T* a, T* b)
{
	int la=0,lb=0;
	for(T* pa=a;pa->parent!=NULL;pa=pa->parent)la++;
	for(T* pa=b;pa->parent!=NULL;pa=pa->parent)lb++;
//    printf("la=%d,lb=%d\n",la,lb);
	while(la>lb)a=a->parent,la--;
	while(lb>la)b=b->parent,lb--;
//    int jt;
//    printf("la=%d\n",la);
//    a->BackPrint();
//    b->BackPrint();
	while(a!=b){
		a=a->parent,b=b->parent;
//        printf("jt=%d\n",jt++);
	}
	return a;
}
