#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <writefile.h>


namespace
{
   namespace Local
   {
      std::string getFilename(const int&         idx,
                              const std::string& fileName);
      std::string getName(const std::string& fileName);
   }
}


Matlab::WriteFile::WriteFile(const std::string& filename)
   : fileName_(filename.c_str())
{
}



Matlab::WriteFile::~WriteFile()
{
}



void
Matlab::WriteFile::createFile()
{
   std::ostringstream os;
   os << "plot_"
      << fileName_
      << ".m";

   std::ofstream printFile(os.str().c_str());

   Vectors::const_iterator vectors;
   int idx = 0;
   for (vectors = vectors_.begin(); vectors != vectors_.end(); ++vectors)
   {
      std::string fileName = Local::getFilename(idx, fileName_);
      writeToFile(fileName, *vectors);
      printFile << Local::getName(fileName) << "\n";
      ++idx;
   }

   printFile << "\nh = figure(1)\n";
   for (int iPlots = 0; iPlots < idx; ++iPlots)
   {
      std::string name = Local::getName(Local::getFilename(iPlots, fileName_));
      printFile << "plot(" << name << "_vec" << ")\n"
                << "hold on;\n";
      std::cout << name << std::endl;
   }

   printFile << "hold off;";
   printFile.close();
}



void
Matlab::WriteFile::setVector(const std::vector<double>& vec)
{
   vectors_.push_back(vec);
}



void
Matlab::WriteFile::writeToFile(const std::string&         fileName,
                               const std::vector<double>& vec)
{
   std::ofstream outputFile(fileName.c_str());

   outputFile << Local::getName(fileName) << "_vec"
              << " ="
              << "\n[";

   std::vector<double>::const_iterator vector;
   for(vector = vec.begin(); vector != vec.end(); ++vector)
   {
      outputFile << "\n" << *vector;
   }

   outputFile << "\n]";
}



std::string
Local::getFilename(const int&         idx,
                   const std::string& fileName)
{
   std::ostringstream os;
   os << fileName
      << std::setfill('0') << std::setw(3) << idx
      << ".m";

   return os.str();
}



std::string
Local::getName(const std::string& fileName)
{
   std::string name = fileName;
   name.erase(name.end()-2,name.end());

   return name;
}
