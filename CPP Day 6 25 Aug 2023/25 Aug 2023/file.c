#include<stdio.h>
int main()
{
	int a;
	FILE *fp;
	fp=fopen("input.txt","r");
	fscanf(fp,"%d",&a);
	printf("%d",a);
	fclose(fp);
return 0;

}
