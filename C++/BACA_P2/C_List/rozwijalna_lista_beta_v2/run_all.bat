@echo off
if not exist "main.cpp" (
    echo Plik z kodem powinien nazywac sie main.cpp
    exit /b 1
)

echo [INFO]  COMPILING main.cpp
g++ -std=c++11 -ggdb -Wall -Wextra -Wno-comment -Wshadow -Wformat=2 -pedantic -pedantic-errors -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -o main.exe main.cpp

if %ERRORLEVEL% NEQ 0 (
    exit /b 1
)

for %%f in (tests\*.in) do (
    (main.exe < "%%f" > tmp.out 2>NUL) >NUL 2>&1
    if !ERRORLEVEL! NEQ 0 (
        echo [RTE] ! %%~nf
    ) else (
        fc /b tmp.out "%%~dpnf.out" >NUL 2>&1
        if !ERRORLEVEL! EQU 0 (
            echo [OK]    %%~nf
        ) else (
            echo [ANS] ! %%~nf
        )
    )
)

del tmp.out main.exe