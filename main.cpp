#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define met(a,b) memset(a,b,sizeof a)
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N = 1e6+5;
int n,m,k;
set<int>s,t;
set<int>::iterator it;
vector<int>edg[N];
int vis[N];
ll dis[N],a,b;
bool ok;
void init(){
    s.clear();t.clear();
    ok=false;
    for(int i=0;i<=n;i++){
        vis[i]=dis[i]=0;
        edg[i].clear();
    }
}
void spfa()  {
    queue<int>q;
    for(int i=0;i<N;i++)dis[i]=inf;
    dis[1]=0;
    q.push(1);
    vis[1]=1;
    while(!q.empty())  {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=0;i<edg[u].size();i++)  {
            int v=edg[u][i];
            if(dis[v]>dis[u]+1)  {
                dis[v]=dis[u]+1;
                if(!vis[v])  {
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    printf("%lld\n",min(dis[n]*a,b));
}
void bfs(){
    queue<int>q;
    for(int i=2;i<=n;i++){
        s.insert(i);
    }
    q.push(1);
    dis[1]=0;
    dis[n]=inf;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<edg[u].size();i++){
            int v=edg[u][i];
            if(!s.count(v))continue;
            s.erase(v);t.insert(v);
        }
        for(it = s.begin();it!=s.end();it++){
            q.push(*it);
            dis[*it]=dis[u]+1;
        }
        s.swap(t);
        t.clear();
    }
    printf("%lld\n",min(dis[n]*b,a));
}
int main(){
#ifdef LOCAL
    freopen("IN.txt","r",stdin);
#endif // LOCAL
   int u,v;
   while(~scanf("%d%d%lld%lld",&n,&m,&a,&b)){
    init();
    while(m--){
        scanf("%d%d",&u,&v);
        edg[u].pb(v);
        edg[v].pb(u);
        if(u>v)swap(u,v);
        if(u==1&&v==n)ok=true;
    }
    if(ok)bfs();
    else spfa();
   }
   return 0;
}
