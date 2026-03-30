#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

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

int _printf(const char * const format, ...);
void print_char(va_list *ap);
void print_int(va_list *ap);
void print_double(va_list *ap);
void print_string(va_list *ap);

#endif
