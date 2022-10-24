package ojas;
import java.util.*;
public class Temp_converter 
{
	Scanner sc = new Scanner(System.in);
	static int n=1;
	int ch;
	void c2f(double c)
	{
		double f;
		f=(c*(9/5))+32;
		System.out.println("The temperature in farenheit is :"+f);
		System.out.println("Do you want to continue?\nEnter 1 for Yes\n\t2 for No");
		ch=sc.nextInt();
		if(ch==2)
			n=2;
	}
	void c2k(double c)
	{
		double k;
		k=c+273.15;
		System.out.println("The temperature in kelvin is :"+k);
		System.out.println("Do you want to continue?\nEnter 1 for Yes\n\t2 for No");
		ch=sc.nextInt();
		if(ch==2)
			n=2;
	}
	void f2k(double f)
	{
		double k;
		k=(f-32)*(5/9)+273.15;
		System.out.println("The temperature in Kelvin is :"+k);
		System.out.println("Do you want to continue?\nEnter 1 for Yes\n\t2 for No");
		ch=sc.nextInt();
		if(ch==2)
			n=2;
	}
	void f2c(double f)
	{
		double c;
		c=(f-32)*(5/9);
		System.out.println("The temperature in celcius is :"+c);
		System.out.println("Do you want to continue?\nEnter 1 for Yes\n\t2 for No");
		ch=sc.nextInt();
		if(ch==2)
			n=2;
	}
	void k2f(double k)
	{
		double f;
		f=(k-273.15)*(9/5)+32;
		System.out.println("The temperature in farenheit is :"+f);
		System.out.println("Do you want to continue?\nEnter 1 for Yes\n\t2 for No");
		ch=sc.nextInt();
		if(ch==2)
			n=2;
	}
	void k2c(double k)
	{
		double c;
		c=k-273.15;
		System.out.println("The temperature in celcius is :"+c);
		System.out.println("Do you want to continue?\nEnter 1 for Yes\n\t2 for No");
		ch=sc.nextInt();
		if(ch==2)
			n=2;
	}
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		Temp_converter tc = new Temp_converter();
		int ch1,ch2;
		double c,f,k;
		while(n==1)
		{
			System.out.println("Enter the unit of temperature you want to convert :\n1)Celcius\n2)Farenheit\n3)Kelvin");
			ch1=sc.nextInt();
			switch(ch1)
			{
			case 1:
				System.out.println("Enter the temperature in Celcius :");
				c=sc.nextDouble();
				System.out.println("Enter the unit of temperature you want to convert to :\n1)Farenheit\n2)Kelvin");
				ch2=sc.nextInt();
				if(ch2==1)
					tc.c2f(c);
				else if(ch2==2)
					tc.c2k(c);
				else
					System.out.println("Invalid choice.");
				break;
			case 2:
				System.out.println("Enter the temperature in Farenheit :");
				f=sc.nextDouble();
				System.out.println("Enter the unit of temperature you want to convert to :\n1)Celcius\n2)Kelvin");
				ch2=sc.nextInt();
				if(ch2==1)
					tc.f2c(f);
				else if(ch2==2)
					tc.f2k(f);
				else
					System.out.println("Invalid choice.");
				break;
			case 3:
				System.out.println("Enter the temperature in Kelvin :");
				k=sc.nextDouble();
				System.out.println("Enter the unit of temperature you want to convert to :\n1)Celcius\n2)Farenheit");
				ch2=sc.nextInt();
				if(ch2==1)
					tc.k2c(k);
				else if(ch2==2)
					tc.k2f(k);
				else
					System.out.println("Invalid choice.");
				break;
			default:
				System.out.println("Invalid choice.");
			}
		}
	}
}
