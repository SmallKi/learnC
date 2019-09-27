#include<stdio.h>
#include<Windows.h>
_declspec(dllexport) void go() {
	Sleep(1);
	go();
}