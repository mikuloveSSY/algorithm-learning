#include <stdio.h>
#include <windows.h>   // 用于Sleep函数

void clear_line() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // 获取控制台缓冲区信息
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        columns = csbi.dwSize.X;
    } else {
        // 如果获取失败，默认80列
        columns = 80;
    }

    printf("\r");
    for (int i = 0; i < columns; i++) {
        printf(" ");
    }
    printf("\r");
    fflush(stdout);
}

int main() {
    printf("这是需要被清除的行内容...");
    fflush(stdout);
    Sleep(2000);   // 等待2秒

    clear_line();

    printf("这是新的内容!\n");
    getchar();
    return 0;
}