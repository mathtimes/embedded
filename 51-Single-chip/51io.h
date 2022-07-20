__code u8 nums[16] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};


void beep(u16 time) //1ms
{
	while(time--)
	{
		u16 t = 112;
		beeper = !beeper;
		while(t--);
	}
}

void Print(u8 *source)
{
	P2 = P2|0b00011100;
	for(int j=0;j<8;j++)
	{
		P0 = source[j];
		//Delay
		delay_ms(1);
		P0 = 0;
		P2 -= 0b100;  //换选择子，从右向左
	}
}

void PrintErr()
{
	u16 count = 0;
	u8 error[5] = {0b01110010, nums[0x0], 0b01110010, 0b01110010, nums[0xE]};
	while(count++<128)
	{
		P2 &= 0b11100011;
		for(int j=0;j<5;j++)
		{
			P0 = error[j];
			beep(1);
			P0 = 0;
			
			P2 += 0b100;  //换选择子，从右向左
		}
	}
}

void PrintDec(u32 sourcenum)
{
	if(sourcenum>=1e8)
	{
		PrintErr();
		return;
	}
	u8 singalbit[8] = {0};
	for(int i=0;i<8;i++)
	{
		singalbit[i] = sourcenum%10;
		sourcenum /= 10;
	}
	for(int i=0;i<8;i++)
	{
		P0 = 0;
		
		P2 &= 0b11100011;
		//P2 = P2|0b00011100;
		for(int k=0;k<i;k++)
			P2 += 0b100;//-=
		
		P0 = nums[singalbit[i]];
		
		sleep(1);
	}
}

void PrintHex(u32 sourcenum)
{
	u8 singalbit[8] = {0};
	for(int i=0;i<8;i++)
	{
		singalbit[i] = sourcenum%16;
		sourcenum /= 16;
	}
	for(int i=0;i<8;i++)
	{
		P0 = 0;
		
		P2 &= 0b11100011;
		//P2 = P2|0b00011100;
		for(int j=0;j<i;j++)
			P2 += 0b100;//-=
		
		P0 = nums[singalbit[i]];
		
		sleep(1);
	}
}