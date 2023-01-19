
#include "Common.h"
#include "Trajectory.h"
#include "Utility/SimpleConfig.h"
#include "Utility/StringUtils.h"

using namespace SLR;

Trajectory::Trajectory() : traj(MAX_TRAJECTORY_POINTS) 
{
  _log_file = NULL;
}

Trajectory::Trajectory(const string& filename) : traj(MAX_TRAJECTORY_POINTS)
{
  ReadFile(filename);
}

Trajectory::~Trajectory()
{
  // Close any open logging files
  if (_log_file)
  {
    fclose(_log_file);
  }
}

bool Trajectory::ReadFile(const string& filename)
{
  traj.reset();

  FILE* f = fopen(filename.c_str(), "r");
  if (!f)
  {
    return false;
  }

  char buf[512];