vuser_init()
{
	tName = "01.Login_open_field";
	lr_start_transaction(tName);
	
	
	web_reg_save_param_ex(
		"ParamName=CompSession",
		"LB=userSession\" value=\"",
		"RB=\"/>",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);
	
	status=web_url("Webtours",
		"URL=http://localhost:1080/Webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	end_transaction(tName, status); lr_think_time(5);
	
	tName = "02.Login_fillin_fiels";
	lr_start_transaction(tName);

	status=web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={CompSession}", ENDITEM, 
		"Name=username", "Value={UserName}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=69", ENDITEM, 
		"Name=login.y", "Value=11", ENDITEM, 
		LAST);
	
	end_transaction(tName, status); lr_think_time(5);
	
	return 0;
}
