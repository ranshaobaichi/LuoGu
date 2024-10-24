#include<iostream>
#include<string>
using namespace std;

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