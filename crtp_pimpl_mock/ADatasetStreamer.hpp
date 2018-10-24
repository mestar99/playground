
#pragma once

#include "Streamer.hpp"
#include "InterfaceADataset.hpp"

#include <memory>

class ADatasetStreamer : public Streamer
{
public:
  ADatasetStreamer( std::unique_ptr< InterfaceADataset > dataset);

  ~ADatasetStreamer() override;

  void read() override;
  
  void write() override;
  
private:
  class Impl;
  
  std::unique_ptr< Impl > mImpl;
};
