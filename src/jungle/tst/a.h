template<typename T>
class KR
{
public :
	T j;
	void prt();
};
template<typename T>
void KR<T>::prt(){
	int a=1;
}
/*
template<>
void KR<int>::prt(){
	int b=2;
}
*/
