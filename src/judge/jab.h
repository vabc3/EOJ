#include "judgebase.h"

class J0P : public JudgeParameters
{
public:
	J0P(int a,int b):a(a),b(b){}
	int a,b; 
};

class J0R : public JudgeReturnValue
{
public:
	J0R(int r):r(r){}
	virtual bool compare(const JudgeReturnValue*);
	int r;
};

class J0 : public JudgeBase
{
protected:
	virtual bool getPair(istream& is_input, istream& is_except);
    virtual J0R* call();
};
