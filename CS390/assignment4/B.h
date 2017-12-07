#ifndef __B_H__
#define __B_H__

#include "A.h"

class B : public A
{
public:
	char get_char() { return 'B'; }
};

#endif //__B_H__
