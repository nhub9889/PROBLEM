
//http://www.upcoder.xyz/'index.php/2758c5706eb2233474801dfd162f79ac43a391d8e9cfe1414f69735a503b48d4/lvypJ''0y3.0SdSKOr&0z5'nnOMy!Rmp'SsSgpeRv'wwjmBw'EC89'feM-h0!_K-4Nbk5-iCkfiM9LA_7i56.g'1~C9$JP2*OrdA:T*~~PA:1s!:pRpo6MK$4?2/d5e2747e980ca6964f268ee1c55bad92d2594d35894e39e5a75f82e83122ce28
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Employee
{
    int id;
    string firstName, lastName;
    double salary;
public:
    Employee() {};
    Employee(int _id, string _firstName, string _lastName, double _salary) {
        id = _id;
        firstName = _firstName;
        lastName = _lastName;
        salary = _salary;
    }
    int getID() {
        return id;
    }
    string getFirstName() {
        return firstName;
    }
    string getLastName()
    {
        return lastName;
    }
    string getName() {
        return firstName + " " + lastName;    
    }
    double getSalary() {
        return salary;
    }
    void setSalary(double _salary) {
        salary = _salary;
    }
    double getAnnualSalary() {
        return 12*salary;
    }
    double raiseSalary(double percent) {
        return salary + salary*percent/100;
    }
    string toString() {
        stringstream ss;
        ss << fixed << setprecision(2) << "$" << salary;
        return "Employee[id=" + to_string(id) + ",name=" + getName() + ",salary=" + ss.str() + "]";
    }
    friend istream& operator >> (istream &is, Employee &e) {
        is >> e.id >> e.firstName >> e.lastName >> e.salary;
        return is;
    }
    friend ostream& operator << (ostream &os, Employee e) {
        os << e.toString();
        os << endl;
        return os;
    }
    // toan tu hau to
    void operator++(int) {
        salary *= 1.1;
    }
    void operator--(int) {
        salary *= 0.9;
    }
    // toan tu tien to
    void  operator ++ () {
        salary *= 1.1;
    }
    void operator -- () {
        salary *= 0.9;
    }
    friend void operator + (Employee &e, float k) {
        e.salary += k;
    }
    friend void operator - (Employee &e, float k) {
        e.salary -= k;
    }
    bool operator < (Employee e) {
        return getAnnualSalary() < e.getAnnualSalary();
    }
    bool operator > (Employee e)
    {
        return getAnnualSalary() > e.getAnnualSalary();
    }
    bool operator == (Employee e)
    {
        return getAnnualSalary() == e.getAnnualSalary();
    }
    bool operator != (Employee e)
    {
        return getAnnualSalary() != e.getAnnualSalary();
    }
};
int main()
{
    Employee *e = new Employee[2];
    cin >> e[0] >> e[1];
    float a, b;
    cin >> a >> b;
    // float x = e[0].raiseSalary(a);
    // float y = e[1].raiseSalary(b);
    // e[0].setSalary(x);
    // e[1].setSalary(y);
    cout << e[0] << e[1];    
    if (e[0] == e[1]) cout << "BANG NHAU";
    else if (e[0] < e[1]) cout << "NHO HON";
    else cout << "LON HON";
    cout << endl;
    
    e[0] - a;
    e[1]--;
    e[1] + b;
    cout << "$" << fixed << setprecision(2) << e[0].getSalary() << endl;
    cout << "$" << fixed << setprecision(2) << e[1].getSalary();
    delete[]e;
}