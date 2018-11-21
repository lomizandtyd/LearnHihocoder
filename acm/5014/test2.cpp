#include <iostream>
#include <cstdio>
using namespace std;
int map[]={0,1,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767,65535,131071};
int main()
{
    int n;
    int a[100001];
    int b[100001];
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        int k=0;
        while (map[k]<=n)
        {
            k++;
        }
        int right=0,left=0;
        right=n;
        while (right>=0)
        {
            while ((right^map[k])>=right && k>0)
            {
                k--;
            }
            left=right^map[k];
            for (int i=right; i>=left; i--)
            {
                b[i]=i^map[k];
            }
            k--;
            right=left-1;
        }
        long long sum=0;
        for (int i=0; i<=n; i++)
        {
            sum+=a[i]^b[a[i]];
        }
        cout<<sum<<endl;
        for (int i=0; i<n; i++)
        {
            cout<<b[a[i]]<<" ";
        }
        cout<<b[a[n]]<<endl;
    }
    return 0;
}
