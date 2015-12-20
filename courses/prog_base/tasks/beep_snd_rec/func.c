#include <windows.h>
struct Note {

double frequency;
char name[5];

};
struct Record {
char name[5];
double frequency;
int t;
};
typedef struct Note Note;
typedef struct Record Record;
struct Note mNotes[3][13] = {
   {{130.82, "Do"}, {138.59 , "Do#"}, {147.83, "Re"}, {155.56, "Re#"}, {164.81, "Mi"}, {174.62, "Fa"}, {185.00, "Fa#"}, {196.00, "Sol"}, {207.00, "Sol#"}, {220.00, "La"}, {233.08, "La#"}, {246.96, "Si"}},
   {{261.63, "Do"}, {277.18 , "Do#"}, {293.66, "Re"}, {311.13, "Re#"}, {329.63, "Mi"}, {349.23, "Fa"}, {369.99, "Fa#"}, {392.00, "Sol"}, {415.30, "Sol#"}, {440.00, "La"}, {466.16, "La#"}, {493.88, "Si"}},
   {{523.25, "Do"}, {554.36 , "Do#"}, {587.32, "Re"}, {622.26, "Re#"}, {659.26, "Mi"}, {698.46, "Fa"}, {739.98, "Fa#"}, {784.00, "Sol"}, {830.60, "Sol#"}, {880.00, "La"}, {932.32, "La#"}, {987.75, "Si"},{0.0,"pause"} }
    };
Record records[10][200];

enum Notes {Do , Do_sh,Re, Re_sh, Mi, Fa, Fa_sh, Sol,Sol_sh, La, La_sh, Si, p };
enum Oct {Small ,first ,second} oct;
enum time {s = 1, m , l = 4};

void record(int oct,int note, int t, int j, int i){
strcpy(records[j][i].name, mNotes[0][note].name);
records[j][i].frequency = mNotes[oct][note].frequency ;
records[j][i].t = t;
}

void play(int oct, int note, int time){
Beep(mNotes[oct][note].frequency,250*time);
}

void print_note(int note){
printf("%s", mNotes[0][note].name);
}

void keys(int x, int y0, int y1){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos;
pos.X = x;
for (int y = y0; y < y1; y++){
                pos.Y = y;
                SetConsoleCursorPosition(hConsole, pos);
                printf("|");
}
}


void fill_b(int i, int color){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos;
for (int y = 0; y < 16; y++){
    for (int x = i; x <  i+ 7; x++){
                pos.X = x;
                pos.Y = y;
                SetConsoleCursorPosition(hConsole, pos);
                SetConsoleTextAttribute(hConsole, color);
        printf(" ");
    }
}

}

void print(int x, int y, int color){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos;
                pos.X = x;
                pos.Y = y;
                SetConsoleCursorPosition(hConsole, pos);
                SetConsoleTextAttribute(hConsole, color);

}

void fill_w_1(int i, int color){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos;
for (int y = 0; y < 25; y++){
    for (int x = i; x <  i  + 7; x++){
                pos.X = x;
                pos.Y = y;
                SetConsoleCursorPosition(hConsole, pos);
                SetConsoleTextAttribute(hConsole, color);
        printf(" ");
    }
}
    for (int y = 16; y < 25; y++){
    for (int x = i+7; x <  i  + 10; x++){
                pos.X = x;
                pos.Y = y;
                SetConsoleCursorPosition(hConsole, pos);
                SetConsoleTextAttribute(hConsole, color);
        printf(" ");
    }




}
}

void fill_w_2(int i, int color){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos;
for (int y = 16; y < 25; y++){
    for (int x = i; x <  i  + 10; x++){
                pos.X = x;
                pos.Y = y;
                SetConsoleCursorPosition(hConsole, pos);
                SetConsoleTextAttribute(hConsole, color);
        printf(" ");
    }
}
    for (int y =0; y < 16; y++){
    for (int x = i+3; x <  i + 7; x++){
                pos.X = x;
                pos.Y = y;
                SetConsoleCursorPosition(hConsole, pos);
                SetConsoleTextAttribute(hConsole, color);
        printf(" ");
    }




}
}


void fill_w_3(int i, int color){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos;
for (int y = 16; y < 25; y++){
    for (int x = i; x <  i  + 3; x++){
                pos.X = x;
                pos.Y = y;
                SetConsoleCursorPosition(hConsole, pos);
                SetConsoleTextAttribute(hConsole, color);
        printf(" ");
    }
}
    for (int y =0; y < 25; y++){
    for (int x = i+3; x <  i + 10; x++){
                pos.X = x;
                pos.Y = y;
                SetConsoleCursorPosition(hConsole, pos);
                SetConsoleTextAttribute(hConsole, color);
        printf(" ");
    }
}
}

void playnp(int m, int n){
printf("%s ",records[m][n].name);
Beep(records[m][n].frequency,250*records[m][n].t);

}

void jingle_bells(){
play(first,Re,m);
play(first,Si,m);
play(first,La,m);
play(first,Sol,m);
play(first,Re,l);
play(second,p,s);
play(first,Re,m);
play(first,Si,m);
play(first,La,m);
play(first,Sol,m);
play(first,Mi,l);
play(second,p,s);
play(first,Mi,m);
play(second,Do,m);
play(first,Si,m);
play(first,La,m);
play(first,Fa_sh,l);
play(second,Re,m);
play(second,Re,m);
play(second,Do,m);
play(first,La,m);
play(first,Si,l);

play(first,Re,m);
play(first,Si,m);
play(first,La,m);
play(first,Sol,m);
play(first,Re,l);
play(second,p,s);
play(first,Re,m);
play(first,Si,m);
play(first,La,m);
play(first,Sol,m);
play(first,Mi,l);
play(second,p,s);
play(first,Mi,m);
play(second,Do,m);
play(first,Si,m);
play(first,La,m);
play(second,Re,m);
play(second,Re,m);
play(second,Re,m);
play(second,Re,m);
play(second,Mi,m);
play(second,Re,m);
play(second,Do,m);
play(first,La,m);
play(first,Sol,l);


play(first,Si,m);
play(first,Si,m);
play(first,Si,l);
play(first,Si,m);
play(first,Si,m);
play(first,Si,l);

play(first,Si,m);
play(second,Re,m);
play(first,Sol,m);
play(first,La,m);
play(first,Si,l);

play(second,Do,m);
play(second,Do,m);
play(second,Do,m);
play(second,Do,m);
play(second,Do,m);
play(first,Si,m);
play(first,Si,m);
play(first,Si,m);
play(first,Si,m);
play(first,La,m);
play(first,La,m);
play(first,Si,m);
play(first,La,l);
play(second,Re,l);

play(first,Si,m);
play(first,Si,m);
play(first,Si,l);
play(first,Si,m);
play(first,Si,m);
play(first,Si,l);

play(first,Si,m);
play(second,Re,m);
play(first,Sol,m);
play(first,La,m);
play(first,Si,l);

play(second,Do,m);
play(second,Do,m);
play(second,Do,m);
play(second,Do,m);
play(second,Do,m);
play(first,Si,m);
play(first,Si,m);
play(first,Si,m);

play(second,Re,m);
play(second,Re,m);
play(second,Do,m);
play(first,La,m);
play(first,Sol,l);
}
