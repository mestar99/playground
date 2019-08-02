#include <iostream>
#include <functional>
#include <memory>
#include <type_traits>
#include <sstream>
#include <cassert>

class Drawable {
  std::shared_ptr<void> ptr{};

 public:
  template <class T, class = std::enable_if_t<!std::is_convertible<T, Drawable>::value>>
  Drawable(T t) : ptr{std::make_shared<T>(t)}, draw{[this](auto&... args) { static_cast<T*>(ptr.get())->draw(args...); }} {}

  std::function<void(std::ostream&)> draw;
};

class App {
 public:
  explicit App(const Drawable drawable) : drawable{drawable} {}
  void draw(std::ostream& out) const { drawable.draw(out); }

 private:
  const Drawable drawable;
};

struct Null {
  void draw(std::ostream& out) const { out << "NULL"; }
};

struct Square {
  void draw(std::ostream& out) const { out << "Square"; }
};

struct Circle {
  void draw(std::ostream& out) const { out << "Circle"; }
};

int main(int argc, char* argv[]) {
  std::stringstream str{};

  Drawable drawer{ Null{} };

  if(argc > 1)
    drawer = Drawable{ Square{} };
  else
    drawer = Drawable{ Circle{} };

  App example{ drawer } ;
  example.draw(std::cout);
  std::cout << std::endl;
  //assert("Square" == str.str());
}
