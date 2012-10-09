#include"sort.h"
void sort()
{
	int i,j,k,tmp;
	for(i=1;i<N;i++){
		tmp=am[i];
		for(j=0;j<i;j++){
			if(am[j]>tmp)break;
		}
		for(k=i;k>=j;k--){
			am[k]=am[k-1];
		}
		am[j]=tmp;

//		showam();
	}
}
