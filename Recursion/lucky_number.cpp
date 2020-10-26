Lucky numbers are subset of integers. Rather than going into much theory, let us see the process of arriving at lucky numbers,
Take the set of integers
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,……
First, delete every second number, we get following reduced set.
1, 3, 5, 7, 9, 11, 13, 15, 17, 19,…………
Now, delete every third number, we get
1, 3, 7, 9, 13, 15, 19,….….
Continue this process indefinitely……
Any number that does NOT get deleted due to above process is called “lucky”.

Example 1:

Input:
N = 5
Output: 0
Explanation: 5 is not a lucky number 
as it gets deleted in the second 
iteration.
Example 2:

Input:
N = 19
Output: 1
Explanation: 19 is a lucky number
Your Task:
You don't need to read input or print anything. You only need to complete the function isLucky that takes n as parameter and '
returns either 0 if the n is not lucky else 1.

****************************************************************************************************************************************************************************


bool find(int *a , int n , int x , int cnt)
{
    if(a[n-1] != x) return false;
    
    if(cnt >= n) return true;
    
    if(n == 2) return false;
    
    int b[ (n-1) - (n-1)/cnt + 1];
    
    int k=1;
    
    for(int i=1 ; i < n ;i++)
    {
        if(i % cnt != 0)
          b[k++] = a[i];
    }
    
    return find(b , (n-1) - (n-1)/cnt + 1 , x , cnt+1);
    
}

bool isLucky(int n, int &cnt) {
    if(n & 1 == 0) return false;
    
    int a[n+1];
    
    for(int i=1 ; i <= n ; i++)
      a[i] = i;
    
    return find(a , n+1 , n , cnt);
}
