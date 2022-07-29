#include <iostream>
#include <algorithm>
#define INFINITY 10000

using namespace std;

int n;
int graph[105][105];// 存储各对结点间的权值
int gMatrix[105][105];// 通过Floyd算法得到的最短路径

void Initgraph()
{//初始化各对结点间的权值，除了对角线都赋于无穷大
    for(int i = 0; i < 105; i++)
    {
        for(int j = 0; j < 105; j++)
        {
            graph[i][j] = INFINITY;
        }
        graph[i][i] = 0;//结点到自身为0
    }
}

void InitgMatrix()
{// 初始化
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            gMatrix[i][j] = graph[i][j];
        }
    }
}

void Floyd()
{//弗洛伊德算法求最短路径
    for(int k = 0; k < n; k++) //k表示中间结点
    {
        for(int i = 0; i < n; i++)// i表示起点
        {
            for(int j = 0; j < n; j++) //j表示终点
            {
                if(gMatrix[i][j] > gMatrix[i][k] + gMatrix[k][j])
                {
                    gMatrix[i][j] = gMatrix[i][k] + gMatrix[k][j];
                }
            }
        }
    }
}

void ShortestPath_FLOYD()
{
    int maxPath;//最长魔咒长度
    int minNum = INFINITY + 1;//记录满足条件的最短路径
    int minId;//若存在多个满足条件的动物编号，输出最小那一个
    int i, j;
    for(i = 0; i < n; i++)
    {
        maxPath = 0;
        for(j = 0; j < n; j++)
        {
            if(gMatrix[i][j] > maxPath)
                maxPath = gMatrix[i][j];
        }
        if(maxPath == INFINITY)
        {//注意，如果一只动物不能变成其他所有的动物
        // 则不满足条件，所以某一趟只要存在一对结点
        // 之间没有路径即长度为无穷大，则停止。
            cout << 0 << endl;
            return;
        }
        if(maxPath < minNum)
        {
            minNum = maxPath;
            minId = i + 1;
        }
    }
    cout << minId << " " << minNum << endl;
}

int main()
{
    int m;//m表示魔咒条数
    int anim1, anim2, len;
    cin >> n >> m;
    Initgraph();
    for(int i = 0; i < m; i++) //终止条件是m不是n
    {// 输入各对结点间的权值
        cin >> anim1 >> anim2 >> len;
        graph[anim1 - 1][anim2 - 1] = len;
        graph[anim2 - 1][anim1 - 1] = len;
    }
    InitgMatrix();
    Floyd();
    ShortestPath_FLOYD();
    return 0;
}