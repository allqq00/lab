#include <iostream>


using namespace std;

int n, m;
int val00;
int* odd_arr = nullptr;
int* ord = nullptr;

int get_odd_idx(int r, int c)
{
    int idx = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i + j) % 2 != 0)
            {
                idx++;
            }
        }
    }
    for (int j = 0; j < c; j++)
    {
        if ((r + j) % 2 != 0)
        {
            idx++;
        }
    }
    return idx;
}

int get(int r, int c)
{
    int real_r = ord[r];
    if ((real_r + c) % 2 == 0)
    {
        return val00;
    }
    return odd_arr[get_odd_idx(real_r, c)];
}

void print_matrix()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << get(i, j) << "\t";
        }
        cout << "\n";
    }
}

int row_sum(int r)
{
    int sum = 0;
    for (int j = 0; j < m; j++)
    {
        int v = get(r, j);
        if (v > 0)
        {
            sum += v;
        }
    }
    return sum;
}

int main()
{


    cout << "Enter N (1-10): ";
    cin >> n;
    cout << "Enter M (1-10): ";
    cin >> m;

    int count_odd = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i + j) % 2 != 0) count_odd++;
        }
    }

    if (count_odd > 0)
    {
        odd_arr = new int[count_odd];
    }
    ord = new int[n];
    for (int i = 0; i < n; i++)
    {
        ord[i] = i;
    }

    cout << "Enter a[0][0]: ";
    cin >> val00;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i + j) % 2 != 0)
            {
                cout << "a[" << i << "][" << j << "]: ";
                cin >> odd_arr[get_odd_idx(i, j)];
            }
        }
    }

    cout << "\nInitial matrix:\n";
    print_matrix();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (row_sum(j) > row_sum(j + 1))
            {
                int tmp = ord[j];
                ord[j] = ord[j + 1];
                ord[j + 1] = tmp;
            }
        }
    }

    cout << "\nSorted matrix:\n";
    print_matrix();

    int no_zero_cols = 0;
    for (int j = 0; j < m; j++)
    {
        bool has_zero = false;
        for (int i = 0; i < n; i++)
        {
            if (get(i, j) == 0)
            {
                has_zero = true;
                break;
            }
        }
        if (!has_zero)
        {
            no_zero_cols++;
        }
    }

    cout << "\nColumns without zeros: " << no_zero_cols << "\n";

    delete[] odd_arr;
    delete[] ord;

    return 0;
}
