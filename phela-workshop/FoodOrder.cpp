// Name: [Your Name]
// Seneca Email: [Your Email]
// Seneca Student ID: [Your Student ID]
// Date: [Completion Date]
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#include <iostream>
#include <iomanip>
#include <cstring>
#include "FoodOrder.h"

namespace seneca {
    double g_taxrate;
    double g_dailydiscount;

    FoodOrder::FoodOrder() : m_price(0), m_isDailySpecial(false) {
        m_customerName[0] = '\0';
        m_orderDescription[0] = '\0';
    }

    void FoodOrder::read(std::istream& in) {
        if (in.good()) {
            in.get(m_customerName, 11, ',');
            in.ignore();
            in.get(m_orderDescription, 26, ',');
            in.ignore();
            in >> m_price;
            in.ignore();
            char isSpecial;
            in >> isSpecial;
            in.ignore();
            m_isDailySpecial = (isSpecial == 'Y');
        }
    }

    void FoodOrder::display() const {
        static int counter = 1;
        std::cout << std::left << std::setw(2) << counter << ". ";
        if (m_customerName[0] == '\0') {
            std::cout << "No Order" << std::endl;
        }
        else {
            double priceWithTax = m_price * (1 + g_taxrate);
            std::cout << std::setw(10) << m_customerName << "|"
                << std::setw(25) << m_orderDescription << "|"
                << std::setw(12) << std::fixed << std::setprecision(2) << priceWithTax;
            if (m_isDailySpecial) {
                std::cout << "|" << std::setw(13) << std::right << std::setprecision(2) << (priceWithTax - g_dailydiscount);
            }
            else {
                std::cout << "|";
            }
            std::cout << std::endl;
        }
        ++counter;
    }
}
