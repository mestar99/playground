
#pragma once

#include <unordered_map>

template <typename T>
class mi_tls_repository;

template <typename T>
class mi_tls : protected mi_tls_repository<T>
{
public:
  mi_tls()
  {
  }

  mi_tls(T const & value)
  {
    this->store(reinterpret_cast<uintptr_t>(this), value);
  }

  mi_tls<T> & operator=(T const & value)
  {
    this->store(reinterpret_cast<uintptr_t>(this), value);
    return *this;
  }

  operator T()
  {
    return this->load(reinterpret_cast<uintptr_t>(this));
  }

  ~mi_tls()
  {
    this->remove(reinterpret_cast<uintptr_t>(this));
  }
};

template <typename T>
class mi_tls_repository
{
protected:
  void store(uintptr_t instance, T value)
  {
    repository[instance] = value;
  }

  T load(uintptr_t instance)
  {
    return repository[instance];
  }

  void remove(uintptr_t instance)
  {
    repository.erase(instance);
  }

private:
  static thread_local std::unordered_map<uintptr_t, T> repository;
};

template <typename T>
thread_local std::unordered_map<uintptr_t, T> mi_tls_repository<T>::repository;
