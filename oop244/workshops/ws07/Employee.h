#ifndef SENECA_EMPLOYEE_H
#define SENECA_EMPLOYEE_H

#include <iostream>

namespace seneca {

class Employee {
    char* m_name{};
    size_t m_empNo{};
    double m_salary{};

public:
    Employee();
    Employee(const char* name, size_t empNo, double salary);
    ~Employee();

    double salary() const;

    std::istream& read(std::istream& istr = std::cin);
    std::ostream& write(std::ostream& ostr = std::cout) const;
    std::ostream& title(std::ostream& ostr = std::cout) const;
};

std::ostream& operator<<(std::ostream& ostr, const Employee& E);
std::istream& operator>>(std::istream& istr, Employee& E);

}

#endif
