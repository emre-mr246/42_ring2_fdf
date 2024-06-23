/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:07:46 by emgul             #+#    #+#             */
/*   Updated: 2024/06/22 06:11:32 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H

# include "color.h"

// ERROR
# define ERR_ARG BRED "Usage: " BWHT \
	"./fdf [" BGRN ".fdf" BWHT "::" BCYN "FILE" BWHT "] \
	[" BGRN "-flags" BWHT ":" BCYN "FLAG" BWHT "(" BCYN "Optional" \
	BWHT ")]\n" COLOR_RESET BYEL \
	"-> For more detailed information: -H or --help" COLOR_RESET
# define ERR_NOFILE BRED "The file was not found." \
	COLOR_RESET
# define ERR_FILEEXT BRED "File extension must be: " \
	BWHT "[" BGRN ".fdf" BWHT "::" BCYN "FILE" BWHT "]" COLOR_RESET
# define ERR_NAMELEN BYEL "File name must be at least 4 characters long." \
	COLOR_RESET
# define ERR_FLAG BYEL "Invalid flag." COLOR_RESET
# define ERR_MALLOC BYEL "Memory allocation failed." COLOR_RESET
# define ERR_OPEN BYEL "Unable to open map file." COLOR_RESET
# define ERR_MAP_SIZE BYEL "The map can only be square." COLOR_RESET
# define ERR_MAP_DIMENSION BYEL "Map dimensions are invalid." COLOR_RESET
# define ERR_COORD BYEL "Coordinates out of bounds." COLOR_RESET
# define ERR_LINE BYEL "Line is missing. Please check the map file." COLOR_RESET
# define ERR_INIT_MLX BYEL "Failed to initialize MiniLibX." COLOR_RESET
# define ERR_INIT_MLX_WIN BYEL "Failed to initialize MiniLibX window." \
	COLOR_RESET
# define ERR_INIT_MLX_IMG BYEL "Failed to initialize MiniLibX image." \
	COLOR_RESET
# define ERR_WIN_SIZE BYEL "Minimum window size is 1080x720." COLOR_RESET

// MESSAGE
# define MSG_HELP BYEL "Flags Usage:\n" BCYN "-H, --help:" BWHT \
	" Prints more information about parameters.\n" BCYN \
	"-CL, --low-color:" BWHT " Set default low color for your instance." \
	"Usage: --low-color <color::hex>\n" \
	COLOR_RESET BCYN "-CH, --high-color:" BWHT " \
	Set default high color for your instance. " \
	"Usage: --high-color <color::hex>\n" COLOR_RESET
# define MSG_EXIT BGRN "Program exited successfully." COLOR_RESET

#endif
