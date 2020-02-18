#include<stdio.h>
#include<conio.h>

#define size 5
#define quanta 3
typedef struct task
{
    int at,bt,ct,tat,wt,pas,sno;
}task;

int main()
{
    task prg[size];
    int btarr[size];
    task tmp;
    int i,j,time=0,ti,count=0;
    float atat=0,awt=0;
    int bo=0;
    clrscr();
    printf("Quanta:%d\n ",quanta);
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
    printf("GANTT CHAT: ");
    while(count<size)
    {
		if(time%quanta==0 || bo==1)
		{
			bo=0;
			for(i=0;i<size;i++)
			{
				if(time>=prg[i].at && prg[i].pas==0 && i!=ti)
					ti=i;
			}
		}
		time++;
		btarr[ti]--;
		printf("%d",prg[ti].sno);
		if(btarr[ti]==0)
		{
			bo=1;
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
    atat=atat/size;
    awt=awt/size;
    printf("Average TAT = %f\n",atat);
    printf("Average WT =%f",awt);

    printf("\n");
    getch();
    return 0;

}