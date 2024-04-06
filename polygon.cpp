///////////////////////////////////////////////////////////////////////////////
// File Name:      polygon.cpp
//
// Author:         Najih
// Email:          2302642@sit.singaporetech.edu.sg
//
// Description:    Methods to perform some processing on containers of
//                 type std::vector<Shape*>.
///////////////////////////////////////////////////////////////////////////////
#include "polygon.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

int Polygon::count = 0;                                                     // Initialize the static member count
Polygon::Polygon(std::string& data) : Shape(data) {
    std::istringstream line(data);                                          // parsing data to extract polygon-specific information
    char pattern;
    if (!(line >> pattern)) { return; }                                     // skiping the first character
        
    std::string border_color, fill_color;
    line >> border_color >> fill_color;                                     // skiping the border color and fill color
    
    double x, y;                                                            // setting temporary variables to store coordinates
    char comma;
    while (line >> x >> comma >> y) {                                       // reading pairs of doubles as vertices and Create a Point object and add it to the vertices vector
        vertices.push_back(Point{static_cast<int>(x), static_cast<int>(y)}); 
        }  
    count++;                                                                // incrementing the count of polygons created
}


Polygon::~Polygon() { count--; }                                            // destructor fo polygon decrementing the count of polygons when destroyed
std::vector<Point>& Polygon::getVertices() { return vertices; }             // accessor for the vertices of the polygon
int Polygon::getCount() { return count; }                                   // static function to get the total number of polygon shapes

void Polygon::print_details() const {                                       // printing details of Polygon shape
    
    Shape::print_details();                                                 // calling the print_details() function of the base class Shape
    std::cout << "Type = Polygon Shape\n";
    std::cout << "Vertices = ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        std::cout << vertices[i].x << "," << vertices[i].y;
        if (i < vertices.size() - 1) { std::cout << " "; } 
        else { std::cout << " \n"; }                                        // adding newdata after the last vert of each polygon
    }
    std::cout << "\n";                                                      // adding an extra newdata between polygons
}

Point make_point(int x, int y) {                                            // defining the make_point function outside of any class or function
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

Point Polygon::getCenter() const {                                          // function to calculate the center of the polygon
    int total_x = 0, total_y = 0;
    for (const auto& vert : vertices) {
        total_x += vert.x;
        total_y += vert.y;
    }
    return make_point(static_cast<int>(total_x / vertices.size()), static_cast<int>(total_y / vertices.size()));    // calculating the average of x and y coordinates to find the center
}

double Polygon::getArea() const {                                           // function to calculate the area of the polygon
    double area = 0.0;
    int z = vertices.size() - 1;
    for (size_t i = 0; i < vertices.size(); ++i) {
        area += (vertices[z].x + vertices[i].x) * (vertices[z].y - vertices[i].y);
        z = i;
    }
    return -0.5 * area;                                                     // taking the absolute value and divide by 2 to get the area
}
