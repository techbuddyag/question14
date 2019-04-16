#include<stdio.h>

int main()
{
   int BURSTTIME[10],Processno[10],WEIGHTINGTIME[10],TURNAROUNDTIME[10];
   int ARRIVALTIME[10],priority[10],i,j,Noofprocess,tot=0,flag,temp,Avg_WEIGHTINGTIME,Avg_TURNAROUNDTIME;
   printf("No. of process you want to enter:");
   scanf("%d",&Noofprocess);
   printf("\nEnter the burst time and the priority: \n");
   for(i=0;i<Noofprocess;i++) //complexity=n
   {
       printf("\nP[%d]\n",(i+1));
       printf("Enter Burst Time:");
       scanf("%d",&BURSTTIME[i]);
       printf("Enter Arrival Time:");
       scanf("%d",&ARRIVALTIME[i]);
       printf("Enter priority:");
       scanf("%d",&priority[i]);
       Processno[i]=i+1;
   }
   for(i=0;i<Noofprocess;i++) //complexity=n
   {
       flag=i;
       for(j=i+1;j<Noofprocess;j++) //complexity=n
       {
           if(priority[j]<priority[flag])
           flag=j;
       }
       temp=priority[i];
       priority[i]=priority[flag];
       priority[flag]=temp;
       temp=BURSTTIME[i];
       BURSTTIME[i]=BURSTTIME[flag];
       BURSTTIME[flag]=temp;
       temp=Processno[i];
       Processno[i]=Processno[flag];
       Processno[flag]=temp;
   }
   WEIGHTINGTIME[0]=0;  
   for(i=1;i<Noofprocess;i++)  //complexity=n
   {
       WEIGHTINGTIME[i]=0;
       for(j=0;j<i;j++) //complexity=n
           WEIGHTINGTIME[i]+=BURSTTIME[j];
       tot+=WEIGHTINGTIME[i];
   }
   Avg_WEIGHTINGTIME=tot/Noofprocess;  
   tot=0;
   printf("========================================================================");
;
   printf("\nProcess\t       Burst Time              Waiting Time              T A T");
   for(i=0;i<Noofprocess;i++)//complexity=n
   {
       TURNAROUNDTIME[i]=BURSTTIME[i]+WEIGHTINGTIME[i];  
       tot+=TURNAROUNDTIME[i];
       printf("\nProcess %d \t %d\t\t \t   %d\t\t\t   %d",Processno[i],BURSTTIME[i],WEIGHTINGTIME[i],TURNAROUNDTIME[i]);
   }
   printf("\n========================================================================");
   Avg_TURNAROUNDTIME=tot/Noofprocess;  
   printf("\n\nAvgerage Waiting Time is: %d",Avg_WEIGHTINGTIME);
   printf("\nAverage TurnAroundTime is: %d",Avg_TURNAROUNDTIME);
   return 0;
}
