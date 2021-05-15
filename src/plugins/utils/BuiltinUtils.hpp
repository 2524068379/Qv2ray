#pragma once

#include "QvPluginInterface.hpp"

#include <QObject>
#include <QtPlugin>

using namespace Qv2rayPlugin;

class InternalUtilsPlugin
    : public QObject
    , public Qv2rayInterface
{
    Q_INTERFACES(Qv2rayPlugin::Qv2rayInterface)
    Q_PLUGIN_METADATA(IID Qv2rayInterface_IID)
    Q_OBJECT
  public:
    const QvPluginMetadata GetMetadata() const override
    {
        return { "Builtin Ultilities",                //
                 "Qv2ray Core Workgroup",             //
                 "qv2ray_builtin_utils",              //
                 "Some useful ultilities for Qv2ray", //
                 QV2RAY_VERSION_STRING,               //
                 "Qv2ray/Qv2ray",                     //
                 { COMPONENT_EVENT_HANDLER, COMPONENT_GUI },
                 UPDATE_NONE };
    }

    bool InitializePlugin(const QString &, const QJsonObject &) override;
    void SettingsUpdated() override{};

  signals:
    void PluginLog(QString) const override;
    void PluginErrorMessageBox(QString, QString) const override;
};
