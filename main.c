#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"

static char	*ft_strndup(const char *s1, size_t size)
{
	char	*dest;

	dest = ft_calloc(sizeof(char), size + 1);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s1, size);
	return (dest);
}

static int	starts_with(char *heystack, char *needle)
{
	size_t	i;

	if (!heystack || !needle)
		return (0);
	i = 0;
	while (1)
	{
		if (needle[i] != '\0' && heystack[i] != needle[i])
			return (0);
		if (needle[i] == '\0')
			return (1);
		i++;
	}
}

static char*	delete_speace(char *src)
{
	size_t	dst_i;
	size_t	src_i;
	char	*dst;

	dst_i = 0;
	src_i = 0;
	dst = ft_calloc(ft_strlen_s(src) + 1, sizeof(char));
	while(src[src_i] == ' ')
		src_i++;
	while (src[src_i] != '\0')
	{
		dst[dst_i] = src[src_i];
		if (src[src_i] == ' ')
		{
			while (src[src_i + 1] != '\0' && src[src_i + 1] == ' ')
				src_i++;
		}
		dst_i++;
		src_i++;
	}
	return (dst);
}

static void	write_wrapper(int output_fd, char *airport_code, char *rwy_name, char *sid_name, char *fixs)
{
	write(output_fd, airport_code, 4);
	write(output_fd, ":", 1);
	write(output_fd, rwy_name, ft_strlen_s(rwy_name));
	write(output_fd, ":", 1);
	write(output_fd, sid_name, ft_strlen_s(sid_name));
	write(output_fd, ":", 1);
	ft_putstr_fd(fixs, output_fd);
//	write(output_fd, fixs, ft_strlen_s(fixs));
	write(output_fd, "\n", 1);
}

void	write_star(char *airport_code, char *rwy, char *sid_name, char *fixs, int output_fd)
{
	ft_putstr_fd("STAR:", output_fd);
	ft_putstr_fd(airport_code, output_fd);
	ft_putchar_fd(':', output_fd);
	ft_putstr_fd(rwy, output_fd);
	ft_putchar_fd(':', output_fd);
	ft_putstr_fd(fixs, output_fd);
	ft_putchar_fd('\n', output_fd);
}

