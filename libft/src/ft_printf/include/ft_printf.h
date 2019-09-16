/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idunaver <idunaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:03:52 by idunaver          #+#    #+#             */
/*   Updated: 2019/09/16 16:34:07 by idunaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "get_next_line.h"
# include "libft.h"
# include <stdarg.h>
# include <float.h>
# include <stdio.h>

# define FLAG_MINUS 1
# define FLAG_PLUS 2
# define FLAG_SPACE 4
# define FLAG_OCT 8
# define FLAG_ZERO 16
# define SIZE_LL 1
# define SIZE_L 2
# define SIZE_H 4
# define SIZE_HH 8
# define MAX_POWER 10
# define BASE_INT 2
# define MAX_CELL 100000000
# define LEN_ARR 1500
# define SIZE_LLL 16

typedef unsigned long long int	t_ulli;

typedef long long int			t_lli;

typedef const char				t_cc;

typedef enum
{
	false,
	true
}	t_bool;

typedef struct					s_printf
{
	char						type;
	char						flags;
	int							width;
	int							accuracy;
	char						size;
	t_bool						sign;
	int							len;
	t_bool						acc;
	unsigned					l_count;
	unsigned					count_l;
	unsigned					h_count;
	int							printed;
}								t_printf;

typedef struct					s_buffer
{
	unsigned					s;
	char						temp[22];
	char						buffer[512];
}								t_buffer;

typedef union
{
	unsigned long				unsignedlong;
	long double					longdouble;
}								t_longdoubletounsignedlong;

typedef struct					s_longdouble
{
	int							sign;
	int							exp;
	unsigned long				mantis;
}								t_longdouble;

typedef struct					s_arrayint
{
	unsigned long int			intresult[LEN_ARR];
	unsigned long int			inttmp[LEN_ARR];
	int							lenarr;
	int							iarr;
	int							jarr;
}								t_arrayint;

typedef struct					s_temp
{
	char						*tmp;
	char						*temp;
	char						*result_temp;
}								t_temp;

typedef struct					s_powerbits
{
	int							power;
	int							countpower;
	int							remainpower;
	int							base;
	int							numofbits;
	int							flag;
}								t_powerbits;

typedef struct					s_doubletochar
{
	char						*inttochar;
	char						*nulls;
	char						*fractiontochar;
}								t_doubletochar;

typedef struct					s_workwithmantis
{
	int							numofintbits;
	char						*result_tmp;
}								t_workwithmantis;

int								ft_printf(t_cc *format, ...);
t_cc							*ft_check_ptc(va_list ap,
t_cc *format, t_printf *data, t_buffer *bf);
int								ft_specifier_format(
t_cc *format, t_printf *data);
void							ft_choose_print(
va_list ap, t_printf *data, t_buffer *bf);
void							ft_dioux_x(va_list ap,
t_printf *data, t_buffer *bf);
void							ft_print_di(t_printf *data,
t_buffer *bf);
void							ft_print_oux_x(t_printf *data,
t_buffer *bf);
void							ft_print_char(va_list ap,
t_printf *data, t_buffer *bf);
void							ft_print_string(va_list ap,
t_printf *data, t_buffer *bf);
void							ft_print_percent(t_printf *data,
t_buffer *bf);
int								type(char c);
void							ft_itoa_base(t_ulli value, int base,
t_printf *data, t_buffer *bf);
void							ft_check_buffer(t_printf *data,
t_buffer *bf);
void							ft_add_sign(t_printf *data,
t_buffer *bf);
void							ft_fill_bf(t_printf *data,
t_buffer *bf);
void							ft_fill_spaces_di(t_printf *data,
t_buffer *bf);
void							ft_fill_zeroes_di(t_printf *data,
t_buffer *bf);
void							ft_fill_spaces_oux(t_printf *data,
t_buffer *bf);
void							ft_fill_zeroes_oux(t_printf *data,
t_buffer *bf);
void							ft_print_int(int nbr);
void							ft_longdouble(va_list ap,
t_printf *data, t_buffer *bf);
int								ft_minpowerfractional
(unsigned long mantis);
char							*ft_numtochar(t_arrayint arrayint);
t_powerbits						ft_bitspowercontructor(t_powerbits bitspower);
t_arrayint						ft_fillarray(t_powerbits bitspower,
t_arrayint arrayint);
char							*ft_workwithmantis(t_longdouble longdouble);
t_arrayint						ft_findingintpower(t_longdouble longdouble,
int numofintbits, t_powerbits bitspower);
t_arrayint						ft_findingfractionpower(t_longdouble longdouble,
int numofintbits, t_powerbits bitspower);
char							*ft_fillnulls(int exp, char *fraction,
unsigned long mantis);
t_arrayint						ft_multlongnumbyashort(t_arrayint arrayint,
int power, int base);
t_arrayint						ft_multlongnumbyaten(t_arrayint arrayint);
int								ft_exponentiation(int power, int number);
t_arrayint						ft_summpower(t_arrayint arrayint);
int								ft_maxindex(t_arrayint arrayint);
void							ft_printlongdouble(char *result, t_printf *data,
int sign, t_buffer *bf);
void							ft_printfractional(t_printf *data, char *result,
t_buffer *bf);
char							*ft_rounding(char *result, long long accuracy);
char							*ft_rounding_fraction(char *result,
long long accuracy);
char							*ft_if_five_in_fractional(char *result,
int check, long long accuracy);
char							*ft_replace_num_round(int check,
long long accuracy, char *result);
t_arrayint						ft_bzeroarrs(void);
t_arrayint						ft_bzerotmparr(t_arrayint arrayint);
t_arrayint						ft_separationpower(t_powerbits bitspower,
t_arrayint arrayint);
t_arrayint						ft_bitsandpower(t_arrayint arrayint,
t_powerbits bitspower);
void							ft_print_ptr(va_list ap, t_printf *data,
t_buffer *bf);
void							ft_freedoubletochar(t_doubletochar doublechar);
void							ft_nulldoubletochar(t_doubletochar *doublechar);
char							*ft_strdupandfree(t_workwithmantis wwm,
char *result);
char							*ft_doublecat(char *result,
t_doubletochar doublechar, t_workwithmantis wwm);
t_temp							ft_fornulls(int lenarr, t_temp temp);
int								ft_kostil(t_printf *data, t_buffer *bf);

#endif
