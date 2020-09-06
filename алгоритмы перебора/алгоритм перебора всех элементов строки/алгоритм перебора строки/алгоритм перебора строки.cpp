﻿// в данном алгоритме любое значение из строки при переборе может быть повторено сколько угодно раз, например, при переборе строки "2017" будут выведены следующие результаты:
/*2222
2220
2221
2227
2202
2200
2201
2207
2212
2210
2211
2217
2272
2270
2271
2277
2022
2020
2021
2027
2002
2000
2001
2007
2012
2010
2011
2017
2072
2070
2071
2077
2122
2120
2121
2127
2102
2100
2101
2107
2112
2110
2111
2117
2172
2170
2171
2177
2722
2720
2721
2727
2702
2700
2701
2707
2712
2710
2711
2717
2772
2770
2771
2777
0222
0220
0221
0227
0202
0200
0201
0207
0212
0210
0211
0217
0272
0270
0271
0277
0022
0020
0021
0027
0002
0000
0001
0007
0012
0010
0011
0017
0072
0070
0071
0077
0122
0120
0121
0127
0102
0100
0101
0107
0112
0110
0111
0117
0172
0170
0171
0177
0722
0720
0721
0727
0702
0700
0701
0707
0712
0710
0711
0717
0772
0770
0771
0777
1222
1220
1221
1227
1202
1200
1201
1207
1212
1210
1211
1217
1272
1270
1271
1277
1022
1020
1021
1027
1002
1000
1001
1007
1012
1010
1011
1017
1072
1070
1071
1077
1122
1120
1121
1127
1102
1100
1101
1107
1112
1110
1111
1117
1172
1170
1171
1177
1722
1720
1721
1727
1702
1700
1701
1707
1712
1710
1711
1717
1772
1770
1771
1777
7222
7220
7221
7227
7202
7200
7201
7207
7212
7210
7211
7217
7272
7270
7271
7277
7022
7020
7021
7027
7002
7000
7001
7007
7012
7010
7011
7017
7072
7070
7071
7077
7122
7120
7121
7127
7102
7100
7101
7107
7112
7110
7111
7117
7172
7170
7171
7177
7722
7720
7721
7727
7702
7700
7701
7707
7712
7710
7711
7717
7772
7770
7771
7777*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
string str;
vector<string> a;

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
        a[idx] = str[i];
        rec(idx + 1, len_str);
    }
}

int main()
{

    cin >> str;
    int len_str = str.length();
    

    a = vector<string>(len_str);
    rec(0, len_str);

    return 0;
}