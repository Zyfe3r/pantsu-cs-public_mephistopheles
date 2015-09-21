#include "top.h"

/* sdk */
#include "client-entity-list.h"
#include "engine-client.h"
#include "panel.h"
#include "surface.h"
#include "hook.h"

CTools * Tools;
IPanel * Panel;
ISurface * Surface;
IVEngineClient * EngineClient;
IClientEntityList * ClientEntityList;

/* cheat */
#include "esp.h"

CHook * PanelHook;
CESP * ESP;
CRender * Render;

PaintTraverse _PaintTraverse;


/* ptrav hook function */
void __stdcall HookedPaintTraverse( int VGUIPanel, bool ForceRepaint, bool AllowForce )
{
	_PaintTraverse( Panel, VGUIPanel, ForceRepaint, AllowForce );


	/* right panel */
	if ( !strcmp( "FocusOverlayPanel", Panel->GetName( VGUIPanel ) ) )
	{

		if ( EngineClient->IsInGame( ) && EngineClient->IsConnected( ) )
		{

			Render->DrawF( 10, 10, CColor( 26, 188, 156, 255 ), 5, 0, "[ pantsu-mephistopheles by madddie.co ]" );

			ESP->Think( );

		}

	}
}

/* main */
void __stdcall Start( )
{
	/* maketools */
	Tools = new CTools;


	/* createinterface the objects we need */
	Panel = ( IPanel* )Tools->GetInterface( "vgui2.dll", "VGUI_Panel009" );
	Surface	= ( ISurface* )Tools->GetInterface( "vguimatsurface.dll", "VGUI_Surface031" );
	EngineClient = ( IVEngineClient* )Tools->GetInterface( "engine.dll", "VEngineClient013" );
	ClientEntityList = ( IClientEntityList* )Tools->GetInterface( "client.dll",	"VClientEntityList003" );


	/* init cheat */
	ESP = new CESP;


	/* setup hook */
	PanelHook = new CHook( ( DWORD** ) Panel );

	_PaintTraverse = ( PaintTraverse ) PanelHook->dwHookMethod( ( DWORD ) HookedPaintTraverse, 41 );

	return;
}


int __stdcall DllMain( HMODULE Instacen, DWORD Reason, LPVOID _Reserved )
{

	if ( Reason == 1 )
	{
		CreateThread( 0, 0, ( LPTHREAD_START_ROUTINE ) Start, 0, 0, 0 );
	}

	return 1;
}