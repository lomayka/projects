#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
void command (char com[], char str[], char str1[] );
void del (char * str);

int main(void){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int fmt1 = FOREGROUND_RED | FOREGROUND_GREEN| FOREGROUND_BLUE |  FOREGROUND_INTENSITY;
    char com[100];
    char str[100];
    char str1[100];
    srand(time(NULL));
    SetConsoleTextAttribute(hConsole, fmt1);
    printf("Please, enter your string.");
    printf("\n");
    gets (str);
    strcpy(str1,str);
    system("cls");
    command(com, str,str1);
}
void command ( char com[], char str[], char str1[]){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int fmt = FOREGROUND_RED | FOREGROUND_INTENSITY;
    int fmt1 = FOREGROUND_RED | FOREGROUND_GREEN| FOREGROUND_BLUE |  FOREGROUND_INTENSITY;// White
    int fmt2 = FOREGROUND_RED | FOREGROUND_BLUE |  FOREGROUND_INTENSITY;// Purple
    int fmt3 = FOREGROUND_GREEN | FOREGROUND_RED |  FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE;// Yellow
    int fmt4 = BACKGROUND_GREEN | BACKGROUND_BLUE;
    int fmt5 = FOREGROUND_GREEN;
     int fmt6 = FOREGROUND_RED | FOREGROUND_INTENSITY| BACKGROUND_GREEN | BACKGROUND_BLUE;;
    int i = 0, j = 0, k = 0, m = 0, len = 0, max_len = 0, s_len = 0, occurance = 0, value = 0, N = 0;
    int n = 6;
    char s ;
    char * Help = "help";
    char * Delete = "delete";
    char * Change_Rand = "change_rand";
    char * Exit = "exit";
    char * Change_rand = "change_rand";
    char * Change_new = "change_new";
    char * Change_new_del = "change_nd";
    char * Print_words = "print_words";
    char * Words_amount = "words_amount";
    char * Max_length = "max_length";
    char * String_length = "string_length";
    char * Entrance = "entrance";
    char * Number = "number";
    char * Delete_spaces = "delete_spaces";
    char * If_int = "if_int";
    char sep[50];
    for (i = 0; i < 35; i++){
            if (i <=32){
    sep[i]= 32+i;
            }
            else if(i > 32 ){
        sep[i]= 91+i;
            }
    }
    COORD pos;
    for (k = 1; k < 14; k++){
            for (m = 1; m < 80; m++){
    pos.X = m;
    pos.Y = k;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt4);
    printf(" ");
            }
    }
    pos.X = 10;
    pos.Y = 6;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
    printf("%s", str);


     while (1){

    i = 1;
    while(i<79){
    pos.X = i;
    pos.Y = 0;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt5);
    printf("*");
    pos.X = i;
    pos.Y = 14;
    SetConsoleCursorPosition(hConsole, pos);
    printf("*");
    i++;
    }
    j = 1;
    while (j < 14){
    pos.X = 0;
    pos.Y = j;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt5);
    printf("*");
    pos.X = 79;
    pos.Y = j;
    SetConsoleCursorPosition(hConsole, pos);
    printf("*");
    j++;
    }
    pos.X = 0;
    pos.Y = 15;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt1);
    printf("Please, enter your command.\n>> ");
    gets (com);
    system("cls");
    for (k = 1; k < 14; k++){
            for (m = 1; m < 80; m++){
    pos.X = m;
    pos.Y = k;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt4);
    printf(" ");
            }
    }
    if (0 == strcmp(Help,com)){
    pos.X = 0;
    pos.Y = 17;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt1);
    printf("1.                         Delete srting\n");
    printf("2.                         Change to string with random characters\n");
    printf("3.                         Change to new, entered by user\n");
    printf("4.                         Change to new, entered by user only alphabetic. \n");
    printf("5.                         Print words\n");
    printf("6.                         Print amount of words\n");
    printf("7.                         Print word with max length and its length\n");
    printf("8.                         Print length of the string\n");
    printf("9.                         Print amount of entrance \n");
    printf("10.                        Print amount of number characters \n");
    printf("11.                        Delete excess spaces\n");
    printf("12.                        Print dividers of int number\n");
    printf("13.                        Exit\n");
    pos.X = n;
    pos.Y = 17;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt2);
    printf("delete ");
    pos.X = n;
    pos.Y = 18;
    SetConsoleCursorPosition(hConsole, pos);
    printf("change_rand ");
    pos.X = n;
    pos.Y = 19;
    SetConsoleCursorPosition(hConsole, pos);
    printf("change_new");
    pos.X = n;
    pos.Y = 20;
    SetConsoleCursorPosition(hConsole, pos);
    printf("change_nd");//must be changed
    pos.X = n;
    pos.Y = 21;
    SetConsoleCursorPosition(hConsole, pos);
    printf("print_words");
    pos.X = n;
    pos.Y = 22;
    SetConsoleCursorPosition(hConsole, pos);
    printf("words_amount");
    pos.X = n;
    pos.Y = 23;
    SetConsoleCursorPosition(hConsole, pos);
    printf("max_length");
    pos.X = n;
    pos.Y = 24;
    SetConsoleCursorPosition(hConsole, pos);
    printf("string_length");
    pos.X = n;
    pos.Y = 25;
    SetConsoleCursorPosition(hConsole, pos);
    printf("entrance");
    pos.X = 6;
    pos.Y = 26;
    SetConsoleCursorPosition(hConsole, pos);
    printf("number");
    pos.X = 6;
    pos.Y = 27;
    SetConsoleCursorPosition(hConsole, pos);
    printf("delete_spaces");
    pos.X = 6;
    pos.Y = 28;
    SetConsoleCursorPosition(hConsole, pos);
    printf("if_int");
    pos.X = 6;
    pos.Y = 29;
    SetConsoleCursorPosition(hConsole, pos);
    printf("exit");
    printf("\n");
    pos.X = 10;
    pos.Y = 6;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
    printf("%s", str);
    }
    else if(0 == strcmp(Delete,com)){
            int i;
            str[0] = '\0';
     }
    else if(0 == strcmp(Exit,com)){
            i = 1;
    while(i<79){
    pos.X = i;
    pos.Y = 0;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt5);
    printf("*");
    pos.X = i;
    pos.Y = 14;
    SetConsoleCursorPosition(hConsole, pos);
    printf("*");
    i++;
    }
    j = 1;
    while (j < 14){
    pos.X = 0;
    pos.Y = j;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt5);
    printf("*");
    pos.X = 79;
    pos.Y = j;
    SetConsoleCursorPosition(hConsole, pos);
    printf("*");
    j++;
    }
    pos.X = 10;
    pos.Y = 6;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
    printf("%s", str);
    pos.X = 0;
    pos.Y = 16;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt1);
        exit(EXIT_SUCCESS);
    }
    else if (0  == strcmp(Change_rand,com)){


    i = 1;
    while(i<79){
    pos.X = i;
    pos.Y = 0;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt5);
    printf("*");
    pos.X = i;
    pos.Y = 14;
    SetConsoleCursorPosition(hConsole, pos);
    printf("*");
    i++;
    }
    j = 1;
    while (j < 14){
    pos.X = 0;
    pos.Y = j;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt5);
    printf("*");
    pos.X = 79;
    pos.Y = j;
    SetConsoleCursorPosition(hConsole, pos);
    printf("*");
    j++;
    }
    pos.X = 10;
    pos.Y = 6;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
    printf("%s", str);
    SetConsoleTextAttribute(hConsole, fmt1);
        pos.X = 0;
        pos.Y = 17;
    SetConsoleCursorPosition(hConsole, pos);
        printf("Please, enter string length\n>> ");
        scanf("%i", &N);
        if (N)
        if (strlen(str) < N){
        for (i = 0;  i < N; i++){
        str[i] = rand() % 94 + ' ';
        }
    }
     if (strlen(str) > N){
        for (i = 0; i < strlen(str); i++){
                if (i < N){
            str[i] = rand() % 94 + ' ';
                }
                else {
                  str[i] = '\0';
                }
        }
    }
      pos.X = 0;
    pos.Y = 15;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt1);
    printf("Please, enter your command.\n>> ");
    gets (com);
    system("cls");
    for (k = 1; k < 14; k++){
            for (m = 1; m < 80; m++){
    pos.X = m;
    pos.Y = k;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt4);
    printf(" ");
            }
    }
    pos.X = 10;
    pos.Y = 6;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
    printf("%s", str);
    }
    else if(0 == strcmp(Change_new,com)){
    i = 1;
    while(i<79){
    pos.X = i;
    pos.Y = 0;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt5);
    printf("*");
    pos.X = i;
    pos.Y = 14;
    SetConsoleCursorPosition(hConsole, pos);
    printf("*");
    i++;
    }
    j = 1;
    while (j < 14){
    pos.X = 0;
    pos.Y = j;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt5);
    printf("*");
    pos.X = 79;
    pos.Y = j;
    SetConsoleCursorPosition(hConsole, pos);
    printf("*");
    j++;
    }
    pos.X = 10;
    pos.Y = 6;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
    printf("%s", str);
    pos.X = 0;
    pos.Y = 15;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt1);
        pos.X = 0;
        pos.Y = 17;
    SetConsoleCursorPosition(hConsole, pos);
    printf("Please, enter new string\n>> ");
    gets(str);
    system("cls");
    for (k = 1; k < 14; k++){
            for (m = 1; m < 80; m++){
    pos.X = m;
    pos.Y = k;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt4);
    printf(" ");
            }
    }
    pos.X = 10;
    pos.Y = 6;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
    printf("%s", str);

    }
    else if(0 == strcmp(Change_new_del,com)){
            i = 1;
    while(i<79){
    pos.X = i;
    pos.Y = 0;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt5);
    printf("*");
    pos.X = i;
    pos.Y = 14;
    SetConsoleCursorPosition(hConsole, pos);
    printf("*");
    i++;
    }
    j = 1;
    while (j < 14){
    pos.X = 0;
    pos.Y = j;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt5);
    printf("*");
    pos.X = 79;
    pos.Y = j;
    SetConsoleCursorPosition(hConsole, pos);
    printf("*");
    j++;
    }
    pos.X = 10;
    pos.Y = 6;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
    printf("%s", str);
    pos.X = 0;
    pos.Y = 15;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt1);
        pos.X = 0;
        pos.Y = 17;
    SetConsoleCursorPosition(hConsole, pos);
    printf("Please, enter new string\n>> ");
    gets(str);
    system("cls");
    for (k = 1; k < 14; k++){
            for (m = 1; m < 80; m++){
    pos.X = m;
    pos.Y = k;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt4);
    printf(" ");
            }
    }
    pos.X = 10;
    pos.Y = 6;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
    str1[0] = '\0';
    str = strtok(str,sep);
    while (str != NULL){
        strcat(str1,str);
        str = strtok(NULL, sep);
    }
    str = malloc(100);
    str[0] = '\0';
    strcpy(str,str1);
    printf("%s", str);

    }
    else if (0 == strcmp(Print_words,com)){
    pos.X = 10;
    pos.Y = 8;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
  strcpy(str1,str);
   str = strtok(str,sep);
    while (str != NULL){
        printf("%s ", str);
        str = strtok(NULL, sep);
    }
    str = malloc(100);
    str[0] = '\0';
    strcpy(str,str1);
    }
    else if(0 == strcmp(Words_amount,com)){
    pos.X = 10;
    pos.Y = 8;
    SetConsoleCursorPosition(hConsole, pos);
    strcpy(str1,str);
   str = strtok(str,sep);
      i = 0;
    while (str != NULL){
            i++;
        str = strtok(NULL, sep);
    }
    str = malloc(100);
    str[0] = '\0';
    strcpy(str,str1);
    printf("%d", i);
    }
    else if (0 == strcmp(Max_length, com)){
   strcpy(str1,str);
   max_len = 0;
   str = strtok(str,sep);
      i = 1;
    while (str != NULL){
        len = strlen(str);
        if (len > max_len){
            max_len = len;
        }
        str = strtok(NULL, sep);
    }
    str = malloc(100);
    str[0] = '\0';
    strcpy(str,str1);
    str = strtok(str,sep);
    while (str != NULL){
        len = strlen(str);
        if (len == max_len){
    pos.X = 10;
    pos.Y = 6;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
             printf("Word:%s  ", str);
             break;
        }
             str = strtok(NULL, sep);
    }
    pos.X = 10;
    pos.Y = 8;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
    printf("Length:%d  ", max_len);
    strcpy(str,str1);
    }
    else if (0 == strcmp(String_length,com)){
    s_len = strlen(str);
    pos.X = 10;
    pos.Y = 8;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
    printf("%d", s_len);
    }
    else if (0 == strcmp(Entrance, com)){
       i = 1;
    while(i<79){
    pos.X = i;
    pos.Y = 0;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt5);
    printf("*");
    pos.X = i;
    pos.Y = 14;
    SetConsoleCursorPosition(hConsole, pos);
    printf("*");
    i++;
    }
    j = 1;
    while (j < 14){
    pos.X = 0;
    pos.Y = j;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt5);
    printf("*");
    pos.X = 79;
    pos.Y = j;
    SetConsoleCursorPosition(hConsole, pos);
    printf("*");
    j++;
    }
    pos.X = 10;
    pos.Y = 6;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
    printf("%s", str);
    pos.X = 0;
    pos.Y = 15;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt1);
        pos.X = 0;
        pos.Y = 17;
    SetConsoleCursorPosition(hConsole, pos);
    printf("Please, enter a character.\n>> ");
    scanf("%c", &s);
    system("cls");
    for (k = 1; k < 14; k++){
            for (m = 1; m < 80; m++){
    pos.X = m;
    pos.Y = k;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt4);
    printf(" ");
            }
    }
    pos.X = 10;
    pos.Y = 6;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
    occurance = 0;
    for (i = 0; i < strlen(str); i++){
        if (*(str + i)== s){
              occurance++;
              }
    }
    printf("%d", occurance);
    pos.X = 0;
    pos.Y = 15;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt1);
    printf("Please, enter your command.\n>> ");
    gets (com);
    }
    else if (0 == strcmp(Number,com)){
    pos.X = 10;
    pos.Y = 6;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
            occurance = 0;
        for (i = 0; i < strlen(str); i++){
            if (*(str+i) >= 48 && *(str+i) <=57  ){
               occurance++;
            }
        }
    printf("%d", occurance);
    }
   else if (0 == strcmp(Delete_spaces,com)){
    pos.X = 10;
    pos.Y = 6;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
    str1[0] = '\0';
    str = strtok(str,sep);
    while (str != NULL){
        strcat(str1,str);
        strcat(str1," ");
        str = strtok(NULL, sep);
    }
    str = malloc(100);
    str[0] = '\0';
    strcpy(str,str1);
    printf("%s", str);
    }
    else if(0 == strcmp(If_int,com)){
    value = atoi(str);
    pos.X = 10;
    pos.Y = 6;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
    for (i = 1; i <=value; i++){
        if (value % i == 0){
            printf("%d ", i);
        }
    }
    }
    else{
    pos.X = 0;
    pos.Y = 18;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt);
    printf("Invalid command, try again ");
    printf("\n");
    pos.X = 10;
    pos.Y = 6;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, fmt3);
    printf("%s", str);

    }

     }
}

