/* 
Author: github.com/annadostoevskaya
File: platform_game.h
Date: August 28th 2022 10:05 pm 

Description: <empty>
*/

#ifndef PLATFROM_GAME_H
#define PLATFROM_GAME_H

#include "base_types.h"

#define PERMANENT_STORAGE_SIZE 4096

struct game_memory
{
    u8 PermanentStorage[PERMANENT_STORAGE_SIZE]; // NOTE(annad): We have to fit in 4KB
    u64 PermanentStorageSize;
};

struct game_time 
{
    u64 BeginTime;
    u64 EndTime;
    u32 dt;
};

enum Keys 
{
    KEY_NOTHING = 0,
    
    KEY_MOVE_DOWN,
    KEY_MOVE_LEFT,
    KEY_MOVE_RIGHT,
    
    KEY_ROTATE_LEFT,
    KEY_ROTATE_RIGHT,
    
#ifdef _GAME_INTERNAL
    KEY_SPACE,
#endif
    
    KEY_TOTAL
};

struct game_input 
{
    b32 Changed;
    Keys PressedKey;
};

struct game_screen_buffer 
{
    u32 Width;
    u32 Height;
    u32 Pitch;
    void *Memory;
};

struct game_sound_buffer
{
    i16 *Stream;
    u32 StreamLen;
    u32 Frequency;
    u16 Samples;
};

#define GAME_UPDATE_AND_RENDER(name) void name(game_screen_buffer *Buffer, \
game_input *Input, \
game_memory *Memory, \
game_time *Time)

typedef GAME_UPDATE_AND_RENDER(game_update_and_render);

#define GAME_UPDATE_SOUND_BUFFER(name) void name(game_memory *Memory, \
game_sound_buffer *SoundBuffer)

typedef GAME_UPDATE_SOUND_BUFFER(game_update_sound_buffer);

#endif //PLATFROM_GAME_H

