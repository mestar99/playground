
#pragma once

class ADataset
{
public:
  ADataset(int value);

  ~ADataset();
  
  void open();

  int getValue();

private:
  
  int mValue;
};
