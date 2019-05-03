#include <vector>
#include <iostream>
using namespace std;

void merge(vector<int> &v, int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L(n1);
    vector<int> R(n2);

    for (i = 0; i < n1; i++)
    {
        L[i] = v[p + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = v[q + 1 + j];
    }

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            v[k] = L[i];
            i++;
        }
        else
        {
            v[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &v, int p, int r)
{
    if (p >= r)
    {
        return;
    }
    int q = (p + r) / 2;
    mergeSort(v, p, q);
    mergeSort(v, q + 1, r);
    merge(v, p, q, r);
}

int main()
{
    vector<int> v = {5, 4, 10, 17, 9};
    mergeSort(v, 0, v.size() - 1);
    for(int &e: v)
    {
        cout << e << " ";
    }
    return 0;
}