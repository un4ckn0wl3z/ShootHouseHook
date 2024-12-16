#pragma once

#include "base.h"

struct D3DXMATRIX
{
	FLOAT _11; FLOAT _12; FLOAT _13; FLOAT _14;
	FLOAT _21; FLOAT _22; FLOAT _23; FLOAT _24;
	FLOAT _31; FLOAT _32; FLOAT _33; FLOAT _34;
	FLOAT _41; FLOAT _42; FLOAT _43; FLOAT _44;
};


class Vector2
{
public:
	float x, y;

	Vector2()
	{
		RtlZeroMemory(this, sizeof(Vector2));
	}
};


class Vector3
{
public:
	float x, y, z;

	Vector3()
	{
		RtlZeroMemory(this, sizeof(Vector3));
	}
};

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

class Camera
{
public:
	bool WorldToScreen(Vector3 position, Vector2& Point);

};