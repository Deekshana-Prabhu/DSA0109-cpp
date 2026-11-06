#include <iostream>
using namespace std;

// Returns reference to the highest mark
int& highestMark(int marks[], int size)
{
    int maxIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[maxIndex])
        {
            maxIndex = i;
        }
    }
    return marks[maxIndex];
}
// Dangerous function
int& dangerousFunction()
{
    int x = 50;
    return x;
}
int main()
{
    int marks[5] = {75, 89, 92, 84, 78};

    cout << "Highest mark: "
         << highestMark(marks, 5) << endl;
    highestMark(marks, 5) += 2;
    cout << "After moderation: "
         << highestMark(marks, 5) << endl;
    return 0;
}


