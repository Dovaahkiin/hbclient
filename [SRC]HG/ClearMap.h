// ClearMap.h: interface for the CClearMap class.
//
//////////////////////////////////////////////////////////////////////

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <windows.h>
#include <winbase.h>
#include "OccupyFlag.h"
#include "Tile.h"
#include "Item.h"


class CClearMap
{
public:
	CClearMap();
	virtual ~CClearMap();
	
	class CClearMap * m_pInicio, * m_pFin, *m_pSig, *m_pAnt;
	DWORD dw_Timer;
	CTile * m_pTile;
	CItem * m_pItem;

	void AddNewElement(class CItem *,class CTile *);
	void DeleteElements();
	void Monitor();
};
