//Вывести все последовательности длины n, состоящие из чисел от 1 до m
using namespace std;
#include <iostream>
#include <vector>
vector<int> a;
int n, m;
void out()
{
    for (int i = 0; i < n; i++)
    {
        
        cout << a[i];
    }
    cout << endl;
}

void rec(int idx)
{
    if (idx == n)
    {
        out();
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        a[idx] = i;
        rec(idx + 1);
    }
}

int main()
{
    cin >> n >> m;
    a = vector<int>(n);
    rec(0);
    return 0;
}

