#pragma once

#include <vector>

namespace SLR
{
// helper function -- trimming
inline std::string Trim(const std::string& str,
                 const std::string& whitespace = " \t\n")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return ""; // no content

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

inline std::string ToUpper(const std::string& in)
{
  std::string ret=in;
  for(std::size_t i=0;i<in.size();i++)
  {
    if(ret[i]>='a' && ret[i]<='z') ret[i] -= ('a'-'A');
  }
  return ret;
}

inline std::string ToLower(const std::string& in)
{
  std::string ret = in;
  for (std::size_t i = 0; i<in.size(); i++)
  {
    if (ret[i] >= 'A' && ret[i] <= 'Z') ret[i] += ('a' - 'A');
  }
  return ret;
}


inline std::stri