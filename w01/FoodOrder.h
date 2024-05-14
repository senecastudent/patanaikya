// Name: [Your Name]
// Seneca Email: [Your Email]
// Seneca Student ID: [Your Student ID]
// Date: [Completion Date]
// I declare that this submission is the result of my own work and I only copied the code that my professor provided to complete my workshops and assignments. This submitted piece of work has not been shared with any other student or 3rd party content provider.

#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H

#include <iostream>

namespace seneca {
    extern double g_taxrate;
    extern double g_dailydiscount;

    class FoodOrder {
        char m_customerName[11];
        char m_orderDescription[26];
        double m_price;
        bool m_isDailySpecial;
    public:
        FoodOrder();
        void read(std::istream& in);
        void display() const;
    };
}

#endif
