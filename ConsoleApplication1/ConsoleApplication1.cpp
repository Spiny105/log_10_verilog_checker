// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <bitset> 

int fxlog(int x) {

  int t,y;

  y=0xa65af;
  if(x<0x00008000) x<<=16,              y-=0xb1721;
  if(x<0x00800000) x<<= 8,              y-=0x58b91;
  if(x<0x08000000) x<<= 4,              y-=0x2c5c8;
  if(x<0x20000000) x<<= 2,              y-=0x162e4;
  if(x<0x40000000) x<<= 1,              y-=0x0b172;
  t=x+(x>>1); if((t&0x80000000)==0) x=t,y-=0x067cd;
  t=x+(x>>2); if((t&0x80000000)==0) x=t,y-=0x03920;
  t=x+(x>>3); if((t&0x80000000)==0) x=t,y-=0x01e27;
  t=x+(x>>4); if((t&0x80000000)==0) x=t,y-=0x00f85;
  t=x+(x>>5); if((t&0x80000000)==0) x=t,y-=0x007e1;
  t=x+(x>>6); if((t&0x80000000)==0) x=t,y-=0x003f8;
  t=x+(x>>7); if((t&0x80000000)==0) x=t,y-=0x001fe;

  x=0x80000000-x;
  y-=x>>15;
  return y;
  }

int _tmain(int argc, _TCHAR* argv[])
{
	//Исходное число из которого берется логарифм
	int x = 0x10000;

	for (int i = 0; i < 10; i++)
	{
		std::cout << "source bin = "  << std::bitset<sizeof(x) * 8>(x) << std::endl;
		std::cout << "source hex = "  << std::hex << x << std::endl;
		int result = fxlog(x);

		float result_f = ((float)result) / 65536;

		std::cout << "result     = " << std::dec << result_f << std::endl;
		std::cout << "result hex = 0x" << std::hex << result << std::endl;
		std::cout << "result bin = "  << std::bitset<sizeof(result) * 8>(result) << std::endl << std::endl;

		x += 0x3FF0000;
	}

	system("pause");
	return 0;
}

