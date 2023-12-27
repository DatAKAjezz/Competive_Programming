#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("avx2,fma,bmi,bmi2,popcnt,lzcnt")

#define ll long long
const int max_n = 10e4 + 1;
struct egde{
    int u,v,w;
};

bool cmp(egde x,egde y){

    return (x.w > y.w);

}

int n,m;
int parent[max_n];
int sizee[max_n];
int f[1001][1001];
vector<egde> e;

void inpp(){

    
    cin >> n >> m;
    for (int i = 0;i<m;i++){

        int u1,v1,w1;
        cin >>u1 >> v1 >> w1 ;
        e.push_back({u1,v1,w1});

    }
}
void make_set(){
    for (int i = 1;i<=n;i++){
        parent[i] = i;
        sizee[i] = 1;
    }
}

int findroot(int v){
    if (v==parent[v]){
        return v;
    }
    return parent[v]=findroot(parent[v]);
}

bool Union (int a,int b){   
    a = findroot(a); b = findroot(b);
    if (a == b) return false;
    if (a != b){

        if (sizee[a] < sizee[b]) swap(a,b);
        parent[b] = a;
        sizee[a]+= sizee[b];       
    }
    return true;

}
void Kruskal(){
    make_set();
    vector<egde> min_tree;
    sort(e.rbegin(),e.rend(), cmp);
    //for (auto x : e){
    //     cout << x.u <<" "<< x.v <<" "<< x.w <<endl;
    // }
    int dem = 0;
    int weight = 0;
    for(int i = 0;i<m;i++){
        if (dem == n - 1) break;
        int a = e[i].u;
        int b = e[i].v;
        //cout << a << " " <<b <<endl; 
        if (Union(a,b)){
            dem ++;
            min_tree.push_back({a,b,e[i].w});
            weight+= e[i].w;
        }
    }

    //In  kq______________________________________________________
    cout << weight <<endl;
    for (egde x : min_tree){
        cout << x.u <<" " <<x.v << " " << x.w <<endl;

    }

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    inpp();
    Kruskal();

}