import java.io.*;
class Stack_list
{
	private class Node
	{
		private int data;
		private Node link;
		public Node()
		{
			data=0;
			link=null;
		}
	}
	private Node top;
	public Stack_list()
	{
		top=null;
	}
	public void push(int value)
	{
		Node newnode=new Node();
		newnode.data=value;
		newnode.link=top;
		top=newnode;
	}
	public int pop()
	{
		if(top==null)
		{
			System.out.println("stack underflow");
			return -1;
		}
		else
		{
			Node temp=top;
			top=top.link;
			return temp.data;
		}
	}
	public void print_stack()
	{
		Node temp=top;
		if(temp==null)
			return;
		System.out.print("linked list: ");
		while(temp!=null)
		{
			System.out.print(temp.data+",");
			temp=temp.link;
		}
	}	
	
}
public class Implement_stack
{
	public static void main(String args[])throws IOException
	{
		Stack_list stack=new Stack_list();
		stack.push(5);
		stack.push(6);
		stack.push(7);
		stack.push(8);
		stack.push(5);
		stack.print_stack();
		System.out.println("popped element: "+stack.pop());
		stack.print_stack();
		System.out.println("popped element: "+stack.pop());
		stack.print_stack();
		System.out.println("popped element: "+stack.pop());
		stack.print_stack();
		stack.pop();
		stack.pop();
		stack.pop();
	}
}






		

