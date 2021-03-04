/*
There is only one beauty parlour in the town CodingNinjasLand. The receptionist at the beauty parlor 
is flooded with appointment requests because the “Hakori” festival is round the corner and everyone 
wants to look good on it.
She needs your help. The problem is they don’t have chairs in reception. They are ordering chairs from 
NinjasKart. They don’t want to order more than required. You have to tell the minimum number of chairs 
required such that none of the customers has to stand.

Input Format :
First line contains the number of customers that will come. Second line contains N space-separated integers
which represent the arrival timings of the customer. Third line contains N space-separated integers which represent
the departure timings of the customer. Arrival and departure timings are given in 24-hour clock.

Constraints:

1<= N <= 100
Arrival and departure timings lie in the range [0000 to 2359]
Time Limit: 1 second

Output Format :

You have to print the minimum number of chairs required such that no customer has to wait standing. 
Sample Test Cases:

Sample Input 1 :
5
900 1000 1100 1030 1600
1900 1300 1130 1130 1800

Sample Output 1:

4

Explanation:
4 because at 1100 hours, we will have maximum number of customers at the shop, throughout the day. And that maximum number is 4.

*/

#include <bits/stdc++.h>
using namespace std;

class detail
{
public:
    int t = 0;
    int check = 0;
};

bool camp(detail &a, detail &b)
{
    return (a.t < b.t);
}

int main()
{

    // Write your code here

    int n;
    cin >> n;

    vector<detail> t1;

    for (int i = 0; i < n; ++i)
    {
        int x = 0;
        cin >> x;
        detail temp;
        temp.t = x;
        temp.check = 1;
        t1.push_back(temp);
    }

    for (int i = 0; i < n; ++i)
    {

        int z = 0;
        cin >> z;
        detail temp1;
        temp1.t = z;
        temp1.check = 0;
        t1.push_back(temp1);
    }

    sort(t1.begin(), t1.end(), camp);
    int res = 0;
    int m = 0;
    for (int i = 0; i < t1.size(); ++i)
    {

        if (t1.at(i).check == 1)
            ++m;
        else
            --m;
        res = max(res, m);
    }

    cout << res;
}