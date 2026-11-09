
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
    int* p = NULL;

    try
    {
        p = new int(100);

        throw runtime_error("Error occurred");
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    delete p;

    return 0;
}



