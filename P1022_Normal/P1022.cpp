#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
    string a;
    cin >> a;
    int i = 0, k = 1;
    int num = 0, un_known = 0, m = 0;
    char u;

    while (a[i] != '=')
    {
        if ('0' <= a[i] && a[i] <= '9')
            m = m * 10 + a[i] - '0';
        else if('a' <= a[i] && a[i] <= 'z')
        {
            if ((m == 0 && a[i - 1] != '0') || i == 0)
                m = 1;
            un_known += m * k;
            m = 0;
            u = a[i];
        }
        else 
        {
            num += m * k;
            m = 0;
            if (a[i] == '-')
                k = -1;
            else if (a[i] == '+')
                k = 1;
        }
        i++;
    }
    num += m * k;
    k = -1;
    m = 0;
    i++;
    while (i < a.length())
    {
        if ('0' <= a[i] && a[i] <= '9')
            m = m * 10 + a[i] - '0';
        else if('a' <= a[i] && a[i] <= 'z')
        {
            if (m == 0 && a[i - 1] != 0)
                m = 1;
            un_known += m * k;
            m = 0;
            u = a[i];
        }
        else 
        {
            num += m * k;
            m = 0;
            if (a[i] == '-')
                k = 1;
            else if (a[i] == '+')
                k = -1;
        }
        i++;
    }
    num += m * k;
    float ans = -(float)num / (float)un_known;
    ans = ans == -0.0 ? 0 : ans;
    printf("%c=%0.3f", u, ans);
    return 0;
}