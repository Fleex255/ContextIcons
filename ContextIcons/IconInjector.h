// IconInjector.h : Declaration of the CIconInjector

#pragma once
#include "resource.h"       // main symbols

#include <comdef.h>
#include "Shobjidl.h"
#include "ContextIcons_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CIconInjector

class ATL_NO_VTABLE CIconInjector :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CIconInjector, &CLSID_IconInjector>,
	public IShellExtInit, public IContextMenu
{
protected:
	TCHAR m_szFile[MAX_PATH];
public:
	CIconInjector()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ICONINJECTOR)

DECLARE_NOT_AGGREGATABLE(CIconInjector)

BEGIN_COM_MAP(CIconInjector)
	COM_INTERFACE_ENTRY(IShellExtInit)
	COM_INTERFACE_ENTRY(IContextMenu)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHODIMP Initialize(LPCITEMIDLIST, LPDATAOBJECT, HKEY);
	STDMETHODIMP GetCommandString(UINT_PTR, UINT, UINT*, LPSTR, UINT);
	STDMETHODIMP InvokeCommand(LPCMINVOKECOMMANDINFO);
	STDMETHODIMP QueryContextMenu(HMENU, UINT, UINT, UINT, UINT);
};


OBJECT_ENTRY_AUTO(__uuidof(IconInjector), CIconInjector)
