@echo off
g++ -o test.exe etest.cpp
g++ -o soln.exe esol.cpp
g++ -o brute.exe ebrute.cpp
for /l %%x in (1, 1, 1000) do (
    test %%x > input.in
    soln < input.in > output.out 
    brute < input.in > output2.out
    fc output.out output2.out > diagnostics || exit /b
    echo %%x
)
echo all tests passed
pause