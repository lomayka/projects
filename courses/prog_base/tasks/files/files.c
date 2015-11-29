void fprocess(const char * pread, const char * pwrite){

FILE * fp = fopen(pread, "r");
    char * b ;
    char * s;
    int  N = 0, m = 0,n = 1;
    int p = 0, d, min, min_index;
    while (n <= 10){
    fgets(b,100,fp);
    n++;
    }
    b = strtok(b," ");
    N = atoi(b);
    b = strtok(NULL,",");
    p = atoi(b);
    //min = p;
    for (m = 0; m < N-1; m++){
    b = strtok(NULL,",");
    d = atoi(b);
    if (p > d){
        p = d;
    }

    }
fclose(fp);
fflush(fp);
FILE * pf = fopen(pwrite, "w");
fprintf(pf,"%d",p);
fclose(pf);

}
