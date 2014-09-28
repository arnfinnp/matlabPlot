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

   Matlab::PlotObject vector("random");
   vector.addVector(vec);
   vector.setColor(Matlab::green);
   vector.setLegend("Dette er en tilfeldig vector");
   vector.setlineWidth(4);

   std::string filename("test");
//   Matlab::WriteFile write(filename);



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
