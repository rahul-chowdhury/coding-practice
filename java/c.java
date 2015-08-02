import java.io.*;
class a
{
a()
{
System.out.println("a");
}
}

class b extends a
{
b()
{
System.out.println("b");
}
}
class c
{
public static void main(String args[])
{
b B=new b();
}
}

