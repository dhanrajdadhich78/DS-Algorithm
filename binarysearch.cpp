#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &v, int x)
{
    int l = 0;
    int r = int(v.size()) - 1;
    int m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (v[m] == x)
        {
            return m;
        }
        else if (v[m] > x)
        {
            r = m - 1;
        }
        else if (v[m] < x)
        {
            l = m + 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> v = {1, 12, 24, 35, 117};
    int result = binarySearch(v, 12);
    cout << result;
    return 0;
}