#pragma once

#include "base.h"

namespace Utils
{
	class VTableHook
	{
	public:
		void Initialize(void* pTarget);
		void Bind(uint32_t Index, void* Function);
		void UnBind(uint32_t Index);
		void UnBindAll();

		template<typename T>
		T GetOriginal(uint32_t Index)
		{
			return (T)oVTable[Index];
		}

	private:
		uint32_t CalcVTableSize();
		void* pTarget = NULL;
		void** VTable = NULL;
		void** oVTable = NULL;
	};
}