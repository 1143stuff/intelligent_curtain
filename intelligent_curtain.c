//@author: Aditya Sundararajan and Team
// www.github.com/1143stuff

#include<reg51.h>
																							                                       
sbit a= P0^0;				//Enable pin of L293D
sbit b= P0^1;				//Input pin of L293D
sbit c= P0^2;				//Input pin of L293D

sbit i1= P1^0;				//Output of Comparator 1
sbit i2= P1^1;				//Output of Comparator 2

sbit sw= P0^3;				//External Switch

int f;					//Flag 1				
int f2;					//Flag 2

void delay()				//Function for setting the delay
{
int i,j;
for(i=0;i<1000;i++)
{
	for(j=0;j<1000;j++);
}
}

void motor_open()				//Function for opening the curtains
{							     
a=1;					//Enable L293D
b=1;		   
c=0;
delay();

a=0;					//Disable L293D
b=0;
c=0;	
}

void motor_close()				//Function for closing the curtains
{

a=1;					//Enable L293D
b=0;
c=1;
delay();

a=0;					//Disable L293D
b=0;
c=0;	
}

void main()
{

f=1;
f2=0;

//P1^0=i1=Temperature Sensor and P1^1=i2=LDR

while(1)							//Infinite loop
{

	if(sw==0)
	{ 
		f2=0;
		if(i1==0 && i2==0)				//If room temperature is low and light is off
		{
			if(f!=1)				//If the curtain is not already closed
			{
				motor_close();
				f=1;
			}

		}
		if(i1==0 && i2==1)				//If room temperature is low and light is on
		{
			if(f!=1)				//If the curtain is not already closed
			{
				motor_close();
				f=1;  
			}
		}


		if(i1==1 && i2==0)				//If room temperature is high and light is off
		{
			if(f!=1)				//If the curtain is not already closed
			{
				motor_close();
				f=1;
			}
		}

		if(i1==1 && i2==1)				//If room temperature is high and light is on
		{
			if(f!=0)				//If the curtain is not already opened
			{
				motor_open();
				f=0;
			}
		}
	}
	if(sw==1)
	{
		if(f2==0)
		{
			if(f!=1)				//If the curtain is open
			{  
			 	motor_close();
			 	f=1;
				f2=1;
		   
			}
		
			if(f!=0)				//If the curtain is close
			{
			  	motor_open();
			  	f=0;
				f2=1;
	    		}
		}
	}
}

}
