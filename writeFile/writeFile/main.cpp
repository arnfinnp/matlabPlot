#include <armadillo>
#include <iostream>
#include <string>
#include <vector>

#include <plotobject.h>
#include <writefile.h>

int main(int argv, char* argc[])
{
   static_cast<void>(argv);
   static_cast<void>(argc);

   std::vector<int> vec;
   vec.push_back(1);
   vec.push_back(2);
   vec.push_back(3);
   vec.push_back(4);
   vec.push_back(5);

   std::vector<double> vec2;
   vec2.push_back(1.4);
   vec2.push_back(2.54);
   vec2.push_back(3.123);
   vec2.push_back(4.990);
   vec2.push_back(5.89123);

   std::vector<double> vec3;
   vec3.push_back(341.4);
   vec3.push_back(22.54);
   vec3.push_back(53.123);
   vec3.push_back(64.990);
   vec3.push_back(15.89123);

   Matlab::PlotObject vector;
   vector.addVector(vec, Matlab::x, "u");
   vector.addVector(vec2, Matlab::y, "v");
   vector.setColor(Matlab::random);
   vector.setLegend("vector");
   vector.setlineWidth(4);

   Matlab::PlotObject vector2;
   vector2.addVector(vec3, Matlab::x, "a");
   vector2.addVector(vec2, Matlab::y, "b");
   vector2.setColor(Matlab::blue);
   vector2.setLegend("vector2");
   vector2.setlineWidth(2);

   Matlab::PlotObject vector3;
   vector3.addVector(vec3, Matlab::x, "iii");
   vector3.addVector(vec, Matlab::y, "jjj");
   vector3.setColor(Matlab::green);
   vector3.setLegend("vector3");
   vector3.setlineWidth(3);

   Matlab::PlotObject vector4;
   vector4.addVector(vec2, Matlab::x, "z");
   vector4.addVector(vec, Matlab::y, "y");
   vector4.setColor(Matlab::green);
   vector4.setLegend("vector4");
   vector4.setlineWidth(1);

   Matlab::PlotObject vector5;
   vector5.addVector(vec3, Matlab::y, "z");
   vector5.addVector(vec3, Matlab::x, "y");
   vector5.setColor(Matlab::green);
   vector5.setLegend("vector5");
   vector5.setlineWidth(5);

   std::string filename("test");
   Matlab::WriteFile write(filename, true);
   write.addPlotObject(vector, 2);
   write.addPlotObject(vector2,1);
   write.addPlotObject(vector3,2);
   write.addPlotObject(vector4,3);
   write.addPlotObject(vector5,1);
   write.setTitle("test1", 1);
   write.setTitle("test2", 2);
   write.setTitle("test3", 3);
   write.createFile();



//   std::vector<double> vec2;
//   vec2.push_back(5.123);
//   vec2.push_back(2.1245);
//   vec2.push_back(3.435345);
//   vec2.push_back(4.3647);
//   vec2.push_back(5.675673);

//   write.addVector<int>(vec);
//   write.addVector<double>(vec2);
//   write.createFile();
//   std::cout << "test";

   return 0;
}
