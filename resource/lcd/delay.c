#include <REGX51.H>
#include <intrins.h>



void	DelayX10us(unsigned char us)
{
	for(;us>0;us--)
	{
	_nop_();
	}
}

void	DelayX1ms(unsigned char ms)
{
	for(;ms>0;ms--)
	{
		DelayX10us(49);
		DelayX10us(50);
		_nop_();
		_nop_();
	}
}

void	DelayX100ms(unsigned char ms)
{
	for(;ms>0;ms--)
	{
		DelayX1ms(100);
	}
}


