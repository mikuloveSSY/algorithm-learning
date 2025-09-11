#include <stdio.h>
#include <windows.h>   // ����Sleep����

void clear_line() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // ��ȡ����̨��������Ϣ
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        columns = csbi.dwSize.X;
    } else {
        // �����ȡʧ�ܣ�Ĭ��80��
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
    printf("������Ҫ�������������...");
    fflush(stdout);
    Sleep(2000);   // �ȴ�2��

    clear_line();

    printf("�����µ�����!\n");
    getchar();
    return 0;
}