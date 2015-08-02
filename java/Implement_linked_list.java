import java.io.*;
public class Implement_linked_list
{
	public static void main(String args[])throws IOException
	{
		boolean val;
		Linked_list list=new Linked_list();
		list.insert(1);
		list.insert(2);
		list.insert(3);
		list.insert(5);
		list.print_list();
		val=list.delete(3);
		if(val==false) System.out.println("element not found");
		val=list.delete(6);
		if(val==false) System.out.println("element not found");
		list.print_list();
		val=list.delete(1);
		if(val==false) System.out.println("element not found");
		list.print_list();
	}
}
