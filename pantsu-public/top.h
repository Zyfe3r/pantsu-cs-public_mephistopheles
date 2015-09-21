#pragma once

#pragma region includes

#include <Windows.h>
#include <iostream>

#pragma endregion

#pragma region protos

typedef void*	( *Interface )( char* _Name, int Return );

typedef void( __thiscall *PaintTraverse )( void*, unsigned int, bool, bool );

#pragma endregion

class CTools
{
public:

	virtual void* GetInterface( char* _Module, char* _Interface )
	{
		Interface TempInterface = ( Interface ) GetProcAddress( GetModuleHandle( _Module ), "CreateInterface" );

		return ( void* ) TempInterface( _Interface, 0 );
	}


}; extern CTools * Tools;


template< typename Function > Function EmulateVirtual( void* _VMT, int Index )
{
	void*** _TVMT = ( void*** ) _VMT;

	void** VMT = *_TVMT;

	void* _Address = VMT[ Index ];

	return ( Function ) ( _Address );
}