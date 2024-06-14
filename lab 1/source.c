#include <stdio.h>
#include <stdlib.h>


void find_indegree(int n,int a[][10],int indegree[])
{

    int i,j,sum;
    for(j=0;j<n;j++)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            sum=sum+a[i][j];
        }
        indegree[j]=sum;
    }

}
void topo_sr(int n,int a[][10])
{

    int i,k,u,v,top,t[10],indegree[10],s[10];
    find_indegree(n,a,indegree);

    top=-1;
    k=0;

    for(i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            s[++top]=i;
        }
    }
    while(top!=-1)
    {
        u=s[top--];
        t[k++]=u;

        for(v=0;v<n;v++)
        {
            if(a[u][v]==1)
            {
                indegree[v]--;
                if(indegree[v]==0)
                {
                    s[++top]=v;
                }
            }
        }
    }

    printf("Topological order\n");
    for(i=0;i<n;i++)
        printf("%d\t",t[i]);

}

void main()
{

        int n,b[10][10];
        int i,j;

        printf("Enter the number of jobs\n");
        scanf("%d",&n);

        printf("Enter the adjancy matrix");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&b[i][j]);
            }
        }

        topo_sr(n,b);
}
