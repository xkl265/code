#include<bits/stdc++.h>
using namespace std;
int lowbit(int i){
        return (i&-i);
}
int main()
{
    int x;

    cin>>x;
    x=-x;
    char s[10];
    cout<<lowbit(x);
    return 0;
}
