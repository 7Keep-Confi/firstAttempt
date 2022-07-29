#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

string str;
bool visited[1005] = {false};
map<string, int> mp;

int judge(int sum, int p)
{
    if(mp.count(str))
    {
        return sum;
    }
    if(!visited[sum])
    {
        visited[sum] = true;
        mp[str] = sum;
        return sum;
    }
    else if(visited[sum] && mp[str] == 0)
    {
        int k = 1, temp = sum;
        while(visited[sum])
        {
            sum = (temp + k * k) % p;
            if(!visited[sum]) break;
            sum = (temp - k * k + p) % p;
            ++k;
        }
        visited[sum] = true;
        mp[str] = sum;
        return sum;
    }
}

int main()
{
    int n, p;//n为关键字个数，p为散列表长度
    int sum = 0,flag = 0;//sum用来计算关键字的地址
    cin >> n >> p;
    while(n--)
    {
        cin >> str;//输入字符串
        int k = 0, num[3] = {0};
        int len = str.size();
        if(len > 3)
        {
            for(int j = len - 3; j < len; j++)
            {
                int temp = str[j] - 'A';
                num[k++] = temp;
            }
            
        }
        else
        {
            for(int j = 0; j < len; j++)
            {
                int temp = str[j] - 'A';
                num[j] = temp;
            }
        }
        sum = num[0] * 32 * 32 + num[1] * 32 + num[2];
        sum %= p;//此时表示经过除留余数法得到的地址
        if(!flag)
        {
            cout << judge(sum, p);
            flag = 1;
        }
        else
        {
            cout << " " << judge(sum, p);
        }
    }
    return 0;
}