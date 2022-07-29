#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Student
{
    string id;//考号
    int grade;// 得分
    int curRank;//当前考点的排名
    int allRank;//最终排名
    int testsite;//考点
};

bool cmp(Student p, Student q)
{
    if(p.grade != q.grade)
        return (p.grade > q.grade);
    else
        return (p.id < q.id);
}

int main()
{
    struct Student table[30005];//创建结构体数组
    int n, m;//n表示考点个数，m用来暂存每个考点的考生数
    int sum = 0;//计算考生总数
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> m;
        for(int j = sum; j < sum + m; j++)
        {
            cin >> table[j].id >> table[j].grade;//输入考生基本信息
            table[j].testsite = i + 1;//指定考场
        }
        // 每个考场的考生信息输入完毕后，进行考点内部排序
        sort(table + sum, table + sum + m, cmp);
        int rank = 1;//用于计算当前考点各考生的排名
        table[sum].curRank = rank;//先处理第一名，之后用一个循环处理剩余考生
        for(int k = sum + 1; k < sum + m; k++)
        {//如果进入if语句，则再一次循环时rank和k应同步更新才符合题目要求的排名
            rank++;//先令排名加1
            if(table[k].grade == table[k - 1].grade)
            {//当前考生成绩与前一个相等时，将前面考生排名直接赋给当前考生
                table[k].curRank = table[k - 1].curRank;
            }
            else 
                table[k].curRank = rank;
        }
        sum += m;//处理完一个考点就更新考生总数
    }
    int rank = 1;//用于同步所有考生范围内的排名
    sort(table, table + sum, cmp);//将所有考生进行排序
    table[0].allRank = rank;
    for(int i = 1; i < sum; i++)
    {
        rank++;
        if(table[i].grade == table[i - 1].grade)
            table[i].allRank = table[i - 1].allRank;
        else 
            table[i].allRank = rank;
    }
    
    cout << sum << endl;

    for(int i = 0; i < sum; i++)
    {
        cout << table[i].id << " " ;
        cout << table[i].allRank << " " ;
        cout << table[i].testsite << " " ;
        cout << table[i].curRank << endl;
    }

    return 0;
}