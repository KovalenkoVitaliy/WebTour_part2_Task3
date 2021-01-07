vuser_end()
{
	tName = "11.Log_out";
	lr_start_transaction(tName);

	status=web_url("SignOff Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
	
	end_transaction(tName, status); lr_think_time(5);
	
	return 0;
}
