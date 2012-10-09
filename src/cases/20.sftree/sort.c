#include"sort.h"
#include<stdio.h>
#include<string.h>
int am[N];

void readam(const char *fn)
{	
	int i;
	FILE *fp;
	fp = fopen(fn,"r");
	if(fp==NULL){
		fprintf(stderr,"文件%s打开错误\n",fn);
	}
	for(i=0;i<N;i++){
		fscanf(fp,"%d",&am[i]);
	}
	fclose(fp);
}

void stringam(char *buf)
{
	int i;
	char tmp[255];

	buf[0]='\0';
	for(i=0;i<N;i++){
		sprintf(tmp,"%d ",am[i]);
		strcat(buf,tmp);
	}
//	strcat(buf,"\n");
}

void showam()
{	char s[255];
	stringam(s);
	printf("%s\n",s);
}

