

// Q.You are given a set of N integers. You have to return true if there exists a subset that sum up to K, otherwise return false.



// Input Format

// The first line of the test case contains an integer 'N' representing the total elements in the set.
// The second line of the input contains N integers separated by a single space.    
// The third line of the input contains a single integer, denoting the value of K.

// Output Format

// Output Yes if there exists a subset whose sum is k, else output No.



// Sample Input 1 :
// 4
// 4 3 5 2
// 13
// Sample Output 1 :
// No
// Sample Input 2 :
// 5
// 4 2 5 6 7
// 14
// Sample Output 2 :
// Yes



#include <iostream>
using namespace std;


bool isSubsetPresent(int *set, int n, int sum)
{
    
    
    bool subset[n + 1][sum + 1];
 
    
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
 
   
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;
 
  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - set[i - 1]];
        }
    }
 
  
 
    return subset[n][sum];
    
}


int main()
{
    int n, sum;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> sum;

    if (isSubsetPresent(arr, n, sum))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    delete[] arr;
}