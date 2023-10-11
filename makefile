all:
	make linux
	make windows

linux:
	g++ -std=c++11 src/cat.cpp -o bin/linux/cat -static
	g++ -std=c++11 src/cp.cpp -o bin/linux/cp -static
	g++ -std=c++11 src/sleep.cpp -o bin/linux/sleep -static
	g++ -std=c++11 src/timeout.cpp -o bin/linux/timeout -static
	g++ -std=c++11 src/touch.cpp -o bin/linux/touch -static
	#done making the linux version

windows:
	x86_64-w64-mingw32-g++ -std=c++11 src/cat.cpp -o bin/windows/cat.exe -static
	x86_64-w64-mingw32-g++ -std=c++11 src/cp.cpp -o bin/windows/cp.exe -static
	x86_64-w64-mingw32-g++ -std=c++11 src/sleep.windows.cpp -o bin/windows/sleep.exe -static
	#im not dealing with windows strange compile errors,
	#compile it yourself if you want it
	#x86_64-w64-mingw32-g++ -std=c++11 src/timeout.windows.cpp -o bin/windows/timeout.exe -static
	x86_64-w64-mingw32-g++ -std=c++11 src/touch.cpp -o bin/windows/touch.exe -static
	#done making the windows version
