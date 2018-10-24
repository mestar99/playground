
#include "InterfaceADatasetImpl.hpp"

#include <iostream>

InterfaceADatasetImpl::InterfaceADatasetImpl(int value)
  : dataset{ value }
{
  std::cout << "InterfaceADatasetImpl::InterfaceADatasetImpl(int)" << std::endl;
}

InterfaceADatasetImpl::~InterfaceADatasetImpl()
{
  std::cout << "InterfaceADatasetImpl::~InterfaceADatasetImpl()" << std::endl;
}

void InterfaceADatasetImpl::open()
{
  std::cout << "InterfaceADatasetImpl::open()" << std::endl;

  dataset.open();
}

int InterfaceADatasetImpl::getValue()
{
  return dataset.getValue();
}
