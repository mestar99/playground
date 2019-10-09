
#ifndef FIXEDSTR_H_
#define FIXEDSTR_H_

#include <array>

template <std::size_t N>
class fixed_string
{
public:
  constexpr fixed_string(char const (&input)[N])
  {
    for(std::size_t i{0}; i < N; ++i) {
      content[i] = input[i];
      if(i == (N-1) && input[i] == 0)
        break;
    }
  }

  constexpr fixed_string(fixed_string const & other)
  {
    for(std::size_t i{0}; i < N; ++i) {
      content[i] = other.content[i];
    }
  }

  constexpr std::size_t size() const
  {
    return content.size();
  }

  constexpr char const * begin() const
  {
    return content.data();
  }

  constexpr char const * end() const
  {
    return content.data() + size();
  }

  constexpr char operator[](std::size_t i) const
  {
    return content[i];
  }

private:
  std::array<char, N> content{};
};

template <>
class fixed_string<0>
{
public:
  constexpr fixed_string(char const *)
  {

  }

  constexpr fixed_string( fixed_string const &)
  {

  }

  constexpr std::size_t size() const
  {
    return 0;
  }

  constexpr char const * begin() const
  {
    return content.data();
  }

  constexpr char const * end() const
  {
    return content.data() + size();
  }

  constexpr char operator[](std::size_t) const
  {
    return 0;
  }

private:
  static constexpr std::array<char, 1> content{0};
};

template <typename CharT, size_t N> fixed_string(CharT const (&)[N]) -> fixed_string<N>;
template <std::size_t N> fixed_string(fixed_string<N>) -> fixed_string<N>;

#endif
