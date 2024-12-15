#pragma once

#include "base.h"

class Unity_Array
{
public:
	char pad_0000[0x18];
	size_t Count;
	void* Objects[65536];
};