// Random Number Utilities, super-lightweight-robotics library
// License: BSD-3-clause

#include "../Common.h"
#include "Random.h"
#include <math.h>

// from num recipes in c++ chap7
// a uniform random number generator 
double ran1(int &idum)
{
	const int IA = 16807, IM = 2147483647, IQ = 127773, IR = 2836, NTAB = 32;
	const int NDIV = (1+ (IM-1)/NTAB);
	const double EPS = 3.0e-16, AM = 1.0/IM, RNMX = (1.0-EPS);
	static int iy = 0;
	static int iv[NTAB];
	int j,k;
	double temp;

	if(idum<=0 || ! iy) // initialization
	{
		if(-idum<1) idum = 1; // prevent idum = 0
		else idum = -idum;
		for (j = NTAB+7; j>=0; j--) 
		{
			k = idum/IQ;
			idum = IA*(idum-k*IQ)-IR*k;
			if(idum<0) idum += IM;
			if (j<NTAB) iv[j] = idum;
		}
		iy = iv[0];
	}

	// normal operation
	k = idum/IQ; 
	idum = IA*(idum-k*IQ)-IR*k;
	if(idum<0) idum += IM;
	j = iy/NDIV;
	iy = iv[j];
	iv[j] = idum;
	if((temp = AM*