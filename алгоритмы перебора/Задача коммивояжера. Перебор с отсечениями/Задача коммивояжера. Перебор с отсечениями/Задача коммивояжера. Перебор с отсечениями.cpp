#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int** a;            //Массив расстояний    
int* mas;        // Храним Перестановку
bool* used;        //Использование числа
int ans = 100000;//длина пути

int n;
void out()
{
    cout << ans << " :";

    for (int i = 0; i < n; i++)
    {
        cout << mas[i] << " ";
    }
    cout << endl;

}
int min(int a, int b)
{
    if (a < b)return a;
    return b;

}

void rec(int idx, int len)
{

    if (len >= ans) return;

    if (idx == n)//Если заполнили K числа то выходим
    {
        ans = min(ans, len + a[mas[idx - 1]][0]);//добавить длину от посленего города в перестановке до нулевого
        out();//вывод

        return;
    }

    for (int i = 1; i <= n - 1; i++)
    {

        if (used[i]) continue;//Если число занято то следущая итерация цикла

        mas[idx] = i;

        used[i] = true;
        rec(idx + 1, len + a[mas[idx - 1]][i]);//к расстоянию прибаили расстояние от последнего города в перестановке до текущего города i
        used[i] = false;
    }
}

int main()
{


    cin >> n;


    mas = new int[n];

    a = new int* [n];

    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];

    }

    used = new bool[n];//Храним занятые числа(номера)

    for (int i = 0; i < n; i++)
    {
        used[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        mas[i] = 0;

    }

    for (int i = 0; i < n; i++)//Заполняем длинами дорог
    {

        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];

        }
    }

    rec(1, 0);//начинаем с нулевого города (0)-фиксирован остальные значения пробуем
    system("pause");
}