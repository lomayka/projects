#ifndef List_H
#define List_H

#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100


class List
{
private:
	void * arr[MAX_LIST_SIZE];
	int size;
public:
	List(){
		this->size = 0;
	}
	void list_add(void * data)
	{
		this->arr[this->size] = data;
		this->size++;
	}
	void * list_getById(int id){
		return this->arr[id];
	}
	int list_getSize()
	{
		return this->size;
	}
	void list_delete(int index)
	{
		for (int i = index; i < this->size-1; i++){
			this->arr[i] = this->arr[i + 1];
		}
		this->size--;
	}


};

#endif