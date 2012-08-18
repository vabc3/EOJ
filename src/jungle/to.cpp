#include <iostream>

#include "case.h"
#include "datacontainer.h"
#include "jungle.h"

using namespace std;
class KP
{
	public:	
		int deal(int a){
			return a*3;
		}
};

class KDS :public DataSource<int>
{
	public:
		int get(){
			return idx++;
		}
		int getM(){return 7;}
	private:
		int idx;
};

class KDF:public FileDataSource<int>
{
	public:
		KDF():FileDataSource("in"){}
		int _do(istream& is){
			int tmp;
			is>>tmp;
			return tmp;
		}
};

int main()
{	
	Jungle<int,int,KP> jn(new KDS,new KDF);
	jn.Run();

	return 0;
}
