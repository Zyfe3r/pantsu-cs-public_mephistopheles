#pragma once

#include "client-entity-list.h"
#include "engine-client.h"
#include "entity.h"

#include "render.h"

class CESP
{
public:

	void Think( )
	{

		CBaseEntity* Local = ( CBaseEntity* )ClientEntityList->GetClientEntity( EngineClient->GetLocalPlayer( ) );

		PlayerInfo_t Info;

		Matrix3x4_t Matrix = EngineClient->GetMatrix( );

		CVector Screen, Head;
		
		for ( int i = 0; i < 64; ++i )
		{

			CBaseEntity* Entity = ( CBaseEntity* ) ClientEntityList->GetClientEntity( i );		

			if ( !Entity )
				continue;
			
			if ( Entity == Local )
				continue;

			if ( Entity->GetDormant( ) )
				continue;


			if ( Entity->GetHealth( ) )
			{
			
				EngineClient->GetPlayerInfo( i, &Info );

				if ( WorldToScreen( Entity->GetOrigin( ), Screen ) && WorldToScreen( ( Entity->GetEyePosition( ) + CVector( 0, 0, 8.f ) ), Head ) )
				{
					CColor Color( 255, 255, 255, 255 );

					if ( Entity->GetTeam( ) != Local->GetTeam( ) )
						Color = CColor( 255, 0, 0, 255 );

					else
						Color = CColor( 0, 255, 255, 255 );

					Render->DrawF( Screen.x, Screen.y + 2, Color, 5, 1, "- %s -", Info.Name );

					Render->DrawF( Head.x, Head.y - 12, Color, 5, 1, "- %d -", Entity->GetHealth( ) );

					int Height = Screen.y - Head.y, Width = Height / 2.5;

					Render->DrawInlineRect( Head.x - Width / 2, Head.y, Width, Height, Color );

				}


			}


		}

	}

	__forceinline bool WorldToScreen( CVector In, CVector& Out ) 
	{
		Matrix3x4_t ViewMatrix = EngineClient->GetMatrix( );

		Out.x = ViewMatrix.Matrix[ 0 ] * In.x + ViewMatrix.Matrix[ 1 ] * In.y + ViewMatrix.Matrix[ 2 ] * In.z + ViewMatrix.Matrix[ 3 ];

		Out.y = ViewMatrix.Matrix[ 4 ] * In.x + ViewMatrix.Matrix[ 5 ] * In.y + ViewMatrix.Matrix[ 6 ] * In.z + ViewMatrix.Matrix[ 7 ];

		Out.z = ViewMatrix.Matrix[ 12 ] * In.x + ViewMatrix.Matrix[ 13 ] * In.y + ViewMatrix.Matrix[ 14 ] * In.z + ViewMatrix.Matrix[ 15 ];

		if ( Out.z < 0.01f )
			return false;

		float Inverse = 1.f / Out.z;

		Out.x *= Inverse;
		Out.y *= Inverse;

		int Width, Height;

		EngineClient->GetScreenSize( Width, Height );

		auto X = Width / 2;
		auto Y = Height / 2;

		X += 0.5 * Out.x * Width + 0.5;
		Y -= 0.5 * Out.y * Height + 0.5;

		Out.x = X;
		Out.y = Y;

		return true;
	}

};
