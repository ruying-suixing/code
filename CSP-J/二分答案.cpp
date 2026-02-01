//P2440
#include<bits/stdc++.h>
using namespace std;
int t,m,v[105],w[105],dp[1005];
int main(){
	cin>>t>>m;
	for(int i=1;i<=m;++i)cin>>v[i]>>w[i];
	for(int i=1;i<=m;++i){
		for(int j=t;j>=0;--j){
			if(j>=v[i])dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
		}
	}
	cout<<dp[t];
	return 0;
}
