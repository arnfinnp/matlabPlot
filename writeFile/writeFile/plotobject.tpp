template <typename Type>
void
setVector(const std::vector<Type>& vec)
{
   std::vector<double> tmpVector;
   for (std::size_t iVec = 0; iVec < vec.size(); ++iVec)
   {
      tmpVector.push_back(static_cast<double>(vec[iVec]));
   }

   setVector(tmpVector);
}



template <typename Type>
void
setVector(const arma::Col<Type>& vec)
{
   std::vector<double> tmpVector;
   for (std::size_t iVec = 0; iVec < vec.size(); ++iVec)
   {
      tmpVector.push_back(static_cast<double>(vec(iVec)));
   }

   setVector(tmpVector);
}



template <typename Type>
void
setVector(const arma::Row<Type>& vec)
{
   std::vector<double> tmpVector;
   for (std::size_t iVec = 0; iVec < vec.size(); ++iVec)
   {
      tmpVector.push_back(static_cast<double>(vec(iVec)));
   }

   setVector(tmpVector);
}
