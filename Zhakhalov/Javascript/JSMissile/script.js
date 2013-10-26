const FPS = 60;

var canvas = document.getElementById("myCanvas");
var context = canvas.getContext("2d");

var displayOrder = new DisplayOrder();
var gravity = new Vec2();
var missile = new Body();
var water = new Sprite();
var tank = new Sprite();

var background = context.createLinearGradient(0,300,0,700);
background.addColorStop(0,"black");
background.addColorStop(1,"rgba(128,128,200,255)");

function Update()
{
	missile.Update();
	
	missile.prototype.rotation = Math.atan(-missile.velocity.y / missile.velocity.x) * 180 / Math.PI;
	if(missile.velocity.x < 0)
		missile.prototype.rotation += 180;
	
	if(missile.prototype.rectangle.y > water.rectangle.y)
	{
		missile.friction.Set(15.0,15.0);
		missile.prototype.visible = false;
	}
	else
	{
		missile.friction.Set(0.5,0.5);
	}
	
	Draw();
}

function Draw()
{
	context.clearRect(0,0,canvas.width,canvas.height);
	
	//context.globalCompositeOperation = 'xor'
	context.fillStyle = background;
	context.fillRect(0,0,canvas.width,canvas.height);
	
	
	displayOrder.Draw(canvas);
	
	
}

function Start()
{
	gravity.Set(0,9.81);
	
	missile.prototype.rectangle.x = 10
	missile.prototype.rectangle.y = 200;
	missile.velocity.Set(8, -8);	
	missile.prototype.rectangle.width = 13;
	missile.prototype.rectangle.height = 7;
	missile.prototype.rotation = 0;
	missile.prototype.hotSpot.Set(7, 4);
	missile.prototype.img.src = "missile.png";
	missile.prototype.visible = false;
	missile.mass = 5.0;
	
	water.img.src = "water.png";
	water.rectangle.width = 1280;
	water.rectangle.height = 650;
	water.rectangle.x = 0;
	water.rectangle.y = 600;
	
	tank.img.src = "ball.png";
	tank.rectangle.width = 8.0;
	tank.rectangle.height = 8.0;
	tank.rectangle.x = 200;
	tank.rectangle.y = 550;
	tank.hotSpot.Set(4, 4);
	
	displayOrder.AddAt(missile.prototype,0);
	displayOrder.AddAt(tank,1);
	displayOrder.AddAt(water,2);
	
	//canvas.addEventListener('mousedown', startDrag, false);
	canvas.addEventListener('mouseup', endDrag, false);
	canvas.addEventListener('mousemove', drag, false);

	var myTimer = setInterval(Update, 1000/FPS);
}

function startDrag(event)
{	
	/*if(ball.rectangle.Contains(event.clientX, event.clientY))
	{
		canvas.addEventListener('mousemove', drag, false);
		canvas.addEventListener('mouseup', endDrag, false);
	}*/
}

function drag(event)
{

}

function endDrag(event)
{
	missile.prototype.visible = true;
	missile.velocity.Set((event.clientX - canvas.getBoundingClientRect().left - tank.rectangle.x - tank.hotSpot.x) / 10, (event.clientY - canvas.getBoundingClientRect().top - tank.rectangle.y - tank.hotSpot.y) / 10);
	missile.pos.x = tank.rectangle.x + tank.hotSpot.x;
	missile.pos.y = tank.rectangle.y + tank.hotSpot.y;
}