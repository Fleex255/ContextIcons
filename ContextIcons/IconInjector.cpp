// IconInjector.cpp : Implementation of CIconInjector

#include "stdafx.h"
#include "IconInjector.h"
#include <string>

// CIconInjector

	HBITMAP bmpCopy = NULL;
	HBITMAP bmpCut = NULL;
	HBITMAP bmpUndo = NULL;
	HBITMAP bmpRedo = NULL;
	HBITMAP bmpSendto = NULL;
	HBITMAP bmpDel = NULL;
	HBITMAP bmpPaste = NULL;
	STDMETHODIMP CIconInjector::Initialize(LPCITEMIDLIST pidlFolder, LPDATAOBJECT pDataObj, HKEY hProgID) {
		// Load the images
		bmpCopy = (HBITMAP)LoadImageA(NULL, "C:\\shellicon\\copy.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);
		bmpCut = (HBITMAP)LoadImageA(NULL, "C:\\shellicon\\cut.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);
		bmpUndo = (HBITMAP)LoadImageA(NULL, "C:\\shellicon\\undo.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);
		bmpRedo = (HBITMAP)LoadImageA(NULL, "C:\\shellicon\\redo.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);
		bmpSendto = (HBITMAP)LoadImageA(NULL, "C:\\shellicon\\sendto.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);
		bmpDel = (HBITMAP)LoadImageA(NULL, "C:\\shellicon\\delete.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);
		bmpPaste = (HBITMAP)LoadImageA(NULL, "C:\\shellicon\\paste.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE);
		int err = GetLastError();
		return S_OK;
	}
	STDMETHODIMP CIconInjector::QueryContextMenu(HMENU hmenu, UINT uMenuIndex, UINT uidFirst, UINT uidLast, UINT flags) {
		using namespace std;
		if (flags & CMF_DEFAULTONLY) return S_OK; // Don't do anything if it's just a double-click
		int itemsCount = GetMenuItemCount(hmenu);
		for (int i = 0; i < itemsCount; i++) { // Iterate over the menu items
			MENUITEMINFO mii;
			ZeroMemory(&mii, sizeof(mii));
			mii.cbSize = sizeof(mii);
			mii.fMask = MIIM_FTYPE | MIIM_STRING;
			mii.dwTypeData = NULL;
			BOOL ok = GetMenuItemInfo(hmenu, i, TRUE, &mii); // Get the string length
			if (mii.fType != MFT_STRING) continue;
			UINT size = (mii.cch + 1) * 2; // Allocate enough space
			LPWSTR menuTitle = (LPWSTR)malloc(size);
			mii.cch = size;
			mii.fMask = MIIM_TYPE;
			mii.dwTypeData = menuTitle;
			ok = GetMenuItemInfo(hmenu, i, TRUE, &mii); // Get the actual string data
			mii.fMask = MIIM_BITMAP;
			bool chIcon = true;
			if (wcscmp(menuTitle, L"&Copy") == 0) {
				mii.hbmpItem = bmpCopy;
			}
			else if (wcscmp(menuTitle, L"Cu&t") == 0) {
				mii.hbmpItem = bmpCut;
			}
			else if (wcscmp(menuTitle, L"&Paste") == 0) {
				mii.hbmpItem = bmpPaste;
			} 
			else if (wcscmp(menuTitle, L"Se&nd to") == 0) {
				mii.hbmpItem = bmpSendto;
			}
			else if (wcsstr(menuTitle, L"&Undo") != NULL) {
				mii.hbmpItem = bmpUndo;
			}
			else if (wcsstr(menuTitle, L"&Redo") != NULL) {
				mii.hbmpItem = bmpRedo;
			}
			else if (wcscmp(menuTitle, L"&Delete") == 0) {
				mii.hbmpItem = bmpDel;
			}
			else {
				chIcon = false;
			}
			if (chIcon) SetMenuItemInfo(hmenu, i, TRUE, &mii);
			free(menuTitle);
		}
		return MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_NULL, 0); // Same as S_OK (= 0) but is The Right Thing To Do [TM]
	}
	STDMETHODIMP CIconInjector::InvokeCommand(LPCMINVOKECOMMANDINFO info) {
		return S_OK;
	}
	STDMETHODIMP CIconInjector::GetCommandString(UINT_PTR, UINT, UINT*, LPSTR, UINT) {
		return S_OK;
	}