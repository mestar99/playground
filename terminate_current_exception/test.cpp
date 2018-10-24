
#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>

void my_terminate_handler()
{
  std::cout << "Inside terminate handler!" << std::endl;

  std::exception_ptr eptr = std::current_exception();

  try {
    if( eptr ) {
      std::rethrow_exception(eptr);
    }

    std::cout << "Terminate called outside of stack unwinding" << std::endl;
  }
  catch(const std::exception& e) {
    std::cout << "Caught exception \"" << e.what() << "\"" << std::endl;
  }

  std::abort();
}

int main()
{
  std::set_terminate( my_terminate_handler );

  std::string().at(1);
  //std::terminate();

  return 0;
}
