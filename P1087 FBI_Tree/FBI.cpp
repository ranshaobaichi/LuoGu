#include<iostream>
#include<string>
#include<assert.h>
using namespace std;

class FBI{
public:
    FBI(string t) : text(t) { }
    int POST_ORDER_FBI(int head, int tail);

private:
    string text;
};

int FBI::POST_ORDER_FBI(int head, int tail){
    assert(head <= tail);
    int ans = text[head] == '0' ? 0 : 1;

    if (head != tail)
    {
        int left = POST_ORDER_FBI(head, (head + tail) / 2);
        int right = POST_ORDER_FBI((head + tail) / 2 + 1, tail);
        if (left != right)
            ans = -1;
        else
            ans = (left + right) / 2;
    }

    switch(ans){
        case -1:
            cout << 'F'; break;
        case 0:
            cout << 'B'; break;
        case 1:
            cout << 'I'; break;
        default:
            throw("unexpexted input");
    }

    return ans;
}

int main(){
    int a;
    cin >> a;
    string pp;
    cin >> pp;
    FBI fbi(pp);
    fbi.POST_ORDER_FBI(0, pp.length() - 1);
    return 0;
}