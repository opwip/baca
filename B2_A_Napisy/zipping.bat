@echo off
REM Check if kod.cpp exists in the current directory
if not exist "kod.cpp" (
    echo Error: kod.cpp not found in the current directory.
    pause
    exit /b 1
)

REM Delete previous kod.zip if it exists
if exist "kod.zip" (
    del "kod.zip"
    if errorlevel 1 (
        echo Error: Could not delete existing kod.zip.
        pause
        exit /b 1
    )
)

REM Zip kod.cpp into kod.zip using built-in Windows compression
powershell -Command "Compress-Archive -Path 'kod.cpp' -DestinationPath 'kod.zip' -Force"
if errorlevel 1 (
    echo Error: Failed to create kod.zip.
    pause
    exit /b 1
)

echo Successfully created kod.zip from kod.cpp.