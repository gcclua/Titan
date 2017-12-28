﻿/*******************************************************************
** 文件名:	SchemeMatchRankConfig.h
** 版  权:	(C) 深圳冰川网络技术有限公司 2008 - All Rights Reserved
** 创建人:	秦其勇
** 日  期:	3/13/2015
** 版  本:	1.0
** 描  述:	撮合匹配设置
********************************************************************/
#pragma once

#include "ISchemeEngine.h"
#include "ISchemeCenter.h"
#include "SchemeCache.h"
#include "MatchSchemeDef.h"
// 定义
class CSchemeMatchRankConfig : public ISchemeMatchRankConfigInfo, public ISchemeUpdateSink, public CSchemeCache<CSchemeMatchRankConfig>
{
public:

    /////////////////////////ISchemeMatchRankConfigInfo/////////////////////////
	/** 取得撮合配置信息
	@param eMatchTypeID:	    撮合类型ID
    @param nGradeId:            等级
	@return  
	*/
	virtual SMatchRankConfigSchemeInfo* getMatchRankConfigShemeInfo(int eMatchTypeID, int nGradeId);


    /////////////////////////ISchemeMatchRankConfigInfo/////////////////////////
	/** 取得撮合配置信息
    @param eMatchTypeID:	    撮合类型ID
    @param nGradeId:            等级
	@return  
	*/
	virtual SMatchRankConfigSchemeInfo* getShemeInfoByTypeAndScore(int eMatchTypeID, int nScore);

    /** 根据隐藏得分取得撮合配置信息
    */
    virtual SMatchRankConfigSchemeInfo* getShemeHideInfoByTypeAndScore(int eMatchTypeID, int nScore);

    /** 取得王者分段最低段位等级
    */
    virtual int getMatchTypeKingRankBaseScore(int eMatchTypeID);

	/** 取得王者分段最低等级
	*/
	virtual int getMatchTypeKingRankBaseGrade(int eMatchTypeID);

	/////////////////////////ISchemeUpdateSink/////////////////////////
	virtual bool OnSchemeLoad(SCRIPT_READER reader,const char* szFileName);
	virtual bool OnSchemeUpdate(SCRIPT_READER reader, const char* szFileName);

	/////////////////////////CSchemeMatchRankConfig//////////////////////////
	/** 载入脚本
	@param   
	@param   
	@return  
	*/
	bool LoadScheme(void);

	/** 关闭
	@param   
	@param   
	@return  
	*/
	void Close(void);

	/** 
	@param   
	@param   
	@return  
	*/
	CSchemeMatchRankConfig(void);

	/** 
	@param   
	@param   
	@return  
	*/
	virtual ~CSchemeMatchRankConfig(void);
private:
    bool LoadMatchRankScheme(ICSVReader* pCSVReader);

private:
    // 段位索引
    typedef std::map<int, SMatchRankConfigSchemeInfo> TMAP_MATCHRANKCONFIGSCHEME;
    // 类型索引
    typedef std::map<EMMatchType, TMAP_MATCHRANKCONFIGSCHEME> TMAP_MATCHRANKCONFIG_MANAGER;
    TMAP_MATCHRANKCONFIG_MANAGER  m_mapMatchRankConfigManager;
    // 每个比赛类型最低的王者段位分
    map<BYTE, pair<int, int>>  m_mapMatchTypeKingRankBase;
};