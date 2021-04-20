#include <iostream>
#include <fstream>
#include <sstream>
#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel {

    void NumberWithUnits::read_units(ifstream& file){}

    ostream& operator <<(ostream& out, const NumberWithUnits& a){
        return out<< a.value << "[" << a.unit << "]";
    }
    istream& operator >>(istream& in, NumberWithUnits& a){
        string str;
        return in >> a.value >> str >> a.unit;
    }

    NumberWithUnits operator +(const NumberWithUnits& n1, const NumberWithUnits& n2) {
        return n1;
    }
    NumberWithUnits operator +(const NumberWithUnits& n, double a) {
        return n;
    }
    NumberWithUnits operator -(const NumberWithUnits& n1, const NumberWithUnits& n2) {
        return n1;
    }
    NumberWithUnits operator -(const NumberWithUnits& n) {
        return n;
    }
    NumberWithUnits operator +=(NumberWithUnits& n1, const NumberWithUnits& n2) {
        return n1;
    }
    NumberWithUnits operator -=(NumberWithUnits& n1, const NumberWithUnits& n2) {
        return n1;
    }
    NumberWithUnits operator ++(NumberWithUnits& n) {
        return n;
    }
    NumberWithUnits operator ++(NumberWithUnits& n, int num) {
        return n;
    }
    NumberWithUnits operator --(NumberWithUnits& n) {
        return n;
    }
    NumberWithUnits operator --(NumberWithUnits& n, int num) {
        return n;
    }
    NumberWithUnits operator *(NumberWithUnits& n, double num) {
        return n;
    }
    NumberWithUnits operator *(double num, NumberWithUnits& n) {
        return n;
    }

    bool operator >(const NumberWithUnits& n1, const NumberWithUnits& n2){
        return true;
    }
    bool operator <(const NumberWithUnits& n1, const NumberWithUnits& n2){
        return true;
    }
    bool operator >=(const NumberWithUnits& n1, const NumberWithUnits& n2){
        return true;
    }
    bool operator <=(const NumberWithUnits& n1, const NumberWithUnits& n2){
        return true;
    }
    bool operator ==(const NumberWithUnits& n1, const NumberWithUnits& n2){
        return true;
    }
    bool operator !=(const NumberWithUnits& n1, const NumberWithUnits& n2){
        return true;
    }
}