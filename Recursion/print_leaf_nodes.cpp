Given a preorder traversal of a BST, print the leaf nodes of the tree without building the tree.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. 
Each test case contains an integer N denoting the no of nodes of the BST. Then in the next line are N space separated values
denoting the preorder traversal of the binary tree.

Output:
For each test case in a new line print the leaf nodes separated by space of the BST in sorted order.

Example:
Input:
2
5
890 325 290 530 965 
3
3 2 4

Output:
290 530 965
2 4

******************************************************************************************************************************************************************************

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

void printAllLeaves(int *a , int l , int r)
{
    if(l == r)
    {
        cout<<a[l]<<" ";
        return;
    }
    
    if(l > r) return;
    
    int x = a[l] , mid , i=l+1;
    
    while(a[i] < x)
    {
        i++;
    }
    
    printAllLeaves(a , l + 1 , i-1 );
    printAllLeaves(a , i , r);
    
}

void solve()
{
    int n;
    cin>>n;
    
    
    int a[n];
    loop(i,0,n) cin>>a[i];
    
    printAllLeaves(a , 0 , n-1);
    cout<<endl;
}

int32_t main()
{
    int t;
    cin>>t;
    
    while(t--)
    solve();
    
    return 0;
}
       
