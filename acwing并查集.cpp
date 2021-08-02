#include <iostream>
using namespace std;

const int N=10e5+10;

int p[N];
int n,m;

int find(int x)//路径优化和返回祖宗节点
{
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}

int main()
{
    cin>>n>>m;
    char op[2];
    int a,b;
    for(int i=1;i<=n;i++)p[i]=i;
    
    while(m--)
    {
        int a,b;
        cin>>op>>a>>b;
        if(op[0]=='M')
        {
            p[find(a)]=find(b);
        }
        else 
        {
            if(find(a)==find(b))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}