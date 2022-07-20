void watch(void)
{
	while (1) 
	{
		P0 = 1;
		for(int i=0;i<8;i++)
		{
			sleep(60000);
			P0<<=1;
		}
	}
}

void sleep(u16 time) //1ms
{
	time *= 114;
	while(time--);
}