#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct process{
//should contain max,allocted,need
int max[10];
int alloc[10];
int need[10];
int id;
}process;

typedef struct req{
//should contain id and resource required
int resour[10];
int id;
}req;

int main()
{
    int m,n,r,i,j;
    void bankers(req,int,int,int*,process * );
    printf("Enter of processes: ");
    scanf("%d",&n);
    printf("Enter no of resources: ");
    scanf("%d",&m);
    int* available=(int *)malloc(sizeof(int)*m);
    process *tasks=(process *)malloc(sizeof(process)*n);
    for(i=0;i<m;i++)
    {
        printf("Enter total availabe resource of %d : ",i+1);
        scanf("%d",&available[i]);
    }
    for(i=0;i<n;i++)
    {
        tasks[i].id=i+1;
        printf("Enter maximum allocation required for %d process\n",i+1);
        for(j=0;j<m;j++)
        {   
            printf("%d resource required: ",j+1);
            scanf("%d",&tasks[i].max[j]);
            printf("\n");
        }
    }
    for(i=0;i<n;i++)
    {
        printf("Enter already allocated memory for %d process\n",i+1);
        for(j=0;j<m;j++)
        {
            printf("amount %d resource allocated: ",j+1);
            scanf("%d",&tasks[i].alloc[j]);
            printf("\n");
            tasks[i].need[j]=tasks[i].max[j]-tasks[i].alloc[j];
        }
    }
    printf("Enter no of requests: ");
    scanf("%d",&r);
    req *requests=(req*)malloc(sizeof(req)*r);
    for(i=0;i<r;i++)
    {
        printf("Enter process id: ");
        scanf("%d",&requests[i].id);
        for(j=0;j<m;j++)
        {
            printf("%d resource required: ",j+1);
            scanf("%d",&requests[i].resour[j]);
        }
        printf("\n");
    }
    for(i=0;i<r;i++)
    {
        bankers(requests[i],m,n,available,tasks);
    }

    return 0;
}

void bankers(req request,int m,int n,int * available,process * tasks)
{
    int i;
    bool safetyModule(int,int,int *,process *);
    for(i=0;i<m;i++)
    {
        if(request.resour[i]<=tasks[request.id-1].need[i])
        {
            if(request.resour[i]<=available[i])
            {
                available[i]=available[i]-request.resour[i];
                tasks[request.id-1].alloc[i]=tasks[request.id-1].alloc[i]+request.resour[i];
                tasks[request.id-1].need[i]=tasks[request.id-1].need[i]-request.resour[i];
            }
            else
            {
                printf("Wait till more resource arrive");
                return;
            }
        }
        else
        {
            printf("error 'request < need'");
            return;
        }
        
    }
    bool k=safetyModule(m,n,available,tasks);
    available[i]=available[i]+request.resour[i];
    tasks[request.id-1].alloc[i]=tasks[request.id-1].alloc[i]-request.resour[i];
    tasks[request.id-1].need[i]=tasks[request.id-1].need[i]+request.resour[i];
    if(k==true)
        printf("safe\n");
    else
        printf("not safe\n");
    
}

bool safetyModule(int m,int n,int * available,process * tasks)
{
    int* work=(int* )malloc(sizeof(int)*m);
    bool* finish=(bool *)malloc(sizeof(bool)*n);
    for(int i=0;i<m;i++)
        work[i]=available[i];
    for(int i=0;i<n;i++)
        finish[i]=false;
    while(1)
    {
        int k=0;
        for(int i=0;i<n;i++)
        {
            int j;
            if(finish[i]==false)
            {
                for(j=0;j<m;j++)
                    if(tasks[i].need[j]>work[j])
                        break;
                if(j==m)
                {
                    k=1;
                    for(j=0;j<m;j++)
                        work[j]=work[j]+tasks[i].alloc[j];
                    finish[i]=true;
                }
            }
        }
        if(k==0)
            break;
    }
    for(int i=0;i<n;i++)
        if(finish[i]==false)
            return false;
    return true;
}
