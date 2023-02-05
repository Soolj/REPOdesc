#include "Common.h"
#include "SimpleConfig.h"
#include "Utility/StringUtils.h"

#include <vector>
#include <string>
using namespace std;

#define MAX_INCLUDE_DEPTH 5

namespace SLR
{
	
shared_ptr<SimpleConfig> SimpleConfig::s_config;

SimpleConfig::SimpleConfig()
{
	Reset("");
}

ParamsHandle SimpleConfig::GetInstance()
{
	if (!s_config)
	{
		s_config.reset(new SimpleConfig());
	}
	return s_config;
}

void SimpleConfig::Reset(string rootParam)
{
  // todo: go to the right directory
  // load all the files in the directory?
  _params.clear();
  if (rootParam != "")
  {
    ReadFile(rootParam);
  }
}

void SimpleConfig::ReadFile(const string& filename, int depth)
{
  if (depth > MAX_INCLUDE_DEPTH)
  {
    SLR_WARNING0("Config includes excede maximum include depth (is something including itself?)");
    return;
  }

  FILE* f = fopen(filename.c_str(), "r");
  if (!f)
  {
    SLR_ERROR1("Can't open file %s", filename.c_str());
    return;
  }

  char buf[512]; buf[511] = 0;
  int lineNum = 0;
  string curNamespace = "";

  // read line by line...
  while (fgets(buf, 510, f))
  {
    lineNum++;
    string s(buf);

    ParseLine(filename, s, lineNum, curNamespace, depth);
  }

  fclose(f);
}

void SimpleConfig::ParseLine(const string& filename, const string& line, int lineNum, string& curNamespace, int depth)
{
  // primitive trailing removal
  string s = SLR::LeftOf(line, '#');

  std::size_t firstNonWS = s.find_first_not_of("\n\t ");

  // is it a comment?
  if (firstNonWS == std::string::npos || s[firstNonWS] == '#' || firstNonWS == '/')
  {
    return;
  }

  // include?
  if (SLR::ToUpper(s).find("INCLUDE ") == 0)
  {
    string filenameToInclude = s.substr(7);
    filenameToInclude = Trim(filenameToInclude);
    // need to put the file in the same directory as this one
    auto tmp = filename.find_last_of("/\\");
    string path="";
    if (tmp != s