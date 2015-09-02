#include "sitefirewalldefaultpolicy.h"
#include"controller/messagethread.h"
#include"controller/MessageType.h"
SiteFirewallDefaultPolicy::SiteFirewallDefaultPolicy(QObject *parent):
    QObject(parent)
{

}

static SiteFirewallDefaultPolicy* siteFirewallDefaultPolicy;//SiteFirewallDefaultPolicy单例对象

SiteFirewallDefaultPolicy* SiteFirewallDefaultPolicy::getSiteFirewallDefaultPolicyInstance()
{
    if(siteFirewallDefaultPolicy==NULL)
    {
        siteFirewallDefaultPolicy=new SiteFirewallDefaultPolicy();
    }
    return siteFirewallDefaultPolicy;
}

void SiteFirewallDefaultPolicy::enableFirewallDefaultPolicy(QString hostName)
{
    QString str= QString::number(MessageType::enableFirewallDefaultPolicy)
                +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit();
  MessageThread::getMessageThreadInstance()->sendData(str);
}

void SiteFirewallDefaultPolicy::undoFirewallDefaultPolicy(QString hostName)
{
    QString str= QString::number(MessageType::undoFirewallDefaultPolicy)
                +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit();
  MessageThread::getMessageThreadInstance()->sendData(str);
}

void SiteFirewallDefaultPolicy::sendEnableFirewallDefaultPolicySignals(QString msg)
{
    emit enableFirewallDefaultPolicySignals(msg);
}

void SiteFirewallDefaultPolicy::sendUndoFirewallDefaultPolicySignals(QString msg)
{
    emit undoFirewallDefaultPolicySignals(msg);
}
