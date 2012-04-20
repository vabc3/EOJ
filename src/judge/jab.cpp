/*
 * =====================================================================================
 *
 *       Filename:  jab.cpp
 *
 *    Description:  Test for a+b
 *
 *        Version:  1.0
 *        Created:  2012年04月20日 21时51分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Karata Lau (kl), vabc3h@gmail.com
 *        Company:  ZJU
 *
 * =====================================================================================
 */

#include "jab.h"
#include <iostream>
using namespace std;

bool J0::getPair(istream& is_input, istream& is_except)
{
	int a,b;

	if(is_input>>a>>b){
		input=new J0P(a,b);
		is_except>>a;
		expect=new J0R(a);
		return true;
	}else
		return false;
}


bool J0R::compare(const JudgeReturnValue* rb)
{
	J0R* b=dynamic_cast<J0R*>(const_cast<JudgeReturnValue*>(rb));
	cout<<r<<" VS "<<b->r<<endl;
	return r==b->r;
}

J0R* J0::call()
{
	J0P* data=dynamic_cast<J0P*>(input);
	return new J0R(data->a+data->b);
}

