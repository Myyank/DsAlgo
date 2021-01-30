
// Q.A thief is robbing a store and can carry a maximal weight of W into his knapsack.
// There are N items and ith item weighs wi and is of value vi. Considering the constraints
// of maximum weight that knapsack can carry, you have to find and return the maximum value 
// that thief can generate by stealing items.


// Input Format :
// The first line contains an integers, that denote the value of N. The following line contains N space separated integers,
// that denote the values of weight of items. The following line contains N space separated integers, that denote the values
// associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight that
// thief can carry.
// Output Format :
// The first and only line of output contains the maximum value that thief can generate, as described in the task. 


// Sample Input 1 :
// 4
// 1 2 4 5
// 5 4 8 6
// 5
// Sample Output 1 :
// 13



#include <iostream>
using namespace std;



int knapsack(int* weight, int* value, int n, int maxWeight) {
	
    
    int i=n, w; 
    int W=maxWeight;
    
    
    int K[n + 1][W + 1]; 
  
   
    for (i = 0; i <= n; i++)  
    { 
        for (w = 0; w <= W; w++)  
        { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (weight[i - 1] <= w) 
                K[i][w] = max(value[i - 1] 
                          + K[i - 1][w - weight[i - 1]], 
                          K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
  
    return K[n][W]; 
}





int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}