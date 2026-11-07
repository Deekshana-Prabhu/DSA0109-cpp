#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int copies;

public:
    // Default constructor
    Book() : Book("Unknown", "Unknown", 0) {}

    // Constructor with title only
    Book(string t) : Book(t, "Unknown", 1) {}

    // Parameterized constructor
    Book(string t, string a, int c)
        : title(t), author(a), copies(c)
    {
        if (copies < 0)
        {
            copies = 0;
            cout << "Invalid copies. Set to 0.\n";
        }
    }

    // Display function
    void display() const
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Copies: " << copies << endl;
        cout << "------------------\n";
    }
};

int main()
{
    Book b1;
    Book b2("C++ Programming");
    Book b3("Python Basics", "John", 5);
    Book b4("Java", "David", -3);

    b1.display();
    b2.display();
    b3.display();
    b4.display();

    return 0;
}
