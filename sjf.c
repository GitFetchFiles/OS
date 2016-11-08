#include<stdio.h>
#include<stdlib.h>
void main()
{
        int wt[20],bt[20],at[20],i,j,p1[20],temp,n,k,flag,tat[20],totaltat=0,totalwt=0;
        float avgwt=0.0,sum=0.0,avgtat;
        printf("\nEnter no of processes:");
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
                printf("\nEnter burst time of P%d:",i+1);
                scanf("%d",&bt[i]);
        }

        for(i=0;i<n;i++)
        {

                printf("\nEnter arrival time of P%d:",i+1);
                scanf("%d",&at[i]);
        }

        for(i=0;i<n;i++)
        {
                for(j=i+1;j<n;j++)
                {
                        if((at[i]>at[j]) || ((at[i]==at[j]) && (bt[i]>bt[j])))
                        {
                                temp=at[i];
                                at[i]=at[j];
                                at[j]=temp;

                                temp=bt[i];
                                    bt[i]=bt[j];
                                bt[j]=temp;

                                temp=p1[i];
                                p1[i]=p1[j];
                                p1[j]=temp;
                        }
                }
        }
        k=at[0]+bt[0];

    for(i=1;i<n;i++)
        {
                for(j=i+1;j<n;j++)
                {
                        if(bt[i]>bt[j] && k>=at[j])
                        {
                                flag=1;

                                temp=bt[i];
                                bt[i]=bt[j];
                                bt[j]=temp;

                                temp=at[i];
                                at[i]=at[j];
                                at[j]=temp;

                                temp=p1[i];
                                p1[i]=p1[j];
                                p1[j]=temp;
                        }
                }
                if (flag==0)
                k=k+bt[i];
                else
                k++;
                flag=0;
        }
        wt[0]=0;
        for(i=0;i<n;i++)
        {
        tat[i]=0;
                for(j=i;j>=0;j--)
                {
                        tat[i]=tat[i]+bt[j];
                }
                tat[i]=tat[i]-at[i];
                wt[i]=tat[i]-bt[i];
        }
        printf("\n");
        printf("Process\t\tAT\t\tBT\t\tTAT\t\tWT\n");
        printf("------------------------------------------------------------------------------\n");
        for(i=0;i<n;i++)
        {
                printf("%d\t\t%dms\t\t%dms\t\t%dms\t\t%dms\n",i, at[i],bt[i],tat[i],wt[i]);
                totaltat+=tat[i];
                totalwt=totalwt+wt[i];
        }

        avgwt=(float)totalwt/n;
        printf("\nAverage Waiting Time = %.2fms\n",avgwt);
        avgtat=(float)totaltat/n;
        printf("\nAverage Turn Around Time = %.2fms\n",avgtat);
}


/*OUTPUT
Enter no of processes:5

Enter burst time of P1:5

Enter burst time of P2:3

Enter burst time of P3:4

Enter burst time of P4:1

Enter burst time of P5:2

Enter arrival time of P1:0

Enter arrival time of P2:0
