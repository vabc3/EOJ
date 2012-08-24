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
#endif
