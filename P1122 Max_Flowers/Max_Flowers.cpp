#include<iostream>
#include<vector>
using namespace std;

struct flower{
    int val;
    vector<flower *> connect;
    flower(int v) : val(v){ }
};

class Solution{
public:
    Solution(int n);
    flower *head = nullptr;
    int Max_(flower *caller, int index);

private:
    int num;
    int ans = INT_MIN;
};

Solution::Solution(int n) : num(n)
{
    vector<flower *> temp(n);
    //init head
    int v;
    cin >> v;
    head = new flower(v);
    temp[0] = head;

    //init each flower
    for (int i = 1; i < n; i++)
    {
        cin >> v;
        temp[i] = new flower(v);
    }

    //connect each flower
    for (int i = 0; i < 2 * (n - 1); i++)
    {
        int F, S;
        cin >> F >> S;
        temp[F]->connect.push_back(temp[S]);
        temp[S]->connect.push_back(temp[F]);
    }
}

int Solution::Max_(flower* caller,int index){

}

int main(){
    int n;
    cin>>n;
    Solution S(n);
    cout << S.Max_(S.head, 0);
    return 0;
}