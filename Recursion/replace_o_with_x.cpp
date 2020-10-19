/*
The first line of input contains an integer T denoting the no of test cases. 
Then T test cases follow. The first line of each test case contains two integers N and M denoting the size of the matrix. 
Then in the next line are N*M space separated values of the matrix.

Output:
For each test case print the space separated values of the new matrix.


ex:
Input: mat[N][M] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'O', 'X'},
                     {'X', 'X', 'X', 'O', 'O', 'X'},
                     {'O', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                     {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
Output: mat[N][M] =  {{'X', 'O', 'X', 'X', 'X', 'X'},
                      {'X', 'O', 'X', 'X', 'X', 'X'},
                      {'X', 'X', 'X', 'X', 'X', 'X'},
                      {'O', 'X', 'X', 'X', 'X', 'X'},
                      {'X', 'X', 'X', 'O', 'X', 'O'},
                      {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
*/

******************************************************************************************************************************************************************************************
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

#define N 20


void markAll(char **mat ,  char **ans , int n , int m , int i , int j , bool **visited)
{
    visited[i][j] = true;
    
    if(mat[i][j] == 'O')
        ans[i][j] = 'N';
    
    if(i>=0 && i< n && j-1 >=0 && j-1 < m && !visited[i][j-1] && mat[i][j-1] != 'X')
       markAll(mat , ans , n , m , i , j-1 , visited);
    
    if(i>=0 && i< n && j+1 >=0 && j+1 < m && !visited[i][j+1] && mat[i][j+1] != 'X')
       markAll(mat , ans , n , m , i , j+1 , visited);
    
    if(i-1>=0 && i-1< n && j >=0 && j < m && !visited[i-1][j] && mat[i-1][j] != 'X')
       markAll(mat , ans , n , m , i-1 , j , visited);
    
    if(i+1>=0 && i+1< n && j >=0 && j < m && !visited[i+1][j] && mat[i+1][j] != 'X')
       markAll(mat , ans , n , m , i+1 , j , visited);
}

void solve()
{
    int n,m;
    cin>>n>>m;
    
    char **mat = new char*[n];
    char **ans = new char*[n];
    bool **visited = new bool*[n];
    
    for(int i=0 ; i < n ; i++)
    {
        mat[i] = new char[m];
        ans[i] = new char[m];
        visited[i] = new bool[m];
    }
    
    
    for(int i=0 ; i < n ; i++)
    {
        for(int j=0; j<m ;j++)
        {
            cin>>mat[i][j];
            ans[i][j] = mat[i][j];
            visited[i][j] = false;
        }
    }
    
    // First row
    for(int i=0 ;i<m; i++)
    {
        if(mat[0][i] == 'O' && (visited[0][i] == false))
        {
            markAll(mat , ans , n , m , 0 , i , visited);
        }
    }
    
    //Last Row
    for(int i=0 ;i<m; i++)
    {
        if(mat[n-1][i] == 'O' && (visited[n-1][i] == false))
        {
            markAll(mat , ans , n , m , n-1 , i , visited);
        }
    }
    
    //first column
    for(int i=0 ; i<n ;i++)
    {
        if(mat[i][0] == 'O' && (visited[i][0] == false))
        {
            markAll(mat , ans , n , m , i , 0 , visited);
        }
    }
    
    //last column
    for(int i=0 ; i<n ;i++)
    {
        if(mat[i][m-1] == 'O' && (visited[i][m-1] == false))
        {
            markAll(mat , ans , n , m , i , m-1 , visited);
        }
    }
    
    for(int i=0 ; i < n ; i++)
       for(int j=0 ; j < m ;j++)
         if(ans[i][j] == 'N')
            cout<<'O'<<" ";
         else
            cout<<'X'<<" ";
    
    cout<<endl;
}

int32_t main()
{
	io
 	multipletest
	solve();
}
