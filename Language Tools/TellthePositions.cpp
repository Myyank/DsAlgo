/*

In a class there are ‘n’ number of students. They have three different subjects: Data Structures, 
Algorithm Design & Analysis and Operating Systems. Marks for each subject of all the students are 
provided to you. You have to tell the position of each student in the class. Print the names of each 
student according to their position in class. Tie is broken on the basis of their roll numbers. 
Between two students having same marks, the one with less roll number will have higher rank. 
The input is provided in order of roll number.

Input Format:
First line will have a single integer ‘n’, denoting the number of students in the class.
Next ‘n’ lines each will have one string denoting the name of student and three space 
separated integers m1, m2, m3 denoting the marks in three subjects.

Output Format:
Print ‘n’ lines having two values: First, the position of student in the class and second his name.

Constraints:
1 <= n <= 10^5
0 <= m1, m2, m3 <= 100

Sample Input:
3
Mohit 94 85 97
Shubham 93 91 94
Rishabh 95 81 99

Sample Output:
1 Shubham
2 Mohit
3 Rishabh
*/

#include <vector>
#include <bits/stdc++.h>
using namespace std;

class stu
{
public:
    string name;
    int sum = 0;
    int check = 0;
};

bool comp(stu &a, stu &b)
{
    if (a.sum != b.sum)
        return a.sum > b.sum;
    else
        return a.check < b.check;
}

int main()
{

    int n = 0;
    cin >> n;

    vector<stu> st;

    int k = n;
    int z = 0;
    while (k--)
    {
        int m1 = 0, m2 = 0, m3 = 0;
        string str;
        cin >> str >> m1 >> m2 >> m3;
        int s = m1 + m2 + m3;

        stu temp;
        temp.name = str;
        temp.sum = s;
        temp.check = z + 1;

        st.push_back(temp);
        ++z;
        //cout<<str<<" "<<s<<endl;
    }

    sort(st.begin(), st.end(), comp);

    int j = 1;
    for (int i = 0; i < n; ++i)
    {
        cout << i + 1 << " " << st.at(i).name << endl;
    }

    return 0;
}
