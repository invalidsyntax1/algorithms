// lданный алгоритм перебирает строчку так, что каждый элемент в этой строке повторяется только 1 раз, например, при вводе числа 2017, ответ будет следующим:
/*2107
2170
2701
2710
0217
0271
0127
0172
0721
0712
1207
1270
1027
1072
1720
1702
7201
7210
7021
7012
7120
7102*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
string str;
vector<string> a;
vector <bool> used;

void out(int len_str)
{
    for (int i = 0; i < len_str; i++)
    {

        cout << a[i];
    }
    cout << endl;
}

void rec(int idx, int len_str)
{
    if (idx == len_str)
    {
        out(len_str);
        return;
    }
    for (int i = 0; i < len_str; i++)
    {
        if (used[i]) { continue; }
        a[idx] = str[i];
        used[i] = true;
        rec(idx + 1, len_str);
        used[i] = false;
    }
}

int main()
{

    cin >> str;
    int len_str = str.length();


    a = vector<string>(len_str);
    used = vector<bool>(len_str, false);
    rec(0, len_str);

    return 0;
}

