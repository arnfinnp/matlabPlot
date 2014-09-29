#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

#include <writefile.h>



Matlab::WriteFile::WriteFile(const std::string& filename,
                             bool               save)
   : fileName_(filename.c_str())
   , save_(save)
{
}



Matlab::WriteFile::~WriteFile()
{
}



void
Matlab::WriteFile::addPlotObject(const PlotObject& object,
                                 uint              figure)
{
   figures_.push_back(std::make_pair(object, figure));
}



void
Matlab::WriteFile::setTitle(const std::string& title,
                            const uint&        figure)
{
   titles_.push_back(std::make_pair(title, figure));
}



void
Matlab::WriteFile::createFile()
{
   std::ostringstream os;
   const std::vector<uint> figureNumbers = findFigureNumbers();
   std::cout << __LINE__ << "\n";

   for (std::size_t i = 0; i < figureNumbers.size(); ++i)
   {
      std::cout << __LINE__ << "\n";
      createFigure(figureNumbers[i], os);
   }
   std::ostringstream fileName;
   fileName << fileName_ << ".m";
   createFile(fileName.str(), os.str());
}



std::vector<uint>
Matlab::WriteFile::findFigureNumbers()
{
   std::vector<uint> figureNumbers;
   std::cout << figures_.size() << std::endl;
   for (std::size_t i = 0; i < figures_.size(); ++i)
   {
//      uint counter = 0;
      const uint figureNumber = figures_[i].second;
      if (std::find(figureNumbers.begin(), figureNumbers.end(), figureNumber) == figureNumbers.end())
         figureNumbers.push_back(figureNumber);

//      for (std::size_t j = 0; j < figureNumbers.size(); ++j)
//      {
//         if (figureNumber == figureNumbers[j])
//         {
//            ++counter;
//         }
//      }
//      if (counter == 0)
//      {
//         figureNumbers.push_back(figureNumber);
//      }
   }

   return figureNumbers;
}



void
Matlab::WriteFile::createFigure(const uint&         figure,
                                std::ostringstream& os)
{
   std::vector<PlotObject> plotObject;
   std::ostringstream fileName;
   std::ostringstream vectors;
   std::ostringstream legend;

   for (std::size_t i = 0; i < figures_.size(); ++i)
   {
      const uint figureNumber = figures_[i].second;
      if (figureNumber == figure)
      {
         PlotObject object = figures_[i].first;
         writeToFile(vectors, object);
         plotObject.push_back(object);
      }
   }

   fileName << fileName_
            << "_figure_" << figure
            << "_" << plotObject[0].getLabel(Matlab::x)
            << "_" << plotObject[0].getLabel(Matlab::y);

   os << fileName.str()  << "\n"
      << "figure(" << figure << ")\n"
      << plotObject[0].getPlotString() << "\n";
   legend << "legend('"
          << plotObject[0].getLegend()
          << "'";
   for (std::size_t i = 1; i < plotObject.size(); ++i)
   {
      os << "hold on"                     << "\n"
         << plotObject[i].getPlotString() << "\n";
      legend << ",'" << plotObject[i].getLegend() << "'";
   }

   legend << ")";
   os << "xlabel('" << plotObject[0].getLabel(Matlab::x) << "')\n"
      << "ylabel('" << plotObject[0].getLabel(Matlab::y) << "')\n";
   os << legend.str() << "\n";

   if (save_)
   {
      os << "print('"
         << fileName.str()
         << "', '-dpng', '-r300')";
   }
   os << "\n\n";
   fileName << ".m";

   createFile(fileName.str(), vectors.str());
}



void
Matlab::WriteFile::createFile(const std::string& fileName,
                              const std::string& content)
{
   std::ofstream printFile(fileName.c_str());
   printFile << content;
   printFile.close();
}



void
Matlab::WriteFile::writeToFile(std::ostringstream& vectors,
                               PlotObject&         object)
{
   {
      // x-axis
      std::vector<double> vectorX = object.getVector(Matlab::x);
      vectors << object.getVectorName(Matlab::x) << "_vec"
              << " = [";

      std::vector<double>::const_iterator vector;
      for(vector = vectorX.begin(); vector != vectorX.end(); ++vector)
      {
         vectors << "\n" << *vector;
      }

      vectors << "\n]\n\n";
   }

   {
      // y-axis
      std::vector<double> vectorY = object.getVector(Matlab::y);
      vectors << object.getVectorName(Matlab::y) << "_vec"
              << " = [";

      std::vector<double>::const_iterator vector;
      for(vector = vectorY.begin(); vector != vectorY.end(); ++vector)
      {
         vectors << "\n" << *vector;
      }

      vectors << "\n]\n\n";
   }
}
