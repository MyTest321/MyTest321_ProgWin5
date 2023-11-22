@REM #change current directory to this file
@%~d0
@cd %~dp0

@REM why use -A Win32: https://learn.microsoft.com/en-us/answers/questions/1153918/createwindow-error-identifier-gwl-hinstance-is-und

cmake -G "Visual Studio 17 2022" -A Win32 -B build/ProgWin5-x86-windows .

@pause