void	all_rwy_star(int output_fd, char *airport_code, char *sid_name, char *fixs)
{
	size_t	i;
	char	*RJAH[] = {"03L", "21R", "03R", "21L", NULL};
	char	*RJAW[] = {"07", "25", NULL};
	char	*RJBB[] = {"06R", "24L", "06L", "24R", NULL};
	char	*RJBE[] = {"09", "27", NULL};
	char	*RJCM[] = {"18", "36", NULL};
	char	*RJCN[] = {"08", "26", NULL};
	char	*RJCW[] = {"08", "26", NULL};
	char	*RJDA[] = {"13", "31", NULL};
	char	*RJDT[] = {"14", "32", NULL};
	char	*RJDU[] = {"18", "36", NULL};
	char	*RJEO[] = {"13", "31", NULL};
	char	*RJFA[] = {"12", "30", NULL};
	char	*RJFC[] = {"14", "32", NULL};
	char	*RJFF[] = {"16", "34", NULL};
	char	*RJFM[] = {"09", "27", NULL};
	char	*RJFO[] = {"09", "19", NULL};
	char	*RJFS[] = {"11", "29", NULL};
	char	*RJFT[] = {"07", "25", NULL};
	char	*RJFU[] = {"14", "32", NULL};
	char	*RJFY[] = {"08R", "26L", "06L", "26R", NULL};
	char	*RJKN[] = {"01", "19", NULL};
	char	*RJNA[] = {"16", "34", NULL};
	char	*RJNO[] = {"08", "26", NULL};
	char	*RJNS[] = {"12", "30", NULL};
	char	*RJNT[] = {"02", "20", NULL};
	char	*RJNW[] = {"07", "25", NULL};
	char	*RJNY[] = {"09", "27", NULL};
	char	*RJOA[] = {"10", "28", NULL};
	char	*RJOK[] = {"14", "32", NULL};
	char	*RJOM[] = {"14", "32", NULL};
	char	*RJOO[] = {"14R", "32L", "14L", "32R", NULL};
	char	*RJOS[] = {"11", "29", NULL};
	char	*RJOT[] = {"08", "26", NULL};
	char	*RJOW[] = {"11", "29", NULL};
	char	*RJSA[] = {"06", "24", NULL};
	char	*RJSF[] = {"01", "19", NULL};
	char	*RJSK[] = {"10", "28", NULL};
	char	*RJSS[] = {"09", "27", "12", "30", NULL};
	char	*RJTK[] = {"02", "20", NULL};
	char	*RJTT[] = {"16L", "34R", "16R", "34L", "04", "22", "05", "23", NULL};
	char	*RJTU[] = {"01", "19", NULL};
	char	*ROAH[] = {"18L", "36R", "18R", "36L", NULL};
	char	*ROIG[] = {"04", "22", NULL};
	char	*RORY[] = {"14", "32", NULL};

	if (starts_with(airport_code, "RJAH"))
	{
		i = 0;
		while (RJAH[i] != NULL)
		{
			write_star(airport_code, RJAH[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJAW"))
	{
		i = 0;
		while (RJAW[i] != NULL)
		{
			write_star(airport_code, RJAW[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJBB"))
	{
		i = 0;
		while (RJBB[i] != NULL)
		{
			write_star(airport_code, RJBB[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJBE"))
	{
		i = 0;
		while (RJBE[i] != NULL)
		{
			write_star(airport_code, RJBE[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJCM"))
	{
		i = 0;
		while (RJCM[i] != NULL)
		{
			write_star(airport_code, RJCM[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJCN"))
	{
		i = 0;
		while (RJCN[i] != NULL)
		{
			write_star(airport_code, RJCN[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJCW"))
	{
		i = 0;
		while (RJCW[i] != NULL)
		{
			write_star(airport_code, RJCW[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJDA"))
	{
		i = 0;
		while (RJDA[i] != NULL)
		{
			write_star(airport_code, RJDA[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJDT"))
	{
		i = 0;
		while (RJDT[i] != NULL)
		{
			write_star(airport_code, RJDT[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJDU"))
	{
		i = 0;
		while (RJDU[i] != NULL)
		{
			write_star(airport_code, RJDU[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJEO"))
	{
		i = 0;
		while (RJEO[i] != NULL)
		{
			write_star(airport_code, RJEO[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJFA"))
	{
		i = 0;
		while (RJFA[i] != NULL)
		{
			write_star(airport_code, RJFA[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJFC"))
	{
		i = 0;
		while (RJFC[i] != NULL)
		{
			write_star(airport_code, RJFC[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJFF"))
	{
		i = 0;
		while (RJFF[i] != NULL)
		{
			write_star(airport_code, RJFF[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJFM"))
	{
		i = 0;
		while (RJFM[i] != NULL)
		{
			write_star(airport_code, RJFM[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJFO"))
	{
		i = 0;
		while (RJFO[i] != NULL)
		{
			write_star(airport_code, RJFO[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJFS"))
	{
		i = 0;
		while (RJFS[i] != NULL)
		{
			write_star(airport_code, RJFS[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJFT"))
	{
		i = 0;
		while (RJFT[i] != NULL)
		{
			write_star(airport_code, RJFT[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJFU"))
	{
		i = 0;
		while (RJFU[i] != NULL)
		{
			write_star(airport_code, RJFU[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJFY"))
	{
		i = 0;
		while (RJFY[i] != NULL)
		{
			write_star(airport_code, RJFY[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJKN"))
	{
		i = 0;
		while (RJKN[i] != NULL)
		{
			write_star(airport_code, RJKN[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJNA"))
	{
		i = 0;
		while (RJNA[i] != NULL)
		{
			write_star(airport_code, RJNA[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJNO"))
	{
		i = 0;
		while (RJNO[i] != NULL)
		{
			write_star(airport_code, RJNO[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJNS"))
	{
		i = 0;
		while (RJNS[i] != NULL)
		{
			write_star(airport_code, RJNS[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJNT"))
	{
		i = 0;
		while (RJNT[i] != NULL)
		{
			write_star(airport_code, RJNT[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJNW"))
	{
		i = 0;
		while (RJNW[i] != NULL)
		{
			write_star(airport_code, RJNW[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJNY"))
	{
		i = 0;
		while (RJNY[i] != NULL)
		{
			write_star(airport_code, RJNY[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJOA"))
	{
		i = 0;
		while (RJOA[i] != NULL)
		{
			write_star(airport_code, RJOA[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJOK"))
	{
		i = 0;
		while (RJOK[i] != NULL)
		{
			write_star(airport_code, RJOK[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJOM"))
	{
		i = 0;
		while (RJOM[i] != NULL)
		{
			write_star(airport_code, RJOM[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJOO"))
	{
		i = 0;
		while (RJOO[i] != NULL)
		{
			write_star(airport_code, RJOO[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJOS"))
	{
		i = 0;
		while (RJOS[i] != NULL)
		{
			write_star(airport_code, RJOS[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJOT"))
	{
		i = 0;
		while (RJOT[i] != NULL)
		{
			write_star(airport_code, RJOT[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJOW"))
	{
		i = 0;
		while (RJOW[i] != NULL)
		{
			write_star(airport_code, RJOW[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJSA"))
	{
		i = 0;
		while (RJSA[i] != NULL)
		{
			write_star(airport_code, RJSA[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJSF"))
	{
		i = 0;
		while (RJSF[i] != NULL)
		{
			write_star(airport_code, RJSF[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJSK"))
	{
		i = 0;
		while (RJSK[i] != NULL)
		{
			write_star(airport_code, RJSK[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJSS"))
	{
		i = 0;
		while (RJSS[i] != NULL)
		{
			write_star(airport_code, RJSS[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJTK"))
	{
		i = 0;
		while (RJTK[i] != NULL)
		{
			write_star(airport_code, RJTK[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJTT"))
	{
		i = 0;
		while (RJTT[i] != NULL)
		{
			write_star(airport_code, RJTT[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RJTU"))
	{
		i = 0;
		while (RJTU[i] != NULL)
		{
			write_star(airport_code, RJTU[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "ROAH"))
	{
		i = 0;
		while (ROAH[i] != NULL)
		{
			write_star(airport_code, ROAH[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "ROIG"))
	{
		i = 0;
		while (ROIG[i] != NULL)
		{
			write_star(airport_code, ROIG[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else if (starts_with(airport_code, "RORY"))
	{
		i = 0;
		while (RORY[i] != NULL)
		{
			write_star(airport_code, RORY[i], sid_name, fixs, output_fd);
			i++;
		}
	}
	else
	{
		write_star(airport_code, "ALL", sid_name, fixs, output_fd);
		/*
		ft_putstr_fd("STAR:", output_fd);
		ft_putstr_fd(airport_code, output_fd);
		ft_putchar_fd(':', output_fd);
		ft_putstr_fd("ALL", output_fd);
		ft_putchar_fd(':', output_fd);
		ft_putstr_fd(fixs, output_fd);
		ft_putchar_fd('\n', output_fd);
		*/
	}
}

int	main(void)
{
	int		sid_fd;
	int		star_fd;
	int		output_fd;
	char	*line;
	char	*airport_code;
	char	*rwy_name;
	char	*sid_name;
	char	*fixs = NULL;
	char	**index_line;
	char	*tmp;

	printf("running......");
	output_fd = open("./output.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (output_fd == -1)
	{
		printf("output.txt ファイルの作成に失敗しました。");
		exit(1);
	}
	sid_fd = open("./data/PSSSID.dat", O_RDONLY);
	star_fd = open("./data/PSSSTAR.dat", O_RDONLY);
	if (sid_fd == -1 || star_fd == -1)
	{
		printf("datファイルの読み込みに失敗しました。");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(sid_fd);
		if (line == NULL || starts_with(line, "[RP"))
			break;
		if(starts_with(line, "[RJ") || starts_with(line, "[RO"))
		{
			airport_code = ft_strndup(&(line[1]), 4);
			if (!starts_with(&(line[13]), "ALL"))
				rwy_name = ft_strndup(&(line[15]), ft_strclen_s(&(line[15]), ' '));
			else
				rwy_name = ft_strndup(&(line[13]), ft_strclen_s(&(line[13]), ' '));
			sid_name = ft_strndup(&(line[6]), ft_min(ft_strclen_s(&(line[6]), ' '), ft_strclen_s(&(line[6]), '/')));
			while(1)
			{
				line = get_next_line(sid_fd);
				if (line == NULL || line[0] == 13 || line[0] == 10)
					break;
				fixs = ft_strjoin(ft_strjoin(fixs, ft_strndup(&(line[14]), 5)), " ");
			}
			write(output_fd, "SID:", 4);
			write_wrapper(output_fd, airport_code, rwy_name, sid_name, delete_speace(fixs));
			free(fixs);
			fixs = NULL;
		}
	}
	while (1)
	{
		line = get_next_line(star_fd);
		if (line == NULL || starts_with(line, "[RP"))
			exit(0);
		if(starts_with(line, "[RJ") || starts_with(line, "[RO"))
		{
			airport_code = ft_strndup(&(line[1]), 4);
			if (!starts_with(&(line[13]), "ALL"))
				rwy_name = ft_strndup(&(line[15]), ft_strclen_s(&(line[15]), ' '));
			else
				rwy_name = ft_strndup(&(line[13]), ft_strclen_s(&(line[13]), ' '));
			sid_name = ft_strndup(&(line[6]), ft_min(ft_strclen_s(&(line[6]), ' '), ft_strclen_s(&(line[6]), '/')));
			while(1)
			{
				line = get_next_line(star_fd);
				if (line == NULL || line[0] == 13 || line[0] == 10)
					break;
				fixs = ft_strjoin(ft_strjoin(fixs, ft_strndup(&(line[14]), 5)), " ");
			}
			if (!starts_with(rwy_name, "ALL"))
			{
				write(output_fd, "STAR:", 5);
				write_wrapper(output_fd, airport_code, rwy_name, sid_name, delete_speace(fixs));
			}
			else
			{
				all_rwy_star(output_fd, airport_code, sid_name, delete_speace(fixs));
			}
			free(fixs);
			fixs = NULL;
		}
	}
}
