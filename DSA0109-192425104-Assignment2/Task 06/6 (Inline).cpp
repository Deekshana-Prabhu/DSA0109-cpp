#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

inline int inlineAdd(int a, int b)
{
    return a + b;
}
int normalAdd(int a, int b)
{
    return a + b;
}
int main()
{
    volatile long long result = 0;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < 10000000; i++)
    {
        result = result + inlineAdd(i, 2);
    }
    auto end = high_resolution_clock::now();
    cout << "Inline Time: "
         << duration_cast<microseconds>(
                end - start).count()
         << " microseconds\n";
    start = high_resolution_clock::now();
    for (int i = 0; i < 10000000; i++)
    {
        result = result + normalAdd(i, 2);
    }
    end = high_resolution_clock::now();
    cout << "Normal Time: "
         << duration_cast<microseconds>(
                end - start).count()
         << " microseconds\n";
    return 0;
}



