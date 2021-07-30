#include <iostream>
using namespace std;

const int N=10e5+10;

int stk[N],tt;

int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        int x;
        cin>>x;
        
        while(tt&&stk[tt]>=x)tt--;
        if(tt)cout<<stk[tt]<<" ";
        else cout<<"-1"<<" ";
        
        stk[++tt]=x;
    }
    return 0;
}