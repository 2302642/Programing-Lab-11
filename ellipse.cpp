///////////////////////////////////////////////////////////////////////////////
// File Name:      ellipse.cpp
//
// Author:         Najih
// Email:          2302642@sit.singaporetech.edu.sg
//
// Description:    Methods to perform some processing on containers of
//                 type std::vector<Shape*>.
///////////////////////////////////////////////////////////////////////////////
#include "ellipse.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

int Ellipse::count = 0;                                                 // Initialize the static member count
Ellipse::Ellipse(std::string& data) : Shape(data) {                     // constructor for ellipse
    
    std::istringstream line(data);                                      // parsing data to extract ellipse-specific information
    char pattern;
    if (!(line >> pattern)) {return;}                                   // skiping the first character
        
    std::string border_color, fill_color;
    line >> border_color >> fill_color;                                 // skiping the border color and fill color
   
    int center_x, center_y;    char comma;
    line >> center_x >> comma >> center_y;                              // parsing the center coordinates

    int semi_major, semi_minor;
    line >> semi_major >> semi_minor;                                   // parsing the lengths of semi-major and semi-minor axes

    center = Point{center_x, center_y};                                 // seting ellipse-specific data   
    this->a = semi_major;
    this->b = semi_minor;
    count++;                                                            // incrementing the count of ellipses created
}

Ellipse::~Ellipse() { count--; }                                        // destructor foe elipse and decrement the count of ellipses created
int Ellipse::getA() const { return a;     }                             // accessor for a-length of ellipse
int Ellipse::getB() const { return b;     }                             // accessor for b-length of ellipse
int Ellipse::getCount()   { return count; }                             // static function to get the total number of ellipse shapes
void Ellipse::print_details() const {                                   // printing details of Ellipse shape
    Shape::print_details();                                             // printing common details from base class
    std::cout << "Type = Ellipse Shape\n" << "Center = " << center.x << "," << center.y << "\n" << "a-length = " << a << "\n"  "b-length = " << b << "\n" << std::endl;
}

Point Ellipse::getCenter() const { return center; }                     // accessor for center of Ellipse shape
double Ellipse::getArea() const  { return M_PI * a * b; }               // calculating the area of Ellipse shape
