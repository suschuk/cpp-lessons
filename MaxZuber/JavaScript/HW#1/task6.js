function task6()
{
	var addr = "http://www.ufa.com.ua/utilites/hdd/out.php?sort=2"

	var srch = addr.indexOf(":");	
	var protocol = addr.slice(0, srch + 1);
	srch = addr.search("www.*/");
	var host = addr.slice(srch, addr.indexOf("/", srch));	
	var path = addr.slice(addr.indexOf("/", srch),addr.lastIndexOf("/") );
	var fileName = addr.slice(addr.lastIndexOf("/") + 1, addr.indexOf("?"));	
	var request = addr.slice(addr.indexOf("?") + 1, addr.length );
	
	alert("Protocol: " + protocol + "\nHost: " + host + "\nPath: " + path + "\nFileName: " + fileName + "\nRequest: " +request);
	
	
}
