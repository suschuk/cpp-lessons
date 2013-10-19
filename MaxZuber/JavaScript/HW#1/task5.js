function task5()
{
	function Test()
	{
		function question(q, a, point)
		{
			this.question_ = q;
			this.answer_ = a;
			this.point_ = point;
			
			this.doQuestion = function()
			{
				var ans = confirm(this.question_);
				if(this.answer_ == ans)
					return this.point_;
				return "0";
			}
			
			this.info = function()
			{
				return confirm("Question: " + this.question_ + "\nRight answwer: " +(a?"ok" : "cancle") + "\nPoints: " + this.point_  + "\n");
			}
		}
	
	
		this.questions_ = new Array();
		
		this.addQ = function()
		{
			var q = prompt("Type question:");
			var a = confirm("Chose right answer for question\n" + q + "\n");
			var p = prompt("Point's for question:\n" + q + "\n");
			
			this.questions_.push(new question(q, a, p));
		}
		this.rmQ = function()
		{
			for(var i = 0; i < this.questions_.length; ++i)
			{
				if(this.questions_[i].info())
				{
					this.questions_.splice(i,1);
					--i;
				}
			}
		}
		this.clearQ = function()
		{
			this.questions_ = new Array();
		}
		this.doTest = function()
		{
		
			if(this.questions_.length != 0)
			{
				var points = 0;
				for(var i = 0; i < this.questions_.length; ++i)
				{
					 points += parseInt(this.questions_[i].doQuestion());
					
				}
				
				alert("Your result is: " + points);
			}
		}
		
	}

		var test = new Test();
			
		do
		{
			var ans = prompt("Action? \n1 - Add new question \n2 - Remove Question \n3 - Clear test \n4 - Run test \n\n0 - Exit")
				
			switch(ans)
			{
				case "1": test.addQ(); break;
				case "2": test.rmQ(); break;
				case "3": test.clearQ(); break;
				case "4": test.doTest(); break;
				case "0": break;
				default: break;
					
			}
				
				
		}while(ans != "0")
	
}