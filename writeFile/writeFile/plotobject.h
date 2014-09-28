#ifndef PLOTOBJECT_H
#define PLOTOBJECT_H

#include <string>
#include <sstream>

#include <armadillo>

namespace Matlab
{
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
      First = blue,
      Last = white
   };

   class PlotObject
   {
   public:
      PlotObject(const std::string&);
      ~PlotObject();

      template <typename Type>
      void addVector(const std::vector<Type>&);
      template <typename Type>
      void addVector(const arma::Col<Type>& vec);
      template <typename Type>
      void addVector(const arma::Row<Type>& vec);

      void setColor(const Color&);
      void setLegend(const std::string&);
      void setlineWidth(const int&);

   protected:
      void init();
      void setVector(const std::vector<double>&);
   private:
//      typedef boost::optional<std::string> Option;
      std::string              name_;
      std::string              color_;
      std::string              lineWidth_;
      std::vector<std::string> legend_;
      std::vector<double>      vector_;

      std::ostringstream os_;
   };
}

#include <plotobject.tpp>

#endif // PLOTOBJECT_H
