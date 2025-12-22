#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define STASH_SIZE 4096
#define FLAG_SIZE 10

typedef struct s_data
{
   char stash[STASH_SIZE];
   bool if_positive_space;
   bool show_num_sign;
   bool hex_hash;
   bool left_align;
   bool zero_pad;
   bool precision_set;
   char width_padding;
   int total_bytes;
   int current_byte;
   char flag[FLAG_SIZE];
   int width;
   int precision;
   char specifier;
} t_data;

int ft_printf(const char *format, ...);

void c_handler(t_data *data, va_list *ap);
void s_handler(t_data *data, va_list *ap);
void p_handler(t_data *data, va_list *ap);
void x_X_handler(t_data *data, va_list *ap);
void u_handler(t_data *data, va_list *ap);

int ft_strlen(char *str);
char *ft_memset(char *str, int c, size_t n);
char *ft_memcpy(char *dest, char *src, size_t n);

void check_flush_insert(t_data *data, char c);

#endif
