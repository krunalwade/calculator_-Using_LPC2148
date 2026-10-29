#include <LPC214X.H>

void lcd_data(char);
void lcd_com(char);
void init();
char key_pad(void);
void Delay(int);

#define rs (1<<0)
#define e (1<<1)

#define c1 (1<<16)
#define c2 (1<<17)
#define c3 (1<<18)
#define c4 (1<<19)
#define r1 (1<<20)
#define r2 (1<<21)
#define r3 (1<<22)
#define r4 (1<<23)

int main()
{
	char key;
	char temp = 0;
	long num1=0;
	long num2=0;
	long result;
	int i=0;
	int data[10];
	int x=0;
	
	IODIR0 = 0xff;
	IODIR1 = 0x00f00000;
	
	init();
	while(1)
	{
		key = key_pad();
		if(key >= '0' && key<='9')
		{
			lcd_data(key);
			if(temp == 0)	num1=(num1*10)+(key-'0');
			else			num2=(num2*10)+(key-'0');
		}
		if(key=='/' || key=='x' || key=='-' || key=='+')
		{
			if(x==1)
			{
				lcd_com(0x01);
				if(temp=='/') result=num1/num2;
				if(temp=='x') result=num1*num2;
				if(temp=='-') result=num1-num2;
				if(temp=='+') result=num1+num2;
				num1=result;
				num2=0;
				while(result>0)
				{
					data[i++] = result % 10;
					result=result/10;
				}
				while(i>0)	lcd_data(data[--i]+'0');
			}
			x=1;
			temp=key;
			lcd_data(key);
		}
		if(key == '=')
		{
			lcd_com(0xc0);
			if(temp=='/') result=num1/num2;
			if(temp=='x') result=num1*num2;
			if(temp=='-') result=num1-num2;
			if(temp=='+') result=num1+num2;
			num1=result;
			num2=0;
			while(result>0)
			{
				data[i++] = result % 10;
				result=result/10;
			}
			while(i>0)	lcd_data(data[--i]+'0');
		}
		if(key == 'C')
		{
			x=0;
			lcd_com(0x01);
			temp=0;
			num1=0;
			num2=0;
		}
	}
}

char key_pad(void)
{
	//row 1
	IOCLR1 |= r1;
	IOSET1 |= r2 | r3 | r4;
	if(!(IOPIN1 & c1))    //collome 1
    {
        while(!(IOPIN1 & c1));
        return '7';
		}
	if(!(IOPIN1 & c2))    //collome 2
    {
        while(!(IOPIN1 & c2));
        return '8';
		}
	if(!(IOPIN1 & c3))    //collome 3
    {
        while(!(IOPIN1 & c3));
        return '9';
		}
	if(!(IOPIN1 & c4))    //collome 4
    {
        while(!(IOPIN1 & c4));
        return '/';
		}
	//row 2
	IOCLR1 |= r2;
	IOSET1 |= r1 | r3 | r4;
	if(!(IOPIN1 & c1))
    {
        while(!(IOPIN1 & c1));
        return '4';
		}
	if(!(IOPIN1 & c2))
    {
        while(!(IOPIN1 & c2));
        return '5';
		}
	if(!(IOPIN1 & c3))
    {
        while(!(IOPIN1 & c3));
        return '6';
		}
	if(!(IOPIN1 & c4))
    {
        while(!(IOPIN1 & c4));
        return 'x';
		}
	//row 3
	IOCLR1 |= r3;
	IOSET1 |= r2 | r1 | r4;
	if(!(IOPIN1 & c1))
    {
        while(!(IOPIN1 & c1));
        return '1';
		}
	if(!(IOPIN1 & c2))
    {
        while(!(IOPIN1 & c2));
        return '2';
		}
	if(!(IOPIN1 & c3))
    {
        while(!(IOPIN1 & c3));
        return '3';
		}
	if(!(IOPIN1 & c4))
    {
        while(!(IOPIN1 & c4));
        return '-';
		}
	//row 4
	IOCLR1 |= r4;
	IOSET1 |= r2 | r3 | r1;
	if(!(IOPIN1 & c1))
    {
        while(!(IOPIN1 & c1));
        return 'C';
		}
	if(!(IOPIN1 & c2))
    {
        while(!(IOPIN1 & c2));
        return '0';
		}
	if(!(IOPIN1 & c3))
    {
        while(!(IOPIN1 & c3));
        return '=';
		}
	if(!(IOPIN1 & c4))
    {
        while(!(IOPIN1 & c4));
        return '+';
		}

    return 0;
}

void init()
{
	lcd_com(0x02);      // 4-bit mode
  lcd_com(0x28);      // 2 lines, 5x7 matrix
	lcd_com(0x0e); 			//lcd on , cursor on
	lcd_com(0x01); 			//clear screen
	Delay(10);
	lcd_com(0x06); 			//inc cursor
	lcd_com(0x80);      // 1st row, 1st position
}

void lcd_com(char cm)
{
	char temp;
  // Higher nibble
  temp = cm & 0xF0;
	IOCLR0 |= rs;
	IOSET0 |= temp;
	IOSET0 |= e;
	Delay(5);
	IOCLR0 |= e;
	IOCLR0 = temp;
	
	 // Lower nibble
  temp = (cm & 0x0F) << 4;
	IOCLR0 |= rs;
	IOSET0 |= temp;
	IOSET0 |= e;
	Delay(5);
	IOCLR0 |= e;
	IOCLR0 = temp;
}

void lcd_data(char dt)
{
	char temp;
  // Higher nibble
  temp = dt & 0xF0;
	IOSET0 |= rs;
	IOSET0 |= temp;
	IOSET0 |= e;
	Delay(200);
	IOCLR0 |= e;
	Delay(5);
	IOCLR0 = temp;
	
	 // Lower nibble
  temp = (dt & 0x0F) << 4;
	IOSET0 |= rs;
	IOSET0 |= temp;
	IOSET0 |= e;
	Delay(200);
	IOCLR0 |= e;
	Delay(5);
	IOCLR0 = temp;
}

void Delay(int a)
{
	int i, j;
	for(i=0; i<a; i++)
		for(j=0; j<a; j++);
}