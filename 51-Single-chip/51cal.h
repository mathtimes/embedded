u32 Dec2Hex(u32 decnum)
{
	u32 hexnum = 0;
	for(int i=0;i<8;i++)
	{
		hexnum += decnum%10 << 4*i;
		decnum /= 10;
	}
	return hexnum;
}