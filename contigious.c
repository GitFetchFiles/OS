#include<stdio.h>
void main()
{
	int fs,bs,sb,nb,val,search,byteno,offset;
	printf("Enter the File Size in bytes: \n");
	scanf("%d",&fs);
	printf("Enter the Block Size in bytes: \n");
	scanf("%d",&bs);
	printf("Enter the Start Block: \n");
	scanf("%d",&sb);
	val=fs/bs;
	nb=convert(val);
	printf("Number of blocks: 2^%d = %d\n",nb,val);
	printf("Enter the number to be searched\n");
	scanf("%d",&search);
	byteno=search/bs;
	offset=search%bs;
	printf("The block number is %d\nThe offset is %d\n",byteno+sb,offset);
}

int convert(int a)
{
	int count=0;
	while(a>=2)
	{
		a=a/2;
		count++;
	}
	return count;
}
