# ContextIcons
Allows setting icons for standard Windows context menu items like "Copy" and "Paste." Designed for Windows 8 (or greater) x64.

## Inception
This was originally written as [an answer on Super User](http://superuser.com/a/1021873/380318), earning a hearty bounty of 100 points from the very generous [Sk8erPeter](http://superuser.com/users/62130/sk8erpeter).

## To use
Put BMP files in the `C:\shellicon` directory with the names found in `IconInjector.cpp`. This works best if the images are saved with MS Paint.

Install the built DLL with `regsvr32 ContextIcons.dll`. To remove, do `regsvr32 /u ContextIcons.dll`.