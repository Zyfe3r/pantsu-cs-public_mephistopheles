#pragma once

#include "top.h"

class IPanel
{
public:

	const char* GetName( int Panel )
	{
		typedef const char*( __thiscall* _GetName )( void*, int );
		return EmulateVirtual< _GetName >( this, 36 )( this, Panel );
	}

}; extern IPanel * Panel;