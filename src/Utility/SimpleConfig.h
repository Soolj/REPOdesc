#pragma once

#include <map>
#include <vector>
using std::vector;
using std::map;

namespace SLR{

class SimpleConfig;
typedef shared_ptr<SimpleConfig> ParamsHandle;


class SimpleConfig
{
	SimpleConfig();
	void ReadFile(const string& filename, int depth=0);

public:
	static ParamsHandle GetInstance();
	void Reset(string rootParam);
  
  bool Exists(const string& param);
  bool GetFloat(const string& param, float& ret);
  bool GetString(const string& param, string& ret);
  bool GetV3F(const strin