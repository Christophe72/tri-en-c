@echo off
set CC=C:\gcc-15.2.0\bin\gcc.exe
set CFLAGS=-Wall -Wextra -std=c11
set TARGET=bubble_sort
set SRC=main.c bubble_sort.c saisie.c

if "%1"=="clean" (
    del /f %TARGET%.exe 2>nul
    echo Nettoyage effectue.
    exit /b
)

echo Compilation de %SRC%...
%CC% %CFLAGS% %SRC% -o %TARGET%
if %errorlevel%==0 (
    echo OK : %TARGET%.exe genere.
) else (
    echo ERREUR de compilation.
)
