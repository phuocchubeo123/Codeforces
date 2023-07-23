@echo off
g++ -o test.exe %1test.cpp
g++ -o sol.exe %1sol.cpp
g++ -o brute.exe %1brute.cpp
for /l %%x in (1, 1, 100) do (
    test %%x > %1in.txt
    sol < %1in.txt > %1out1.txt
    brute < %1in.txt > %1out2.txt
    fc %1out1.txt %1out2.txt > diagnostics || exit /b
    echo %%x
)
echo all tests passed
pause