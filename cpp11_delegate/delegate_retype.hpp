#pragma once

#ifndef DELEGATE_HPP
#define DELEGATE_HPP

template <typename T>
class delegate;

template <typename R, typename ...A>
class delegate<R (A...)>
{
private: 
  using stub_ptr_type = R (*)(void *, A&&...);

  delegate(void * const o, stub_ptr_type const m) noexcept
  : object_ptr_{o},
    stub_ptr_{m}
  {

  }

public:
  delegate() = default;
  
  delegate(delegate const &) = default;

  delegate(delegate &&) = default;

  delegate(::std::nullptr_t const) noexcept
  : delegate{}
  {

  }

  template< typename C, typename = typename ::std::enable_if< ::std::is_class<C>{} >::type >
  explicit delegate(C const * const o) noexcept
  : object_ptr_{const_cast<C *>(o)}
  {

  }

  template< typename C, typename = typename ::std::enable_if< ::std::is_class<C>{}>::type >
  explicit delegate(C const & o) noexcept
  : object_ptr_{const_cast<C *>(&o)}
  {

  }

  template< typename C >
  delegate(C * const object_ptr, R (C::* const method_ptr)(A...))
  {
    *this = from(object_ptr, method_ptr);
  }

  template< typename C >
  delegate(C * const object_ptr, R (C::* const method_ptr)(A...) const)
  {
    *this = from(object_ptr, method_ptr);
  }

  template< typename C >
  delegate(C & object, R (C::* const method_ptr)(A...))
  {
    *this = from(object, method_ptr);
  }

  template< typename C >
  delegate(C const & object, R (C::* const method_ptr)(A...) const)
  {
    *this = from(object, method_ptr);
  }

  template< typename T, typename = typename ::std::enable_if< !::std::is_same<delegate, typename ::std::decay<T>::type>{}>::type >
  delegate( T && f )
  : store_{operator new(sizeof(typename ::std::decay<T>::type)), functor_deleter< typename ::std::decay<T>::type >},
  store_size_{sizeof(typename ::std::decay<T>::type)}
  {
    using functor_type = typename ::std::decay<T>::type;
    
    new (store_.get()) functor_type(::std::forward<T>(f));

    object_ptr_ = store_.get();
    stub_ptr_ = functor_stub<functor_type>;
    deleter_ = deleter_stub<functor_type>;
  }

  delegate& operator=(delegate const &) = default;

  delegate& operator=(delegate&& ) = default;
                                                                                                                              
};

#endif
