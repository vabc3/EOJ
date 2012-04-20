/*
 * =====================================================================================
 *
 *       Filename:  eoj.cpp
 *
 *    Description:  Main Entrance of eoj
 *
 *        Version:  1.0
 *        Created:  2012年04月20日 19时17分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Karata Lau (kl), vabc3h@gmail.com
 *        Company:  ZJU
 *
 * =====================================================================================
 */

#include <iostream>
#include <libintl.h>
#define _(String) gettext (String)
using namespace std;

static void init_nls()
{
	setlocale(LC_ALL,"");
	bindtextdomain("eoj", "");
 	textdomain("eoj");
}

int main(int argc,char** argv)
{
	init_nls();

	if(argc != 3){
		cerr<<*argv<<_(" <prog> <case>")<<endl;
	}

	return 0;
}
