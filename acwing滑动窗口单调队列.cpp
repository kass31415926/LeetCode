#include <iostream>
using namespace std;

const int N=1000010;

int a[N],q[N];

int n,k;

int main()
{
    cin>>n>>k;

    for(int i=0;i<n;i++)cin>>a[i];

    int hh=0,tt=-1;

    for(int i=0;i<n;i++)
    {
        if(hh<=tt&&i+1-k>q[hh])hh++;
        while(hh<=tt&&a[q[tt]]>=a[i])tt--;
        q[++tt]=i;
        if(i>=k-1)cout<<a[q[hh]]<<" ";
    }
    cout<<endl;

    hh=0,tt=-1;
    for(int i=0;i<n;i++)
    {
        if(hh<=tt&&i+1-k>q[hh])hh++;
        while(hh<=tt&& a[q[tt]]<=a[i])tt--;
        q[++tt]=i;
        if(i>=k-1)cout<<a[q[hh]]<<" ";
    }
    cout<<endl;
    return 0;
}

作者：你仲要K
链接：https://www.acwing.com/activity/content/code/content/1539809/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。