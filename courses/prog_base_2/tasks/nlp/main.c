#include <stdio.h>
#include <stdlib.h>
#include "nlp.h"
#define MAX_BUFF_SIZE 100000

int main()
{
    FILE * input = file_new("input.txt","r");
    FILE * output = file_new("output.txt","w");
    char buff[MAX_BUFF_SIZE];
    word_t * word;
    fread(buff,1,MAX_BUFF_SIZE,input);
    removeBrackets(buff);
    text_t * text = text_new(buff);
    text_split(text);
    int sentences_count = text_getSentencesCount(text);
    for (int i = 0; i < sentences_count; i++)
    {

        sentence_split(text_getSentence(text,i));
        int words_count = sentence_getWordsCount(text_getSentence(text,i));
        for (int j = 0; j < words_count; j++)
        {
            word = sentence_getWords(text_getSentence(text,i),j);
            word_handler(word,text_getSentence(text,i),j);
            if (word_getWord(word) != NULL) fprintf(output,"%s,",word_getWord(word));

        }
        fprintf(output,"\n");
    }
    word_free(word);
    text_free(text);
    file_free(input);
    file_free(output);
    printf("Press any key to exit.");
    getch();
    return 0;
}
