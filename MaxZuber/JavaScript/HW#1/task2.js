function task2()
{
	function Worker(FSLName, Job, Phone)
	{
		this.name = FSLName;
		this.job = Job;
		this.phone = Phone;
		this.nameToStr = nameToStr;
		this.jobToStr = jobToStr;
		this.phonetoStr = phoneToStr;
		this.info = info;
		return this;
	}
	
	function nameToStr()
	{
		return ""+this.name;
	}
	function jobToStr()
	{
		return (""+this.job).toUpperCase();
	}
	function phoneToStr()
	{
		return ""+this.phone;
	}
	function info()
	{
		return "Name: " + this.name + "\nJob: " +this.job.toUpperCase() + "\n Phone# " + this.phone;
	}
		
		var arr = Array();
		
		for(var i = 0; i < 3; ++i)
		{
		var name = "", job = "", phone = ""; 
			name = prompt("Last, First and Second name ?", "Zuber Max V");
			while(name.search("[a-zA-Z0-9.]"))
			{
				name = prompt("Wrong Symbol\nEnter your Name again");
			}
			job = prompt("Job ?");
			phone = prompt("Phone ?");
			arr.push(new Worker(name, job, phone));
		
		}
		function srt( first, second)
		{
			var one, two;
			one = first.nameToStr().slice(0, first.nameToStr().indexOf(" ")); //slice last name
			two = second.nameToStr().slice(0, first.nameToStr().indexOf(" ")); //slice last name
			return one > two;
		}
		arr.sort(srt);
		
	alert(arr[0].info() + "\n\n" + arr[1].info() + "\n\n" + arr[2].info());

}