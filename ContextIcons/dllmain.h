// dllmain.h : Declaration of module class.

class CContextIconsModule : public ATL::CAtlDllModuleT< CContextIconsModule >
{
public :
	DECLARE_LIBID(LIBID_ContextIconsLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_CONTEXTICONS, "{E50C4C50-F2C5-4AED-BA20-8E7E6336447D}")
};

extern class CContextIconsModule _AtlModule;
