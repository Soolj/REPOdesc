#include "Common.h"
#include "GLUTMenu.h"
#include <vector>
#include "DrawingFuncs.h"

using std::vector;


GLUTMenu* _g_GLUTMenu = NULL;

void _g_OnMenu(int code)
{
  if (_g_GLUTMenu != NULL)
  {
    _g_GLUTMenu->OnGLUTMenu(code);
  }
}

GLUTMenu::GLUTMenu()
{
  _g_GLUTMenu = this;
}

GLUTMenu::~GLUTMenu()
{
  _g_GLUTMenu = NULL;
}

void GLUTMenu::AddMenuEntry(const string& entry, const string& fullCommand, GLUTMenu::MenuEntry& top)
{
  auto tmp = entry.find_first_of(".");
  if (tmp == string::npos)
  {
    top.children[entry] = MenuEntry();
    top.children[entry].glutMenuEntryID = _menuItemCounter;
    _menuMap[_menuItemCounter++] = fullCommand;
  }
  else
  {
    string left = entry.substr(0, tmp);
    string right = entry.substr(tmp + 1);
    if (top.children.find(left) == top.children.end())
    {
      top.children[left] = MenuEntry();
    }
    AddMenuEntry(right, fullCommand, top.children[left]);
  }
}

GLUTMenu::MenuEntry GLUTMenu::StringListToMenuTree(const vector<string>& strings)
{
  MenuEntry top;
  for (unsigned int i = 0; i < strings.size(); i++)
  {
    AddMenuEntry(strings[i],strings[i],top);
  }
  return top;
}

void GLUTMenu::CreateGLUTMenus(MenuEntry& top)
{
  if (top.children.empty()) 
    return;

  for (auto i = top.children.begin(); i != top.children.end(); i++)
  {
    // create the submenus
    CreateGLUTMenus(i->second);
  }

  top.glutMenuHandle = glut