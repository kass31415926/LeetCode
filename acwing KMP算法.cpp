#include <iostream>
#include <string>
using namespace std;

const int N=10e6+10;

int queue[N];

int main()
{
    int hh=0,tt=-1;
    int m,k;
    cin>>m;
    while(m--)
    {
        string op;
        cin>>op;
        if(op=="push")
        {
            cin>>k;
            queue[++tt]=k;
        }
        else if(op=="pop")
        {
            hh++;
        }
        else if(op=="empty")
        {
            if(tt>=hh)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        else 
        {
            cout<<queue[hh]<<endl;
        }
    }
    return 0;
}

作者：你仲要K
链接：https://www.acwing.com/activity/content/code/content/1540462/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。