# Copyright 2019 Manna Harbour
# https://github.com/manna-harbour/miryoku

TAP_DANCE_ENABLE = yes
NKRO_ENABLE = yes
COMBO_ENABLE = yes
# WPM_ENABLE = yes

# reduce firmware size
AUDIO_ENABLE   = no
LINK_TIME_OPTIMIZATION_ENABLE = yes
SPACE_CADET_ENABLE=no

ifeq ($(strip $(KEYBOARD)), lily58/rev1)
	OLED_ENABLE = yes
	OLED_DRIVER = SSD1306
	SRC +=  ./lib/logo_reader.c \
					./lib/layer_state_reader.c
endif
ifeq ($(strip $(KEYBOARD)), keebio/iris/rev4)
	ENCODER_ENABLE = yes
endif

EXTRAFLAGS+=-flto 

