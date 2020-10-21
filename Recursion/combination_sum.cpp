Author : sourabh kumar
Date created : 21 / 10 / 20

Given an array of integers A and a sum B, find all unique combinations in A where the sum is equal to B. 
The same repeated number may be chosen from A unlimited number of times.

Note:
        1. All numbers will be positive integers.
        2. Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
        3. The combinations themselves must be sorted in ascending order.

Input:
First line of input contains number of testcases T. For each testcase, there will be three lines of input, first of which contains N, size of array. Next line contains N space seperated integers, and the last line contains B.

Output:
For each testcase, print the sets enclosing a backet "(" and ")". No space between two sets. If no set can be formed with the given set, then print "Empty" (without quotes).

ex :
1
4
7 2 6 5
16

output:(2 2 2 2 2 2 2 2)(2 2 2 2 2 6)(2 2 2 5 5)(2 2 5 7)(2 2 6 6)(2 7 7)(5 5 6)

***************************************************************************************************************************************************************************

#include<bits/stdc++.h>
using namespace std;
#define vi               vector<int>
#define pii              pair<int,int>
#define si               set<int>
#define ff               first
#define ss               second
#define mii              map<int,int>
#define umii             unordered_map<int,int>
#define p_b              push_back
#define pqi               priority_queue<int>
#define loop(i,a,b)      for(int i=a;i<b;i++)
#define int              long long
#define io          	 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define multipletest     int t;cin>>t;while(t--) 
bool isPrime(int n){if(n==1){return false;}if(n==2){return true;}if(n%2==0){return false;}for(int i = 3; i <= sqrt(n); i+=2){if(n % i == 0){return false;}}return true;}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////f//////////////////////////////////////////////////////////////////////////////

void findAll ( vector<string> &ans , string cur , int start , int req , int n , int *a)
{
    if(req == 0)
    {
        ans.push_back(cur);
        return;
    }
    
    if(start >= n) return;
    
    for(int i=start ;  i < n ; i++)
    {
        if(i != 0 && a[i] == a[i-1]) continue;
        
        if(a[i] <= req)
          findAll(ans , cur + to_string(a[i]) , i , req - a[i] , n , a);
    }
    
}

void solve()
{
    int n;
    cin>>n;
    
    int a[n];
    loop(i,0,n) cin>>a[i];
    
    int req;
    cin>>req;
    
    sort(a , a+n);
    
    vector<string> ans;
    
    findAll(ans , "" , 0 , req , n , a);
    
    if(ans.size() == 0)
    {
        cout<<"Empty\n";
        return;
    }
    
    
    for(int i=0 ; i < ans.size() ; i++)
    {
        
    cout<<"(";
        for(int j=0;j<ans[i].size() ; j++)
        {
            cout<<ans[i][j];
            
            if(j != ans[i].size()-1)
               cout<<" ";
        }
        
        cout<<")";
        
    }
    
    cout<<endl;
    
}

int32_t main()
{
	io
 	multipletest
	solve();
}
