@echo off
REM Double-click this file to build NumberGuesser.exe
REM Requires g++ (MinGW-w64). Easiest install: winget install BrechtSanders.WinLibs.POSIX.UCRT

setlocal
cd /d "%~dp0"

where g++ >nul 2>nul
if errorlevel 1 (
    echo.
    echo   ERROR: g++ was not found on your PATH.
    echo   Install MinGW-w64, for example:
    echo       winget install BrechtSanders.WinLibs.POSIX.UCRT
    echo   then open a NEW terminal and run this script again.
    echo.
    pause
    exit /b 1
)

echo Building NumberGuesser.exe ...
g++ -std=c++17 -O2 -static -o NumberGuesser.exe main.cpp
if errorlevel 1 (
    echo.
    echo   Build FAILED.
    pause
    exit /b 1
)

echo.
echo   Done. Run NumberGuesser.exe
echo.
pause
