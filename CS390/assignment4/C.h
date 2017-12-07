#ifndef __C_H__
#define __C_H__

#include "B.h"

class C : public B
{
public:
	char get_char() { return 'C'; }
};

#endif //__C_H__
