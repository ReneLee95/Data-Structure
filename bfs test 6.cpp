#include <queue>
#include <iostream>
#include <stdio.h>
#include <utility>

using namespace std;

int r;
int c;
bool map[100][100];
int check[100][100];

int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void init()
{
	for(int i =0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			int point;
			scanf("%1d", &point);
			
			if(point ==1)
			{
				map[i][j] = true;
			}
		}
	}
	
	for(int i =0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			printf("%d",map[i][j]);
		}
		cout<<endl;
	}
}

bool CheckMap(int a, int b)
{
	return (a>=0 && a<r) && (b >=0 && b < c);
}

int Bfs_Logic()
{
	int cur_r = 0;
	int cur_c = 0;
	
	queue<pair<int,int>> q;
	q.push(pair<int,int>(cur_r,cur_c));
	
	check[cur_r][cur_c] = 1;
	
	while(!q.empty())
	{
		cur_r = q.front().first;
		cur_c = q.front().second;
		q.pop();
		
		if(cur_r == r && cur_c == c)
		{
			break;
		}
		
		for(int i =0; i<4; i++)
		{
			int next_r = cur_r + dir[i][0];
			int next_c = cur_c + dir[i][1];
			
			if(CheckMap(next_r, next_c)&& check[next_r][next_c] == 0 && map[next_r][next_c])
			{
				check[next_r][next_c] = check[cur_r][cur_c] + 1;
				q.push(pair<int,int>(next_r,next_c));
			}
		}
	}
	return check[r-1][c-1];
}

int main(void)
{
	int result = 0;
	init();
	result = Bfs_Logic();
	cout<<result<<endl;
	return 0;
}
