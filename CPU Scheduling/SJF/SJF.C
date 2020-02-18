#include<stdio.h>
#include<conio.h>

typedef struct task
{
	int at,bt,ct,tat,wt,pas,sno;
}task;

int main()
{
	task prg[100],sprg[100];
	task tmp;
	int i,j,time=0,btmp=100,ti,count=0,n;
	float atat=0,awt=0,x;
	clrscr();
	printf("Enter no of jobs: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter Arrival Time of %d programe: ",i);
		scanf("%d",&prg[i].at);
		printf("Enter Bust Time of %d programe: ",i);
		scanf("%d",&prg[i].bt);
		prg[i].pas=0;
		prg[i].sno=i+1;
	}
	while(count<n)
	{
		btmp=100;
		for(i=0;i<n;i++)
		{
			if(prg[i].at<=time && prg[i].pas==0)
			{
				if(btmp>prg[i].bt)
				{
					btmp=prg[i].bt;
					ti=i;
				}

			}
		}
		prg[ti].pas=1;
		time=time+btmp;
		sprg[count]=prg[ti];
		count++;
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
			sprg[i].ct=sprg[i].bt+sprg[i].at;
		else
			if(sprg[i].at>sprg[i-1].ct)
				sprg[i].ct=sprg[i].bt+sprg[i-1].ct+sprg[i].at-sprg[i-1].ct;
			else
				sprg[i].ct=sprg[i].bt+sprg[i-1].ct;
		sprg[i].tat=sprg[i].ct-sprg[i].at;
		sprg[i].wt=sprg[i].tat-sprg[i].bt;
	}
	printf("S.NO\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",sprg[i].sno);
		printf("%d\t",sprg[i].at);
		printf("%d\t",sprg[i].bt);
		printf("%d\t",sprg[i].ct);
		printf("%d\t",sprg[i].tat);
		printf("%d\n",sprg[i].wt);
		atat=sprg[i].tat+atat;
		awt=sprg[i].wt+awt;
	}
	atat=atat/4;
	awt=awt/4;
	printf("Average TAT=%f\n",atat);
	printf("Average WT=%f",awt);

	getch();


	return 0;
}