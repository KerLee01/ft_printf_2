#ifndef FT_PRINTF_BONUS_H
#define FT_PRINTF_BONUS_H

#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define STASH_SIZE 4096

typedef struct s_data
{
   char stash[STASH_SIZE];
   bool write_failed;
   bool if_positive_space;
   bool show_sign;
   bool hex_hash;
   bool left_align;
   bool precision_set;
   char width_padding;
   long total_bytes;
   int current_byte;
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
void i_d_handler(t_data *data, va_list *ap);
void precision_pad(t_data *data, long num);

int ft_strlen(char *str);

void check_flush_insert(t_data *data, char c);

#endif
