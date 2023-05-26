@echo off
g++ -o test.exe test.cpp
g++ -o soln.exe soln.cpp
g++ -o brute.exe brute.cpp
for /l %%x in (1, 1, 100) do (
    test %%x > input.in
    soln < input.in > output.out 
    brute < input.in > output2.out
    fc output.out output2.out > diagnostics || exit /b
    echo %%x
)
echo all tests passed
pause