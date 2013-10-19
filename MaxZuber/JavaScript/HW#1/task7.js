function task7()
{
	Array.prototype.max = function ()
	{
	var arr = this;
	var max = arr[0];
		for(var i = 1; i < this.length; ++i)
		{
			if(max < arr[i])
				max = arr[i];
		}
		return max;
	}
	
	var arr = new Array();
	
	for(var i = 0; i < 15; ++i)
		arr.push(i);
		
		
		arr.push(19);
		
	
	var v  = arr.max();
	alert(arr.join(", ") + "\n\nMax value" + v);

}


