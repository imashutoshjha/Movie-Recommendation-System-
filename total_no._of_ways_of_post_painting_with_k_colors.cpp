#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;
//start calculating from n=1 to 3 and generalise the formula with prev_diff and prev_same.

class Solution{
    public:
    long long countWays(int n, int k){
        if(n==0)
            return 0;
        if(n==1)
            return k;
        long long int mod=pow(10,9)+7;
        long long int same=k%mod;
        long long int dif=((k%mod)*((k-1)%mod))%mod;
        for(int i=3;i<=n;i++){
            long long int prev_dif=dif;
            long long int prev_same=same;
            same=prev_dif*1;
            dif=((prev_same*(k-1))%mod+(prev_dif*(k-1))%mod)%mod;
        }
        return (same+dif)%mod;
        
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends