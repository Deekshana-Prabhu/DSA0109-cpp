
#include <iostream>
#include <stdexcept>
using namespace std;

class ClaimError : public runtime_error
{
public:
    ClaimError(const string& message)
        : runtime_error(message)
    {
    }
};

double approve(double billed, double cover)
{
    if (billed < 0 || cover < 0)
        throw invalid_argument("negative amount");

    if (billed > cover)
        throw ClaimError("exceeds cover");

    return billed;
}

double settle(double billed, double cover)
{
    try
    {
        return approve(billed, cover);
    }
    catch (const ClaimError& e)
    {
        cout << "audit: " << e.what() << endl;
        throw;
    }
}

int main()
{
    double cases[3][2] = {
        {40000, 50000},
        {60000, 50000},
        {-1, 50000}
    };

    for (int i = 0; i < 3; i++)
    {
        try
        {
            double paid = settle(cases[i][0], cases[i][1]);
            cout << "approved " << paid << endl;
        }
        catch (const ClaimError& e)
        {
            cout << "claim rejected: " << e.what() << endl;
        }
        catch (const exception& e)
        {
            cout << "error: " << e.what() << endl;
        }
    }

    return 0;
}

