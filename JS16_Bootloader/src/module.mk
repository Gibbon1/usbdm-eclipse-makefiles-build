# List source file to include from current directory
SRC += ApplicationFiles.cpp
SRC += FlashImage.cpp
SRC += ICP.cpp
SRC += JS16_Bootloader.cpp
SRC += JS16_BootloaderApp.cpp
SRC += low_level_usb.cpp
SRC += MainDialogue.cpp
SRC += Names.cpp
SRC += Version.rc

# Shared files $(SHARED_SRC)
VPATH := $(VPATH) $(SHARED_SRC)
INCS  += -I$(SHARED_SRC)
SRC += Log.cpp
