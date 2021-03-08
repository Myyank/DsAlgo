/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the 
count of elements populated in the output array.

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

#include <string>
using namespace std;

int keypad(int num, string output[])
{

    string input = "";
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }

    int k = num % 10;
    num = num / 10;
    int smallsize = keypad(num, output);

    if (k == 2)
        input = "abc";
    if (k == 3)
        input = "def";
    if (k == 4)
        input = "ghi";
    if (k == 5)
        input = "jkl";
    if (k == 6)
        input = "mno";
    if (k == 7)
        input = "pqrs";
    if (k == 8)
        input = "tuv";
    if (k == 9)
        input = "wxyz";

    int otsize = smallsize * (input.size());
    string temp[otsize];
    int p = 0;
    for (int i = 0; i < smallsize; ++i)
    {
        for (int j = 0; j < input.size(); ++j)
        {
            temp[p++] = output[i] + input[j];
        }
    }
    for (int i = 0; i < otsize; ++i)
        output[i] = temp[i];

    return input.size() * smallsize;
}
