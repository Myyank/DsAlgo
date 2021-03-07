/*

Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies (between 1 and 1000000000). 
Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students. He want to distibute them 
in a way such that:
1. All students get equal number of candies.
2. All the candies which a student get must be from a single box only.
As he want to make all of them happy so he want to give as many candies as possible. Help Shaky in finding out what 
is the maximum number of candies which a student can get.

Input
First line contains 1<=T<=20 the number of test cases. Then T test cases follow. 
First line of each test case contains N and K. Next line contains N integers, ith 
of which is the number of candies in ith box.

Output
For each test case print the required answer in a seperate line.

Sample Input:
2
3 2 
3 1 4
4 1
3 2 3 9

Sample Output:
3
9

*/

#include <bits/stdc++.h>
using namespace std;

bool check(long long child, long long ar[], long long size, long long m)
{
    int tc = child * m;
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (ar[i] / m > 0)
        {
            count = ar[i] / m + count;
        }
        if (count >= child)
            return true;
    }
    return false;
}

int main()
{

    // Write your code here
    int t = 0;
    cin >> t;
    while (t--)
    {

        long long n, k;
        cin >> n >> k;
        long long arr[n];

        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
            sum = sum + arr[i];
        }
        sort(arr, arr + n);

        if (k == 1)
        {
            cout << arr[n - 1] << endl;
            continue;
        }

        if (k > sum)
        {
            cout << "0" << endl;
            continue;
        }
        long long res = -1;
        long long start = 1;
        long long end = arr[n - 1];
        while (start <= end)
        {
            long long mid = (start + end) / 2;

            if (check(k, arr, n, mid))
            {
                res = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }

        cout << res << endl;
    }
}