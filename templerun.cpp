#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int a[n];
    cin>>a[0];
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    int t,k;
    cin>>t;
    while(t--)
    {
        cin>>k;
        if(a[n-1]<k)
        {
            cout<<-1<<"\n";
            continue;
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]>=k)
            {
                cout<<i+1<<"\n";
                break;
            }
        }
    }
    return 0;
}
