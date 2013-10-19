function task3()
{

	function MenuItem()
	{
		this.name = "";

		
		this.additem = function()
		{
			this.name = prompt("Enter action name");
			
			switch(prompt("Chose action: \n1. Say hello\n2.Growl\n3. Say Good Bye!"))
			{
				case "1":
					this.action = sayHello;
					break;
				case "2":
					this.action = Growl;
					break;
				case "3":
					this.action = sayGoodBye;
					break;
			}
		}
		this.n = function ()
		{
			return ""+this.name;
		}
	}
	var sayHello = function()
	{
		alert("Hello");
	}
	var Growl = function()
	{
		alert("WOOooooof");
	}
	var sayGoodBye = function()
	{
		alert("GoodBye!");
	}
	
	function Menu()
	{	
		this.arr = new Array();
		this.showConstructor = showConstructor;
		this.addMenu = function ()
		{
			var tmp = new MenuItem();
			tmp.additem();
			this.arr.push(tmp);
		}
		this.showMenu = function() 
		{
			var menuList= "";
			for(var i = 0; i < this.arr.length ; ++i)
			{
				menuList += i + ". " + this.arr[i].n() + "\n";
			}
			menuList += "'c' Menu Constructor \n";
			menuList += "'e' Exit \n";
			
			
			var choose = prompt(menuList);
			if(choose == "c")
				this.showConstructor();
			else if(choose == "e")
			{
				return;
			}
			else
				{				
					this.arr[choose].action();
					this.showMenu();
				}
		}
		
	}
	function showConstructor()
	{
		switch(prompt("1 - add new menu item \n2 - Show menu list\n"))
		{
			case "1":
				this.addMenu();
				this.showConstructor();
				break;
				
			case "2":
				this.showMenu();
				break;
		}
		
	}
	
	var m = new Menu();
	m.showConstructor();

}