
	var first = false;
	var last = false;
	var email = false;
$(document).ready(function()
{	
	$("#first").blur(function() {
		var str = $(this).val();
		var res = str.search(/[^a-zA-Z]/i);
		if(res != -1)	
			{
			$(this).removeClass().addClass("wrongText")
			first = false;
			}
		else
		{
			$(this).removeClass().addClass("goodText")
			first = false;
			}
	});
	$("#last").blur(function() {
			var str = $(this).val();
		var res = str.search(/[^a-zA-Z]/i);
		if(res != -1)	
		{
			$(this).removeClass().addClass("wrongText");
			last = false;
			}
		else
		{
			$(this).removeClass().addClass("goodText");
			last = false;
			}
	});
	$("#email").blur(function() {
			var str = $(this).val();
			var tmp ="";
			var dogIndex = str.indexOf('@');
			
			if(dogIndex == -1)
			{
				$(this).removeClass().addClass("goodText");
				email = true;
			}
			else
			{
				email = false;
				tmp = str.slice(0, dogIndex);
				var res = tmp.search(/[^a-zA-Z0-9_.]/);
				if(res != -1)
				{
					email= false;
				}
				else
				{
					email = true;
				tmp = str.slice(dogIndex+1, str.length);
				res = tmp.search(/[a-zA-Z]+.\.[a-zA-Z]/);
				if(res == -1)	
				{
				email= false;
				}	
				else
				{
				email= true;
				}				
				}
				
			}
			
			if(email)
			{
				$(this).removeClass().addClass("goodText");
			}
			else
			{
				$(this).removeClass().addClass("wrongText");
			}
	});
	
	$("#commentForm").submit(function(event)
	{

			/*$.ajax({
			type:"POST",
			url:"http://127.0.0.1/",
			data: $("commentForm").serialize(),
			dataType: "text",
			success: function(data)
				{
					alert("suc");
				}
			});*/
			
			$.post("http://127.0.0.1/", $("#commentForm").serialize()).done(function(data){
			
				alert("Data loaded: " + data);
			});
		
})
})


	
