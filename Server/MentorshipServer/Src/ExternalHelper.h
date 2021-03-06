﻿/*******************************************************************
** 文件名:	ExternalHelper.h
** 版  权:	(C) 深圳冰川网络技术有限公司 2008 - All Rights Reserved
** 创建人:	易耀辉
** 日  期:	11/29/2016
** 版  本:	1.0
** 描  述:	辅助功能类
********************************************************************/

#ifndef __EXTERNALHELPER_H__
#define __EXTERNALHELPER_H__

#include "IActorService.h"
#include "MentorshipDef.h"
#include "Chat_ManagedDef.h"

// 定义
class CExternalHelper
{
public:
	// 构造函数
	CExternalHelper(void);
	// 虚构函数
	~CExternalHelper(void);

    // 发送消息
    void sendMentorshipSocial(BYTE byKeyAction, int nActionID,void *pData, int nLen);
    // 发送数据到客户端
	void send2Client(DWORD dwPDBID, BYTE byKeyModule, BYTE byKeyAction, LPCSTR pszData, size_t nDataLen);

    // 取得帮会常量信息
	SMentorshipConfig* getConfig();

	/** 判断两个时间点之间相差几周
	@return
	*/
	int DiffWeek(DWORD dwTime1, DWORD dwTime2);

    // 显示提示文字
	void showSystemMessage(DWORD dwPDBID, EMChatTipID nTipID, LPCSTR szParam = NULL);
};
extern CExternalHelper				g_EHelper;

#endif // __EXTERNALHELPER_H__