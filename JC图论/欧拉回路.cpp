//P7771
#include<bits/stdc++.h>
using namespace std;
int n,m,d[100005],c[100005],f[100005]/*表示遍历到第几个点*/;
vector<int>a[100005];
stack<int>st;
void dfs(int x){
	int l=0;
	while(f[x]<a[x].size()){
		int y=a[x][f[x]];
		f[x]++;
		dfs(y);
		c[++l]=y;
	}
	st.push(x);
}
int main(){
	cin>>n>>m;
	int ind[100005],outd[100005],u,v;
	for(int i=1;i<=m;++i){
		cin>>u>>v;
		a[u].push_back(v);
		ind[v]++,outd[u]++;
	}
	for(int i=1;i<=n;++i)sort(a[i].begin(),a[i].end());
	int x=1,y=0,z=0;
	for(int i=1;i<=n;++i){
		if(ind[i]+1==outd[i])x=i,++y;
		if(ind[i]!=outd[i])++z;
	}
	if(!((y==1&&z==2)||!z)){
		cout<<"No"<<endl;
		return 0;
	}
	dfs(x);
	while(!st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
}
