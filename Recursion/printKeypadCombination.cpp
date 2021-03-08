/*
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n

Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:

23

Sample Output:

ad
ae
af
bd
be
bf
cd
ce
cf

*/

#include <iostream>
#include <string>
using namespace std;
int getsize(int num, string output[])
{

    string input = "";
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }

    int n = num % 10;
    num = num / 10;
    int smallsize = getsize(num, output);

    if (n == 2)
        input = "abc";
    if (n == 3)
        input = "def";
    if (n == 4)
        input = "ghi";
    if (n == 5)
        input = "jkl";
    if (n == 6)
        input = "mno";
    if (n == 7)
        input = "pqrs";
    if (n == 8)
        input = "tuv";
    if (n == 9)
        input = "wxyz";

    int bigsize = smallsize * (input.size());
    string temp[bigsize];

    int k = 0;
    for (int i = 0; i < smallsize; ++i)
    {
        for (int j = 0; j < input.size(); ++j)
            temp[k++] = output[i] + input[j];
    }

    for (int i = 0; i < bigsize; ++i)
        output[i] = temp[i];

    return bigsize;
}

void printKeypad(int num)
{

    if (num == 0)
    {
        return;
    }

    string output[10000];
    int z = getsize(num, output);

    for (int i = 0; i < z; ++i)
        cout << output[i] << endl;
}
