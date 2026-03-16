#include <iostream>
#include <iomanip>
#include <cstring>
#include "Employee.h"
#include "Utils.h"

using namespace std;

namespace seneca {

Employee::Employee() {
    m_name = nullptr;
    m_empNo = 0;
    m_salary = 0.0;
}

Employee::Employee(const char* name, size_t empNo, double salary) {
    m_name = ut.alocpy(name);
    m_empNo = empNo;
    m_salary = salary;
}

Employee::~Employee() {
    delete[] m_name;
}

double Employee::salary() const {
    return m_salary;
}

istream& Employee::read(istream& istr) {

    char name[1025];

    istr.getline(name, 1024, ',');
    delete[] m_name;
    m_name = ut.alocpy(name);

    istr >> m_empNo;
    istr.ignore();

    istr >> m_salary;
    istr.ignore();

    return istr;
}

ostream& Employee::write(ostream& ostr) const {

    ostr << "| "
         << left << setw(15)
         << (m_name ? m_name : "")
         << " | ";

    ostr << right << setw(6)
         << setfill('0') << m_empNo
         << setfill(' ')
         << " | ";

    ostr << setw(6)
         << fixed << setprecision(0)
         << m_salary
         << " | ";

    return ostr;
}

ostream& Employee::title(ostream& ostr) const {

    ostr << "| Name            | Emp No | $alary |";

    return ostr;
}

ostream& operator<<(ostream& ostr, const Employee& E) {
    return E.write(ostr);
}

istream& operator>>(istream& istr, Employee& E) {
    return E.read(istr);
}

}
