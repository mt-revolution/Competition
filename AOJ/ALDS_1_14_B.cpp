#include<bits/stdc++.h>

using namespace std;


template<typename T,T MOD,T B>
struct RollingHash{
    using ll = long long;
    vector<T> hash,po;

    RollingHash(vector<T> vs) {
        init(vs);
    
    }

    RollingHash(string &s){
        vector<T> vs;
        for(char c:s) vs.emplace_back(c);
        init(vs);
    }

    void init(vector<T> vs){
        int n=vs.size();
        hash.assign(n+1,0);
        po.assign(n+1,1);
        for(int i=0;i<n;i++){
        hash[i+1]=((ll)hash[i]*B+vs[i])%MOD;
        po[i+1]=(ll)po[i]*B%MOD;
        }
    }
    //S[l, r)
    T find(int l,int r){
        T res=(ll)hash[r]+MOD-(ll)hash[l]*po[r-l]%MOD;
        return res>=MOD?res-MOD:res;
    }
};



int main() {
    // string T, P;
    // cin >> T;
    // cin >> P;
    
    // BM_search(T, P);


    // cin.tie(0);
    // ios::sync_with_stdio(0);

    string t,p;
    cin>>t>>p;
    using ll = long long;
    const ll MOD = 1e9+7;
    const ll B = 1777771;
    using RH = RollingHash<ll, MOD, B>;

    RH rt(t),rp(p);
    for(int i=0;i<(int)t.size()-(int)p.size()+1;i++)
        if(rt.find(i,i+p.size())==rp.find(0,p.size())) cout<<i<<"\n";

    cout<<flush;

	return 0;
}