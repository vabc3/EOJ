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
	if(expected	== out){
		cout<<"Pass!"<<endl;
		return true;
	}else{
		cout<<"Fail!"<<endl;
		return false;
	}
}
#endif
