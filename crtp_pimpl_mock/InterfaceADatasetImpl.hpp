
#pragma once

#include "InterfaceADataset.hpp"
#include "ADataset.hpp"

class InterfaceADatasetImpl : public InterfaceADataset< InterfaceADatasetImpl >
{
public:
  InterfaceADatasetImpl(int value);

  ~InterfaceADatasetImpl();

  void open();

  int getValue();

private:
  ADataset dataset;
};
