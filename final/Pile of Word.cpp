#include <bits/stdc++.h>
using namespace std;

void Pil_Wor()
{
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.length() != s2.length())
    {
        cout << "NO" << endl;
        return;
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if (s1 == s2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Pil_Wor();
    }
    return 0;
}