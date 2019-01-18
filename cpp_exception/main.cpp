#include <iostream>
#include <exception>
#include <stdexcept>

class MyException : public std::exception
{
public:
  virtual ~MyException()
  {

  }

  virtual const char * what() const noexcept
  {
    return "My Custom Exception";
  }
};

class MyRuntimeException : public std::runtime_error
{
public:
  MyRuntimeException()
    : std::runtime_error{"My Custom Runtime Exception"}
  {

  }

  virtual ~MyRuntimeException()
  {

  }
};

int main() {
  try {
    throw std::exception{};
  }
  catch(std::exception & e) {
    std::cout << "1 - Caught exception: \"" << e.what() << "\""<< std::endl;
  }

  try {
    throw MyException{};
  }
  catch(std::exception & e) {
    std::cout << "2 - Caught exception: \"" << e.what() << "\""<< std::endl;
  }

  try {
    throw MyRuntimeException{};
  }
  catch(std::exception & e) {
    std::cout << "3 - Caught exception: \"" << e.what() << "\""<< std::endl;
  }

  try {
    throw MyRuntimeException{};
  }
  catch(std::runtime_error & e) {
    std::cout << "4 - Caught runtime_error: \"" << e.what() << "\""<< std::endl;
  }

  try {
    throw MyException{};
  }
  catch(std::runtime_error & e) {
    std::cout << "5 - Caught runtime_error: \"" << e.what() << "\""<< std::endl;
  }
  catch(...) {
    std::cout << "5 - Didn't catch runtime_error" << std::endl;
  }

  return 0;
}
