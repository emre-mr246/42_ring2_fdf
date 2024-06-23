/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgul <emgul@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:59:07 by emgul             #+#    #+#             */
/*   Updated: 2024/06/22 06:17:58 by emgul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

// Regular text
# define BLK "\e[0;30m"
# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"

// Regular bold text
# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"

// Reset
# define COLOR_RESET "\e[0m"

// HEX COLORS
# define HEX_BORDER_CLR 0x222222
# define HEX_GRAY 0x333333
# define HEX_CYAN 0x00FFFF
# define HEX_GREEN 0x00FF00
# define HEX_ORANGE 0xFFA500
# define HEX_WHITE 0xFFFFFF
# define HEX_BLUE 0x0000FF
# define HEX_RED 0xFF0000
# define HEX_PRED 0xFF0070
# define HEX_YELLOW 0xFFFF00
# define HEX_PURPLE 0xF000F0
# define HEX_LIME 0x00FF8F
# define HEX_LBLUE 0xAE00FF
#endif