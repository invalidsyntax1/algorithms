//Вывести все последовательности длины n, состоящие из чисел от 1 до m, в которых каждое число встречается ровно один раз
using namespace std;
#include <iostream>
#include <vector>
vector<int> a;
vector<bool> used;
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
        if (used[i]) { continue; }

        a[idx] = i;
        used[i] = true;
        rec(idx + 1);
        used[i] = false;
    }
}

int main()
{
    cin >> n >> m;
    a = vector<int>(n);
    used = vector<bool>(n + 1, false);
    rec(0);
    return 0;
}
