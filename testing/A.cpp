#include <bits/stdc++.h>
using namespace std;
#define FAST    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define all(n)  (n).begin(), (n).end()
#define SZ(n)    ((int)(n).size())

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


int main(){
FAST
vector<vector<int>> flights {{0,1,10},{1,2,10},{2,3,10},{3,4,0},{0,3,0}};
int src = 0;
int dst = 4;
int k = 2;
int n = (int)flights.size();
  map<array<int, 2>, int> M;
        vector<vector<int>> G(n);
        for (auto w : flights) {
            G[w[0]].push_back(w[1]);
            M[{w[0], w[1]}] = w[2];
        }
        dbg(G);
        vector<vector<int>> routes;
        vector<int> a;
        vector<bool> vis(n, false);
        a.push_back(src);
        function<void(int)> dfs = [&](int v) {
           if ((int)a.size() - 2 == k && v != dst) {
               dbg("from size", a);
               vis[a.back()] = false;
               return ;
           } 
           if (v == dst) {
               routes.push_back(a);
               return ;
           }
           vis[v] = true;
           for (int u : G[v]) {
               if (!vis[u]) {
                   a.push_back(u);
                   dfs(u);
                   a.pop_back();
               }
           }
        };
        dfs(src);
        dbg(vis);
        dbg(routes);
        int ans = INT_MAX;
        for (auto a : routes) {
            int sum = 0;
            for (int i = 0; i + 1 < (int)a.size(); i++) {
                sum += M[{a[i], a[i + 1]}];
            }
            ans = min(ans, sum);
        }
        cout << "ANSWER : " << ans;

 return 0; 
}  
