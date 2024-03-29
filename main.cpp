#include <iostream>
#include <stack>
#include <queue>
using namespace std;
// n không âm

void gen(int k, int n, int arr[])
{

    if (k == n)
    {
        for (int i = 1; i <= n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    bool kt[100] = {false};

    for (int i = 1; i <= k; i++)
        kt[arr[i]] = true;

    int next[100] = {};

    // copy
    for (int j = 1; j <= k; j++)
        next[j] = arr[j];

    for (int i = 1; i <= n; i++)
        if (kt[i] == false)
        {
            next[k + 1] = i;

            // recursion
            gen(k + 1, n, next);
        }
}
int main()
{
    int arr[100], n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        arr[1] = i;
        gen(1, n, arr);
    }
}