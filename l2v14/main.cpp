#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const int Max = 100;
    double arr[Max];
    int n;

    cout << "Enter n: ";
    cin >> n;

    if (n < 1 || n > Max)
    {
        cout << "Out of bounds\n";
        return 1;
    }

    int mode;
    cout << "1 - manual, 2 - random: ";
    cin >> mode;

    if (mode == 1)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
    }
    else if (mode == 2)
    {
        double min_val, max_val;
        cout << "Enter min max: ";
        cin >> min_val >> max_val;

        srand(time(NULL));
        for (int i = 0; i < n; ++i)
        {
            arr[i] = min_val + (double)rand() / RAND_MAX * (max_val - min_val);
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        return 1;
    }

    double max_el = arr[0];
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] > max_el)
        {
            max_el = arr[i];
        }
    }
    cout << "\nMax: " << max_el << "\n";

    int last_pos = -1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (arr[i] > 0)
        {
            last_pos = i;
            break;
        }
    }

    if (last_pos == -1)
    {
        cout << "No positive elements\n";
    }
    else
    {
        double sum = 0;
        for (int i = 0; i < last_pos; ++i)
        {
            sum += arr[i];
        }
        cout << "Sum: " << sum << "\n";
    }

    double a, b;
    cout << "\nEnter a b: ";
    cin >> a >> b;

    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        if (abs(arr[i]) < a || abs(arr[i]) > b)
        {
            arr[k] = arr[i];
            k++;
        }
    }

    for (int i = k; i < n; ++i)
    {
        arr[i] = 0.0;
    }

    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
