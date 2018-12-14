
#pragma once

#include <iostream>

namespace ns2 {
  class TypeBInfoHandle
  {
  public:
    template <class S >
    class HasMetadata {
      template <class T > static std::true_type hasMetadata( typename T::MetadataFactory * );

      template <class T > static std::false_type hasMetadata( ... );

    public:
      static constexpr bool value = std::is_same< decltype( hasMetadata<S>(0) ), std::true_type >::value;
    };

    template <class tValueType, class... tArgs >
    typename std::enable_if< HasMetadata< tValueType >::value, typename tValueType::MetadataFactory::value_type >::type
    add( std::string const & pName, tArgs&&... pArgs) {
      std::cout << "Metadata" << std::endl;

      typename tValueType::MetadataFactory::value_type val{123};

      return val;
    }

    template <class tValueType>
    typename std::enable_if< !HasMetadata< tValueType >::value >::type
    add( std::string const & pName ) {
      std::cout << "No metadata" << std::endl;
    }
  };
}

namespace ns1 {
  class Stream {
  private:
    ns2::TypeBInfoHandle bInfoHandle;

  public:

    ns2::TypeBInfoHandle & getTypeBInfo() {
      return bInfoHandle;
    }

    ns2::TypeBInfoHandle const & getTypeBInfo() const {
      return bInfoHandle;
    }

    template <class tValueType, class... tArgs >
    auto
    add( std::string const & pName, tArgs&&... pArgs ) ->

    /*
      typename std::result_of< decltype( &ns2::TypeBInfoHandle::add< tValueType, tArgs... >)( ns2::TypeBInfoHandle *,
                                                                                              std::string const &,
                                                                                              tArgs&&... ) >::type
    */

      typename std::result_of< decltype(&ns2::TypeBInfoHandle::add< tValueType, tArgs...>)(ns2::TypeBInfoHandle, std::string const &, tArgs&&...) >::type
    {
      return getTypeBInfo().add< tValueType >( pName, std::forward<tArgs>(pArgs)... );
    }
  };
}
