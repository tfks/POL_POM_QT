
class SteamPluginInterface
{
public:
    virtual SteamPluginInterface() {}
    virtual ~SteamPluginInnterface() {}
};

#define SteamPluginInterface_iid "playonlinux.com.SteamPluginInterface"

Q_DECLARE_INTERFACE(SteamPluginInterface, SteamPluginInterface_iid)
