#include<stdio.h>
int i,j,sum=0,n,d[20],head,temp,max,dloc,ch,cylinders,dis[100],dis1[100],m=0,k,q=0,sum1=0;
void low_start();
void high_end();
void main()
{
	printf("ENTER TOTAL NUMBER OF CYLINDERS:\n");
	scanf("%d",&cylinders);
	printf("ENTER TOTAL NUMBER OF LOCATIONS\t");
	scanf("%d",&n);
	printf("ENTER POSITION OF HEAD:\t");
	scanf("%d",&head);
	printf("ENTER ELEMENTS:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&d[i]);
	}
	d[n]=head;
	n=n+1;
	do
	{
		printf("\nENTER DIRECTION\n");
		printf("\n1.Towards Lower");
		printf("\n2)Towards Higher");
		printf("\n3)Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: low_start();
			break;

			case 2: high_end();
			break;

		}
	}while(ch!=3);
}
void low_start()
{
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(d[i]>d[j])
			{
				temp=d[i];
				d[i]=d[j];
				d[j]=temp;
			}
		}
	}
	max=d[n];
	for(i=0;i<n;i++)
	{
		if(head==d[i])
		{
			dloc=i;
			break;
		}
	}
	for(i=dloc;i>=0;i--)
	{
		printf("%d -->",d[i]);
		dis[m]=d[i];
		m++;

	}
	printf("0 -->");
	dis[m]=0;
	for(i=dloc+1;i<n;i++)
	{
		printf("%d-->",d[i]);
		dis[m+1]=d[i];
		m++;
	}
	for(k=0;k<m;k++)
	{
		sum=sum+abs(dis[k]-dis[k+1]);
	}
	printf("\nDISTANCE COVERED BY CYLINDERS= %d",sum);
}
void high_end()
{
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(d[i]>d[j])
			{
				temp=d[i];
				d[i]=d[j];
				d[j]=temp;
			}
		}
	}
	max=d[n];
	for(i=0;i<n;i++)
	{
		if(head==d[i])
		{
			dloc=i;
			break;
		}
	}
	for(i=dloc;i<n;i++)
	{
		printf("%d -->",d[i]);
		dis1[q]=d[i];
		q++;
	}
	printf("%d -->",cylinders-1);
	dis1[q]=cylinders-1;
	for(i=dloc-1;i>=0;i--)
	{
		printf("%d-->",d[i]);
		dis1[q+1]=d[i];
		q++;
	}
	for(k=0;k<q;k++)
	{
		sum1=sum1+abs(dis1[k]-dis1[k+1]);
	}
	printf("\nDISTANCE COVERED BY CYLINDERS= %d",sum1);
}
/*ENTER TOTAL NUMBER OF CYLINDERS:
100
ENTER TOTAL NUMBER OF LOCATIONS 5
ENTER POSITION OF HEAD: 25
ENTER ELEMENTS:
10
20
60
80
40

ENTER DIRECTION

1.Towards Lower
2)Towards Higher
3)Exit
Enter your choice:1
25 -->20 -->10 -->0 -->40-->60-->80-->
DISTANCE COVERED BY CYLINDERS= 105
ENTER DIRECTION

1.Towards Lower
2)Towards Higher
3)Exit
Enter your choice:2
25 -->40 -->60 -->80 -->99 -->20-->10-->
DISTANCE COVERED BY CYLINDERS= 163
ENTER DIRECTION

1.Towards Lower
2)Towards Higher
3)Exit
Enter your choice:3
