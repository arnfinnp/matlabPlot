#ifndef WRITEFILE_H
#define WRITEFILE_H

#include <armadillo>
#include <string>
#include <vector>

namespace Matlab
{
   class WriteFile
   {
   public:
      WriteFile(const std::string& filename);
      ~WriteFile();

      void setLineWidth(const int&);
      void addLegend(const std::string&);
      void addAxisLabel(const std::string& xLabel,
                        const std::string& yLabel);
      void createFile();

      template <typename Type>
      void addArmaCol(const arma::Col<Type>&);
      template <typename Type>
      void addArmaRow(const arma::Row<Type>&);
      template <typename Type>
      void addVector(const std::vector<Type>&);

   protected:
      void setVector(const std::vector<double>& );
      void writeToFile(const std::string&         fileName,
                       const std::vector<double>& vector);

   private:
      typedef std::vector<std::vector<double> > Vectors;
      Vectors     vectors_;
      const std::string fileName_;

      const std::string legend_;
      const std::string xLabel_;
      const std::string yLabel_;
   };
}

#include <writefile.tpp>

#endif // WRITEFILE_H
