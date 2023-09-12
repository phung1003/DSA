#include <iostream>

using namespace std;

void SelectionSort(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        int t = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[t]) t = j;
        }
        int temp = a[i];
        a[i] = a[t];
        a[t] = temp;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    SelectionSort(n, a);
    for (int j = 0; j < n; j++)
        {
            cout << a[j] << " ";
        }

    return 0;
}
