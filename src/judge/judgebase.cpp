/*
 * =====================================================================================
 *
 *       Filename:  judgebase.cpp
 *
 *    Description:  Impl
 *
 *        Version:  1.0
 *        Created:  2012年04月20日 21时36分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Karata Lau (kl), vabc3h@gmail.com
 *        Company:  ZJU
 *
 * =====================================================================================
 */

#include "judgebase.h"
//#include <tr1>
#include <iostream>
#include <fstream>
using namespace std;

JudgeBase::JudgeBase()
{
}

JudgeBase::~JudgeBase()
{
}

void JudgeBase::run(string file_input,string file_expect)
{
	cout<<"Run Begins\n";
	int n=1;
	ifstream fi(file_input.c_str()),fe(file_expect.c_str());
	cout<<boolalpha;
	try{
		fi.exceptions ( ifstream::goodbit | ifstream::badbit );
		fe.exceptions ( ifstream::failbit | ifstream::badbit );
		while(getPair(fi,fe))
			cout<<"Case "<<n++<<":"<<judge()<<endl;
	}catch(std::ios_base::failure){
		cout<<"file error!\n";
	}
}

bool JudgeBase::judge()
{
	JudgeReturnValue* jv	= call();

	return jv->compare(expect);
}


