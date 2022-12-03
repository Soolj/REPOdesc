#include "../Common.h"
#include "ColorUtils.h"

// h from 0-259
// s from 0 to 1
// v from 0 to 1
// http://www.pymolwiki.org/index.php/Color_Objects
V3F HSVtoRGB( float h, float s, float v )
{
	float r,g,b;
	int i;
	float f, p, q, t;
	if( s == 0 ) {
		// achromatic (grey)
		return V3F(v,v,v);
	}
	h /= 60;			// sector 0 to 5
	i = (int)floor( h );
	f = h - i;			// factorial part of h
	p = v * ( 1 - s );
	q = v * ( 1 - s * f );
	t = v * ( 1 - s * ( 1 - f ) );
	switch( i ) {
		case 0:
			r = v;
			g = t;
			b = p;
			break;
		case 1:
			r = q;
			g = v;
			b = p;
			break;
		case 2:
			r = p;
			g = v;
			b = t;
			break;
		case 3:
			r = p;
			g = q;
			b = v;
			break;
		case 4:
			r = t;
			g = p;
			b = v;
			break;
		default:		// case 5:
			r = v;
			g = p;
			b = q;
			break;
	}
	return V3F(r,g,b);
}

// returns BGR!!
V3F FalseColorBGR(float v, float intensityMult)
{
	if(v<=.5f)
  {
    float b = (1.0f-v*2.0f