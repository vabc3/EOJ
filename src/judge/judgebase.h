#ifndef JUDGEBASE_H
#define JUDGEBASE_H

#include <iostream>
#include <string>
using std::istream;
using std::string;

class JudgeParameters
{
public:
	virtual ~JudgeParameters(){}
};

class JudgeReturnValue
{
public:
	virtual ~JudgeReturnValue(){}
	virtual bool compare(const JudgeReturnValue* b) =0;
};

class JudgeBase
{
public:
	JudgeBase();
	virtual ~JudgeBase();
	void run(string file_input,string file_expect);
protected:
	virtual bool getPair(istream& is_input,istream& is_expect)=0;
	virtual JudgeReturnValue* call()=0;
	bool judge();
	JudgeParameters* input;
	JudgeReturnValue* expect;
};

#endif //JUDGEBASE_H


