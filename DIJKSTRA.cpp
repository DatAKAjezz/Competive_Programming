#include <bits/stdc++.h>
#include <vector>

using namespace std;

using ll= long long;

const int maxn=100001;
int n,m,s;
vector<pair<int,int>> adj[maxn];

void inp(){
	cin>>n>>m>>s;
	for (int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].push_back({y,w});
		//adj[y].push_back({x,w});

	}
}
//================================================
void dijkstra(int s){
	const int inf=1e9;
	vector<ll> d(n+1,inf);
	d[s]=0;
	priority_queue<pair<int,int>,vector <pair<int,int>>,greater<pair<int,int>>> Q;
	//{khoang cach,dinh}
	Q.push({0,s});
	while (!Q.empty()){
		//Chon ra dinh co khoang cach tu s nho nhat
		pair<int,int> top=Q.top();  Q.pop();
		int u=top.second;
		int kc=top.first;
		if (kc>d[u])	continue;
		//Relaxation	:Cập nhật khoảng cách từ S tới mọi 
		for (auto it :adj[u]){
			int v=it.first;
			int w=it.second;
			if (d[v]>d[u]+w){
				d[v]=d[u]+w;
				Q.push({d[v],v});
			}		
		}

	}
	for (int i=1;i<=n;i++){
		cout<<d[i]<<endl;
	}
}
int main(){
    #ifndef ONLINE_JUGDE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    inp();
    dijkstra(s);

	return 0;
}