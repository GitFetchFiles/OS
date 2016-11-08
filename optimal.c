#include<stdio.h>
void display();
int n,page[20],fsize,frame[20],i,j=0,flag=0;
void main()
{
	int pf=0, ph=0, max,temp[10],index,m;
	printf("Enter the number of pages:");
	scanf("%d",&n);
	printf("Enter the size of frame:");
	scanf("%d",&fsize);
	printf("Enter the reference string:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&page[i]);
	}
	for(i=0;i<fsize;i++)
	{
		frame[i]=-1;
	}
        for(j=0;j<fsize;j++)
	{
	 	frame[j]=page[j];
	  	flag=1;
	  	pf++;
	  	display();
	  	printf("\n");
	}
	for(j=fsize;j<n;j++)
	{
	  	flag=0;
	  	for(i=0;i<fsize;i++)
	  	{
	   		if(frame[i]==page[j])
	   		{
	    			flag=1;
	    			ph++;
	    			break;}}
	  	if(flag==0)
	  	{
	   		for(i=0;i<fsize;i++)
	   			temp[i]=0;
	   		for(i=0;i<fsize;i++)
	   		{
	    			for(m=j+1;m<n;m++)
	    			{
	     				if(frame[i]==page[m])
	     				{
	      					temp[i]=m-j;
	      					break;
	     				}
	    			}
	   		}
	   		max=temp[0];
	   		index=0;
	   		for(i=0;i<fsize;i++)
	   		{
	    			if(temp[i]==0)
	    			{
	     				index=i;
	     				break;
	    			}
	    			else
	    			{
	     				if(max<temp[i])
	     				{
	      					max=temp[i];
	      					index=i;
	     				}}}
	   		frame[index]=page[j];
	   		pf++;
	   		display();
	   		printf("\n");
	  	}
	 }
	 printf("\nPage faults:%d\n",pf);
	 printf("\nPage hits:%d\n",ph);
}
void display()
{
	for(i=0;i<fsize;i++)
			printf("|%d|",frame[i]);
}
/* output
Enter the number of pages:20
Enter the size of frame:3
Enter the reference string:1
2
3
2
1
5
2
1
6
2
5
6
3
1
3
6
1
2
4
3
|1||-1||-1|
|1||2||-1|
|1||2||3|
|1||2||5|
|6||2||5|
|6||2||3|
|6||1||3|
|2||1||3|
|4||1||3|
Page faults:9
Page hits:11*/
