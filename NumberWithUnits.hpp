#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace ariel {
    class NumberWithUnits{
        double value;
        string unit;
    public:
        NumberWithUnits(double val, string unit){
            value = val;
            this->unit = unit;
        }
        ~NumberWithUnits(){}
        static void read_units(ifstream& file);

        friend ostream& operator <<(ostream& out, const NumberWithUnits& a);
        friend istream& operator >>(istream& in, NumberWithUnits& a);

        friend NumberWithUnits operator +(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend NumberWithUnits operator +(const NumberWithUnits& n, double a);
        friend NumberWithUnits operator -(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend NumberWithUnits operator -(const NumberWithUnits& n);
        friend NumberWithUnits operator +=(NumberWithUnits& n1, const NumberWithUnits& n2);
        friend NumberWithUnits operator -=(NumberWithUnits& n1, const NumberWithUnits& n2);
        friend NumberWithUnits operator ++(NumberWithUnits& n);
        friend NumberWithUnits operator ++(NumberWithUnits& n, int num);
        friend NumberWithUnits operator --(NumberWithUnits& n);
        friend NumberWithUnits operator --(NumberWithUnits& n, int num);

        friend NumberWithUnits operator *(NumberWithUnits& n, double num);
        friend NumberWithUnits operator *(double num, NumberWithUnits& n);

        friend bool operator >(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend bool operator <(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend bool operator >=(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend bool operator <=(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend bool operator ==(const NumberWithUnits& n1, const NumberWithUnits& n2);
        friend bool operator !=(const NumberWithUnits& n1, const NumberWithUnits& n2);
    };
}