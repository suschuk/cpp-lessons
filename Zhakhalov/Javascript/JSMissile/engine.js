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
	
	this.Length = function(vec)
	{
		return(Math.sqrt(Math.pow(this.x - vec.x) + Math.pow(this.y - vec.y)));
	}
	
	this.Polar = function(len, ang)
	{
		this.x = len * Math.cos(ang);
		this.y = len * Math.sin(ang);
	}
}

function Rectangle()
{
	this.x = 0.0;
	this.y = 0.0;
	this.width = 0.0;
	this.height = 0.0;
	
	this.Contains = function(X,Y)
	{
		return ( (X >= this.x) && (X <+ (this.x + this.width)) && (Y >= this.y) && (Y <+ (this.y + this.height)) );
	}
}

function DisplayOrder()
{
	this.order = new Array();
	
	this.Draw = function(canvas)
	{
		for(var i = 0; i < this.order.length; ++i)
		{
			if(this.order[i].visible)
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
	this.rectangle = new Rectangle();
	this.visible = true;
	
	this.Draw = function(canvas)
	{
		canvas.getContext("2d").translate(this.rectangle.x,this.rectangle.y);
		canvas.getContext("2d").rotate(-this.rotation * Math.PI/180);
		canvas.getContext("2d").drawImage(this.img, -this.hotSpot.x, -this.hotSpot.y, this.rectangle.width, this.rectangle.height);
		canvas.getContext("2d").rotate(this.rotation * Math.PI/180);
		canvas.getContext("2d").translate(-this.rectangle.x,-this.rectangle.y);
	}
}

function World()
{
	this.prototype = new Sprite();
	
	this.bricks = new ImageData();
}

function Body()
{
	this.prototype = new Sprite();
	
	this.pos = new Vec2();
	this.force = new Vec2();
	this.velocity = new Vec2();
	this.friction = new Vec2(); //0..1
	this.mass = 0.0;
	
	this.Update = function()
	{
		this.pos.x += this.velocity.x;
		this.pos.y += this.velocity.y;
		this.velocity.Add((this.force.x / this.mass + gravity.x - this.friction.x * this.velocity.x)/ FPS, (this.force.y / this.mass + gravity.y - this.friction.y * this.velocity.y)/ FPS);	

		this.prototype.rectangle.x = this.pos.x - this.prototype.hotSpot.x;
		this.prototype.rectangle.y = this.pos.y - this.prototype.hotSpot.y;
	}
}