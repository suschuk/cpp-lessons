



function main()
{
	var canvas = document.getElementById("myCanvas");
	var context = canvas.getContext("2d");

	imageData = context.createImageData(canvas.width, canvas.height);

	var quads = [];

	function setPixel(imageData, x, y, r, g, b, a) 
	{
		index = (x + y * imageData.width) * 4;
		imageData.data[index+0] = r;
		imageData.data[index+1] = g;
		imageData.data[index+2] = b;
		imageData.data[index+3] = a;
	}

	for(var i = 0; i < 6; ++i)
	{
	quads[i] = new Image();
	quads[i].src = 'img/' + (i+1) + '.jpg';

	}
	
	context.rect(0,0, canvas.width, 30);
	context.fillStyle= "#29A3CC";
	context.fill();
	
	

	var q = 0;
	var t = 100;
	var ds = 10;

	var x = 100;
	var y = 35;
	var x1 = 550;
	var y1 = 70;
	var x2 = 300;
	var y2 = 380;
	var alpha = 20;
	var alpha1 = -205;
	var alpha2 = 255;
	
	function clearVariable()
	{
		x = 100;
		y = 35;
		x1 = 550;
		y1 = 70;
		x2 = 300;
		y2 = 380;
		q = 0;
		t = 100;
	}

	function move()
	{
		x += ds * Math.cos(alpha * Math.PI/ 180);
		y += ds * Math.sin(alpha * Math.PI / 180);
	}
	function move1()
	{
		x1 += ds * Math.cos(alpha1 * Math.PI/ 180);
		y1 += ds * Math.sin(alpha1 * Math.PI / 180);
	}
	function move2()
	{
		x2 += ds * Math.cos(alpha2 * Math.PI/ 180);
		y2 += ds * Math.sin(alpha2 * Math.PI / 180);
	}

	var inProgress = false;
		
	function test()
	{
	context.clearRect(0, 30, canvas.width, canvas.height)
	var rnd = [Math.floor(Math.random() * 6), Math.floor(Math.random() * 6), Math.floor(Math.random() * 6)];
	context.drawImage(quads[rnd[0]], x,y);
	context.drawImage(quads[rnd[1]], x1,y1);
	context.drawImage(quads[rnd[2]], x2,y2);
	++q;
	move();
	move1();
	move2();

	t+= rnd[0] * 10;

	if(q < 10)
	{
		setTimeout(test,t);
		inProgress = true;
	}
	else
	{
		
		clearVariable();
		var sum = 3;
		rnd.forEach(function(value) {sum+=value});
		$('#score').text('Your score is: ' + sum);
		inProgress = false;
	}

}
	
	function drop ()
	{
		if(!inProgress)
		{
			test();
		}
	}

	$('#drop').click(drop);



	//context.putImageData(imageData, 0, 0);
}