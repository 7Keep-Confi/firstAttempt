#include <algorithm>
#include <iostream>

using namespace std;

struct Info
{ //用结构体Info存储考生信息
    int id;// 准考证号
    int d;// 德分
    int c;// 才分
};

struct Info grape[4][100005];// 结构体二维数组存储每个类德考生信息

bool cmp(struct Info m, struct Info n)
{
    int mNum, nNum;
    mNum = m.d + m.c;
    nNum = n.d + n.c;
    if(mNum == nNum)
    {
        if(m.d == n.d)
        {
            return (m.id < n.id);
        }
        else
        {
            return(m.d > n.d);
        }
    }
    else
    {
        return (mNum > nNum);
    }

}

int main()
{
    int n, l, h;
    int sum[4] = {0};
    cin >> n >> l >> h;
    for(int i = 0; i < n; i++)
    {// 原始数据德存储
        struct Info temp;
        cin >> temp.id >> temp.d >> temp.c;
        if(temp.d >= h && temp.c >= h) 
            grape[0][sum[0]++] = temp;
        else if(temp.d >= h && temp.c >= l)
            grape[1][sum[1]++] = temp;
        else if(temp.d >=l && temp.c >= l && temp.d >= temp.c)//注意这里是temp.d >= temp.c而不是只有>
            grape[2][sum[2]++] = temp;
        else if(temp.d >=l && temp.c >= l)
            grape[3][sum[3]++] = temp;
    }
    cout << sum[0] + sum[1] + sum[2] + sum[3] << endl;
    for(int i = 0; i < 4; i++)
    {
        sort(grape[i], grape[i] + sum[i], cmp);
        for(int j = 0; j < sum[i]; j++)
        cout << grape[i][j].id << " " << grape[i][j].d << " " << grape[i][j].c << endl;
    }
    return 0;
}