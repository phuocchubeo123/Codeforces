@echo off
g++ -std=c++17 -o test.exe gtest.cpp
g++ -std=c++17 -o soln.exe gsol.cpp
g++ -std=c++17 -o brute.exe gbrute.cpp
for /l %%x in (1, 1, 10000) do (
    echo %%x
    test %%x > gin.txt
    soln < gin.txt > gout.txt 
    brute < gin.txt > gout2.txt
    fc gout.txt gout2.txt > diagnostics || exit /b
)
echo all tests passed
pause