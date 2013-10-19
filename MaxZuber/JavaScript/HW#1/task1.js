function task1()
{
	var arr = new Array();

	for(var i = 0; i < 10; ++i)
	{
		arr[i] = i; 
	}
	var tmp = new Array();
	if(arr.length == 1)
	{
		tmp.push(arr[0]);
	}
	else if(arr.length == 2)
	{
		tmp.push(arr.join(" and "));
	}
	else
	{
		tmp.push(arr.slice(0, arr.length - 2).join(", "));
		
		tmp.push(arr.slice(arr.length - 2, arr.length).join(" and "));
	}
	
	confirm(tmp);
}