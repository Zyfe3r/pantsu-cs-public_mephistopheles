#pragma once

#include "top.h"

class CVector
{
public:

	float x, y, z;

	CVector( )
	{
		memset( this, 0, sizeof( CVector ) );
	}

	CVector( float x, float y, float z )
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	CVector operator + ( const CVector& In )
	{
		return CVector( x + In.x, y + In.y, z + In.z );
	}

};