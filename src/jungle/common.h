#ifndef COMMON_H
#define COMMON_H
template<typename TParam,typename TResult>
class Proc
{
	public:
		TResult deal(const TParam& dif){
			return Travel(dif);
		}
};

template<typename TData>
class Dinout :public FileDataSource<TData>
{
	public:
		Dinout(string filename):FileDataSource<TData>(filename){}
		TData _do(istream& is){
			TData a;
			is>>a;
//cout<<"DBG@!!!a.len="<<a.len<<endl;
			return a;
		}
};

template<>
class Dinout<string> :public FileDataSource<string>
{
	public:
		Dinout(string filename):FileDataSource<string>(filename){}
		string _do(istream& is){
			string a;
			getline(is,a);
			return a;
		}
};

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void rand_init()
{
	srand(time(NULL));
}

int rand_n(int n)
{
	return rand()%n;
}


#endif
