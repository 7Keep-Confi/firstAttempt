#include <stdio.h>

int indegree[105], work[105], dis[105][105];
int n, times ,count = 0;

int max(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

void Initdis()
{//初始化各任务间的工作时长
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            dis[i][j] = -1;
        }
    }
}

void TopologicalSort()
{
    while(1)
    {
        int flag = 0;
        int i, j;
        for(i = 0; i < n; i++)
        {
            if(!indegree[i]) //当前结点入度为0
            {
                indegree[i]--;
                count++;
                flag = 1;
                for(j = 0; j < n; j++)
                {
                    if(dis[i][j] != -1)
                    {    
                        indegree[j]--;
                        work[j] = max(work[j], work[i] + dis[i][j]);
                        times = max(times, work[j]);
                    }
                }
            }
        }
        if(!flag) break;
    }
    if(count == n) printf("%d\n", times);
    else printf("Impossible\n");
}

int main()
{
    int m;
    int x, y, t;
    scanf("%d %d", &n, &m);
    Initdis();
    while(m--)
    {//输入数据
        scanf("%d %d %d", &x, &y, &t);
        dis[x][y] = t;
        indegree[y]++;//同步更新结点入度
    }
    TopologicalSort();
    return 0;
}