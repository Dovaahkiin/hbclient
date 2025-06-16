// ClearMap.cpp: implementation of the CClearMap class.
//
//////////////////////////////////////////////////////////////////////

#include "ClearMap.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
extern void PutLogFileList(char * cStr);
extern char G_cTxt[512];


CClearMap::CClearMap()
{
	m_pFin = m_pInicio = NULL;
}
CClearMap::~CClearMap()
{
	class CClearMap * aux;
	
	while(m_pInicio)
	{
		aux = m_pInicio->m_pSig;
		delete m_pInicio;
		m_pInicio = aux;
	}
}
void CClearMap::AddNewElement(class CItem * pItem,class CTile * pTile)
{
	class CClearMap * nuevo;

	if((!pItem) || (!pTile))
		return;

	nuevo = new CClearMap;

	nuevo->m_pItem = pItem;
	nuevo->m_pTile = pTile;
	nuevo->dw_Timer = timeGetTime();

	nuevo->m_pAnt = NULL;
	if(!m_pInicio) 
	{
		nuevo->m_pSig = NULL;
		m_pFin = nuevo;
	}
	else 
	{
		nuevo->m_pSig = m_pInicio;
		m_pInicio->m_pAnt = nuevo;

	}
	m_pInicio = nuevo;

	return;
}
void CClearMap::DeleteElements()
{
	class CClearMap * aux;
	register int i;

	aux = m_pFin;

	while(aux)
	{
		if((timeGetTime() - aux->dw_Timer) > (1000*120))
		{
			for (i = DEF_TILE_PER_ITEMS-1; i >= 0; i--) 
			{
				if((aux->m_pTile->m_pItem[i] != NULL)&&(aux->m_pTile->m_pItem[i] == aux->m_pItem)) 
				{
					delete aux->m_pTile->m_pItem[i];
					aux->m_pTile->m_pItem[i] = NULL;
					aux->m_pTile->m_cTotalItem--;
				}
			}
			m_pFin = aux->m_pAnt;
			if(m_pFin) m_pFin->m_pSig = NULL;
			else m_pInicio = m_pFin;
			delete aux;
			aux = m_pFin;
		}
		else
			aux = NULL;
	}
	return;
}
void CClearMap::Monitor()
{
	class CClearMap * actual;
	register int i;
	actual = m_pInicio;
	i=0;
	while(actual)
	{
		i++;
		wsprintf(G_cTxt, "%d->",i);
		PutLogFileList(G_cTxt);
		actual = actual->m_pSig;
	}
	actual = m_pFin;
	while(actual)
	{
		wsprintf(G_cTxt, "||%d<-",i);
		PutLogFileList(G_cTxt);
		i--;
		actual = actual->m_pAnt;
	}

	return;
}