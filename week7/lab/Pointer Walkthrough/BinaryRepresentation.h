#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdio>
#include <limits>
#include <cstdlib>
//////////////////////////////////////////////////////////////////////////////
//                           Function Definition                            //
//////////////////////////////////////////////////////////////////////////////
/*****************************************************************************
*                    string brep (void * base, size_t sz)                    *
*                                                                            *
* Written By :  M. R. Nowak             Environment : Mac OS X 10.10.5       *
* Date ......:  2017/06/15              Compiler ...: Homebrew GCC 6.3.0_1   *
*****************************************************************************/
std::string brep (void * base, size_t sz)
{
    std::ostringstream os;
    char* b = reinterpret_cast<char*>(base);
    for (int i = 1; i <= sz ; i++) {
        for (int j = 0; j < 8 ; j++) {
            // shifting left using << causes 0's to be shifted from the least significant end (right side), causing bits to fall off from the most significant end (left side); shifting left by j bits is equivalent to multiplying by 2^j.
            // after shifting, we then mask off the highest order bit (shifted value & 0x80)
            // and translate to 0 or 1 with !!
            os << !!((b[sz - i] << j) & 0x80);
        }
    }
    return os.str();
}

std::string brepf (void * base, size_t sz, bool number = true, bool highlow=true)
{
    std::string rep = brep(base, sz);
    std::ostringstream os;
    for (int i = 0; i < rep.size(); i++) {
        os << std::setw(3) << std::setfill('-') << '-';
    }
    os << '-' << std::setfill(' ') << std::endl;
    for (int i = 0; i < rep.size(); i++) {
        os << '|' << std::setw(2) << rep.at(i);
    }
    os << '|' << std::endl;
    for (int i = 0; i < rep.size(); i++) {
        os << std::setw(3) << std::setfill('-') << '-';
    }
    if (number) {
        os << '-' << std::setfill(' ') << std::endl;
        for (int i = (highlow ? rep.size() - 1 : 0) ; (highlow ? (i >= 0) : (i < rep.size())); (highlow ? i-- : i++)) {
            os << '|' << std::setw(2) << i;
        }
        os << '|';
    }
    return os.str();
}

void return_to_continue()
{
    std::cout << "Press [Return] to continue..." << std::endl;
    std::string str; std::getline (std::cin, str);
}

//////////////////////////////////////////////////////////////////////////////