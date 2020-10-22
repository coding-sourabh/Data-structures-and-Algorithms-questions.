Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), your task is to replace color of the given pixel and all adjacent(excluding diagonally adjacent) same colored pixels with the given color K.

Example:

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1},
{1, 2, 2, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 0, 1, 0},
{1, 1, 1, 2, 2, 2, 2, 0},
{1, 1, 1, 1, 1, 2, 1, 1},
{1, 1, 1, 1, 1, 2, 2, 1},
 };

 x=4, y=4, color=3 

{{1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 0, 0},
{1, 0, 0, 1, 1, 0, 1, 1}, 
{1, 3, 3, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 0, 1, 0},
{1, 1, 1, 3, 3, 3, 3, 0},
{1, 1, 1, 1, 1, 3, 1, 1},
{1, 1, 1, 1, 1, 3, 3, 1}, };

Note: Use zero based indexing.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains Two integers N and M denoting the size of the matrix. Then in the next line are N*M space separated values of the matrix. Then in the next line are three values x, y and K.

Output:
For each test case print the space separated values of the new matrix.

Example:
Input:
3
3 4
0 1 1 0 1 1 1 1 0 1 2 3
0 1 5
2 2
1 1 1 1
0 1 8
4 4 
1 2 3 4 1 2 3 4 1 2 3 4 1 3 2 4
0 2 9

Output:
0 5 5 0 5 5 5 5 0 5 2 3
8 8 8 8
1 2 9 4 1 2 9 4 1 2 9 4 1 3 2 4

**************************************************************************************************************************************************************************

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

void floodFill(int **mat ,int n , int m , int x , int y , int color , bool **visited , int initialColor)
{
    if(x >= n || x < 0 || y >= m || y < 0 || visited[x][y] || mat[x][y] != initialColor)
       return;
    
    mat[x][y] = color;
    visited[x][y] = true;
    
    floodFill(mat , n , m , x+1 , y , color , visited , initialColor);
    floodFill(mat , n , m , x-1 , y , color , visited , initialColor);
    floodFill(mat , n , m , x , y+1 , color , visited , initialColor);
    floodFill(mat , n , m , x , y-1 , color , visited , initialColor);
    
}

void solve()
{
    int n , m;
    cin>>n>>m;
    
    int **mat = new int*[n];
    bool **visited = new bool*[n];
    
    for(int i=0 ; i < n ; i++)
    {
        mat[i] = new int[m];
        visited[i] = new bool[m];
    
        for(int j=0 ; j < m ; j++){
           cin>>mat[i][j];
           visited[i][j] = false;  
        }
    }
    
    int x , y;  
    cin>>x>>y;
    
    int color;
    cin>>color;
    
    
    floodFill(mat , n , m ,  x , y , color , visited , mat[x][y]);
    
    for(int i=0 ; i <  n;  i++)
       for(int j= 0 ; j < m ; j++)
           cout<<mat[i][j]<<" ";
           
    cout<<endl;
    
}

int32_t main()
{
	io
 	multipletest
	solve();
}
