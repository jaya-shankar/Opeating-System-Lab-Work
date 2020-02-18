#include<stdio.h>
#include<conio.h>

#define size 5
typedef struct task
{
    int at,bt,ct,tat,wt,pas,sno;
}task;

int main()
{
    task prg[size];
    int btarr[size];
    task tmp;
    int i,j,time=0,btmp=100,ti,count=0;
    float atat=0,awt=0;
    clrscr();
    for(i=0;i<size;i++)
    {
		printf("Enter AT of %d prg: ",i+1);
		scanf("%d",&prg[i].at);
		printf("Enter BT of %d prg: ",i+1);
		scanf("%d",&prg[i].bt);
		btarr[i]=prg[i].bt;
		prg[i].pas=0;
		prg[i].sno=i+1;
    }
    while(count<size)
    {
		btmp=100;
		for(i=0;i<size;i++)
		{
			if(prg[i].at<=time && prg[i].pas==0)
			{
				if(btmp>btarr[i])
				{
					btmp=btarr[i];
					ti=i;
				}
			}
		}
		time++;
		btarr[ti]--;
		printf("%d",prg[ti].sno);
		if(btarr[ti]==0)
		{
			prg[ti].pas=1;
			prg[ti].ct=time;
			prg[ti].tat=prg[ti].ct-prg[ti].at;
			prg[ti].wt=prg[ti].tat - prg[ti].bt;
			count++;
		}
    }
    printf("\n");
    printf("sno\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<size;i++)
    {
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",prg[i].sno,prg[i].at,prg[i].bt,prg[i].ct,prg[i].tat,prg[i].wt);
		atat=prg[i].tat+atat;
		awt=prg[i].wt+awt;
    }
    printf("Average TAT = %f\n",(atat/size));
    printf("Average WT =%f",(awt/size));

    printf("\n");
    getch();
    return 0;
}