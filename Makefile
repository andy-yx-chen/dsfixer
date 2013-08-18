!include <win32.mak>

#BOOST
BOOST_LIBS=D:\Data\libs\vc10\boost-x86-libs
BOOST_INCS=D:\Data\libs\vc10

INCLUDES=$(INCLUDE)
LIBS=$(lib)

#Include the sources
!if exists ("sources")
!	include "sources"
!endif

#Default values for reserved Marcos
#USECRT, default to YES
!if !DEFINED(USE_MSVCRT) ||"$(USE_MSVCRT)" == ""
USE_MSVCRT=YES
!endif

#UMTYPE default to console
!if !DEFINED(UMTYPE) || "$(UMTYPE)" == ""
UMTYPE=console
!endif

#USE_BOOST, default to NO
!if !DEFINED(USE_BOOST) || "$(USE_BOOST)" == ""
USE_BOOST=NO
!endif

#USE_UNICODE, default to YES
!if !DEFINED(USE_UNICODE) || "$(USE_UNICODE)" == ""
USE_UNICODE=YES
!endif

#UMENTRY, default to wmain
!if !DEFINED(UMENTRY) || "$(UMENTRY)" == ""
!	if "$(USE_UNICODE)" == "YES"
UMENTRY=wmain
!	else
UMENTRY=main
!	endif
!endif

#TARGETNAME, we don't allow TARGETNAME is undefined or is null
!if !DEFINED(TARGETNAME) || "$(TARGETNAME)" == ""
!error Unknown target name!
!endif

!if !DEFINED(TARGETPATH) || "$(TARGETPATH)" == ""
TARGETPATH=obj
!endif

#TARGETTYPE, default to exe 
!if !DEFINED(TARGETTYPE) || "$(TARGETTYPE)" == ""
TARGETTYPE=exe
!endif

!ifdef DEBUG
cflags=$(cflags) /D_DEBUG /Zi /Od
TARGETPATH=debug\$(TARGETPATH)
BIN_DIR=debug
!else
cflags=$(cflags) /Od
TARGETPATH=release\$(TARGETPATH)
BIN_DIR=release
!endif

!if "$(USE_UNICODE)" == "YES"
cflags=$(cflags) /D_UNICODE /DUNICODE
!endif

TARGETPATH=$(TARGETPATH)\$(CPU)

#generate directories
!if !EXIST("$(TARGETPATH)")
!	if ![-mkdir "$(TARGETPATH)"]
!	endif
!endif
#create objs list file
!if EXIST("$(TARGETPATH)\m_objs")
!	if [del "$(TARGETPATH)\m_objs"]
!	endif
!endif

!if ![-echo OBJS=\>>"$(TARGETPATH)\m_objs"]
!	if ![-for %i in ($(SOURCES)) do (echo %~ni.obj\>>"$(TARGETPATH)\m_objs")]
!		include "$(TARGETPATH)\m_objs"
!	endif
!endif

!if ![-for %i in ($(SOURCES)) do (echo %~ni.obj:%i >> "$(TARGETPATH)\m_src")]
!	include "$(TARGETPATH)\m_src"
!endif

!if "$(USE_MSVCRT)" == "NO"
!	ifdef DEBUG
cflags=$(cflags) /MTd
!	else
cflags=$(cflags) /MT
!	endif
!else
!	ifdef DEBUG
cflags=$(cflags) /MDd
!	else
cflags=$(cflags) /MD
!	endif
!endif

TARGETPDB=$(TARGETNAME).pdb

!if "$(TARGETTYPE)" == "exe"
_TARGETNAME=$(TARGETNAME).exe
!else
_TARGETNAME=$(TARGETNAME).dll
!endif

!if "$(UMTYPE)" == "console"
LINKFLAGS=$(conlflags)
USE_LIBS=$(USE_LIBS) $(conlibs)
!elseif "$(UMTYPE)" == "windows"
LINKFLAGS=$(guilflags)
USE_LIBS=$(USE_LIBS) $(guilibs)
!else
LINKFLAGS=$(dlllflags)
USE_LIBS=$(USE_LIBS) $(conlibs)
!endif

#always enable debug for linking
LINKFLAGS=$(LINKFLAGS) /DEBUG

#for release version, we need private symbol
!ifndef DEBUG
LINKFLAGS=$(LINKFLAGS) /PDBSTRIPPED:"$(TARGETPATH)\$(TARGETNAME).pri"
!endif


!if "$(USE_BOOST)" == "YES"
INCLUDES=$(INCLUDES) $(BOOST_INCS)
LIBS=$(LIBS) $(BOOST_LIBS)
!endif

cflags=$(cflags) /I"$(INCLUDES)"

!if DEFINED(LIBS) && "$(LIBS)" != ""
LINKFLAGS=$(LINKFLAGS) /LIBPATH:"$(LIBS)"
!endif

all:$(_TARGETNAME)

$(_TARGETNAME):$(OBJS)
	$(link) $(LINKFLAGS) /out:"$(_TARGETNAME)" /pdb:"$(TARGETPATH)\$(TARGETPDB)" $(USE_LIBS) $**
	@copy /Y *.obj "$(TARGETPATH)\"
	@copy /Y *.pdb "$(TARGETPATH)\"
	@copy /Y $(_TARGETNAME) "$(TARGETPATH)\$(_TARGETNAME)"
.c.obj:
	$(cc) /c $(cflags) $<

.cpp.obj:
	$(cc) /c $(cflags) /EHac $<

.cxx.obj:
	$(cc) /c $(cflags) /EHac $<

clean:
	@rd /s /q "$(BIN_DIR)"
	@del *.obj
	@del *.pdb
	@echo successfully clean up!
