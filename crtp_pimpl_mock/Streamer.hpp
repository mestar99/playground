
#pragma once

class Streamer
{
public:
  virtual ~Streamer() = 0;

  virtual void read() = 0;
                                               
  virtual void write() = 0;
};
