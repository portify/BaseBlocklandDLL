mkdir output
gcc -c *.cpp
gcc -shared *.o -o output/a.dll -lpsapi
del *.o