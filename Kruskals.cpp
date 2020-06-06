#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
long long int i,j,k,a,b,u,v,n,ne=1;
long long int min,mincost=0,cost[100][100],parent[100];
long long int find(long long int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
long long int uni(long long int i,long long int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
int main()
{
	printf("Implementation of Kruskal's algorithm\n");
	printf("Enter the no of vertices:");
	scanf("%lld",&n);
	printf("Enter the cost adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&cost[i][j]);
			if(cost[i][j]==0)
			cost[i][j]=999;
		}
	}
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d edge (%lld,%lld): %lld\n",ne++,a,b,min);
			mincost+=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("Minimum cost: %lld",mincost);
}