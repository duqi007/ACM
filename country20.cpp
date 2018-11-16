#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
#define MAX 100000+2
vector<int> v[MAX];
int ans[MAX];
void f(int s)
{
    for(int i=0; i<v[s].size(); i++)
    {
        if(ans[v[s][i]])
            continue;
        ans[v[s][i]]=s;
        f(v[s][i]);
    }
}
int main()
{
    int m;
    cin >> m;
    while(m--)
    {
        memset(ans,0,sizeof(ans));
        memset(v,0,sizeof(v));
        int n, s;
        int a, b;
        cin >> n >> s;
        ans[s]=-1;
        for(int i=1; i<n; i++)
        {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        f(s);
        for(int i=1; i<n+1; i++)
        {
            cout << ans[i] << " ";
        }
        cout<<endl;
    }
    return 0;
}

