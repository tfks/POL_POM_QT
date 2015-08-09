#include <QObject>
#include <QtPlugin>

class VirtualDriveManagerPluginInterface
{
public:
    virtual ~VirtualDriveManagerPluginInterface() {}
};

QT_BEGIN_NAMESPACE

#define VirtualDriveManagerPluginInterface_iid "playonlinux.VirtualDriveManagerPluginInterface"

Q_DECLARE_INTERFACE(VirtualDriveManagerPluginInterface, VirtualDriveManagerPluginInterface_iid)

QT_END_NAMESPACE
