#include <plotobject.h>


Matlab::PlotObject::PlotObject()
   : nameX_("x")
   , nameY_("y")
   , xLabel_("x")
   , yLabel_("y")
   , color_("'-k'")
   , lineWidth_("'LineWidth',1")
   , legend_("xy")
{
}



Matlab::PlotObject::~PlotObject()
{
}



void
Matlab::PlotObject::setAxisLabel(const std::string& labelName,
                                 const Axis &       axis)
{
   if (axis == Axis::x)
   {
      xLabel_.clear();
      xLabel_.append(labelName);
   }
   else
      if (axis == Axis::y)
      {
         yLabel_.clear();
         yLabel_.append(labelName);
      }
}


void
Matlab::PlotObject::setColor(const Color& color)
{
   std::string newColor;

   switch(color)
   {
      case blue:
         newColor.append("'-b'");
         break;
      case green:
         newColor.append("'-g'");
         break;
      case red:
         newColor.append("'-r'");
         break;
      case cyan:
         newColor.append("'-c'");
         break;
      case magenta:
         newColor.append("'-m'");
         break;
      case yellow:
         newColor.append("'-y'");
         break;
      case black:
         newColor.append("'-k'");
         break;
      case white:
         newColor.append("'-w'");
         break;
      case random:
         newColor.append("'Color',[rand,rand,rand]");
         break;
      default:
         newColor.append("'-k'");
   }

   color_.clear();
   color_.append(newColor);
}



void
Matlab::PlotObject::setLegend(const std::string& legend)
{
   legend_.clear();
   legend_.append(legend);
}



void
Matlab::PlotObject::setlineWidth(const int& lineWidth)
{
   lineWidth_.clear();
   std::ostringstream os;
   os << "'LineWidth'," << lineWidth;
   lineWidth_.append(os.str());
}



std::string
Matlab::PlotObject::getLegend()
{
   return legend_;
}



std::string
Matlab::PlotObject::getLabel(const Axis& axis)
{
   if (axis == Axis::x)
   {
      return xLabel_;
   }
   else
      if (axis == Axis::y)
      {
         return yLabel_;
      }
}



std::string
Matlab::PlotObject::getPlotString()
{
   std::ostringstream os;
   init(os);
   return os.str();
}



std::vector<double>
Matlab::PlotObject::getVector(const Axis& axis)
{
   if (axis == Axis::x)
   {
      if (vectorX_.size() == 0 &&
          vectorY_.size() > 0)
      {
         for (std::size_t i = 0; i < vectorY_.size(); ++i)
         {
            vectorX_.push_back(static_cast<double>(i));
         }
      }

      return vectorX_;
   }
   else
      if (axis == Axis::y)
      {
         if (vectorX_.size() > 0 &&
             vectorY_.size() == 0)
         {
            for (std::size_t i = 0; i < vectorX_.size(); ++i)
            {
               vectorY_.push_back(static_cast<double>(i));
            }
         }

         return vectorY_;
      }
}



std::string
Matlab::PlotObject::getVectorName(const Axis& axis)
{
   if (axis == Axis::x)
   {
      return nameX_;
   }
   else
      if (axis == Axis::y)
      {
         return nameY_;
      }
}



void
Matlab::PlotObject::init(std::ostringstream& os)
{
   if (vectorX_.size() > 0 &&
       vectorY_.size() == 0)
   {
      os << "plot("
          << nameX_     << "_vec,"
          << color_     << ","
          << lineWidth_
          << ")";
   }
   else
      if (vectorX_.size() == 0 &&
          vectorY_.size() > 0)
      {
         os << "plot("
             << nameY_     << "_vec,"
             << color_     << ","
             << lineWidth_
             << ")";
      }
      else
      {
         os << "plot("
             << nameX_     << "_vec,"
             << nameY_     << "_vec,"
             << color_     << ","
             << lineWidth_
             << ")";
      }

}

void
Matlab::PlotObject::setVector(const std::vector<double> & vec,
                              const Axis& axis)
{
   std::vector<double>::const_iterator vecIterator;
   for (vecIterator = vec.begin(); vecIterator != vec.end(); ++vecIterator)
   {
      if (axis == Axis::x)
      {
         vectorX_.push_back(*vecIterator);
      }
      else
         if (axis == Axis::y)
         {
            vectorY_.push_back(*vecIterator);
         }
   }
}



void
Matlab::PlotObject::setVectorName(const std::string& name,
                                  const Axis& axis)
{
   if (axis == Axis::x)
   {
      nameX_.clear();
      nameX_.append(name);
   }
   else
      if (axis == Axis::y)
      {
         nameY_.clear();
         nameY_.append(name);
      }
}
