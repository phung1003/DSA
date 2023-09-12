#include <iostream>

using namespace std;
void BubbleSort(int n, int a[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
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
    BubbleSort(n,a);
    for (int j = 0; j < n; j++)
        {
            cout << a[j] << " ";
        }

    return 0;
}
