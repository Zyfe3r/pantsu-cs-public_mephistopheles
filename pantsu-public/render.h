#pragma once

#include "surface.h"

class CRender
{
public:

	void DrawF( int X, int Y, CColor Color, int Font, bool Center, char* _Input, ... )
	{
		/* set up buffer */
		char Buffer[ 1024 ] = { '\0' };

		/* set up varargs*/
		va_list Args;

		va_start( Args, _Input );
		vsprintf_s( Buffer, _Input, Args );
		va_end( Args );

		size_t Size = strlen( Buffer ) + 1;

		/* set up widebuffer*/
		wchar_t* WideBuffer = new wchar_t[ Size ];

		/* char -> wchar */
		mbstowcs_s( 0, WideBuffer, Size, Buffer, Size - 1 );

		/* check center */
		int Width = 0, Height = 0;

		if ( Center )
		{
			Surface->GetTextSize( Font, WideBuffer, Width, Height );
		}

		/* call and draw*/
		Surface->DrawSetTextColor( Color );
		Surface->DrawSetTextFont( Font );
		Surface->DrawSetTextPos( X - ( Width * .5 ), Y );
		Surface->DrawPrintText( WideBuffer, wcslen( WideBuffer ), 0 );
	}

	void DrawRect( int X, int Y, int W, int H, CColor Color )
	{
		Surface->DrawSetColor( Color );
		Surface->DrawOutlinedRect( X, Y, X + W, Y + H );
	}

}; extern CRender * Render;