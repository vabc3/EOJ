#ifndef _CASE_H
#define _CASE_H
#include <iostream>

template<typename TInput,typename TOutput,typename Processor>
class Case
{
	private:
		TInput  	input;
		TOutput 	expected;
		Processor 	proc;
	public:
		Case(TInput input,TOutput expected):input(input),expected(expected){}
		bool validate();
};

template<typename TInput,typename TOutput,typename Processor>
bool Case<TInput,TOutput,Processor>::validate()
{
	using std::cout;
	using std::endl;
	TOutput out	= proc.deal(input);
	cout<<"Expecting ["<<expected<<"] by ["<<out<<"]\t";
	bool rt;
	if(expected	== out){
		cout<<"Pass!"<<endl;
		rt= true;
	}else{
		cout<<"\33[5m\33[31mFail!\33[0m"<<endl;
		rt= false;
	}
	return rt;
}
#endif
