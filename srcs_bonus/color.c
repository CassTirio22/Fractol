/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:23:57 by ctirions          #+#    #+#             */
/*   Updated: 2021/08/22 16:02:29 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	color1(int i)
{
	int	color[22];

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
	return (color[i % 22]);
}

static int	color2(int i)
{
	int	color[22];

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
	return (color[i % 22]);
}

static int	color3(int i)
{
	int	color[22];

	color[0] = 0x006E0241;
	color[1] = 0x00790247;
	color[2] = 0x0085024E;
	color[3] = 0x00900254;
	color[4] = 0x009B035B;
	color[5] = 0x00A60361;
	color[6] = 0x00B10368;
	color[7] = 0x00BC036E;
	color[8] = 0x00C70375;
	color[9] = 0x00D2047B;
	color[10] = 0x00DD0482;
	color[11] = 0x00E80488;
	color[12] = 0x00F3048F;
	color[13] = 0x00FF0596;
	color[14] = 0x00000000;
	color[15] = 0x000B0006;
	color[16] = 0x0016000D;
	color[17] = 0x00210013;
	color[18] = 0x002C001A;
	color[19] = 0x00370120;
	color[20] = 0x00420127;
	color[21] = 0x004D012D;
	return (color[i % 22]);
}

static int	color4(int i)
{
	int	color[12];

	color[0] = 0x00500A78;
	color[1] = 0x005F1487;
	color[2] = 0x006E1E96;
	color[3] = 0x00055F32;
	color[4] = 0x00197D37;
	color[5] = 0x002D9B3C;
	color[6] = 0x00C8AF3C;
	color[7] = 0x00E1D23C;
	color[8] = 0x00FAF53C;
	color[9] = 0x00CD730A;
	color[10] = 0x00C56605;
	color[11] = 0x00BE5A00;
	return (color[i % 12]);
}

int	color(int color, int i)
{
	if (color == 1)
		return (color1(i));
	else if (color == 2)
		return (color2(i));
	else if (color == 3)
		return (color3(i));
	else if (color == 4)
		return (color4(i));
	return (color1(i));
}
