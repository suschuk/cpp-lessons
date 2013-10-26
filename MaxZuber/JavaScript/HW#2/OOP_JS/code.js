
function Shape()
{
	this.draw = function ()
	{
		alert("Shape draw");
	}
	this.someFunc = function ()
	{
		alert("SomeFunction");
	}
}

function Circle(x, y, R)
{
	this.x = x;
	this.y = y;
}
Circle.prototype = new Shape();
Circle.prototype.draw = function () 
{
	alert("Draw Circle");
}

function Square(x1, y1, x2, y2)
{
	this.x1 = x1;
	this.x2 = x2;
	this.y1 = y1;
	this.y2 = y2;
}

Square.prototype = new Shape();
Square.prototype.draw = function()
{
	alert("Draw Square");
}

var obj = new Circle();
var obj1 = new Shape();
var obj2 = new Square();

obj.draw();
obj.someFunc();



obj1.draw();
obj1.someFunc();


obj2.draw();
obj2.someFunc();


