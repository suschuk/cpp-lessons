function onSubmit(form)
{
	var firstname = form.firstname.value;
	var lastname = form.lastname.value;
	var pass = form.pass.value;
	var pass_check = form.pass_check.value;
	var email = form.email.value;
	if(form.sex[0].checked || form.sex[1].checked)
	{
		var sex = true;
	}else{
		var sex = false;
	}
	var errors = "";
	
	if (firstname == "" || lastname == "" || pass == "" || pass_check == "" || email == "" || sex == false)
	{
		alert("All the fields must be filled!");
		return false;
	}
	
	var regExpNumb = /\d+/i;
	if(regExpNumb.test(firstname) || regExpNumb.test(lastname))
	{
		errors += "First name and last name can't contain numbers!\n";
	}
	var regExpSpace = /\s+/i;
	if(regExpSpace.test(firstname) || regExpSpace.test(lastname))
	{
		errors += "First name and last name can't contain spaces!\n";
	}
	
	if(pass != pass_check)
	{
		errors += "Passwords do not much!\n";
	}
	
	if (pass.length < 6)
	{
		errors += "Passord is too short(min 6 symbols)!\n";
	}
	
	var regExpEmail = /^\w+@\w+\.\w{2,4}$/i;
	if (!regExpEmail.test(email))
	{
		errors += "Uncorrect e-mail!\n";
	}
	
	if(errors == "")
	{
		return true;
	}else
	{
		alert(errors);
		return false;
	}
}