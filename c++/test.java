import java.io.*;
class test
{
public static void main(String args[])
{
for(int n=1;n<=100;n++)
{
String s=(n%15==0)?"Fizzbuzz":(n%3==0)?"Fizz":(n%5==0)?"Buzz":(String.valueOf(n));
System.out.println(s);

}
}
}
