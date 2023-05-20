@echo off
g++ -o ktest.exe ktest.cpp
g++ -o ksol.exe ksol.cpp
g++ -o kbrute.exe kbrute.cpp
for /l %%x in (1, 5, 3000) do (
    ktest %%x > input.in
    ksol < input.in > output.out 
    kbrute < input.in > output2.out
    fc output.out output2.out > diagnostics || exit /b
    echo %%x
)
echo all tests passed
pause