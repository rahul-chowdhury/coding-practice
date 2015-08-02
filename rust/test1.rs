fn main()
{
	let mut a=23;
	a= match (1,a)
	{
		(1,4)=>a+1,
		(1,6..25)=>6,
		_=>a+2
	};
	println!("{}",a);
		
}


