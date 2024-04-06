///////////////////////////////////////////////////////////////////////////////
// File Name:      process.cpp
//
// Author:         Najih
// Email:          2302642@sit.singaporetech.edu.sg
//
// Description:    Methods to perform some processing on containers of
//                 type std::vector<Shape*>.
///////////////////////////////////////////////////////////////////////////////
#include "process.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void parse_file(std::ifstream& input, std::vector<Shape*>& vs, std::vector<Shape*>& ves, std::vector<Shape*>& vps) {            // Function to parse a file containing shape records and populate vector containers
    std::string data;
    while (std::getline(input, data)) {                                                                                         // Read each data from the input file
        char temp = data[0];
        data = data.substr(2);                                                                                                // Remove the first two characters (shape identifier and space)
        if (temp == 'E') {                                                                                                    // if shape is ellipse create the appropriate shape object for elipse
            Shape *p = new Ellipse(data);                                                                                     // create a new elips object
            vs.push_back(p);                                                                                                  // adding the shape to the vector of all shapes
            ves.push_back(p);                                                                                                 // adding the shape to the vector of ellipse shapes
        } 
        else if (temp == 'P') {                                                                                               // if shape is polygon create the appropriate shape object for polygon
            Shape *p = new Polygon(data);                                                                                     // creating a new polygon object
            vs.push_back(p);                                                                                                  // adding the shape to the vector of all shapes
            vps.push_back(p);                                                                                                 // adding the shape to the vector of polygon shapes
        } 
        else { break; }
    }
}

void print_records(std::vector<Shape*> const& vs) { for (const auto& shape : vs) { shape->print_details(); } }                // Function to print details of all shapes in a vector container
void print_stats(const std::vector<Shape*>& shape_vector) {                                                                   // Function to compute and print statistics about shapes in a vector container
    double total_area = 0.0;
    for (const auto& shape : shape_vector) {  total_area += shape->getArea(); }                                               // calculating the total area of all shapes in the vector

    double mean_area = total_area / shape_vector.size();                                                                      // calculating the mean area of all shapes

    std::cout << "Number of shapes = " << shape_vector.size() << std::endl;
    std::cout << "The mean of the areas = " << mean_area << std::endl;

    std::vector<Shape*> sorted_shapes = shape_vector;                                                                         // creating a copy of the vector and sort it by shape area in ascending order
    auto compareAreas = [](Shape* a, Shape* b) { return a->getArea() < b->getArea(); };                                       // sorting by area in ascending order
    std::sort(sorted_shapes.begin(), sorted_shapes.end(), compareAreas);

    std::cout << "The sorted list of shapes (id,center,area) in ascending order of areas:" << std::endl;                      // printing the sorted list of shapes with their IDs, centers, and areas
    for (const auto& shape : sorted_shapes) {
        Point center = shape->getCenter();
        std::cout << shape->getId() << "," << center.x << "," << center.y << "," << shape->getArea() << std::endl;
    }
}

void cleanup(std::vector<Shape*>& vs, std::vector<Shape*>& ves, std::vector<Shape*>& vps) {                                   // Function to deallocate memory and clear vector containers
  
  for (Shape *ps : vs){ delete ps; }                                                                                          // deleting memory previously allocated by operator new

  vs.clear();
  ves.clear();
  vps.clear();
}
