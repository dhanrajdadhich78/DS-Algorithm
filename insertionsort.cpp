#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &v)
{
    int key, j;
    for (int i = 1; i < int(v.size()); i++)
    {
        key = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

int main()
{
    vector<int> v = {1, 12, 5, 24, 4};
    insertionSort(v);
    for (auto &e : v)
    {
        cout << e << " ";
    }

    return 0;
}