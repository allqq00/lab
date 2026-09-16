#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double x;
    int k;

    cout << "Enter x (x > 1): ";
    cin >> x;
    cout << "Enter k (k > 1): ";
    cin >> k;

    double eps = pow(10, -k);

    double sum = M_PI / 2.0;
    double x2 = x * x;
    double p = x;
    int sign = -1;

    for (int n = 0; ; ++n)
    {
        double cur = 1.0 / ((2 * n + 1) * p);
        if (cur < eps)
        {
            break;
        }

        sum += sign * cur;
        p *= x2;
        sign = -sign;
    }

    double std_res = atan(x);

    cout << fixed << setprecision(k);
    cout << "result: " << sum << endl;
    cout << "atan(x):        " << std_res << endl;
    cout << "diff:           " << abs(sum - std_res) << endl;

    return 0;
}
