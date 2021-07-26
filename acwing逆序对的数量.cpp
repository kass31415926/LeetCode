#include <iostream>
using  namespace std;

const int N=1000010;

int q[N],tmp[N];

long long merge_sort(int q[],int l, int r)
{
    if(l>=r)return 0;
    
    int mid = l + r >> 1;
    long long res = merge_sort(q,l,mid)+merge_sort(q,mid+1,r);
    
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j])tmp[k++]=q[i++];
        else
        {
            tmp[k++]=q[j++];
            res+=mid-i+1;
        }
    }
    while(i<=mid)tmp[k++]=q[i++];
    while(j<=r)tmp[k++]=q[j++];
    
    for(i=l,j=0;i<=r;i++,j++)q[i]=tmp[j];
    
    return res;
    
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>q[i];
    
    long long result=merge_sort(q,0,n-1);
    
    cout<<result<<endl;
    
    return 0;
}