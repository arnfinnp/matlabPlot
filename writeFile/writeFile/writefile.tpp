template <typename Type>
void
Matlab::WriteFile::addArmaCol(const arma::Col<Type>&)
{
}



template <typename Type>
void
Matlab::WriteFile::addArmaRow(const arma::Row<Type>&)
{
}



template <typename Type>
void
Matlab::WriteFile::addVector(const std::vector<Type>& vec)
{
   std::vector<double> tmpVector;
   for(std::size_t iVec = 0; iVec < vec.size(); ++iVec)
   {
      tmpVector.push_back(static_cast<double>(vec[iVec]));
   }

   setVector(tmpVector);
}
