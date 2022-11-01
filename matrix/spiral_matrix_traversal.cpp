// spiral matrix traversal

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        int dir = 0, left = 0, right = m - 1, top = 0, down = n - 1;
        while (left <= right and top <= down)
        {
            if (dir == 0)
            {
                for (int i = left; i <= right; i++)
                {
                    cout << matrix[top][i] << " ";
                }
                cout << endl;
                top++;
            }
            else if (dir == 1)
            {
                for (int i = top; i <= down; i++)
                {
                    cout << matrix[right][i] << " ";
                }
                cout << endl;
                right--;
            }
            else if (dir == 2)
            {
                for (int i = right; i >= left; i--)
                {
                    cout << matrix[down][i] << " ";
                }
                cout << endl;
                down--;
            }
            else if (dir == 3)
            {
                for (int i = down; i >= top; i--)
                {
                    cout << matrix[left][i] << " ";
                }
                cout << endl;
                left++;
            }
            dir = ((dir + 1) % 4);
        }
    }
};


int main()
{
    return 0;
}