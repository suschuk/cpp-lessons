function setDay()
{

var days = [ "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"];
var day = document.getElementById("day");

day.innerHTML = "<span id=\"days\">" + days.join(" ") + "</span>";

this.upDateDate = function()
{
	var d = document.getElementById("days");
	var day = new Date().getDay();
	var str2 = days.join(" ");
	var str2 = str2.replace(days[day], "<span>" + days[day] + "</span>");
	d.innerHTML = str2;

}
upDateDate();

}

function setTime()
{
	var today = new Date();
	var h = today.getHours();
	var m = today.getMinutes();
	var s = today.getSeconds();

	m = checkTime(m);
	s = checkTime(s);

	document.getElementById("time").innerHTML = "<span>" + h + ":" + m + ":" + s + "</span>";

	var t = setTimeout(setTime, 500);



	function checkTime(i)
	{
		if (i<10)
		  {
		  i="0" + i;
		  }
		return i;
	}
}

function fGeneva()
{
	document.getElementById("day").style.fontFamily = "Geneva";
	document.getElementById("time").style.fontFamily = "Geneva";
}

function fArial()
{
	document.getElementById("day").style.fontFamily = "Arail";
	document.getElementById("time").style.fontFamily = "Arial";
}

function fHelvetiva()
{
	document.getElementById("day").style.fontFamily = "Helvetica";
	document.getElementById("time").style.fontFamily = "Helvetica";
}

function fSS()
{
	document.getElementById("day").style.fontFamily = "san-serif";
	document.getElementById("time").style.fontFamily = "san-serif";
}

function mn()
{
el = document.getElementById("day");
var style = window.getComputedStyle(el, null).getPropertyValue('font-size');
var fontSize = parseFloat(style); 

el.style.fontSize = (fontSize - 1) + "px";



document.getElementById("sizeCurentValue").innerHTML = fontSize;
}

function pl()
{
el = document.getElementById("day");
var style = window.getComputedStyle(el, null).getPropertyValue('font-size');
var fontSize = parseFloat(style); 

el.style.fontSize = (fontSize + 1) + "px";

document.getElementById("sizeCurentValue").innerHTML = fontSize;
}



function display2()
{
	var st = document.getElementById("ul_style");
	var st2 = document.getElementById("font");
	if(st2.style.display == "none")
		st2.style.display = "block";
	else
		{
			st2.style.display = "none";
		}
}

function fontStyle()
{
	var ul = document.getElementById('font');
	
	var li = ul.getElementsByTagName('li');
	
	var font = "";
	
	for(var i = 0; i < li.length; ++i)
	{
		font = li[i].textContent;
		li[i].style.fontFamily = font;
	}
	
	var ull = document.getElementById('ul_style');
	ull.style.fontSize = "20px";
	
}

function shClockStyle()
{
	var ul = document.getElementById('ul_style');
	
	if(ul.style.display == 'none')
		ul.style.display = 'block';
	else
	{
		ul.style.display = "none";
	}
}

function load()
{
	document.getElementById('ul_style').style.display = "none";
	document.getElementById("font").style.display  = "none";
	
	
	el = document.getElementById("day");
	var style = window.getComputedStyle(el, null).getPropertyValue('font-size');
	var fontSize = parseFloat(style); 
	document.getElementById('sizeCurentValue').innerHTML = fontSize;
}

