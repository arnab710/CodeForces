// main intution is ---> we are calculating corresponding to each element considering it as the middle element take a larger element from previous PBDS , and a small element from further PBDS... 

void helper(){
 
        ll n;
        cin>>n;
 
        ll nums[n];
 
        for(ll i = 0;i<n;i++)   cin>>nums[i];
 
            pbds<ll> furthersmall;
            pbds<ll> previousgreater;
 
            for(ll i = 0;i<n;i++) furthersmall.insert(nums[i]);
 
 
                ll ans = 0;
            for(ll i = 0;i<n;i++){
 
                furthersmall.erase(nums[i]);
                ll l = furthersmall.order_of_key(nums[i]);
                ll r = previousgreater.size() - previousgreater.order_of_key(nums[i]);
 
                ans += (l*r);
                previousgreater.insert(nums[i]);
 
            }    
 
            cout<<ans;
        
 }
