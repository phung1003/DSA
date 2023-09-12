#include <iostream>

using namespace std;
void InsertionSort(int n, int a[])
{
     int i, key, j;
     for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
        for (int j = 0; j < n; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;
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
    InsertionSort(n, a);
    for (int j = 0; j < n; j++)
        {
            cout << a[j] << " ";
        }

    return 0;
}
