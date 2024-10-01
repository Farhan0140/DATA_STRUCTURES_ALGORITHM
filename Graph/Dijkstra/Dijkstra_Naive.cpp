#include <bits/stdc++.h>
using namespace std;
 
//_______________________________________________________________________________________________

#define ll long long int
#define all(x) x.begin(),x.end()

#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

const ll INF = 1e18;
const int S = 1e5+5;

//        node, Weight [Node]
vector<pair<ll, ll>> Arr[S];
ll Dis[S];

void Dijkstra(ll src);
 
//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    ll n, e; cin >> n >> e;
    while(e--) {
        ll u, v, c; cin >> u >> v >> c;
        Arr[u].push_back({v, c});
        Arr[v].push_back({u, c});
    }

    for(int i=0; i<n; i++) {
        Dis[i] = INF;
    }

    int src; cin >> src;
    Dijkstra(src);

    for(int i=0; i<n; i++) {
        cout << i << " --> " << Dis[i] << endl;
    }
    return 0;
}
 
 
//_______________________________________________________________________________________________

void Dijkstra(ll src) {
    queue<pair<ll, ll>> q;
    q.push({src, 0});
    Dis[src] = 0;

    while(!q.empty()) {
        pair<ll, ll> parent = q.front(); q.pop();
        ll p_node = parent.first;  // Parent Node
        ll p_cost = parent.second; // Parent Cost

        for(pair<ll, ll> child: Arr[p_node]) {
            ll c_node = child.first;  // Child Node
            ll c_cost = child.second; // Child Cost

            if(p_cost + c_cost < Dis[c_node]) {
                Dis[c_node] = p_cost + c_cost;
                q.push({c_node, Dis[c_node]});
            }
        }
    }
}

//_______________________________________________________________________________________________