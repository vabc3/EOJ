#include<iostream>
using namespace std;

void pr(char* number){
	char* p	= number;
	while(*p && *p=='0')p++;
	while(*p)cout<<*p++;
	cout<<endl;
}


void p1mr(char* number,int length, int index){
	if(index==length){
		pr(number);
		return;
	}
	for(int i=0;i<10;++i){
		number[index]='0'+i;
		p1mr(number,length,index+1);
	}
}

void p1mn(int n)
{
	if(n<=0)return;

	char* number =new char[n+1];
	number[n]='\0';
//	for(int i=0;i<10;i++){
//		number[0]='0'+i;
		p1mr(number,n,0);
//	}
	delete[] number;

}

int main()
{

	p1mn(3);

	return 0;
}
