#include<iostream> 
#include<algorithm>

using namespace std;

const int N = 100010;

int h[N], mySize;

int n, m;

void down(int u)
{
    int t = u;
    if (2 * u <= mySize && h[t] > h[2 * u])
        t = 2 * u;
    if (2 * u + 1 <= mySize && h[t] > h[2 * u + 1])
        t = 2 * u + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}

int main()
{
    cin >> n >> m;
    mySize = n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    for (int i = n / 2; i; i--)
        down(i);

    while (m--)
    {
        cout << h[1] << " ";
        h[1] = h[mySize--];
        down(1);
    }

    return 0;
}