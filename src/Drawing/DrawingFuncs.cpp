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
	V3F bottomRight = center - up*height/2.f - 