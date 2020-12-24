#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

static inline bool isPal(string s)
{
    if (s.size() % 2 == 0)
    {
        string t = s.substr(s.size() / 2, s.size() / 2);
        reverse(t.begin(), t.end());
        return s.substr(0, s.size() / 2) == t;
    }
    else
    {
        string t = s.substr(s.size() / 2 + 1, s.size() / 2);
        reverse(t.begin(), t.end());
        return s.substr(0, s.size() / 2) == t;
    }
}

int main()
{
    cout << "input: ";
    string s;
    cin >> s;
    cout << isPal(s) << endl;
    return 0;
}
