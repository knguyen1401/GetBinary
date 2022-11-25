// WHITE color is just the same as NORM, therefore it was deprecated.

#ifdef _WIN32
#include <Windows.h>

void WinEnableColor(){
    DWORD dwMode;
	dwMode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleMode(hOutput, dwMode);
}
#endif

#define NORM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE  "\x1B[34m"
#define MAGNETA  "\x1B[35m" //Well it is purple
#define CYAN  "\x1B[36m"