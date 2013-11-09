$(document).ready(
/*$.ajax({
    url: "cd_catalog.xml",
    dataType: "xml",
    success: function(data) {
	$(data).find('CD').each(function(){
			var sTitle = $(this).find('TITLE').text();
			var sPublisher = $(this).find('ARTIST').text();
			var country = $(this).find('COUNTRY').text();
			var company = $(this).find('COMPANY').text();
			var price = $(this).find('PRICE').text();
			var year = $(this).find('YEAR').text();
	$("<li></li>").html(sTitle + ", " + sPublisher + ", " + country + ", " + company + ", " + company + ", " + price + ", " + year).appendTo("#dest ul");
	});
	
})*/

)

function builtMenu(str, arr, getFirst)
{
	if(getFirst)
	{
	var tmp = arr.shift();
		str.html += "<li>" + "<a id="+tmp+">" + tmp + "</a>" + "<ul>";
	}
		
	arr.forEach(function (ent, idx){	
	
				
		str.html += "\n<li>"	
				if(typeof ent == 'string')
				{
					
					str.html += "<a id="+ent+">" + ent + "</a>";
					
				}
				else if(ent instanceof Array)
				{
					str.html += "<a id="+ent[0]+">" + ent.shift() + "</a>";						
					str.html += "<ul>";
					builtMenu(str, ent, false);
					str.html += "</ul>";
				}
		str.html += "</li>";			
				

	});
	

}

function clck()
{
var str = {html:""};
	$.getJSON("menu.json", function(data)
		{
			data.forEach(function(ent)
			{
				 builtMenu(str, ent.root, true);
				 str.html += "</ul></li>";
				//$("#dest ul").append(str.html);
			});				
			
		$("#menu_warper ul").append(str.html);
		str;
		

	})
	
}














