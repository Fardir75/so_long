# include <math.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_test1
{
	char *str1;
	char *str2;
}		t_test1;

typedef struct s_test2
{
	char *str3;
	char *str4;
}		t_test2;

typedef struct s_box
{
	t_test1 *names;
	t_test2	*words;
}		t_box;


