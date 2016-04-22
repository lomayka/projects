#ifndef PROG_H_INCLUDED
#define PROG_H_INCLUDED

typedef struct {
	char * name;
	char * position;
} company_t;

typedef struct {
	char * 	name;
	char * 	surname;
	char * data_birth;
	int 	year;
	double	rating;
	company_t company;
} programmer_t;

programmer_t
programmer_empty(void);

const char *
programmer_toJSON(const programmer_t * self);

const char *
programmer_listToJSON(const programmer_t * const studentList, int programerListSize);

#endif // PROG_H_INCLUDED
