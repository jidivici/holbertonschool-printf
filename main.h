#ifndef POINTER_H
#define POINTER_H

#include <stdio.h>
#include <stdarg.h>

int _putchar(char c);
int _strlen(char *str);

/**
 * struct op_s - Structure pour associer un caractère à une fonction
 * @op: Le caractère représentant le type à afficher
 * @f: Pointeur de fonction pointe avec le va list adequate.
 *
 * Cette structure permet de lier un type de donnée print
 * dans des fonctions variadiques comme print_all.
 */
typedef struct op_s
{
	char op;
	void (*f)(va_list *);
} op_t;


void print_string(va_list *ap);
void print_double(va_list *ap);
void print_string(va_list *ap);
int _printf(const char *format, ...);

#endif
