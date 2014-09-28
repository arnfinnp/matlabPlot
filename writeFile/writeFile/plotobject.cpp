#include <plotobject.h>


Matlab::PlotObject::PlotObject(const std::string& name)
   : name_(name)
   , color_("-k")
   , lineWidth_("'LineWidth',1")
{
   init();
}



Matlab::PlotObject::~PlotObject()
{
}



void
Matlab::PlotObject::setColor(const Color& color)
{
   std::string newColor;

   switch(color)
   {
      case blue:
         newColor.append("-b");
         break;
      case green:
         newColor.append("-g");
         break;
      case red:
         newColor.append("-r");
         break;
      case cyan:
         newColor.append("-c");
         break;
      case magenta:
         newColor.append("-m");
         break;
      case yellow:
         newColor.append("-y");
         break;
      case black:
         newColor.append("-k");
         break;
      case white:
         newColor.append("-w");
         break;
      default:
         newColor.append("-k");
   }

   std::string plotStr = os_.str();
   plotStr.replace(plotStr.find(color_),2,newColor);

   std::ostringstream os;
   os << plotStr;

   os_.clear();
   os_ << os.str();
   color_.clear();
   color_.append(newColor);
}



void
Matlab::PlotObject::setLegend(const std::string& legend)
{
   legend_.push_back(legend);
}



void
Matlab::PlotObject::setlineWidth(const int& lineWidth)
{
   std::ostringstream osLW;
   osLW << lineWidth;
   std::string plotStr = os_.str();
   plotStr.replace(plotStr.find("LineWidth")+11,1,osLW.str());

   std::ostringstream os;
   os << plotStr;

   os_.clear();
   os_ << os.str();
}



void
Matlab::PlotObject::init()
{
   os_ << "plot(" << name_ << "_vec"
       << "," << color_
       << "," << lineWidth_
       << ")";
}

void
Matlab::PlotObject::setVector(const std::vector<double> & vec)
{
   std::vector<double>::const_iterator vecIterator;
   for (vecIterator = vec.begin(); vecIterator != vec.end(); ++vecIterator)
   {
       vector_.push_back(*vecIterator);
   }
}
