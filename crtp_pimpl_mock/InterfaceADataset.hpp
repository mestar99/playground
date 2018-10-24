
#pragma once

template < typename Implementation >
class InterfaceADataset
{
public:
  void open()
  {
    impl().open();
  }

  int getValue()
  {
    return impl().getValue();
  }

private:
  Implementation & impl() {
    return *static_cast<Implementation*>(this);
  }
};

