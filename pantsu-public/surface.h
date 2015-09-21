#pragma once

#include "top.h"
#include "color.h"

class ISurface
{
public:

	void DrawSetColor( CColor Color )
	{
		typedef void( __thiscall* _DrawSetColor )( void*, CColor );
		return EmulateVirtual<_DrawSetColor>( this, 14 )( this, Color );
	}

	void DrawOutlinedRect( int X, int Y, int W, int H )
	{
		typedef void( __thiscall* _DrawOutlinedRect )( void*, int, int, int, int );
		return EmulateVirtual<_DrawOutlinedRect>( this, 18 )( this, X, Y, W, H );
	}

	void DrawSetTextFont( int Font )
	{
		typedef void( __thiscall* _DrawSetTextFont )( void*, int );
		return EmulateVirtual<_DrawSetTextFont>( this, 23 )( this, Font );
	}

	void DrawSetTextColor( CColor Color )
	{
		typedef void( __thiscall* _DrawSetTextColor )( void*, CColor );
		return EmulateVirtual<_DrawSetTextColor>( this, 24 )( this, Color );
	}

	void DrawSetTextPos( int X, int Y )
	{
		typedef void( __thiscall* _DrawSetTextPos )( void*, int, int );
		return EmulateVirtual<_DrawSetTextPos>( this, 26 )( this, X, Y );
	}

	void DrawPrintText( wchar_t* _Input, int Length, int Type )
	{
		typedef void( __thiscall* _DrawPrintText )( void*, wchar_t*, int, int );
		return EmulateVirtual<_DrawPrintText>( this, 28 )( this, _Input, Length, Type );
	}

	bool GetTextSize( int Font, const wchar_t* _Input, int& Wide, int& Tall )
	{
		typedef bool( __thiscall* _GetTextSize )( void*, int, const wchar_t*, int&, int& );
		return EmulateVirtual< _GetTextSize >( this, 79 )( this, Font, _Input, Wide, Tall );
	}

}; extern ISurface * Surface;