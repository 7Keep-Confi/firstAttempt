#include <stdio.h>
#include <stdlib.h>

int Judgesort(int a[], int b[], int len)
{
    int i, pos, flag = 0;
    for(i = 2; i <= len; i++)
    {
        if(b[i - 1] <= b[i]) flag = 1;
        if(b[i - 1] > b[i])
        {
            pos = i;
            break;
        }
    }
    if(flag)
    {
        for(i = pos; i <= len; i++)
        {
            if(a[i] != b[i])
            {
                pos = 0;
                break;
            }
        }
    }
    else pos = 0;
    return pos; //pos 为0说明是堆排序，不为0 则为插入排序
}

void InsertSort(int a[], int pos, int len)
{ //进行下一趟插入排序
    int i, locate, temp;// locate为插入位置
    temp = a[pos];
    for(i = 1; i < pos; i++)
    {
        if(a[i] > a[pos] )
        { //找到插入位置
            locate = i;
            break;
        }
    }
    for(i = pos - 1; i >= locate; i--)
    {// i应该从待插入关键字的前一个单元开始
        a[i + 1] = a[i];
    }
    a[locate] = temp;
}

void HeapAdjust(int a[], int s, int m)
{ //筛选算法即自上而下调整成大顶堆
    int i;
    a[0] = a[s];
    for(i = 2 * s; i <= m; i *= 2)
    {
        if(i < m && a[i] < a[i + 1]) i++;
        if(a[0] >= a[i]) break;//这里要用a[0] 而不是a[s]!!
        else
        {
            a[s] = a[i];
            s = i;
        }

    }
    a[s] = a[0];
}

void HeapSort(int a[], int len)
{
    int i, loc, temp;
    for(i = 2; i <= len; i++)
    {
        if(a[i] > a[1])
        {
            loc = i - 1;
            break;
        }
    }
    temp = a[1];
    a[1] = a[loc];
    a[loc] = temp;
    HeapAdjust(a, 1, loc - 1);
}

int main()
{
    int n, i, target;
    scanf("%d", &n);
    // unsort数组表示初始序列，sorted数组表示中间序列
    int unsort[105] = {0}, sorted[105] = {0};
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &unsort[i]);
    }
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &sorted[i]);
    }
    target = Judgesort(unsort, sorted, n);
    if(target)
    {
        printf("Insertion Sort\n");
        InsertSort(sorted, target, n);
    }
    else
    {
        printf("Heap Sort\n");
        HeapSort(sorted, n);
    }

    for(int i = 1; i <= n; i++)
    {
        if(i != 1) printf(" ");
        printf("%d", sorted[i]);
    }

    return 0;
}
