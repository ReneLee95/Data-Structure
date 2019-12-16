#include <stdio.h>

int n;
int map[30][30], visit[30];

void DFS(int v)
{
	int i;
	
	visit[v] = 1;
	for(int i =1; i<=n; i++)
	{
		if(map[v][i] == 1 &&!visit[i])
		{
			printf("%d에서 %d로 이동\n",v,i);
			
			DFS(i);
		}
	}
}

int main(void)
{
	int start;
	int v1,v2;
	
	scanf("%d %d",&n, &start);
	
	while(1)
	{
		scanf("%d %d",&v1,&v2);
		if(v1 == -1 && v2 == -1)
		{
			break;
		}
		
		map[v1][v2] = map[v2][v1] = 1;
	}
	
	DFS(start);
	
	return 0;
}
