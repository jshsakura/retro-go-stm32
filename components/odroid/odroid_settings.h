#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "rg_emulators.h"
#include "odroid_input.h"

typedef enum
{
    ODROID_START_ACTION_RESUME = 0,
    ODROID_START_ACTION_NEWGAME,
    ODROID_START_ACTION_NETPLAY
} ODROID_START_ACTION;

typedef enum
{
    ODROID_REGION_AUTO = 0,
    ODROID_REGION_NTSC,
    ODROID_REGION_PAL
} ODROID_REGION;

void odroid_settings_init(void);
void odroid_settings_reset(void);
void odroid_settings_commit(void);

int32_t odroid_settings_FontSize_get();
void odroid_settings_FontSize_set(int32_t);

int32_t odroid_settings_Volume_get();
void odroid_settings_Volume_set(int32_t value);

char* odroid_settings_RomFilePath_get();
void odroid_settings_RomFilePath_set(const char* value);

int32_t odroid_settings_Backlight_get();
void odroid_settings_Backlight_set(int32_t value);

int32_t odroid_settings_StartupApp_get();
void odroid_settings_StartupApp_set(int32_t value);

char* odroid_settings_StartupFile_get(void);
void odroid_settings_StartupFile_set(retro_emulator_file_t *value);

uint16_t odroid_settings_MainMenuTimeoutS_get(void);
void odroid_settings_MainMenuTimeoutS_set(uint16_t value);

uint16_t odroid_settings_MainMenuSelectedTab_get(void);
void odroid_settings_MainMenuSelectedTab_set(uint16_t value);

uint16_t odroid_settings_MainMenuCursor_get(void);
void odroid_settings_MainMenuCursor_set(uint16_t value);

/** Persisted ROM browser subfolder (relative to system ROM dir); empty = root. */
void odroid_settings_MainMenuBrowseSubpath_set(const char *subpath);
bool odroid_settings_MainMenuBrowseSubpath_get(char *buf, size_t buf_size);

ODROID_START_ACTION odroid_settings_StartAction_get();
void odroid_settings_StartAction_set(ODROID_START_ACTION value);

int32_t odroid_settings_AudioSink_get();
void odroid_settings_AudioSink_set(int32_t value);

ODROID_REGION odroid_settings_Region_get();
void odroid_settings_Region_set(ODROID_REGION value);

int32_t odroid_settings_Palette_get();
void odroid_settings_Palette_set(int32_t value);

int32_t odroid_settings_SpriteLimit_get();
void odroid_settings_SpriteLimit_set(int32_t value);

int32_t odroid_settings_DisplayScaling_get();
void odroid_settings_DisplayScaling_set(int32_t value);

int32_t odroid_settings_DisplayFilter_get();
void odroid_settings_DisplayFilter_set(int32_t value);

int32_t odroid_settings_DisplayRotation_get();
void odroid_settings_DisplayRotation_set(int32_t value);

int32_t odroid_settings_DisplayOverscan_get();
void odroid_settings_DisplayOverscan_set(int32_t value);

#if CHEAT_CODES == 1
bool odroid_settings_ActiveGameGenieCodes_is_enabled(char *game_path, int code_index);
bool odroid_settings_ActiveGameGenieCodes_set(char *game_path, int code_index, bool enable);
#endif

bool odroid_settings_DebugMenuDebugClockAlwaysOn_get();
void odroid_settings_DebugMenuDebugClockAlwaysOn_set(bool value);

/** Welcome prompt state: 0 = not anchored, 1 = shown, else YYYYMMDD anchor date. */
uint32_t odroid_settings_WelcomePrompt_get(void);
void odroid_settings_WelcomePrompt_set(uint32_t value);

/*** Generic functions ***/

void odroid_settings_string_set(const char *key, const char *value);
char* odroid_settings_string_get(const char *key, const char *default_value);

int32_t odroid_settings_int32_get(const char *key, int32_t value_default);
void odroid_settings_int32_set(const char *key, int32_t value);

int32_t odroid_settings_app_int32_get(const char *key, int32_t value_default);
void odroid_settings_app_int32_set(const char *key, int32_t value);

uint8_t odroid_settings_cpu_oc_level_get(void);
void odroid_settings_cpu_oc_level_set(uint8_t oc);

/* Per-emulator, user-editable controls.  The small mapping is stored in a
 * separate SD file for each APPID, so adding controls does not grow the
 * resident /CONFIG object (or reset unrelated preferences). */
#define ODROID_KEYMAP_MAX_ACTIONS 8
#define ODROID_KEYMAP_OFF         0xffu

enum {
    ODROID_KEYMAP_NES_A = 0,
    ODROID_KEYMAP_NES_B,
    ODROID_KEYMAP_NES_START,
    ODROID_KEYMAP_NES_SELECT,
};

enum {
    ODROID_KEYMAP_SNES_B = 0,
    ODROID_KEYMAP_SNES_Y,
    ODROID_KEYMAP_SNES_SELECT,
    ODROID_KEYMAP_SNES_START,
    ODROID_KEYMAP_SNES_A,
    ODROID_KEYMAP_SNES_X,
    ODROID_KEYMAP_SNES_L,
    ODROID_KEYMAP_SNES_R,
};

enum {
    ODROID_KEYMAP_MD_A = 0,
    ODROID_KEYMAP_MD_B,
    ODROID_KEYMAP_MD_C,
    ODROID_KEYMAP_MD_X,
    ODROID_KEYMAP_MD_Y,
    ODROID_KEYMAP_MD_Z,
    ODROID_KEYMAP_MD_MODE,
    ODROID_KEYMAP_MD_START,
};

bool        odroid_keymap_supported(void);
int         odroid_keymap_action_count(void);
const char *odroid_keymap_action_name(int action);
uint8_t     odroid_keymap_get(int action);
void        odroid_keymap_set(int action, uint8_t physical_key);
void        odroid_keymap_reset(void);
void        odroid_keymap_save(void);
bool        odroid_keymap_is_default(void);
bool        odroid_keymap_pressed(const odroid_gamepad_state_t *pad, int action);
const char *odroid_keymap_physical_name(uint8_t physical_key);
uint8_t     odroid_keymap_physical_step(uint8_t physical_key, int direction);
