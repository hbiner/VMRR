#ifndef SITEFIREWALLDEFAULTPOLICY_H
#define SITEFIREWALLDEFAULTPOLICY_H
#include<QObject>

class SiteFirewallDefaultPolicy : public QObject
{
    Q_OBJECT
public:
    explicit SiteFirewallDefaultPolicy(QObject *parent = 0);
    static SiteFirewallDefaultPolicy* getSiteFirewallDefaultPolicyInstance();
    void enableFirewallDefaultPolicy(QString hostName);
    void sendEnableFirewallDefaultPolicySignals(QString msg);
    void undoFirewallDefaultPolicy(QString hostName);
    void sendUndoFirewallDefaultPolicySignals(QString msg);
private:

signals:
    void enableFirewallDefaultPolicySignals(QString);
    void undoFirewallDefaultPolicySignals(QString);
public slots:
};

#endif // SITEFIREWALLDEFAULTPOLICY_H
