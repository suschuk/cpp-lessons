var count = 0;
var currentImage = 0;
var currentNav = 0;
var t;
var nav = new Array();
var img = new Array ();
var path = new Array ("img/dino.jpg", "img/frukti.jpg", 
                              "img/indiana.jpg", "img/kubiki.jpg");
							  
		
var navigation = new Array("img/play-pause.png", "img/play.png");
		

for (var i=0; i < path.length; i++) 
{
		img[i] = new Image (320, 240);			
		img[i].onload = countImages;
		img[i].src = path[i];
}	
		
	
for(var i = 0; i < navigation.length; ++i)
{
	nav[i] = new Image (48, 48);			
	nav[i].src = navigation[i];
}
		
        		
function countImages ()
{
	count++;
}
		

	var myImage = null;	
	var scImg = null;
	var animate ;	
function back()
{

	myImage = document.getElementById("main_img");
	scImg  = document.getElementById("secondImg");
	
	myImage.style.left = "0px";
	scImg.style.left = "320px";
	
	

	
	--currentImage;	
	if(currentImage < 0)
		currentImage = img.length - 1;
	scImg.src = img[currentImage].src;
	
	moveLeft();
	




			
	/*--currentImage;	
	if(currentImage < 0)
		currentImage = img.length - 1;
	document.images["main_img"].src = img[currentImage].src;*/
}



function moveLeft()
{
var tmp = parseInt(myImage.style.left);
	if( tmp > -320)
	{
		myImage.style.left= parseInt(myImage.style.left) - 10 + 'px';
		scImg.style.left = parseInt(scImg.style. left) - 10 + 'px';
		animate = setTimeout(moveLeft,10); // call moveRight in 20msec
	}
	else
	{
		myImage.src = scImg.src;
		myImage.style.left = "0px";
		scImg.style.left = "-999px";
		 clearTimeout(animate);
	}
}
		
function pauseBreak()
{
	var im = document.images["playPause"];
	if(currentNav == 1)
	{
		play(true);
		im.src = nav[--currentNav].src;
	}
	else if(currentNav == 0)
	{
		play(false);
		im.src = nav[++currentNav].src;
	}
}

function forward()
{

	myImage = document.getElementById("main_img");
	scImg  = document.getElementById("secondImg");
	
	myImage.style.left = "0px";
	scImg.style.left = "-320px";
	
	
	
	++currentImage;
	
	if(currentImage == img.length)
		currentImage = 0;
	scImg.src = img[currentImage].src;
	
	moveRight();
	

}

function moveRight()
{
var tmp = parseInt(myImage.style.left);
	if( tmp < 320)
	{
		myImage.style.left= parseInt(myImage.style.left) + 10 + 'px';
		scImg.style.left = parseInt(scImg.style. left) + 10 + 'px';
		animate = setTimeout(moveRight,10); // call moveRight in 20msec
	}
	else
	{
		myImage.src = scImg.src;
		myImage.style.left = "0px";
		scImg.style.left = "-999px";
		 clearTimeout(animate);
	}
}


		

function play( pb)
{
		
	if(pb)
		t = setInterval(forward, 1500);
	else 
		clearInterval(t);
}
		
function onld()
{
	//var im = document.images["playPause"];
			
	play(true);
}