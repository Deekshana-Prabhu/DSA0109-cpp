#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int id;
    string phone;
public:
    Person(string n, int i, string p)
        : name(n), id(i), phone(p) {}
};
class Student : virtual public Person
{
protected:
    string programme;
    double cgpa;
public:
    Student(string n, int i, string p,
            string pr, double c)
        : Person(n, i, p), programme(pr), cgpa(c) {}
};
class Staff : virtual public Person
{
protected:
    string department;
    double salary;
public:
    Staff(string n, int i, string p,
          string d, double s)
        : Person(n, i, p), department(d), salary(s) {}
};
class TeachingAssistant : public Student, public Staff
{
public:
    TeachingAssistant(string n, int i, string p,
                      string pr, double c,
                      string d, double s)
        : Person(n, i, p),
          Student(n, i, p, pr, c),
          Staff(n, i, p, d, s) {}
};
class ResearchScholar : public Student
{
private:
    double fellowship;
public:
    ResearchScholar(string n, int i, string p,
                    string pr, double c, double f)
        : Person(n, i, p),
          Student(n, i, p, pr, c),
          fellowship(f) {}
};
int main()
{
    TeachingAssistant ta("Kavya", 101, "9876543210",
                         "AIML", 9.2, "CSE", 30000);
    ResearchScholar rs("Arun", 102, "9876501234",
                       "AIML", 9.5, 15000);
    cout << "Teaching Assistant created" << endl;
    cout << "Research Scholar created" << endl;
    return 0;
}
