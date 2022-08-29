@echo off

utils\ctime.exe -begin tetris.ctm

REM REMOVE THIS !!! -wd4311 -wd4302 !!! FROM OPTS
set opts_dev=-D_GAME_INTERNAL
set opts=-FC -GR- -EHa- -nologo -Zi -Wall -WX -W3 -wd4018 -wd5045 -wd4996 -wd4311 -wd4302 %opts_dev%

set code=%cd%
set lib_path=%code%\thirdparty\libs
set include_path=%code%\thirdparty\includes

if not exist build mkdir build

pushd build
 
if not exist SDL2.dll (
  echo BUILD.BAT: Please, put SDL2.dll in ./BUILD dir. 
  exit /B -1w
)

cl %opts% %code%\sdl_game.cpp -Fesdl_game.exe %lib_path%\SDL2\SDL2.lib %lib_path%\SDL2\SDL2main.lib -I%include_path% shell32.lib /link /SUBSYSTEM:WINDOWS

cl %opts% %code%\game.cpp -Fegame.dll -I%include_path% /LD /link /SUBSYSTEM:WINDOWS -EXPORT:UpdateAndRender -EXPORT:UpdateSoundBuffer

popd

utils\ctime.exe -end tetris.ctm %errorlevel%