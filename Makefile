#
# A Makefile that compiles all .c and .s files in "src" and "res" 
# subdirectories and places the output in a "obj" subdirectory
#

# If you move this project you can change the directory 
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"
GBDK_HOME = C:/gbdk/

LCC = $(GBDK_HOME)bin/lcc 

# You can set the name of the .gb ROM file here
PROJECTNAME    = MosaicMotion

# You can set flags for LCC here
# For example, you can uncomment the line below to turn on debug output
# LCCFLAGS += -debug # Uncomment to enable debug output
# LCCFLAGS += -v     # Uncomment for lcc verbose output
LCCFLAGS += -Wl-yt0x1B # Set an MBC for banking (1B - ROM+MBC5+RAM+BATT)
LCCFLAGS += -autobank # Enable autobanking
LCCFLAGS += -Wl-yoA -Wl-ya1 # MBC + Banking-related flags


SRCDIR      = src
OBJDIR      = obj
RESDIR      = res
BGMDIR		= huge
SFXDIR		= huge/sfx
BINS	    = $(OBJDIR)/$(PROJECTNAME).gb
CSOURCES    = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.c))) $(foreach dir,$(RESDIR),$(notdir $(wildcard $(dir)/*.c))) $(foreach dir,$(BGMDIR),$(notdir $(wildcard $(dir)/*.c)))
ASMSOURCES  = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.s)))
OBJS       = $(CSOURCES:%.c=$(OBJDIR)/%.o) $(ASMSOURCES:%.s=$(OBJDIR)/%.o)

all: 
	make default_sfx
	make prepare $(BINS)

default_sfx:
	python hammer2cbt.py --fxammo 9 --fxmono --fxnamelist sfxnames.txt hammered.sav 0 huge/sfx

compile.bat: Makefile
	@echo "REM Automatically generated from Makefile" > compile.bat
	@make -sn | sed y/\\//\\\\/ | sed s/mkdir\ -p\/mkdir\/ | grep -v make >> compile.bat

# Compile .c files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# Compile .c files in "res/" to .o object files
$(OBJDIR)/%.o:	$(RESDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# Compile .c files in "huge/" to .o object files
$(OBJDIR)/%.o:	$(BGMDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<	

# Compile .c files in "huge/" to .o object files
$(OBJDIR)/%.o:	$(SFXDIR)/%.c
	$(LCC) $(LCCFLAGS) -c -o $@ $<	

# Compile .s assembly files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.s
	$(LCC) $(LCCFLAGS) -c -o $@ $<

# If needed, compile .c files in "src/" to .s assembly files
# (not required if .c is compiled directly to .o)
$(OBJDIR)/%.s:	$(SRCDIR)/%.c
	$(LCC) $(LCCFLAGS) -S -o $@ $<

# Link the compiled object files into a .gb ROM file
$(BINS): $(OBJS)
	$(LCC) $(LCCFLAGS) -o $(BINS) $(OBJS) -Wl-lhuge/hUGEDriver.lib

prepare:
	mkdir $(OBJDIR)
	