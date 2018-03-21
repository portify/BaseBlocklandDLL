mkdir gccOutput
gcc -c *.cpp
gcc -shared *.o -o gccOutput/a.dll -lpsapi
del *.o