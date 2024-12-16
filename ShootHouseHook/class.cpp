#include "class.h"

bool Camera::WorldToScreen(Vector3 position, Vector2& Point)
{
	uint8_t* temp01 = *(uint8_t**)(((uint8_t*)this) + 0x10);
	D3DXMATRIX* Matrix = (D3DXMATRIX*)(temp01 + 0xDC);

	float Z = Matrix->_14 * position.x + Matrix->_24 * position.y + Matrix->_34 * position.z + Matrix->_44;

	if (Z > 0)
	{
		float X = Matrix->_11 * position.x + Matrix->_21 * position.y + Matrix->_31 * position.z + Matrix->_41;
		float Y = Matrix->_12 * position.x + Matrix->_22 * position.y + Matrix->_32 * position.z + Matrix->_42;

		float NdcX = X / Z;
		float NdcY = Y / Z;

		Point.x = (NdcX + 1.f) / 2.f * ImGui::GetIO().DisplaySize.x;
		Point.y = (1.f - (NdcY + 1.f) / 2.f) * ImGui::GetIO().DisplaySize.y;

		return true;
	}


	return false;
}