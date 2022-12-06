#include "../Common.h"
#include "DrawingFuncs.h"

using SLR::Quaternion;

using SLR::OpenGLDrawer;

// up is defined as the vector from the center to the top edge of the rectangle
// normal is the vector from the center in the direction of the front face
void GLRectangle(V3F center, V3F normal, V3F up, float width, float height, int numX, int numY)
{
	// ccw rectangle!
	glBegin(GL_QUADS);

	normal = normal.norm();
	up = up.norm();
	V3F left = normal.cross(up).norm();
	float dx = width/(float)numX;
	float dy = height/(float)numY;
	V3F bottomRight = center - up*height/2.f - left*width/2.f;
	for(int x=0;x<numX;x++)
	{
		for(int y=0;y<numY;y++)
		{
			V3F a = bottomRight + left*dx*(float)x + up*dy*(float)y;
			V3F b = a + up*dy;
			V3F c = b + left*dx;
			V3F d = c - up*dy;

			glNormal3f(normal.x,normal.y,normal.z);
			glVertex3f(a.x,a.y,a.z);
			glVertex3f(b.x,b.y,b.z);
			glVertex3f(c.x,c.y,c.z);
			glVertex3f(d.x,d.y,d.z);
		}
	}
	glEnd();

}

void GLCube(V3F center, V3F dims, int cnt)
{
	GLRectangle(center + V3F(0,0,1)*dims/2.f,V3F(0,0,1),V3F(1,0,0),dims.y,dims.x,cnt,cnt);		// top
	GLRectangle(center - V3F(0,0,1)*dims/2.f,V3F(0,0,-1),V3F(1,0,0),dims.y,dims.x,cnt,cnt);		// bottom
	
	GLRectangle(center + V3F(1,0,0)*dims/2.f,V3F(1,0,0),V3F(0,0,1),dims.y,dims.z,cnt,cnt);		// front
	GLRectangle(center - V3F(1,0,0)*dims/2.f,V3F(-1,0,0),V3F(0,0,1),dims.y,dims.z,cnt,cnt);		// back

	GLRectangle(center + V3F(0,1,0)*dims/2.f,V3F(0,1,0),V3F(0,0,1),dims.x,dims.z,cnt,cnt);		// left
	GLRectangle(center - V3F(0,1,0)*dims/2.f,V3F(0,-1,0),V3F(0,0,1),dims.x,dims.z,cnt,cnt);		// right
}

void GLCross(const V3F& center, const V3F& dims, bool gl_begin_line)
{
  if(gl_begin_line)
  {
    glBegin(GL_LINES);
  }

  glVertex3f(center.x,center.y,center.z+dims.z/2.f);
  glVertex3f(center.x,center.y,center.z-dims.z/2.f);
  glVertex3f(center.x,center.y+dims.y/2.f,center.z);
  glVertex3f(center.x,center.y-dims.y/2.f,center.z);
  glVertex3f(center.x+dims.x/2.f,center.y,center.z);
  glVertex3f(center.x-dims.x/2.f,center.y,center.z);

  if(gl_begin_line)
  {
    glEnd();
  }

}


const float propR = .1f;   // .1 fo