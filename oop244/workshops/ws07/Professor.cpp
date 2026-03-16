#include <iostream>
#include <iomanip>
#include <cstring>
#include "Professor.h"
#include "Utils.h"

using namespace std;

namespace seneca {

Professor::Professor() : Employee() {
    m_subject = nullptr;
    m_sections = 0;
}

Professor::Professor(const char* name,
                     const char* subject,
                     int sections,
                     size_t empNo,
                     double salary)
    : Employee(name, empNo, salary) {

    m_subject = ut.alocpy(subject);
    m_sections = sections;
}

Professor::~Professor() {
    delete[] m_subject;
}

double Professor::devPay() const {
    return salary() * 0.01 * m_sections;
}

istream& Professor::read(istream& istr) {

    char subject[1025];

    Employee::read(istr);

    istr.getline(subject, 1024, ',');

    delete[] m_subject;
    m_subject = ut.alocpy(subject);

    istr >> m_sections;

    return istr;
}

ostream& Professor::write(ostream& ostr) const {

    Employee::write(ostr);

    char subject[21]{};

    if (m_subject) {
        strncpy(subject, m_subject, 20);
        subject[20] = '\0';
    }

    ostr << left << setw(20) << subject;

    ostr << " | ";

    ostr << right << setw(5) << m_sections;

    ostr << " | ";

    ostr << fixed << setprecision(2)
         << setw(8)
         << devPay();

    ostr << " |";

    return ostr;
}

ostream& Professor::title(ostream& ostr) const {

    Employee::title(ostr);

    ostr << " Teaching Subject     | Sec # | $Dev Pay |";

    return ostr;
}

ostream& operator<<(ostream& ostr, const Professor& P) {
    return P.write(ostr);
}

istream& operator>>(istream& istr, Professor& P) {
    return P.read(istr);
}

}
