//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                            PRINTVISUAL.H                                 //
//                                                                          //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.10.5     //
//  Date ......: 2017/04/02              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#ifndef PRINTVISUAL_H
#define PRINTVISUAL_H

//////////////////////////////////////////////////////////////////////////////
// Includes                                                                 //
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

//////////////////////////////////////////////////////////////////////////////
// Begin namespace vis                                                       //
//////////////////////////////////////////////////////////////////////////////
namespace vis {

//////////////////////////////////////////////////////////////////////////////
// Declarations                                                             //
//////////////////////////////////////////////////////////////////////////////
// including vis::center definition so that entire library can be used by
//   #include(ing) this header file
std::string center (const std::string &str, const int col_width)
{
    // quick and easy (but error-prone) implementation
    int padl = (col_width - str.length()) / 2;
    int padr = (col_width - str.length()) - padl;
    std::string strf = std::string(padl, ' ') + str + std::string(padr, ' ');
    return strf;
}

//////////////////////////////////////////////////////////////////////////////
// Templated Fuctions Definitions                                           //
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//     template<typename T> std::ostream& pprint(T*& ptr, const std::string //
//         &name = "", std::ostream& os = std::cout)                        //
//                                                                          //
//       Input : Pointer of type T passed-by-reference, optional const      //
//               std::string passed by reference containing name its        //
//               identifier (for diagram labeling), and std::ostream        //
//               passed-by-reference in which the diagram will be output    //
//                                                                          //
//      Output : Provided an int* i initialized as int* i = new int{1},     //
//               and std::string "i", the following output will drawn to    //
//               the ostream& os.                                           //
//                        i                      *i                         //
//                 .---------------.       .---------------.                //
//                 | 0x7fbbb9c04c50|------>|       1       |                //
//                 '---------------'       '---------------'                //
//                 ( 0x7fff52a9b3b8)       ( 0x7fbbb9c04c50)                //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.10.5     //
//  Date ......: 2017/04/02              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////

template<typename T>
std::ostream& print(T*& ptr, const std::string &name = "",
	std::ostream& os = std::cout, int address_size = 16)
{
    // names
    os << ' ' << center(name, address_size - 1) << ' ';
    os << std::setw(address_size / 2) << std::setfill(' ') << ' ';
    os << center("*" + name, address_size - 1) << std::endl;
    // box tops
    os << '.' << std::setw(address_size) << std::setfill('-') << '.';
    os << std::setfill(' ') << std::setw(address_size / 2);
    os << '.' << std::setw(address_size) << std::setfill('-') << '.' << std::endl;
    // box middles (includes object values)
    os << '|' << std::setw(address_size - 1) << std::setfill(' ') << ptr << '|';
    os << std::setw(address_size / 2 - 1) << std::setfill('-') << '>';
    os << '|' << center(std::to_string(*ptr), address_size - 1) << '|' << std:: endl;
    // box bottoms
    os << '\'' << std::setw(address_size) << std::setfill('-') << '\'';
    os << std::setfill(' ') << std::setw(address_size / 2);
    os << '\'' << std::setw(address_size) << std::setfill('-') << '\'' << std::endl;
    // addresses
    os << '(' << std::setw(address_size - 1) << std::setfill(' ') << &ptr << ')';
    os << std::setw(address_size / 2 - 1) << std::setfill(' ') << ' ';
    os << '(' << std::setw(address_size - 1) << ptr << std::setfill(' ') << ')' << std::endl;
    return os;
}

//////////////////////////////////////////////////////////////////////////////
//    template<typename T> std::ostream& pprint(T**& ptr, const std::string //
//         &name = "", std::ostream& os = std::cout)                        //
//                                                                          //
//       Input : T**& ptr, optional const std::string passed by reference   //
//               containing name of its identifier (for diagram labeling),  //
//               and std::ostream&os in which the diagram will be output    //
//                                                                          //
//      Output : Provided an int** ii is initialized int** ii = &i where    //
//               i is initialized as int* i = new int{1} and an             //
//               std::string "ii", the following output will drawn to the   //
//               ostream& os.                                               //
//           ii                      *ii                    **ii            //
//    .---------------.       .---------------.       .---------------.     //
//    | 0x7fff5a7593b8|------>| 0x7faa5a500000|------>|       1       |     //
//    '---------------'       '---------------'       '---------------'     //
//    ( 0x7fff5a7593b0)       ( 0x7fff5a7593b8)       ( 0x7faa5a500000)     //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.10.5     //
//  Date ......: 2017/04/02              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////

template<typename T>
std::ostream& print(T**& ptr, const std::string &name = "", std::ostream& os = std::cout, int address_size = 16)
{
    // names
    os << ' ' << center(name, address_size - 1) << ' ';
    os << std::setw(address_size / 2) << std::setfill(' ') << ' ';
    os << center("*" + name, address_size - 1) << ' ';
    os << std::setw(address_size / 2) << std::setfill(' ') << ' ';
    os << center("**" + name, address_size - 1) << ' ' << std::endl;
    // box tops
    os << '.' << std::setw(address_size) << std::setfill('-') << '.';
    os << std::setfill(' ') << std::setw(address_size / 2);
    os << '.' << std::setw(address_size) << std::setfill('-') << '.';
    os << std::setfill(' ') << std::setw(address_size / 2);
    os << '.' << std::setw(address_size) << std::setfill('-') << '.' << std::endl;
    // box middles (includes object values)
    os << '|' << std::setw(address_size - 1) << std::setfill(' ') << ptr << '|';
    os << std::setw(address_size / 2 - 1) << std::setfill('-') << '>';
    os << '|' << std::setfill(' ') << std::setw(address_size - 1) << *ptr << '|';
    os << std::setw(address_size / 2 - 1) << std::setfill('-') << '>';
    os << '|' << center(std::to_string(**ptr), address_size - 1) << '|' << std:: endl;
    // box bottoms
    os << '\'' << std::setw(address_size) << std::setfill('-') << '\'';
    os << std::setfill(' ') << std::setw(address_size / 2);
    os << '\'' << std::setw(address_size) << std::setfill('-') << '\'';
    os << std::setfill(' ') << std::setw(address_size / 2);
    os << '\'' << std::setw(address_size) << std::setfill('-') << '\'' << std::endl;
    // addresses
    os << '(' << std::setw(address_size - 1) << std::setfill(' ') << &ptr << ')';
    os << std::setw(address_size / 2 - 1) << std::setfill(' ') << ' ';
    os << '(' << std::setw(address_size - 1) << ptr << std::setfill(' ') << ')';
    os << std::setw(address_size / 2 - 1) << std::setfill(' ') << ' ';
    os << '(' << std::setw(address_size - 1) << *ptr << std::setfill(' ') << ')' << std:: endl;

    return os;
}

//////////////////////////////////////////////////////////////////////////////
//    template<typename T> std::ostream& print(const std::vector<T>& vect,  //
//        const std::string &name = "", std::ostream& os = std::cout, int   //
//        field_size = 20)                                                  //
//                                                                          //
//       Input :                                                            //
//                                                                          //
//      Output :                                                            //
//                             v                                            //
//                   .-------------------.                                  //
//                   | [0] |     18      |                                  //
//                   +-------------------+                                  //
//                   |  0x7fe430500010   |                                  //
//                   '-------------------'                                  //
//                              |                                           //
//                   .-------------------.                                  //
//                   | [1] |     21      |                                  //
//                   +-------------------+                                  //
//                   |  0x7fe430500014   |                                  //
//                   '-------------------'                                  //
//                              |                                           //
//                   .-------------------.                                  //
//                   | [2] |     24      |                                  //
//                   +-------------------+                                  //
//                   |  0x7fe430500018   |                                  //
//                   '-------------------'                                  //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.10.5     //
//  Date ......: 2017/04/02              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
std::ostream& print(const std::vector<T>& vect, const std::string &name = "", std::ostream& os = std::cout, int field_size = 20)
{
    os << ' ' << center(name.substr(0, field_size), field_size) << ' ' << std::endl;
    if (vect.size() == 0)
        os << ' ' << std::setw(field_size) << center("--", field_size - 1) << ' ' << std::setfill(' ') << std::endl;

    for (int i = 0 ; i < vect.size() ; ++i) {
        // top box
        os << '.' << std::setw(field_size) << std::setfill('-') << '.' << std::setfill(' ') << std::endl;
        // middle box
        os << '|' << std::setw(field_size / 4) << center("[" + std::to_string(i) + "]", field_size / 4 - 1) << '|' << center(std::to_string(vect.at(i)), field_size * 3 / 4 - 2) << '|' << std::endl;
        // bottom box
        os << '+' << std::setw(field_size) << std::setfill('-') << '+' << std::setfill(' ') << std::endl;
        // addresses
        std::ostringstream oss; oss << &(vect.at(i)); std::string address = oss.str();
        os << '|' << center(address, field_size - 1) << '|' << std::endl;
        // bottom addresses
        os << '\'' << std::setw(field_size) << std::setfill('-') << '\'' << std::setfill(' ') << std::endl;
        // link
        if (i < vect.size() - 1)
            os << ' ' << std::setw(field_size) << center("|", field_size - 1) << ' ' << std::setfill(' ') << std::endl;
    }
    return os;
}

//////////////////////////////////////////////////////////////////////////////
//    template<typename T> std::ostream& print(const std::vector<T>*& vect, //
//        const std::string &name = "", std::ostream& os = std::cout        //
//                                                                          //
//       Input :                                                            //
//                                                                          //
//      Output :                                                            //
//                             vp                      *vp                  //
//                      .---------------.       .---------------.           //
//                      | 0x7fe3d8402440|------>|       +-------|--|        //
//                      '---------------'       '---------------'  |        //
//                      ( 0x7fff5d94e438)       ( 0x7fe3d8402440)  |        //
//                                                                 |        //
//                                 |-------------------------------|        //
//                      .-------------------.                               //
//                      | [0] |     29      |                               //
//                      +-------------------+                               //
//                      |  0x7fe3d8400080   |                               //
//                      '-------------------'                               //
//                                 |                                        //
//                      .-------------------.                               //
//                      | [1] |     34      |                               //
//                      +-------------------+                               //
//                      |  0x7fe3d8400084   |                               //
//                      '-------------------'                               //
//                                 |                                        //
//                      .-------------------.                               //
//                      | [2] |     89      |                               //
//                      +-------------------+                               //
//                      |  0x7fe3d8400088   |                               //
//                      '-------------------'                               //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.10.5     //
//  Date ......: 2017/04/02              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
std::ostream& print(std::vector<T>*& vect, const std::string &name = "", std::ostream& os = std::cout)
{
    int address_size = 16;
    int field_size = 20;
    // pointer stuff

    // names
    os << ' ' << center(name, address_size - 1) << ' ';
    os << std::setw(address_size / 2) << std::setfill(' ') << ' ';
    os << center("*" + name, address_size - 1) << std::endl;
    // box tops
    os << '.' << std::setw(address_size) << std::setfill('-') << '.';
    os << std::setfill(' ') << std::setw(address_size / 2);
    os << '.' << std::setw(address_size) << std::setfill('-') << '.' << std::endl;
    // box middles (includes object values)
    os << '|' << std::setw(address_size - 1) << std::setfill(' ') << vect << '|';
    os << std::setw(address_size / 2 - 1) << std::setfill('-') << '>';
    os << '|' << std::setw(address_size / 2) << std::setfill(' ') << '+' << std::setw(address_size / 2) << std::setfill('-') << '|' << std::setw(3) << std::setfill('-') << '|' << std:: endl;
    // box bottoms
    os << '\'' << std::setw(address_size) << std::setfill('-') << '\'';
    os << std::setfill(' ') << std::setw(address_size / 2);
    os << '\'' << std::setw(address_size) << std::setfill('-') << '\'' << std::setw(3) << std::setfill(' ') << '|' << std:: endl;
    // addresses
    os << '(' << std::setw(address_size - 1) << std::setfill(' ') << &vect << ')';
    os << std::setw(address_size / 2 - 1) << std::setfill(' ') << ' ';
    os << '(' << std::setw(address_size - 1) << vect << std::setfill(' ') << ')' << std::setw(3) << std::setfill(' ') << '|' << std::endl;
    os << std::setw(field_size * 2 + 4) << std::setfill(' ') << '|' << std::endl;
    // vector contents

    os << ' ' << std::setw(field_size / 2 + 1) << "|" << std::setw(field_size + 12) << std::setfill('-') << '|' << std::endl;
    if (vect->size() == 0)
        os << ' ' << std::setw(field_size) << center("--", field_size - 1) << ' ' << std::setfill(' ') << std::endl;

    for (int i = 0 ; i < vect->size() ; ++i) {
        // top box
        os << '.' << std::setw(field_size) << std::setfill('-') << '.' << std::setfill(' ') << std::endl;
        // middle box
        os << '|' << std::setw(field_size / 4) << center("[" + std::to_string(i) + "]", field_size / 4 - 1) << '|' << center(std::to_string(vect->at(i)), field_size * 3 / 4 - 2) << '|' << std::endl;
        // bottom box
        os << '+' << std::setw(field_size) << std::setfill('-') << '+' << std::setfill(' ') << std::endl;
        // addresses
        std::ostringstream oss; oss << &(vect->at(i)); std::string address = oss.str();
        os << '|' << center(address, field_size - 1) << '|' << std::endl;
        // bottom addresses
        os << '\'' << std::setw(field_size) << std::setfill('-') << '\'' << std::setfill(' ') << std::endl;
        // link
        if (i < vect->size() - 1)
            os << ' ' << std::setw(field_size) << center("|", field_size - 1) << ' ' << std::setfill(' ') << std::endl;
    }
    return os;
}

//////////////////////////////////////////////////////////////////////////////
//    template<typename T> std::ostream& print(std::vector<T*>& vect, const //
//        std::string &name = "", std::ostream& os = std::cout, int         //
//        field_size = 20)                                                  //
//                                                                          //
//       Input :                                                            //
//                                                                          //
//      Output :                                                            //
//                                  vptr                                    //
//                       .-----------------------.                          //
//                       |  [0] | 0x7fe3d8600000 |                          //
//                       +-----------------------+                          //
//                       |    0x7fe3d8402160     |                          //
//                       '-----------------------'                          //
//                                    |                                     //
//                       .-----------------------.                          //
//                       |  [1] | 0x7fe3d8600010 |                          //
//                       +-----------------------+                          //
//                       |    0x7fe3d8402168     |                          //
//                       '-----------------------'                          //
//                                                                          //
//  Written By : Michael R Nowak         Environment : Mac OS X 10.10.5     //
//  Date ......: 2017/04/02              Compiler ...: Homebrew GCC 6.3.0_1 //
//////////////////////////////////////////////////////////////////////////////
template<typename T>
std::ostream& print(std::vector<T*>& vect, const std::string &name = "", std::ostream& os = std::cout, int field_size = 24)
{

    os << ' ' << center(name.substr(0, field_size), field_size) << ' ' << std::endl;
    if (vect.size() == 0)
        os << ' ' << std::setw(field_size) << center("--", field_size - 1) << ' ' << std::setfill(' ') << std::endl;

    for (int i = 0 ; i < vect.size() ; ++i) {
        // top box
        os << '.' << std::setw(field_size) << std::setfill('-') << '.' << std::setfill(' ') << std::endl;
        // middle box
        std::ostringstream oss; oss << (vect.at(i)); std::string address1 = oss.str(); oss.str(""); oss.clear();
        os << '|' << std::setw(field_size / 4) << center("[" + std::to_string(i) + "]", field_size / 4 - 1) << '|' << center(address1, field_size * 3 / 4 - 2) << '|' << std::endl;
        // bottom box
        os << '+' << std::setw(field_size) << std::setfill('-') << '+' << std::setfill(' ') << std::endl;
        // addresses
        oss << &(vect.at(i)); std::string address2 = oss.str(); oss.str(""); oss.clear();
        os << '|' << center(address2, field_size - 1) << '|' << std::endl;
        // bottom addresses
        os << '\'' << std::setw(field_size) << std::setfill('-') << '\'' << std::setfill(' ') << std::endl;
        // link
        if (i < vect.size() - 1)
            os << ' ' << std::setw(field_size) << center("|", field_size - 1) << ' ' << std::setfill(' ') << std::endl;
    }
    return os;

}
std::ostream& boxstr(std::string value, std::string address, const std::string &name = "", std::ostream& os = std::cout, int field_size = 24)
{
    int address_size = address.size();
    os << ' ' << center(name, address_size - 1) << ' ' << std::endl;
    // box top
    os << '.' << std::setw(address_size) << std::setfill('-') << '.' << std::endl;
    // box middles (includes object values)
    os << '|' << std::setw(address_size - 1) << std::setfill(' ') << value << '|' << std::endl;
    // box bottoms
    os << '\'' << std::setw(address_size) << std::setfill('-') << '\'' << std::endl;
    // addresses
    os << '(' << std::setw(address_size - 1) << std::setfill(' ') << address << ')' << std::endl;
	return os;
}
//////////////////////////////////////////////////////////////////////////////
// close namespace vis                                                      //
//////////////////////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////////////////
#endif
