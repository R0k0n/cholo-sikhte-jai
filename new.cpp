
#include<bits/stdc++.h>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define pi acos(-1)
#define pb push_back
#define pll pair <ll, ll>
#define pii <pair<ll , ll>
#define mp make_pair
#define sl1(t) scanf("%lld" , &t)
#define si1(t) scanf("%d" , &t)
#define sl3(t , u , v) scanf("%lld %lld %lld" , &t , &u , &v)
#define si3(t , u , v) scanf("%d %d %d" , &t , &u , &v)
#define sl2(t , u) scanf("%lld %lld" , &t , &u)
#define si2(t , u) scanf("%d %d" , &t , &u)
#define el printf("\n")
#define sp printf(" ")
#define pi1(t) printf("%d " ,t)
#define pl1(t) printf("%lld\n" , t)
#define pc(x) printf("Case %lld: " , x)
#define valid(x , y , i , j) (i >= 0 && i < x && j >= 0 && j < y)
#define MOD 1000000007
#define setbit(x, k) (x | ((long long)1 << k))
#define clearbit(x, k) (x & ~((long long)1 << k))
#define checkbit(x, k) (x & ((long long)1 << k))

ll ax[2] = {0 , 1};
ll ay[2] = {1 , 0};


bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

vector<ll>v[200005];
vector<ll>vis(200005);
vector<ll>pr(200005);
vector<ll>sz(200005);

void dfs(ll node , ll per)
{
    sz[node] = 1;
    for(ll u : v[node]){
        if(u == per)continue;
        dfs(u , node);
        sz[node] += sz[u];
        pr[node] += (pr[u]);
    }
    pr[node] += sz[node];
}
ll mx = 0;
void update(ll u, ll p){
    mx = max(mx, pr[u]);cout << pr[u] << " " << u << endl;

    for(ll c: v[u]){
        if(c==p) continue;

        ll a = sz[u];
        ll b = pr[u];
        ll C = sz[c];
        ll d = pr[c];

        sz[u] -= sz[c];

        pr[u] -= pr[c];
        pr[u] -= sz[c];
        pr[c] += pr[u];
        pr[c] += sz[u];


        sz[c] += sz[u];


        update(c, u);

        sz[u] = a;
        sz[c] = C;
        pr[u] = b;
        pr[c] = d;
    }
}


int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///*
    #ifndef ONLINE_JUDGE
    freopen("input.cpp", "r" , stdin);
    //freopen("output.txt" , "w" , stdout);
    #endif // ONLINE_JUDGE
    //*/
    ll t;t = 1;
    for(ll te = 1 ; te <= t ; te++){
        ll n;cin >> n;
        for(ll i = 0 ; i < n-1 ; i++){
            ll a , b;cin >> a >> b;
            v[a].pb(b);
            v[b].pb(a);
        }
        dfs(1 , 0);

        update(1 , 0);

        cout << mx << endl;

    }































































    return 0;
}

