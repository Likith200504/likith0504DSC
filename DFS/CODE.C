#include<stdio.h>
#include<conio.h>
int i,j,n,a[10][10],vis[10];
void dfs(int v)
{
    vis[v]=1;
    printf("%d ",v);
    for(j=1;j<=n;j++)
    {
        if(a[v][j]==1&&vis[j]==0)
        {
            dfs(j);
        }
    }
}
void main()
{
    printf("Enter the no of vertices:");
    scanf("%d",&n);
    printf("Enter the adjacency matrix");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
        vis[i]=0;
    }
    printf("dfs traversal");
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
            dfs(i);
    }
    getch();
}
