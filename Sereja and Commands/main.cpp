#include <bits/stdc++.h>

using namespace std ;

#define fr first
#define se second
#define pb push_back
#define ll long long

const ll mod = 1000*1000*1000+7 ;

int main(){
    ll T ;
    cin>>T ;
    while(T--){
        ll N,M ;
        cin>>N>>M ;
        ll arr[N+10]={0},qtimes[M+10]={0} ;
        qtimes[M] = 1 ;

        vector< pair<ll ,pair<ll,ll> >> insp ;

        insp.pb({0 , {0,0}}) ;

        for(int i = 1; i<=M ; i++)
        {
            ll t,l,r ;
            cin >> t >> l >> r ;
            insp.pb({t,{l,r}}) ;
        }
        for(int i = M ; i>=1 ; i--)
        {
            qtimes[i]=(qtimes[i]+qtimes[i+1])%mod ;
            ll type = insp[i].fr ;
            if(type == 1)
            {
                ll x = insp[i].se.fr , y = insp[i].se.se ;
                arr[y] = (arr[y]+qtimes[i])%mod ;
                arr[x-1] = (arr[x-1]-qtimes[i]+mod)%mod ;
            }
            else{
                ll x = insp[i].se.fr , y = insp[i].se.se ;
                qtimes[y] = (qtimes[y]+qtimes[i])%mod ;
                qtimes[x-1] = (qtimes[x-1]-qtimes[i]+mod)%mod ;
            }
        }
        for(int i = N ; i>=1 ; i--)
            arr[i]=(arr[i]+arr[i+1])%mod ;
        for(int i = 1 ; i<=N ; i++)
            cout<<arr[i]<<' ';
        cout<<"\n" ;
    }
    return 0 ;

}
