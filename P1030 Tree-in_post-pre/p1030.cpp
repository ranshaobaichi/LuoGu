#include<iostream>
#include<string>
using namespace std;

string In_Post2Pre(string In,string Post){
    if (In.empty() || Post.empty())
        return "";
    char c = Post.back();
    int pos = In.find(c);

    if (In.size() == 1)
        return In;
    else
        return c + In_Post2Pre(In.substr(0, pos), Post.substr(0, pos)) +
               In_Post2Pre(In.substr(pos + 1), Post.substr(pos, Post.size() - 1 - pos));
}

int main(){
    string I, P;
    cin >> I >> P;
    cout << In_Post2Pre(I, P);
    return 0;
}