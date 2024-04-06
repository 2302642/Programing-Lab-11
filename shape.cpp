///////////////////////////////////////////////////////////////////////////////
// File Name:      shape.cpp
//
// Author:         Najih
// Email:          2302642@sit.singaporetech.edu.sg
//
// Description:    Methods to perform some processing on containers of
//                 type std::vector<Shape*>.
///////////////////////////////////////////////////////////////////////////////
#include "shape.hpp"
#include <iostream>
#include <sstream>

int Shape::count = 0;                                                                                                                       // initializing the static member count
Shape::Shape(std::string& data) {                                                                                                          // constructor fore shape
    std::istringstream input(data);                                                                                                          // parsing data to extract shape information
    std::string border_color, fill_color;
    if (!(input >> border_color >> fill_color)) {return;}                                                                                     // skiping the border and fill colors and parse the remaining information
    border = border_color;                                                                                                                  // assigning the border color
    fill = fill_color;                                                                                                                      // assigning the fill color
    id = ++count;                                                                                                                           // assigning a unique ID to the shape
}

Shape::~Shape() { count--; }                                                                                                                // destructor for shap and decrement the count of shapes when destroyed
int Shape::getId() const { return id; }                                                                                                     // accessor for shape's id
std::string Shape::getBorder() const { return border; }                                                                                     // accessor for shape's border color
std::string Shape::getFill() const { return fill; }                                                                                         // accessor for shape's fill color
int Shape::getCount() { return count; }                                                                                                     // static member function to get the count of shapes
void Shape::print_details() const {  std::cout << "Id = " << id << "\n" << "Border = " << border << "\n" << "Fill = " << fill << "\n"; }    // printing details of shape
