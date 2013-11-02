const FPS = 30;



function main()
{
	var canvas = document.getElementById("myCanvas");
	var context = canvas.getContext("2d");

	imageData = context.createImageData(canvas.width, canvas.height);

	function setPixel(imageData, x, y, r, g, b, a) 
	{
		index = (x + y * imageData.width) * 4;
		imageData.data[index+0] = r;
		imageData.data[index+1] = g;
		imageData.data[index+2] = b;
		imageData.data[index+3] = a;
	}
	
	var bg = new Image();
	bg.src = 'img/bg2.jpg';
	var sun = new Image();
	sun.src = 'img/Sun.png';
	var earth = new Image();
	earth.src = 'img/Earth.png';	
	var moon = new Image();
	moon.src = 'img/moon.png';
	
	var mercuriy = new Image();
	mercuriy.src = 'img/Mercury.png';
	


	
	var sunX = canvas.width /2;
	var sunY = canvas.height /2;
	
	var earthX = 20;
	var earthY = 20;
	
	var moonX = 0;
	var moonY = 0;
	
	context.drawImage(bg,0,0);
	context.drawImage(earth, earthX, earthY);
	context.drawImage(sun, sunX, sunY, 50 ,50);
	
	
	function draw()
	{
	context.clearRect(0,0, canvas.width, canvas.height);
		
	context.drawImage(bg,0,0);
	context.drawImage(earth, earthX, earthY, 50, 50);
	context.drawImage(moon, moonX, moonY, 20,20);
	context.drawImage(mercuriy, mercuriyX, mercuriyY, 30,30);
	context.drawImage(sun, sunX, sunY, 50 ,50);
		
	}
	
	var R = 150;
	var moonR = 50;
	var angle = 0;
	
	var moonA = 0;
	var moonDA = 12 * Math.PI / 180;
	var da = 3*Math.PI / 180;
	
	var mercuriyX = 0;
	var mercuriyY = 0;
	var mercuriyR = 50;
	var mercuriyA = 10;
	var mercuriyDA = 1 * Math.PI / 180;


	

	
	function move()
	{
		earthX = sunX + (R+70) * Math.cos(angle);
		earthY = sunY + R * Math.sin(angle);
		
		moonX = earthX + moonR* Math.cos(moonA) + 15 ;
		moonY = earthY +  moonR * Math.sin(moonA) + 15;
		
		mercuriyX = sunX + mercuriyR * Math.cos(mercuriyA) + 10;
		mercuriyY = sunY + mercuriyR * Math.sin(mercuriyA) + 10;
		
		
		mercuriyA += mercuriyDA;
		angle += da;
		moonA += moonDA;
		
		draw();
		setTimeout(move, 1000  / FPS);
	}
	
	move();




	//context.putImageData(imageData, 0, 0);
}