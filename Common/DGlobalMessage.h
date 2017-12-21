﻿/*******************************************************************
** 文件名:	DGlobalMessage.h 
** 版  权:	(C) 深圳未名网络技术有限公司
** 创建人:	隆寒辉(Forlion Lon)
** 日  期:	2007/11/24  15:03
** 版  本:	1.0
** 描  述:	消息码定义
** 应  用:  	
	
**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
********************************************************************/
/*消息码层次
|－服务器消息码
|－－模块消息码
|－－－行为消息码 //*/

#pragma once

// 这是远征的消息头定义，放在这里主要是网关和中心服等老工程用到了这个文件

#include "NetMessageDef.h"

///////////////////////// 所有消息的消息头 ////////////////////////
struct SGameMsgHead
{	
	BYTE		SrcEndPoint;					// 源端点码	
	BYTE		DestEndPoint;					// 目标端点码	
	BYTE		byKeyModule;					// 目标模块消息码	
	BYTE		byKeyAction;					// 行为消息码

	SGameMsgHead(void)
	{
		memset(this, 0, sizeof(*this));
	}
};

// 从场景服发给客户端的消息必须继承此消息体
struct SMsgActionSCHead
{
	LONGLONG	uidEntity;		// 实体uid	
};