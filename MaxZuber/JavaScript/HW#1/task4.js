function task4()
{


	function Book(a, y, page, price)
	{
		this.author_ = a;
		this.year_ = y;
		this.pageCount_ = page;
		this.price_ = price;
		
		this.year = function() {return this.year_;}
		this.setAuthor = function(a) {this.author_ = a;}
		this.setYear = function(y) {this.year_ = y;}
		this.setPageCount = function(cPage) {this.pageCount_ = cPage;}
		this.setPrice = function(price) {this.price_;}
		
		this.info = function() 
		{
			alert("Author: " + this.author_ + "\n" + "Year: " + this.year_ + "\nPage's: " + this.pageCount_ + "\nPrice: " + this.price_  + "$\n" );
		}
		
	}
	function srt(book1, book2)
	{
		return book1.year() > book2.year();
	}
	
	var arr = new Array();
	
	arr.push(new Book("La sombra del ciprés es alargada by Miguel Delibes", 1999, 355, 50));
	arr.push(new Book("Hawkes Harbor by S. E. Hinton", 2007, 3243, 23));
	arr.push(new Book("Abe Lincoln: The Boy Who Loved Books by Kay Winters", 1967, 700, 65));
	arr.push(new Book("One", 2010, 155, 21));

		var makeNewBook = function()
	{
		var n = prompt("Book name ?");
		var y = prompt("Year ?");			
		var pc = prompt("Page Count?");		
		var price = prompt("Price ?");
		return new Book(n ,y, pc, price);
	}
	var editBook = function(b)
	{
		var n = prompt("Book name ?", b.author_);
		var y = prompt("Year ?", b.year_);
		var pc = prompt("Page Count?", b.pageCount_);
		var price = prompt("Price ?", b.price_);
		
		return new Book(n ,y, pc, price);
	}


	
	do
	{
		var ans = prompt("action ? \n1 Add new book\n2 Sort Book\n3 Find $ edit book \n4 Show Books \n0 Exit")
		switch(ans)
		{
			case "1":	
				arr.push(makeNewBook());
				break;
			case "2":
				arr.sort(srt);
				break;
			case "3":
			var name = prompt("Book name for search ?");
			
			for(var i = 0; i < arr.length; ++i)
			{
				if(arr[i].author_.search(name) != -1)
				{	
					
					arr[i] = editBook(arr[i]);
				}
			}
			break;
			
			case "4":
				for(var i = 0; i < arr.length; ++i)
				{
					arr[i].info();
				}
			break;
			case "0": break;
			default: break;
		
		}
	
	
	}while(ans != "0")
	
	

}