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

ParamsHandle SimpleConfig