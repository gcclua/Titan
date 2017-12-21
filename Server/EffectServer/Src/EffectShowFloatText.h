﻿/*******************************************************************
** 文件名:	EffectShowFloatText.h
** 版  权:	(C) 深圳冰川网络技术有限公司 2008 - All Rights Reserved
** 创建人:	彭政林
** 日  期:	12/15/2015
** 版  本:	1.0
** 描  述:	效果-显示飘字
            http://172.16.0.120/redmine/issues/1454
********************************************************************/

#pragma once

#include "IEffect.h"
#include "EffectDef.h"
#include "ExternalHelper.h"

using namespace rkt;
using namespace EFFECT_SERVER;

class CEffectShowFloatText : public IEffectEx
{
public:
	typedef  EffectServer_ShowFloatText    SCHEME_DATA;

	CEffectShowFloatText( SCHEME_DATA & data ) : m_data(data)
	{
	}

    // 获取效果ID
    virtual int             GetID()
    {
        return m_data.nID;
    }

	// 效果启用
	virtual bool			Start( EFFECT_CONTEXT * context,CONDITION_CONTEXT *pConditionContext )
	{
		if ( context==0 || context->pEntity==0 )
			return false;

        g_EHelper.showSystemMessage(context->pEntity, (EMChatTipID)m_data.nTextID);

		return true;
	}

	// 效果停止
	virtual void			Stop()
	{
	}

	// 克隆一个新效果
	virtual IEffect *       Clone()
	{
		return new CEffectShowFloatText(m_data);
	}

	// 释放
	virtual void			Release()
	{
		Stop();
		delete this;
	}

private:
	SCHEME_DATA             m_data;
};