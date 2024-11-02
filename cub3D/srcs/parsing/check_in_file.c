/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <dongeunk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:43:11 by dongeunk          #+#    #+#             */
/*   Updated: 2024/11/02 13:32:00 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_texture(char *str, t_info *info)
{
	int		flag;

	flag = TRUE;
	if (ft_strncmp(str, "NO", 2) == 0)
		get_no_path(str + 2, info, &flag); // NO 경로 저장함수
	else if (ft_strncmp(str, "SO", 2) == 0)
		get_so_path(str + 2, info, &flag); // SO 경로 저장함수
	else if (ft_strncmp(str, "WE", 2) == 0)
		get_we_path(str + 2, info, &flag); // WE 경로 저장함수
	else if (ft_strncmp(str, "EA", 2) == 0)
		get_ea_path(str + 2, info, &flag); // EA 경로 저장함수
	else if (ft_strncmp(str, "F ", 2) == 0)
		get_f_color(str + 2, info, &flag); // Floor 컬러 저장함수
	else if (ft_strncmp(str, "C ", 2) == 0)
		get_c_color(str + 2, info, &flag); // Ceiling 컬러 저장함수
	else
		flag = FALSE;
	return (flag);
}

int	is_map(char str) // N S W E는 is_texture에서 구분
{
	if (str == ' ' || str == '0' || str == '1')
		return (TRUE);
	return (FALSE);
}

void	check_texture(t_info *info, int fd)
{
	char	*str;

	while (info->text->texture_cnt < 6) // 맵이 나오기전  정보
	{
		str = get_next_line(fd);
		if (!str) // 없으면 끝
			break ;
		else if (ft_strcmp(str, "\n") == 0)
			; // 개행은 넘어감;
		else if (is_map(str[0])) // 정보 전에 맵이 나오면 안됨
			break ;
		else if (is_texture(str, info) == FALSE) // 알맞은 정보인지
			break ;
		ft_free((void **)&str);
	}
	if (str)
		ft_free((void **)&str);
	if (info->text->f_color == -1 || info->text->c_color == -1
		|| info->text->texture_cnt != 6)
		close(fd);
	if (info->text->f_color == -1 || info->text->c_color == -1)
		print_error("Error: color value should be between 0 and 255\n");
	if (info->text->texture_cnt != 6)
		print_error("Error: check again texture\n");
}

void	check_in_file(char *path, t_info *info)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error("Error: open fail\n");
	check_texture(info, fd);
	if (is_dup_texture(info) == FALSE) // N,S,W,E / C, F의 파일이 같으면 안됨
	{
		close(fd);
		print_error("Error: texture is duplicated\n");
	}
	get_map(info, fd);
	close(fd);
	is_vaild_map(info);
}
