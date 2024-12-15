#pragma once

#include "base.h"

class Il2CppClass
{
public:
	char pad_0000[0x10];
	const char* ClassName;
	const char* NameSpace;
};

class Unity_Array
{
public:
	char pad_0000[0x18];
	size_t Count;
	void* Objects[65536];
};