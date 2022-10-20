#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define ll  long long
#define ull unsigned long long 
#define ld long double 
 
template<class T> using pbds =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// *find_by_order, order_of_key
 
 
 
// FOR GCD ///
// ll gcd(ll a , ll b){
//     if(b==0) return a;
 
//     return gcd(b,(a%b));
// }
 
// //FOR LCM ///
// ll lcm(ll a, ll b){
    
//    return ((a*b)/gcd(a,b));
// }
//////////////////////////////////////
 
//FOR POWER(X,Y)
// ll power(ll x,ll y){
 
//     ll ans = 1;
//     while(y>0){
//         if(y&1){
//             ans = (ans * x);  
//         }
//         x =(x * x);
//         y = (y>>1);
//     }
//     return ans;
// }
//////////////////////////////////////
 
 
 
 
void judge(){
 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
////////////////////////////////////code/////////////////////////////////////////////////////
 
//const int mod = 1000000007;
 
class SGTree {
public:
    vector<ll> seg;
    SGTree(ll n) {
        seg.resize(4 * n + 1);
    }
 
    void build(ll ind, ll low, ll high) {
        if (low == high) {
            seg[ind] = 0;
            return;
        }
 
        ll mid = (low + high) / 2;
        build(2 * ind + 1, low, mid);
        build(2 * ind + 2, mid + 1, high);
        
        seg[ind] = 0;
 
    }
 
    int query(ll ind, ll low, ll high, ll l, ll r) {
        // no overlap
        // l r low high or low high l r
        if (r < low || high < l) return INT_MAX;
 
        // complete overlap
        // [l low high r]
        if (low >= l && high <= r) return seg[ind];
 
        ll mid = (low + high) >> 1;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);
        return (left | right);
    }
    void update(ll ind, ll low, ll high,vector<ll> &ans,ll &val,ll l ,ll r) {
        if(seg[ind]>0) return;
        if(high<l || low>r) return; 
        if (l == r) {
            ans[l] = val;
            seg[ind] = 1;
            return;
        }
 
        ll mid = (l + r) >> 1;
         update(2 * ind + 1, low, high,ans, val,l,mid);
         update(2 * ind + 2, low, high, ans, val,mid+1,r);
 
         if(seg[2*ind+1]==1 && seg[2*ind+2]==1) seg[ind] = 1;
       
    }   
};
void helper(){
        
      ll n,m;
      cin>>n>>m;
      vector<ll> ans(n,0);
 
      SGTree a(n);
      a.build(0,0,n-1);
      // for(auto &it: a.seg) cout<<it<<" ";
      //   cout<<endl;
      while(m--){
 
        ll l,r,x;
        cin>>l>>r>>x;
 
        if(x-2>=l-1) a.update(0,l-1,x-2,ans,x,0,n-1);
        if(r-1>=x) a.update(0,x,r-1,ans,x,0,n-1);
 
      }
      for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
 
}
    int main(){
    judge();
 
     //  int tt;
     // cin>>tt;
 
     // while(tt--){
    helper();
//     cout<<"\n";
// }
    return 0;
}
