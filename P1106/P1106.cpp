#include<iostream>
#include<string>
using namespace std;

// int main(){
//     string num;
//     cin >> num;
//     int k, n = num.length();
//     cin >> k;
//     char first = num[0], last;
//     string mid = num.substr(1, n - k - 1);
//     for (int i = n - k; i < n; i++)
//     {
//         last = num[i];
//         if(mid[n-k-2]>last)
//             mid[n - k - 2] = last;
//         else if (first + mid > mid + last)
//         {
//             first = mid[0];
//             mid = mid.erase(0) + last;
//         }
//     }
//     cout << first + mid;
//     return 0;
// }

int del(string& num){
    for (int i = 0; i < num.length() - 1; i++)
    {
        if (num[i] > num[i + 1])
            return i;
    }
    return num.length() - 1;
}

int main(){
    string num;
    cin >> num;
    int k, i = 0;
    cin >> k;

    while (k > 0)
    {
        if (num[i] > num[i + 1])
        {
            num.erase(i, 1);
            k--;
            i = i - 2;
        }
        i++;
    }

    while (num[0] == '0' && num.length() > 1)
        num.erase(0, 1);
    cout << num;
    return 0;
}