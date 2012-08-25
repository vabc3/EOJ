//This is the base h
#include <iterator>
#include "datacontainer.h"
#include "case.h"
#include "common.h"

template<typename Tin,typename Tout,typename Processor = Proc<Tin,Tout> >
class Jungle
{
public:
	Jungle(DataSource<Tin>* tin,DataSource<Tout>* tou);
	void Run();
private:
	DataContainer<Tin> tin;
	DataContainer<Tout> tou;
};


template<typename Tin,typename Tout,typename Processor>
Jungle<Tin,Tout,Processor>::Jungle(DataSource<Tin>* tin,DataSource<Tout>* tou )
:tin(tin),tou(tou)
{
}

template<typename Tin,typename Tout,typename Processor>
void Jungle<Tin,Tout,Processor>::Run()
{
	cout<<"Run begin\n";//<<tin.getM()<<" cases\n";
	typename DataContainer<Tin>::iterator it=tin.begin();
	typename DataContainer<Tout>::iterator ot=tou.begin();
	int cou=0;
	int pass=0;
//	cout<<"Rlit :"<<*it<<endl;
		//<<" vs "<<*ot<<endl;
	while(it!=tin.end()){
		Case<Tin,Tout,Processor> dat(*it,*ot);
		cout<<"Case #"<<++cou<<": ";
		if(dat.validate())pass++;
		it++;ot++;
	}
	if(pass<cou)
		cout<<"("<<pass<<"/"<<cou<<")";
	else
		cout<<"All";
	cout<<" passed!\n";
};

