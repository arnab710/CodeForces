void helper(){
    
    ll n,q;
    cin>>n>>q;
 
    vector<ll> a(n);
    vector<ll> qu(q);
    for(auto &it: a) cin>>it;
    for(auto &it: qu) cin>>it;    
    
 
    //prefix maximum array
    vector<ll> p(n);
    vector<ll> sum(n);
 
    sum[0] = a[0];
    p[0] = a[0];
    for(int i = 1;i< n;i++){
        p[i] = max(p[i-1],a[i]);
        sum[i] = sum[i-1]+a[i];
    }
 
    for(auto &it:qu){
 
        ll ind = upper_bound(p.begin(),p.end(),it) - p.begin();
        if(ind==n) cout<<sum[n-1]<<" ";
        else if(ind-1>=0) cout<<sum[ind-1]<<" ";
        else cout<<0<<" ";
    }
return;
 
    }  
