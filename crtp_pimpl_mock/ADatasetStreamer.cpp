
#include "ADatasetStreamer.hpp"

class ADatasetStreamer::Impl
{
  Impl( std::unique_ptr< InterfaceADataset > && dataset )
    : mDataset{ std::move( dataset ) }
  {

  }

  ~Impl() 
  {

  }

  void read()
  {

  }

  void write()
  {

  }

private:
  std::unique_ptr< InterfaceADataset > mDataset;
};

ADatasetStreamer::ADatasetStreamer( std::unique_ptr< InterfaceADataset > && dataset )
  : mImpl{ std::move( dataset ) }
{
  
}

ADatasetStreamer::~ADatasetStreamer()
{
  
}

void ADatasetStreamer::read()
{
  mImpl->read();
}

void ADatasetStreamer::write()
{
  mImpl->write();
}
