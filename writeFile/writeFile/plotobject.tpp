template <typename Type>
void
Matlab::PlotObject::addVector(const std::vector<Type>& vec,
                              const Axis& axis)
{
   std::vector<double> tmpVector;
   for (std::size_t iVec = 0; iVec < vec.size(); ++iVec)
   {
      tmpVector.push_back(static_cast<double>(vec[iVec]));
   }
   setVector(tmpVector, axis);
}



template <typename Type>
void
Matlab::PlotObject::addVector(const std::vector<Type>& vec,
                              const Axis& axis,
                              const std::string& name)
{
   std::vector<double> tmpVector;
   for (std::size_t iVec = 0; iVec < vec.size(); ++iVec)
   {
      tmpVector.push_back(static_cast<double>(vec[iVec]));
   }
   setVector(tmpVector, axis);
   setVectorName(name, axis);
}



template <typename Type>
void
Matlab::PlotObject::addVector(const arma::Col<Type>& vec,
                              const Axis& axis)
{
   std::vector<double> tmpVector;
   for (std::size_t iVec = 0; iVec < vec.size(); ++iVec)
   {
      tmpVector.push_back(static_cast<double>(vec(iVec)));
   }

   setVector(tmpVector, axis);
}



template <typename Type>
void
Matlab::PlotObject::addVector(const arma::Col<Type>& vec,
                              const Axis& axis,
                              const std::string& name)
{
   std::vector<double> tmpVector;
   for (std::size_t iVec = 0; iVec < vec.size(); ++iVec)
   {
      tmpVector.push_back(static_cast<double>(vec(iVec)));
   }

   setVector(tmpVector, axis);
   setVectorName(name, axis);
}



template <typename Type>
void
Matlab::PlotObject::addVector(const arma::Row<Type>& vec,
                              const Axis& axis)
{
   std::vector<double> tmpVector;
   for (std::size_t iVec = 0; iVec < vec.size(); ++iVec)
   {
      tmpVector.push_back(static_cast<double>(vec(iVec)));
   }

   setVector(tmpVector, axis);
}



template <typename Type>
void
Matlab::PlotObject::addVector(const arma::Row<Type>& vec,
                              const Axis& axis,
                              const std::string& name)
{
   std::vector<double> tmpVector;
   for (std::size_t iVec = 0; iVec < vec.size(); ++iVec)
   {
      tmpVector.push_back(static_cast<double>(vec(iVec)));
   }

   setVector(tmpVector, axis);
   setVectorName(name, axis);
}
