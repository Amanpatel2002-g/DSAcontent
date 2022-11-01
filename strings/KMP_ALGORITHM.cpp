// KMP ALGORITHM
#include <bits/stdc++.h>
using namespace std;
class KMP
{
public:
    static vector<int> prefixfunction(string s)
    {
        int n = s.size();
        int prefixCount = 0;
        vector<int> arr(n, -1);
        arr[0] = 1;
        int i = 1;
        while (i != n)
        {
            if (s[prefixCount] == s[i])
            {
                arr[i] = prefixCount + 1;
                prefixCount++;
                i++;
            }
            else
            {
                if (prefixCount != 0)
                {
                    prefixCount = arr[prefixCount - 1];
                }
                else
                {
                    arr[i] = 0;
                    i += 1;
                }
            }
        }
        return arr;
    }
    bool stringMatch(string s1, string s2)
    {
        vector<int> pf = prefixfunction(s2);
        int m = s1.size(), n = s2.size();
        int i = 0, j = 0;
        while (i < (m - n + 1))
        {
            if (s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                if (j != 0)
                {
                    j = pf[j - 1];
                }
                else
                    i++;
            }
            if (j == m)
            {
                cout << s1.substr(i - j, j) << endl;
                j = s1[j - 1];
            }
        }
    }
};
int main()
{
    KMP kmp;
    string s = "aabbaabb";
    vector<int> v = kmp.prefixfunction(s);
    for(int i:v)cout<<i<<endl;

    return 0;
}