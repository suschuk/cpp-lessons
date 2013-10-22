const FPS = 60;

var canvas = document.getElementById("myCanvas");
var context = canvas.getContext("2d");

function Vec2()
{
	this.x = 0.0;
	this.y = 0.0;

	this.Set = function(X,Y)
	{
		this.x = X;
		this.y = Y;
	}
	
	this.Add = function(X,Y)
	{
		this.x += X;
		this.y += Y;
	}
}

function DisplayOrder()
{
	this.order = new Array();
	
	this.Draw = function(canvas)
	{
		for(var i = 0; i < this.order.length; ++i)
		{
			this.order[i].Draw(canvas);
		}
	}
	
	this.RemoveAt = function(idx)
	{
		this.order.splice(idx,1);
	}
	
	this.AddAt = function(sprite,idx)
	{
		this.order.splice(idx,0,sprite);
	}
}

function Sprite()
{
	this.img = new Image();
	this.hotSpot = new Vec2();
	this.rotation = 0.0;
	this.x = 0.0;
	this.y = 0.0;
	this.width = 0.0;
	this.height = 0.0;
	
	this.Draw = function(canvas)
	{
		canvas.getContext("2d").translate(this.x,this.y);
		canvas.getContext("2d").rotate(-this.rotation * Math.PI/180);
		canvas.getContext("2d").drawImage(this.img, -this.hotSpot.x, -this.hotSpot.y, this.width, this.height);
		canvas.getContext("2d").rotate(this.rotation * Math.PI/180);
		canvas.getContext("2d").translate(-this.x,-this.y);
	}
}

function Body()
{
	this.pos = new Vec2();
	this.force = new Vec2();
	this.velocity = new Vec2();
	this.friction = new Vec2(); //0..1
	this.mass = 0.0;
	
	this.prototype = new Sprite();
	
	this.Update = function()
	{
		this.velocity.Add((this.force.x / this.mass + gravity.x - this.friction.x * this.velocity.x)/ FPS, (this.force.y / this.mass + gravity.y - this.friction.y * this.velocity.y)/ FPS);
		this.prototype.x += this.velocity.x;
		this.prototype.y += this.velocity.y;
		
		this.prototype.rotation = -Math.atan(this.velocity.y / this.velocity.x) * 180 / Math.PI;
		this.prototype.rotation -= 90;
	}
}

var displayOrder = new DisplayOrder();


var gravity = new Vec2();
gravity.Set(0,9.81);

var ball = new Body();
ball.prototype.x = 10
ball.prototype.y = 200;
ball.velocity.Set(8, -8);
ball.mass = 5.0;
ball.prototype.width = 9.0;
ball.prototype.height = 14.0;
ball.prototype.rotation = 0.0;
ball.prototype.img.src = "missile.png";

var water = new Sprite();
water.img.src = "water.png";
water.width = 1020;
water.height = 600;
water.x = 0;
water.y = 300;

displayOrder.AddAt(ball.prototype,0);
displayOrder.AddAt(water,1);

function Update()
{
	ball.Update();
	
	if(ball.prototype.y > 300)
	{
		ball.friction.Set(15.0,15.0);
	}
	else
	{
		ball.friction.Set(0.0,0.0);
	}
	
	Draw();
}

function Draw()
{
	context.clearRect(0,0,canvas.width,canvas.height);
	//ball.Draw(canvas);
	displayOrder.Draw(canvas);
}

function Start()
{
	var myTimer = setInterval(Update, 1000/FPS);
}


/*

const FPS = 60;

var canvas = document.getElementById("myCanvas");
var context = canvas.getContext("2d");

function Vec2()
{
	this.x = 0.0;
	this.y = 0.0;

	this.Set = function(X,Y)
	{
		this.x = X;
		this.y = Y;
	}
	
	this.Add = function(X,Y)
	{
		this.x += X;
		this.y += Y;
	}
}

function DisplayOrder()
{
	this.order = new Array();
	
	this.Draw = function(canvas)
	{
		for(var i = 0; i < this.order.length; ++i)
		{
			this.order[i].Draw(canvas);
		}
	}
	
	this.RemoveAt = function(idx)
	{
		this.order.splice(idx,1);
	}
	
	this.AddAt = function(sprite,idx)
	{
		this.order.splice(idx,0,sprite);
	}
}

function Sprite()
{
	this.img = new Image();
	this.hotSpot = new Vec2();
	this.rotation = 0.0;
	this.x = 0.0;
	this.y = 0.0;
	this.width = 0.0;
	this.height = 0.0;
	
	this.Draw = function(canvas)
	{
		canvas.getContext("2d").translate(this.x,this.y);
		canvas.getContext("2d").rotate(-this.rotation * Math.PI/180);
		canvas.getContext("2d").drawImage(this.img, -this.hotSpot.x, -this.hotSpot.y, this.width, this.height);
		canvas.getContext("2d").rotate(this.rotation * Math.PI/180);
		canvas.getContext("2d").translate(-this.x,-this.y);
	}
}

function Body()
{
	this.pos = new Vec2();
	this.force = new Vec2();
	this.velocity = new Vec2();
	this.friction = new Vec2(); //0..1
	this.mass = 0.0;
	
	this.sprite = new Sprite();
	
	this.Update = function()
	{
		this.velocity.Add((this.force.x / this.mass + gravity.x - this.friction.x * this.velocity.x)/ FPS, (this.force.y / this.mass + gravity.y - this.friction.y * this.velocity.y)/ FPS);
		this.pos.Add(this.velocity.x, this.velocity.y);
		
		this.sprite.x = this.pos.x;
		this.sprite.y = this.pos.y;
		
		this.sprite.rotation = -Math.atan(this.velocity.y / this.velocity.x) * 180 / Math.PI;
		this.sprite.rotation -= 90;
	}
}

var displayOrder = new DisplayOrder();


var gravity = new Vec2();
gravity.Set(0,9.81);

var ball = new Body();
ball.pos.Set(10, 200);
ball.velocity.Set(8, -8);
ball.mass = 5.0;
ball.sprite.width = 9.0;
ball.sprite.height = 14.0;
ball.sprite.rotation = 0.0;
ball.sprite.img.src = "missile.png";

var water = new Sprite();
water.img.src = "water.png";
water.width = 1020;
water.height = 600;
water.x = 0;
water.y = 300;

displayOrder.AddAt(ball.sprite,0);
displayOrder.AddAt(water,1);

function Update()
{
	ball.Update();
	
	if(ball.pos.y > 300)
	{
		ball.friction.Set(15.0,15.0);
	}
	else
	{
		ball.friction.Set(0.0,0.0);
	}
	
	Draw();
}

function Draw()
{
	context.clearRect(0,0,canvas.width,canvas.height);
	//ball.Draw(canvas);
	displayOrder.Draw(canvas);
}

function Start()
{
	var myTimer = setInterval(Update, 1000/FPS);
}




*/