#include<stdio.h>

typedef struct task
{
	int at,bt,ct,tat,wt,pas,pr,sno;
}task;

int main()
{
	task prg[100];
	task tmp;
	int i,j,time=0,pri=-1,ti,count=0,n;
	float atat=0,awt=0,x;
	printf("Enter no of jobs: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter Arrival Time of %d programe: ",i);
		scanf("%d",&prg[i].at);
		printf("Enter Bust Time of %d programe: ",i);
		scanf("%d",&prg[i].bt);
        printf("Enter Priority of %d programme: ",i);
        scanf("%d",&prg[i].pr);
		prg[i].pas=0;
		prg[i].sno=i+1;
	}
    printf("S.NO\tAT\tBT\tPR\tCT\tTAT\tWT\n");
	while(count<n)
	{
		pri=-1;
		for(i=0;i<n;i++)
		{
			if(prg[i].at<=time && prg[i].pas==0)
			{
				if(pri<prg[i].pr)
				{
					pri=prg[i].pr;
					ti=i;
				}

			}
		}
		prg[ti].pas=1;
		time=time+prg[ti].bt;
        prg[ti].ct=time;
        prg[ti].tat=time-prg[ti].at;
        prg[ti].wt=prg[ti].tat-prg[ti].bt;
        printf("%d\t",prg[ti].sno);
		printf("%d\t",prg[ti].at);
		printf("%d\t",prg[ti].bt);
        printf("%d\t",prg[ti].pr);
		printf("%d\t",prg[ti].ct);
		printf("%d\t",prg[ti].tat);
		printf("%d\n",prg[ti].wt);
        atat=prg[ti].tat+atat;
		awt=prg[ti].wt+awt;
		count++;
	}
	atat=atat/4;
	awt=awt/4;
	printf("Average TAT=%f\n",atat);
	printf("Average WT=%f",awt);



	return 0;
}