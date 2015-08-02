class superclass
{
	superclass()
	{
		System.out.println("in superclass");
	}
}

class baseclass extends superclass
{
	baseclass()
	{
		super();
		System.out.println("in baseclass");
	}
}
public class inheritence
{
	
	public static void main(String args[])
	{
		baseclass b=new baseclass();
	}
}
