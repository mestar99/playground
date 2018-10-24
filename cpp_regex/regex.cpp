
#include <iostream>
#include <regex>
#include <string>
#include <map>
#include <tuple>

enum class LogSeverity
{
  DEFAULT = 0,
    DEBUG = 100,
    INFO = 200,
    NOTICE = 300,
    WARNING = 400,
    ERROR = 500,
    CRITICAL = 600,
    ALERT = 700,
    EMERGENCY = 800,
    UNKNOWN = -1
    };

void labelFiller( std::string const & str, std::map< std::string, std::string > & map )
{
  if( str.empty() )
    return;

  std::regex re{ "^'([^']+)'='([^']+)'((?:,'[^']+'='[^']+')*)$" };
  std::smatch re_match;

  std::cout << "label str: " << str << std::endl;

  if( std::regex_match( str, re_match, re ) ) {
    std::cout << "Map matches" << std::endl;
  }
  else {
    std::cout << "Map no match" << std::endl;
    return;
  }

  std::cout << "key: " << re_match.str(1) << std::endl;
  std::cout << "value: " << re_match.str(2) << std::endl;

  map.emplace( std::piecewise_construct
	       , std::forward_as_tuple( re_match.str(1) )
	       , std::forward_as_tuple( re_match.str(2) ) );
  
  if( re_match.str(3).empty() == false ) {
    std::cout << "recurse: " << re_match.str(3).substr( 1 ) << std::endl;

    labelFiller( re_match.str(3).substr( 1 ), map );
  }
}

int main()
{
  //std::string s = "foo|severity:ALERT|labels:'key1'='value1','key2'='value2','key3'='value3','key4'='value4'";
  //std::regex re{ "^([^|]+)(?:\\|(severity):(DEFAULT|DEBUG|INFO|NOTICE|WARNING|ERROR|CRITICAL|ALERT|EMERGENCY)|\\|(labels):('[^']+'='[^']+'(?:,'[^']+'='[^']+')*))*$" };

  //std::string s = "foo";
  //std::string s = "foo|severity:WARNING";
  //std::string s = "foo|labels:'key1'='value1','key2'='value2','key3'='value3'";
  std::string s = "foo|severity:WARNING|labels:'key1'='value1','key2'='value2','key3'='value3'";
  std::regex re{ "^([^|]+)(?:\\|severity:(DEFAULT|DEBUG|INFO|NOTICE|WARNING|ERROR|CRITICAL|ALERT|EMERGENCY))?(?:\\|labels:('[^']+'='[^']+'(?:,'[^']+'='[^']+')*))?$" };

  std::smatch re_match;

  if( std::regex_match( s, re_match, re ) ) {
    std::cout << "Text matches" << std::endl;
  }
  else {
    std::cout << "No match" << std::endl;

    return 0;
  }

  std::tuple< std::string, LogSeverity, std::map< std::string, std::string > > stream_info;

  for( size_t i = 0; i < re_match.size(); ++i ) {
    std::ssub_match sub_match = re_match[i];
    std::string piece = sub_match.str();
    std::cout << "submatch " << i << ": " << piece << std::endl;
  }

  // stream_name
  std::get<0>(stream_info) = re_match.str(1);

  if( re_match.str(2).empty() == false) {
    // severity
    if( re_match.str(2) == "DEFAULT" ) {
      std::get<1>(stream_info) = LogSeverity::DEFAULT;
    }
    else if( re_match.str(2) == "DEBUG" ) {
      std::get<1>(stream_info) = LogSeverity::DEBUG;
    }
    else if( re_match.str(2) == "INFO" ) {
      std::get<1>(stream_info) = LogSeverity::INFO;
    }
    else if( re_match.str(2) == "NOTICE" ) {
      std::get<1>(stream_info) = LogSeverity::NOTICE;
    }
    else if( re_match.str(2) == "WARNING" ) {
      std::get<1>(stream_info) = LogSeverity::WARNING;
    }
    else if( re_match.str(2) == "ERROR" ) {
      std::get<1>(stream_info) = LogSeverity::ERROR;
    }
    else if( re_match.str(2) == "CRITICAL" ) {
      std::get<1>(stream_info) = LogSeverity::CRITICAL;
    }
    else if( re_match.str(2) == "ALERT" ) {
      std::get<1>(stream_info) = LogSeverity::ALERT;
    }
    else if( re_match.str(2) == "EMERGENCY" ) {
      std::get<1>(stream_info) = LogSeverity::EMERGENCY;
    }
    else {
      std::get<1>(stream_info) = LogSeverity::UNKNOWN;
    }
  }
  
  if( re_match.str(3).empty() == false ) {
    labelFiller( re_match.str(3), std::get<2>(stream_info) );
  }

  std::cout << "stream_name: " << std::get<0>(stream_info) << std::endl;
  std::cout << "severity: " << static_cast<int>(std::get<1>(stream_info)) << std::endl;
  std::cout << "labels: " << std::endl;
  int count = 0;
  for(auto itr : std::get<2>(stream_info) ) {
    std::cout << "labels(" << count << "): " << itr.first << " = " << itr.second << std::endl;
    ++count;
  }

  return 0;
}
