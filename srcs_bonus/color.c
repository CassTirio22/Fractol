/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:23:57 by ctirions          #+#    #+#             */
/*   Updated: 2021/07/07 17:26:32 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int color1(int i)
{
    int color[24];
    
    color[0] = 0x000A3278;
	color[1] = 0x000F2D79;
	color[2] = 0x0015287B;
	color[3] = 0x001B247D;
	color[4] = 0x00211F7F;
	color[5] = 0x00271B81;
	color[6] = 0x002D1682;
	color[7] = 0x00331284;
	color[8] = 0x00390D86;
	color[9] = 0x003F0988;
	color[10] = 0x0045048A;
	color[11] = 0x004B008C;
	color[12] = 0x00500091;
	color[13] = 0x0067239B;
	color[14] = 0x007F46A6;
	color[15] = 0x009669B1;
	color[16] = 0x00AE8CBB;
	color[17] = 0x00C5AFC6;
	color[18] = 0x00DDD2D1;
	color[19] = 0x00F5F5DC;
	color[20] = 0x00F0F0D7;
	color[21] = 0x00EBCDA0;
	color[22] = 0x00E6AA69;
	color[23] = 0x00E18732;
    return(color[i % 24]);
}

int color2(int i)
{
    int color[24];

    color[0] = 0x001E0500;
	color[1] = 0x00270502;
	color[2] = 0x00300505;
	color[3] = 0x00390508;
	color[4] = 0x0043050B;
	color[5] = 0x004C050E;
	color[6] = 0x00550511;
	color[7] = 0x005F0514;
	color[8] = 0x00640A14;
	color[9] = 0x00781A14;
	color[10] = 0x008C2B14;
	color[11] = 0x00A03C14;
	color[12] = 0x009B0A14;
	color[13] = 0x00910914;
	color[14] = 0x00870814;
	color[15] = 0x007D0714;
	color[16] = 0x00730714;
	color[17] = 0x00690614;
	color[18] = 0x005F0514;
	color[19] = 0x00550514;
	color[20] = 0x005A0A14;
	color[21] = 0x00853214;
	color[22] = 0x00B05A14;
	color[23] = 0x00DC8214;
    return(color[i % 24]);
}