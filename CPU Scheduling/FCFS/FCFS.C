#include<stdio.h>
#include<conio.h>

typedef struct task
{
	int at,bt,ct,tat,wt,sno;
}task;

int main()
{
	task prg[100];
	task tmp;
	int i,j,n;
	float atat=0,awt=0;
	clrscr();
	printf("Enter no of jobs: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter Arrival Time of %d programe: ",i);
		scanf("%d",&prg[i].at);
		printf("Enter Bust Time of %d programe: ",i);
		scanf("%d",&prg[i].bt);
		prg[i].sno=i+1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(prg[j].at>prg[j+1].at)
			{
				tmp=prg[j];
				prg[j]=prg[j+1];
				prg[j+1]=tmp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
			prg[i].ct=prg[i].bt+prg[i].at;
		else
		{
			if(prg[i].at>prg[i-1].ct)
			{
				int k=prg[i].at-prg[i-1].ct;
				prg[i].ct=prg[i].bt+prg[i-1].ct+k;
			}
			else
				prg[i].ct=prg[i].bt+prg[i-1].ct;

		}
		prg[i].tat=prg[i].ct-prg[i].at;
		prg[i].wt=prg[i].tat-prg[i].bt;
	}
	printf("S.NO\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",prg[i].sno);
		printf("%d\t",prg[i].at);
		printf("%d\t",prg[i].bt);
		printf("%d\t",prg[i].ct);
		printf("%d\t",prg[i].tat);
		printf("%d\n",prg[i].wt);
		atat=prg[i].tat+atat;
		awt=prg[i].wt+awt;
	}
	atat=atat/4;
	awt=awt/4;
	printf("Average TAT=%f \n",atat);
	printf("Average WT=%f ",awt);

	getch();


	return 0;
}