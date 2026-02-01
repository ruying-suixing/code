//P7771
#include<bits/stdc++.h>
using namespace std;
int ans[5005];
vector<pair<int,int>>to[5005];
void Bellman_Ford(int n){
	auto relax=[&](){
		bool f=0;
		for(int i=1;i<=n;++i){
			for(auto k:to[i]){
				if(ans[i]>ans[k.first]+k.second){
					ans[i]=min(ans[i],ans[k.first]+k.second),f=1;
				}
			}
		}
		return f;
	};
	for(int i=0;i<n-1;++i)relax();
	if(relax())cout<<"NO";
	else for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
}
int n,m,c1,c2,y;
int main() {
	cin>>n>>m;
	fill(ans,ans+n+1,0);
	for(int i=1;i<=m;++i){
		cin>>c1>>c2>>y;
		to[c1].push_back({c2,y});
	}
	Bellman_Ford(n);
    return 0;
}
