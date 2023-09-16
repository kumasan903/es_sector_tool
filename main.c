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
	dst = ft_calloc(ft_strlen_s(src), sizeof(char));
	while(src[src_i] == ' ')
		src_i++;
	while (src[src_i] != '\0')
	{
		dst[dst_i] = src[src_i];
		if (src[src_i] == ' ')
		{
			while (src[src_i + 1] == ' ')
				src_i++;
		}
		dst_i++;
		src_i++;
	}
	return (dst);
}

static void	write_wrapper(int output_fd, char *airport_code, char *rwy_name, char *sid_name, char *fixs)
{
//	printf("SID:%s:%s:%s:%s\n", airport_code, rwy_name, sid_name, delete_speace(fixs));
	write(output_fd, airport_code, 4);
	write(output_fd, rwy_name, 10);
	write(output_fd, sid_name, 10);
	write(output_fd, fixs, ft_strlen_s(fixs));
	write(output_fd, "\n", 1);
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
			rwy_name = ft_strndup(&(line[13]), ft_strclen_s(&(line[13]), ' '));
			sid_name = ft_strndup(&(line[6]), ft_min(ft_strclen_s(&(line[6]), ' '), ft_strclen_s(&(line[6]), '/')));
			while(1)
			{
				line = get_next_line(sid_fd);
				if (line == NULL || line[0] == 13)
					break;
				fixs = ft_strjoin(ft_strjoin(fixs, ft_strndup(&(line[14]), 5)), " ");
			}
//			printf("SID:%s:%s:%s:%s\n", airport_code, rwy_name, sid_name, delete_speace(fixs));
			write(output_fd, "SID", 3);
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
			rwy_name = ft_strndup(&(line[13]), ft_strclen_s(&(line[13]), ' '));
			sid_name = ft_strndup(&(line[6]), ft_min(ft_strclen_s(&(line[6]), ' '), ft_strclen_s(&(line[6]), '/')));
			while(1)
			{
				line = get_next_line(star_fd);
				if (line == NULL || line[0] == 13)
					break;
				fixs = ft_strjoin(ft_strjoin(fixs, ft_strndup(&(line[13]), 5)), " ");
			}
//			printf("STAR:%s:%s:%s:%s\n", airport_code, rwy_name, sid_name, delete_speace(fixs));
			write(output_fd, "STAR", 4);
			write_wrapper(output_fd, airport_code, rwy_name, sid_name, delete_speace(fixs));
			free(fixs);
			fixs = NULL;
		}
	}
}
