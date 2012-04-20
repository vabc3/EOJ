/*
 * =====================================================================================
 *
 *       Filename:  judge.cpp
 *
 *    Description:  Judger
 *
 *        Version:  1.0
 *        Created:  2012年04月20日 21时07分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Karata Lau (kl), vabc3h@gmail.com
 *        Company:  ZJU
 *
 * =====================================================================================
 */
#include "judgebase.h"
#include "jab.h"
void test(JudgeBase* judgeBase)
{
	judgeBase->run("a","c");
}

int main()
{	
	test(new J0());
	return 0;
}
