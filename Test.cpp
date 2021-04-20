#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <fstream>

using namespace ariel;
ifstream unitsFile{"units.txt"};

TEST_CASE("Operator: +"){
    NumberWithUnits::read_units(unitsFile);
    NumberWithUnits x{10, "km"};
    NumberWithUnits y{222, "m"};
            CHECK_NE((x+212) , y);
            CHECK_EQ(x+y , NumberWithUnits{10.222, "km"});
}

TEST_CASE("Operators: ++, --"){
    NumberWithUnits::read_units(unitsFile);
    NumberWithUnits x{1, "m"};
            CHECK_EQ(x++ , NumberWithUnits{100, "cm"});
            CHECK_EQ(x , NumberWithUnits{101, "cm"});
            CHECK_NE(++x , NumberWithUnits{101, "cm"});
            CHECK_EQ(x , NumberWithUnits{102, "cm"});
            CHECK_NE(x-- , NumberWithUnits{103, "cm"});
            CHECK_EQ(x , NumberWithUnits{101, "cm"});
            CHECK_EQ(--x , NumberWithUnits{100, "cm"});
            CHECK_EQ(x , NumberWithUnits{100, "cm"});
}

TEST_CASE("Operators: +=, -="){
    NumberWithUnits::read_units(unitsFile);
    NumberWithUnits x{10, "kg"};
    NumberWithUnits y{1000, "g"};
            CHECK((x+=y) == NumberWithUnits{11, "kg"});
            CHECK((y+=x) == NumberWithUnits{12000, "g"});
            CHECK((x-=y) == NumberWithUnits{-1, "kg"});
            CHECK((y-=x) == NumberWithUnits{13000, "g"});
            CHECK((y-=x) == NumberWithUnits{14000, "g"});
            CHECK(x == NumberWithUnits{-1, "kg"});
            CHECK(y == NumberWithUnits{14000, "g"});
}

TEST_CASE("Operator: *"){
    NumberWithUnits::read_units(unitsFile);
    NumberWithUnits x{1, "hour"};
    NumberWithUnits y{10, "min"};
            CHECK_EQ(x , (y*6));
            CHECK((x*1.5) == (y*9));
            CHECK_NE(x , (y*7));
}

TEST_CASE("Operators: >, <, >=, <=, ==, != "){
    NumberWithUnits::read_units(unitsFile);
            CHECK_EQ(NumberWithUnits{1, "USD"}, NumberWithUnits{3.33, "ILS"});
            CHECK_EQ(NumberWithUnits{1001, "USD"}, NumberWithUnits{3333.33, "ILS"});
            CHECK_NE(NumberWithUnits{2, "USD"}  , NumberWithUnits{6.60, "ILS"});
            CHECK_NE(NumberWithUnits{1000, "USD"}, NumberWithUnits{3330.33, "ILS"});
            CHECK_NE(NumberWithUnits{1, "USD"} , NumberWithUnits{3.30, "ILS"});
            CHECK_GT(NumberWithUnits{1.5, "USD"}, NumberWithUnits{1, "USD"});
            CHECK_GT(NumberWithUnits{1, "USD"}, NumberWithUnits{3.30, "ILS"});
            CHECK_GT(NumberWithUnits{1, "USD"}, NumberWithUnits{3.33, "ILS"});
            CHECK_LT(NumberWithUnits{1000, "USD"}, NumberWithUnits{1001, "USD"});
            CHECK_LT(NumberWithUnits{1000, "USD"}, NumberWithUnits{3330, "ILS"});
            CHECK_LT(NumberWithUnits{1000, "USD"}, NumberWithUnits{3331, "ILS"});
}

TEST_CASE("Throw") {
    NumberWithUnits::read_units(unitsFile);
    NumberWithUnits n1{1, "km"};
    NumberWithUnits n2{10, "min"};
            CHECK_THROWS(n1 + n2);
}