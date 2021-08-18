#include <bits/stdc++.h>

#define f1(x, y, z) (17 - y + 2 * z) / 20
#define f2(x, y, z) (-18 - 3 * x + z) / 20
#define f3(x, y, z) (25 - 2 * x + 3 * y) / 20

using namespace std;

void jacob()
{
    float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3, e;
    int step = 1;

    cout << setprecision(6) << fixed;

    cout << "Enter tolerable error: ";
    cin >> e;

    cout << endl
         << "Count\tx\t\ty\t\tz" << endl;
    do
    {
        /* Calculation */
        x1 = f1(x0, y0, z0);
        y1 = f2(x0, y0, z0);
        z1 = f3(x0, y0, z0);
        cout << step << "\t" << x1 << "\t" << y1 << "\t" << z1 << endl;

        /* Error */
        e1 = fabs(x0 - x1);
        e2 = fabs(y0 - y1);
        e3 = fabs(z0 - z1);

        step++;

        x0 = x1;
        y0 = y1;
        z0 = z1;
    } while (e1 > e && e2 > e && e3 > e);

    cout << endl
         << "Solution: x = " << x1 << ", y = " << y1 << " and z = " << z1;
}

void guessSheield(void)
{
    float a[10][10], b[10], m[10], n[10];
    int p = 0, q = 0, i = 0, j = 0;
    cout << "\n\nEnter size of 2D array : ";
    cin >> p;
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < p; j++)
        {
            cout << "a[" << i << ", " << j << " ]=";
            cin >> a[i][j];
        }
    }
    cout << "\nEnter values to the right side of equation\n";
    for (i = 0; i < p; i++)
    {
        cout << "b[" << i << ", " << j << " ]=";
        cin >> b[i];
    }
    cout << "Enter initial values of x\n";
    for (i = 0; i < p; i++)
    {
        cout << "x:[" << i << "]=";
        cin >> m[i];
    }
    cout << "\nEnter the no. of iteration : ";
    cin >> q;
    while (q > 0)
    {
        for (i = 0; i < p; i++)
        {
            n[i] = (b[i] / a[i][i]);
            for (j = 0; j < p; j++)
            {
                if (j == i)
                    continue;
                n[i] = n[i] - ((a[i][j] / a[i][i]) * m[j]);
                m[i] = n[i];
            }
            cout << "x" << i + 1 << "=" << n[i] << " ";
        }
        cout << "\n";
        q--;
    }
}

int main()
{
    jacob();
    guessSheield();
    return 0;
}
