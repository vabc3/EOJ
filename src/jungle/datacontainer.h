#ifndef _DCR
#define _DCR

#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

template<typename Ttype>
class DataContainer;

template<typename Ttype>
class DataSource;

template<typename Ttype>
class DataContainerIterator
{
public:
		DataContainerIterator(DataSource<Ttype>* idc=0,int p=0)
			:idc(idc),ptr(p){
				gain=false;
			}
		Ttype operator*(){
//			cout<<"Begin deref ->";
			if(!gain){gain=true;loc=idc->get();}
//cout<<"Got:["<<loc.len<<"]\n";
			return loc;
		}
		DataContainerIterator& operator++(int){
			ptr++;gain=false;
			return *this;
		}	
		bool operator!=(const DataContainerIterator<Ttype>& i) const{
			return ptr!=i.ptr;
		}
private:
	bool gain;
	Ttype loc;
	DataSource<Ttype>* idc;
	int ptr;
};

template<typename Ttype>
class DataSource
{
public:
//	virtual ~DataSource(){}
	virtual Ttype get()=0;
	virtual int getM()=0;
};

template<typename Ttype>
class FileDataSource :public DataSource<Ttype>
{
public:
		FileDataSource(string fn){
//			char ct[255];
//			fn.copy(ct,fn.length(),0);
//			ct[fn.length()]='\0';
			is=new ifstream(fn.c_str());
//			cout<<fn<<endl;
			try{
			is->exceptions(	ifstream::failbit|ifstream::badbit);
				*is>>max;
			}catch(std::ios_base::failure failure){
				cout<<"File error "<<fn<<endl;;
				exit(-1);
			}
			string tmp;
			getline(*is,tmp);
//			cout<<"Max is "<<max<<endl;
		}
		virtual ~FileDataSource(){
//cout<<"Call me!!!";
			is->close();
			delete is;
		}
		int getM(){
			return max;
		}
		Ttype get(){
			Ttype s=_do(*is);
//cout<<"In get()="<<s.len<<endl;
			return s;
		}
protected:
		virtual Ttype _do(istream& is)=0;
		int max;
		ifstream *is;
};

template<typename Ttype>
class DataContainer
{
public:
	DataContainer(DataSource<Ttype>* d){
		ds=d;
		max=ds->getM();
	}
	virtual ~DataContainer(){
//		delete ds;
	}
	typedef DataContainerIterator<Ttype> iterator;
	iterator begin(){ return DataContainerIterator<Ttype>(ds,0);}	
	iterator end(){ return DataContainerIterator<Ttype>(ds,max);}
protected:
	DataSource<Ttype>* ds;
	int max;
};
#endif
