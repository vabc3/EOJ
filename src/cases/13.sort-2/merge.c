#include"sort.h"
int bm[N/2+1],cm[N/2+1];

void merge(int p,int q,int r);
void merge_sort(int p,int r);

void sort(){
	merge_sort(0,N-1);	
}

void merge(int p,int q,int r)
{
	printf("[%d]\n",p);
	int i,j,k;
	for(i=p;i<=q;i++){
		bm[i-p]=am[i];
	}
	bm[q-p+1]=M;
	for(i=q+1;i<=r;i++){
		cm[i-q-1]=am[i];
	}
	cm[r-q]=M;
	i=j=1;
	for(k=p;k<=r;k++){
		if(k==0){
			printf("%d,%d\n",bm[i],cm[j]);
		}
		if(bm[i]<cm[j])
			am[k]=bm[i++];
		else
			am[k]=cm[j++];
	}
//	showam();
}

void merge_sort(int p,int r)
{
	int q;
	if(p<r){
		q=(p+r)/2;
		merge_sort(p,q);
		merge_sort(q+1,r);
		merge(p,q,r);
	}
}
