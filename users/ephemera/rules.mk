# generated from users/ephemera/miryoku.org  -*- buffer-read-only: t -*-

MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
AUTO_SHIFT_ENABLE = yes # Auto Shift
TAP_DANCE_ENABLE = yes
NKRO_ENABLE = yes

SRC += ephemera.c # keymap

# alternative layouts:

# alphas
ifneq ($(strip $(MIRYOKU_ALPHAS)),)
  OPT_DEFS += -DMIRYOKU_ALPHAS_$(MIRYOKU_ALPHAS)
endif

# nav
ifneq ($(strip $(MIRYOKU_NAV)),)
  OPT_DEFS += -DMIRYOKU_NAV_$(MIRYOKU_NAV)
endif

# clipboard
ifneq ($(strip $(MIRYOKU_CLIPBOARD)),)
  OPT_DEFS += -DMIRYOKU_CLIPBOARD_$(MIRYOKU_CLIPBOARD)
endif

# layers
ifneq ($(strip $(MIRYOKU_LAYERS)),)
  OPT_DEFS += -DMIRYOKU_LAYERS_$(MIRYOKU_LAYERS)
endif

# subset mappings
ifneq ($(strip $(MIRYOKU_MAPPING)),)
  OPT_DEFS += -DMIRYOKU_MAPPING_$(MIRYOKU_MAPPING)
endif

ifeq ($(strip $(KEYBOARD)), lily58/rev1)
	OLED_DRIVER_ENABLE = yes
	SRC +=  ./lib/logo_reader.c \
					./lib/keylogger.c \
					./lib/layer_state_reader.c \
					./lib/timelogger.c
endif
ifeq ($(strip $(KEYBOARD)), keebio/iris/rev4)
	ENCODER_ENABLE = yes
endif

EXTRAFLAGS+=-flto
