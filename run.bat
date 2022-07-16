@echo off

set /p inp=

echo.
CALL :compile_func %inp%
EXIT /B %ERRORLEVEL% 
 :compile_func
   g++ -std=c++17 -DLOCAL -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -D_GLIBCXX_DEBUG_PEDANTIC -D_GLIBCXX_DEBUG %~1 
    
  echo Code compiled successfully input : 
   echo.
   a.exe
   echo.

EXIT /B 0