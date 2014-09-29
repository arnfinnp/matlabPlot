#ifndef PLOTOBJECT_H
#define PLOTOBJECT_H

#include <utility>
#include <string>
#include <sstream>
#include <vector>

#include <armadillo>

namespace Matlab
{
   typedef std::vector<double> Vec;
   enum Color
   {
      blue,
      green,
      red,
      cyan,
      magenta,
      yellow,
      black,
      white,
      random
   };

   enum Axis
   {
      x,
      y
   };

   class PlotObject
   {
   public:
      PlotObject();
      ~PlotObject();

      template <typename Type>
      void addVector(const std::vector<Type>&, const Axis&);
      template <typename Type>
      void addVector(const std::vector<Type>&, const Axis&, const std::string&);
      template <typename Type>
      void addVector(const arma::Col<Type>& vec, const Axis&);
      template <typename Type>
      void addVector(const arma::Col<Type>& vec, const Axis&, const std::string&);
      template <typename Type>
      void addVector(const arma::Row<Type>& vec, const Axis&);
      template <typename Type>
      void addVector(const arma::Row<Type>& vec, const Axis&, const std::string&);

      void setAxisLabel(const std::string&, const Axis&);
      void setColor(const Color&);
      void setLegend(const std::string&);
      void setlineWidth(const int&);

      std::string         getLegend();
      std::string         getLabel(const Axis&);
      std::string         getPlotString();
      std::vector<double> getVector(const Axis&);
      std::string         getVectorName(const Axis&);

   protected:
      void init(std::ostringstream& os);
      void setVector(const std::vector<double>&, const Axis&);
      void setVectorName(const std::string&, const Axis&);
   private:
      std::string         nameX_;
      std::string         nameY_;
      std::string         xLabel_;
      std::string         yLabel_;
      std::string         color_;
      std::string         lineWidth_;
      std::string         legend_;
      std::vector<double> vectorX_;
      std::vector<double> vectorY_;
   };
}

#include <plotobject.tpp>

#endif // PLOTOBJECT_H
