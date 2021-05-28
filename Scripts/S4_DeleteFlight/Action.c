Action()
{

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_header("Sec-Fetch-Site", 
		"cross-site");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	web_add_header("Sec-Fetch-Dest", 
		"empty");

	web_add_header("Origin", 
		"chrome-extension://gamlckmepdclkglolaedeigblmmpmfhf");

	web_add_auto_header("sec-ch-ua", 
		"\" Not A;Brand\";v=\"99\", \"Chromium\";v=\"90\", \"Google Chrome\";v=\"90\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(6);
	
	web_reg_save_param_ex("ParamName=userSession", 
			        "LB=name\=\"userSession\" value\=\"",
				    "RB=\"\/>",
				    "Ordinal=1",
				    "SaveLen=-1",
				    SEARCH_FILTERS,
				        "Scope=body",
					LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(18);

/*Correlation comment - Do not change!  Original value='itinerary' Name ='page' Type ='ResponseBased'*/
	web_reg_save_param_regexp(
		"ParamName=page",
		"RegExp=page=(.*?)\"\\ TARGET",
		"Ordinal=2",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t21.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value=ivan", ENDITEM,
		"Name=password", "Value=ivan", ENDITEM,
		"Name=login.x", "Value=0", ENDITEM,
		"Name=login.y", "Value=0", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

//	web_reg_save_param_ex("ParamName=flightID",
//                      "LB=name=\"flightID\" value=\"",
//                      "RB=\"",
//                      "Ordinal=all",
//                      LAST);

//	web_url("Itinerary Button",
//		"URL=http://localhost:1080/cgi-bin/welcome.pl?page={page}",
//		"TargetFrame=body",
//		"Resource=0",
//		"RecContentType=text/html",
//		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home",
//		"Snapshot=t22.inf",
//		"Mode=HTML",
//		LAST);
		

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t10.inf", 
		LAST);

	web_add_header("Origin", 
		"http://localhost:1080");

	web_submit_form("itinerary.pl", 
		"Snapshot=t11.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM,
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(18);

	web_url("SignOff Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in={page}",
		"Snapshot=t24.inf",
		"Mode=HTML",
		LAST);

	return 0;
}