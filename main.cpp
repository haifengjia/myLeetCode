#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

inline size_t summation(size_t n)
{
    return (26 * (pow(26, n) - 1) / 25);
}

string convertToTitle(int columnNumber)
{
    size_t tt_len = 0;
    string res;
    if (columnNumber < 26)
    {
        res += ((char)(64 + columnNumber));
        return res;
    }

    while (1)
    {
        if (summation(tt_len) >= static_cast<size_t>(columnNumber))
            break;
        tt_len++;
    }
    columnNumber -= summation(tt_len - 1);
    int dig;
    for (size_t i = 0; i < tt_len; i++)
    {
        if (i == tt_len - 1)
        {
            res += ((char)(64 + columnNumber));
            break;
        }

        if (columnNumber > 0)
            dig = ((columnNumber - 1) / (pow(26, tt_len - i - 1)));
        else
            dig = 0;
        res += (char)(65 + dig);
        columnNumber -= dig * (pow(26, tt_len - i - 1));
    }
    return res;
}

int main()
{
    string a = convertToTitle(52);
    cout << a + "\n";
    return 0;
}
