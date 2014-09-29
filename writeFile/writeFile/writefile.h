#ifndef WRITEFILE_H
#define WRITEFILE_H

#include <armadillo>
#include <map>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

#include <plotobject.h>

namespace Matlab
{
   class WriteFile
   {
   public:
      WriteFile(const std::string& filename,
                bool               save = false);
      ~WriteFile();

      void addPlotObject(const PlotObject& object,
                         uint              figure);
      void setTitle(const std::string& title,
                    const uint&        figure);
      void createFile();

   protected:
      void createFigure(const uint&         figure,
                        std::ostringstream& os);
      void createFile(const std::string& fileName,
                      const std::string& content);
      std::vector<uint> findFigureNumbers();
      void setVector(const std::vector<double>& );
      void writeToFile(std::ostringstream& vectors,
                       PlotObject&   object);
   private:
      typedef std::pair<PlotObject, uint>  Figure;
      typedef std::vector<Figure>          Figures;
      typedef std::pair<std::string, uint> Title;
      typedef std::vector<Title>           Titles;
      Figures     figures_;
      Titles      titles_;
      std::string fileName_;
      bool        save_;
   };
}

#endif // WRITEFILE_H
