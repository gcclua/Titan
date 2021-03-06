#include "stdafx.h"
#include "SchemeRuneInfo.h"
#include "IServerGlobal.h"
#include <string>

#ifdef FUNCTION_RUNE_OPEN

CSchemeRuneInfo::CSchemeRuneInfo(void)
{
	m_SchemeInfo.clear();
}

CSchemeRuneInfo::~CSchemeRuneInfo(void)
{
	m_SchemeInfo.clear();
}

bool CSchemeRuneInfo::LoadScheme(void)
{
	ISchemeEngine * pSchemeEngine = gServerGlobal->getSchemeEngine();
	if(pSchemeEngine == NULL )
	{
		return false;
	}

    string stringPath = SCP_PATH_FORMAT( RUNE_SCHMEME_FILENAME );
    bool bResult = pSchemeEngine->LoadScheme(stringPath.c_str(), (ISchemeUpdateSink *)this, false);
	if(!bResult)
	{
		ErrorLn("config file load failed! filename=" << stringPath.c_str());
		return false;
	}

	return true;
}

void CSchemeRuneInfo::Close(void)
{	
	m_SchemeInfo.clear();
}

RuneInfoScheme* CSchemeRuneInfo::GetRuneSchemeInfo(int nRuneID)
{
	T_MapRuneInfo::iterator itSchemeInfo = m_SchemeInfo.find( nRuneID );
	if(itSchemeInfo != m_SchemeInfo.end())
	{
		return &(itSchemeInfo->second);
	}

	return NULL;
}

bool CSchemeRuneInfo::OnSchemeLoad(SCRIPT_READER reader, LPCSTR szFileName)
{
    ICSVReader * pCSVReader = reader.pCSVReader;
    if(pCSVReader == NULL || szFileName == NULL || reader.type != READER_CSV)
    {
        return false;
    }

    // ���
    m_SchemeInfo.clear();

    int nLen = 0;
    // ��ȡ
    for (size_t nRow = 0; nRow < pCSVReader->GetRecordCount(); ++nRow)
    {
        RuneInfoScheme item;
        ZeroMemory(&item,sizeof(RuneInfoScheme));

        item.nID = pCSVReader->GetInt(nRow, RUNE_INFO_COL_ID, 0);
        item.nSpecial = pCSVReader->GetFloat(nRow, RUNE_INFO_COL_SPC, 0);
        item.nType = pCSVReader->GetInt(nRow, RUNE_INFO_COL_INLAYTYPE, 0);
        item.nLevel = pCSVReader->GetInt(nRow, RUNE_INFO_COL_LEVEL, 0);
		
        nLen = sizeof(item.stEffectArray);
        pCSVReader->GetString(nRow,  RUNE_INFO_COL_EffectArray, item.stEffectArray, nLen);			
        nLen = sizeof(item.stEffectValueArray);
		pCSVReader->GetString(nRow,  RUNE_INFO_COL_EffectValueArray, item.stEffectValueArray, nLen);	
		item.nLimitCount = pCSVReader->GetInt(nRow, RUNE_INFO_COL_LimitCount, 0);

		m_SchemeInfo.insert(make_pair<unsigned int, RuneInfoScheme>(item.nID, item));
    }

	AfterSchemeLoaded();

	return true;
}

bool CSchemeRuneInfo::OnSchemeUpdate(SCRIPT_READER reader, LPCSTR szFileName)
{
	return false;
}


#endif