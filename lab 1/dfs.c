//dfs tp

#include <stdio.h>
#include <stdlib.h>

//Global Varibles

int res[20];
int s[20];
int j=0;

void dfs(int u,int n,int cost[20][20])
{
    int v;
    // visit the vertex u
    s[u]=1;

    for(v=0;v<n;v++)
    {
        if(cost[u][v]==1 && s[v]==0)
        {
            dfs(v,n,cost);
        }
    }
    res[j++]=u;

}
void dfs_TP(int n,int a[20][20])
{
    int i;

    for(i=0;i<n;i++)
        s[i]=0;
    j=0;
    for(i=0;i<n;i++)
    {
        if (s[i]==0)
            dfs(i,n,a);
    }
}

void main()
{
        int i,j,k,m,n,cost[20][20];

        printf("Enter the no of nodes:");
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cost[i][j]=0;
            }
        }

        printf("Enter the no of edges:\n");
        scanf("%d",&m);
        for(k=0;k<m;k++)
        {
            printf("Enter the edge i,j:\n");
            scanf("%d%d",&i,&j);
            cost[i][j]=1;
        }
        dfs_TP(n,cost);

        printf("The Topological sequence: ");
        for(i=n-1;i>=0;i--)
            printf("%d",res[i]);

        printf("\n");

}
