#include <iostream>

using namespace std;
void quickSort(int l, int h, int a[])
{
    int i, j, x;
    i = l;
    j = h;
    x = a[(l+h)/2];
    do
    {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j)
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j) quickSort(l, j, a);
    if (i < h) quickSort(i, h, a);


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
    quickSort(0, n-1, a);
    for (int j = 0; j < n; j++)
        {
            cout << a[j] << " ";
        }

    return 0;
}
