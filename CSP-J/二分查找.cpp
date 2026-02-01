//P2249
#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],q,l,r,mid;
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; ++i) {
		cin>>a[i];
	}
	for(int i=1; i<=m; ++i) {
		cin>>q;
		l=1,r=n;
		while(l<r) {
			mid=l+(r-l)/2;
			if(a[mid]>=q)r=mid;
			else l=mid+1;
		}
		if(a[l]==q)cout<<l<<" ";
		else cout<<"-1 ";
	}
	return 0;
}