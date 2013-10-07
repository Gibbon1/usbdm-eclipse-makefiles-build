# Shared make definitions
#

#.SILENT :

#===========================================================
# Shared directories - Relative to child directory
SHARED_SRC     := ../Shared_V4/src
SHARED_LIBDIRS := ../Shared_V4/lib
TARGET_DIR     := ../PackageFiles/bin

ifeq ($(OS),Windows_NT)
    UNAME_S := Windows
else
    UNAME_S := $(shell uname -s)
endif

ifeq ($(UNAME_S),Windows)
   .SUFFIXES : .d .rc
   LIB_PREFIX = 
   LIB_SUFFIX = .dll
   EXE_SUFFIX = .exe
   MINGWBIN := c:/Apps/MinGW/bin
   MSYSBIN  := c:/Apps/MinGW/msys/1.0/bin
   RM       := $(MSYSBIN)/rm -f
   RMDIR    := $(MSYSBIN)/rm -R -f
   TOUCH    := $(MSYSBIN)/touch
   MKDIR    := $(MSYSBIN)/mkdir -p
   CP       := $(MSYSBIN)/cp
   MAKE     := $(MINGWBIN)/mingw32-make
   GCC      := $(MINGWBIN)/gcc
   GPP      := $(MINGWBIN)/g++
   WINDRES  := $(MINGWBIN)/windres
   #PROGRAM_DIR = C:/"Program Files"
   PROGRAM_DIR = C:/'Program Files (x86)'
else
   .SUFFIXES : .d
   LIB_PREFIX 			:= lib
   LIB_SUFFIX 			:= .so.$(MAJOR_VERSION).$(MINOR_VERSION)
   LIB_MAJOR_SUFFIX		:= .so.$(MAJOR_VERSION)
   LIB_NO_SUFFIX 		:= .so
   EXE_SUFFIX 			:= 

   MINGWBIN := 
   MSYSBIN  := 
   RM       := rm -f
   RMDIR    := rm -R -f
   TOUCH    := touch
   MKDIR    := mkdir -p
   CP       := cp
   LN       := ln -s -f
   MAKE     := make
   GCC      := gcc
   GPP      := g++
   WINDRES  := 
endif

#===========================================================
# Options to build standalone DLL (windows)
ifeq ($(UNAME_S),Windows)
   STATIC_GCC_OPTION := -static-libstdc++ -static-libgcc
endif

#===========================================================
# WIN32
ifeq ($(UNAME_S),Windows)
   WIN32_GUI_OPTS     := -Wl,--subsystem,windows -mwindows
else
   WIN32_GUI_OPTS     := 
endif


#=============================================================
# Common USBDM DLLs in debug and non-debug versions as needed
ifeq ($(UNAME_S),Windows)
   LIB_WX_PLUGIN = usbdm-wxPlugin
else
   LIB_WX_PLUGIN = usbdm-wx
endif

LIB_USB_SHARED  = usb-1.0
LIB_USB_STATIC  = usb-static-1.0

ifeq ($(UNAME_S),Windows)
   LIB_USB = $(LIB_USB_STATIC)
   ifdef DEBUG
      LIB_USBDM     = usbdm-debug.4 
      LIB_USBDM_TCL = usbdmTCL-debug.4 
      LIB_USBDM_DSC = usbdm-dsc-debug.4 
   else
      LIB_USBDM     = usbdm.4 
      LIB_USBDM_TCL = usbdmTCL.4 
      LIB_USBDM_DSC = usbdm-dsc.4 
   endif
else
   LIB_USB = $(LIB_USB_SHARED)
   ifdef DEBUG
      LIB_USBDM     = usbdm-debug
      LIB_USBDM_TCL = usbdm-tcl-debug 
      LIB_USBDM_DSC = usbdm-dsc-debug 
   else
      LIB_USBDM     = usbdm
      LIB_USBDM_TCL = usbdm-tcl 
      LIB_USBDM_DSC = usbdm-dsc 
   endif
endif

#===========================================================
# Debug flags
ifeq ($(UNAME_S),Windows)
GCC_VISIBILITY_DEFS=
else
GCC_VISIBILITY_DEFS=-fvisibility=hidden -fvisibility-inlines-hidden
endif
ifdef DEBUG
   # Compiler flags
   CFLAGS := -O0 -g3 ${GCC_VISIBILITY_DEFS}
   # Compiler flags (Linking)
   LDFLAGS = 
   # C Definitions
   DEFS   := -DLOG
else
   # Compiler flags
   CFLAGS := -O3 -g0 ${GCC_VISIBILITY_DEFS}
   # Compiler flags (Linking)
   LDFLAGS = -s
endif
#CFLAGS += -Wshadow -DWINVER=0x500 -D_WIN32_IE=0x500 -std=gnu99 -Wall -Wundef -Wunused -Wstrict-prototypes -Werror-implicit-function-declaration -Wno-pointer-sign

#===========================================================
# Look in shared Library dir first
LIBDIRS := -L$(SHARED_LIBDIRS) -L$(TARGET_DIR)

#===========================================================
# Common Definitions for building Programmer, GDI & GDB
PROGRAMMER_DEFS = -DTARGET=$(TARGET) -DFLASH_PROGRAMMER -DUSE_ICON
GDI_DEFS        = -DTARGET=$(TARGET) -DGDI
GDI_LEGACY_DEFS = -DTARGET=$(TARGET) -DGDI -DLEGACY
GDB_DEFS        = -DTARGET=$(TARGET) -DGDB -DGDB_SERVER
GDB_SERVER_DEFS = -DTARGET=$(TARGET) -DUSE_ICON -DGDB -DGDB_SERVER

ifeq ($(UNAME_S),Windows)
# Windows version of Codewarrior packs structs
GDI_DEFS        = -DPACK_STRUCTS=1 -DTARGET=$(TARGET) -DGDI
endif

