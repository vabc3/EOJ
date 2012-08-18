//#include<vector>
//using namespace std;

template<typename TCase>
class CaseIter// : public std::iterator<std::forward_iterator_tag,Case>
{
public:
	
private:
};

template<typename TCase,typename InputContainer,typename OutputContainer>
class CaseList
{
public:
	CaseList();
	typedef CaseIter<TCase> iterator;
private:
	InputContainer ic;
	OutputContainer oc;
};


