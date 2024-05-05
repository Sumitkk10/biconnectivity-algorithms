#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <sys/time.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define float long double
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pb emplace_back
#define mp make_pair
#define unique(v) (v).erase(unique((v).begin(), (v).end()), (v).end()) // creates a vector containing unique elements in sorted order (sort the vector before using to erase all duplicates) ONLY DELETES CONSECUTIVE same elements
#define sz(x) (int)((x).size())
#define all(v) (v).begin(), (v).end()
#define file_open() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define MOD 1000000007           // 1e9+7
#define INF 9223372036854775807 // for long long
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order(k) finds kth element, order_of_key(x) count of element less than x

template<typename datatype> 
void print(vector<datatype> v, string sep = " ", string endline = "\n") {for (auto i : v) cout << i << sep; cout << endline;}
template<typename datatype> 
void print(set<datatype> k,string sep = " ",string endline = "\n") {for (auto i : k) cout << i << sep; cout << endline;}
void print(bool k){cout << (k ? "YES" : "NO") <<"\n";}

#define sp " "
#define endl '\n'

int count_bccs = 0;
int V, E;
vector<int>* adj;
vector<pair<int, int>> edges;

bool visited[1000005];

long long current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (long long)tv.tv_sec * 1000000LL + (long long)tv.tv_usec;
}

void BCCUtil(int u, int disc[], int low[], stack<pair<int, int>>& st, int parent[])
{  
    static int time = 0;
 
    disc[u] = low[u] = ++time;
    int children = 0;

    for (auto v : adj[u]) {
        if (disc[v] == -1) {
            children++;
            parent[v] = u;
            // store the edge in stack
            st.push({u, v});
            BCCUtil(v, disc, low, st, parent);
 
            low[u] = min(low[u], low[v]);

            if ((disc[u] == 1 && children > 1) || (disc[u] > 1 && low[v] >= disc[u])) {
                while (st.top() != make_pair(u, v)) {
                    cout << st.top().first << "<->" << st.top().second << " ";
                    visited[st.top().first]=true;
                    visited[st.top().second]=true;
                    st.pop();
                }
                cout << st.top().first << "<->" << st.top().second;
                visited[st.top().first]=true;
                visited[st.top().second]=true;
    
                st.pop();
                cout << endl;
                count_bccs++;
            }
        }
 
        else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
            if (disc[v] < disc[u]) {
                st.push({u, v});
            }
        }
    }
}
 
void BCC()
{
    int* disc = new int[V];
    int* low = new int[V];
    int* parent = new int[V];
    stack<pair<int, int>> st;
 
    for (int i = 0; i < V; i++) {
        disc[i] = -1;
        low[i] = -1;
        parent[i] = -1;
    }
 
    for (int i = 0; i < V; i++) {
        if (disc[i] == -1)
            BCCUtil(i, disc, low, st, parent);
 
        int j = 0;

        while (!st.empty()) {
            j = 1;
            cout << st.top().first << "<->" << st.top().second << " ";
            visited[st.top().first]=true;
            visited[st.top().second]=true;

            st.pop();
        }
        if (j == 1) {
            cout << endl;
            count_bccs++;
        }
    }
}
 
void solve(int test_case_no) {
    // V = 12; // Number of vertices
    // E = 26; // Number of edges
 
    // // Adding edges to the graph
    // edges = {
    //     {0, 1}, {1, 0}, {1, 2}, {2, 1}, {1, 3}, {3, 1},
    //     {2, 3}, {3, 2}, {2, 4}, {4, 2}, {3, 4}, {4, 3},
    //     {1, 5}, {5, 1}, {0, 6}, {6, 0}, {5, 6}, {6, 5},
    //     {5, 7}, {7, 5}, {5, 8}, {8, 5}, {7, 8}, {8, 7},
    //     {8, 9}, {9, 8}, {10, 11}, {11, 10}
    // };
    // testing static graph 

    int n,m ;
    cin>>n>>m;
    V=n;
    adj = new vector<int>[n];

    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
    long long start_time = current_time();
    BCC();
    int single_ones=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            single_ones++;
        }
    }
    count_bccs+=single_ones;
    long long end_time = current_time();
    double elapsed_time = (end_time - start_time) / 1000.0; // Convert to seconds

	cout << fixed << setprecision(6) << elapsed_time << endl;
    
    cout << count_bccs << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    // file_open()
#endif
    // fast;
    int test_cases = 1;
    // cin >> test_cases;
    for (int test_case_ = 0; test_case_ < test_cases; test_case_++) {
        solve(test_case_+1);
    }
    return 0;
}
