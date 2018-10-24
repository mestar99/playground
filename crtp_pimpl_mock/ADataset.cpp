
#include "ADataset.hpp"

#include <iostream>

ADataset::ADataset(int value)
  : mValue{ value }
{
  std::cout << "ADataset::ADataset(int): " << mValue << std::endl;
}

ADataset::~ADataset()
{
  std::cout << "ADataset::~ADataset()" << std::endl;
}

void ADataset::open()
{
  std::cout << "ADataset::open()" << std::endl;
}

int ADataset::getValue()
{
  std::cout << "ADataset::getValue()" << std::endl;

  return mValue;
}
