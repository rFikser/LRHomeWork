void welcome_page() {
	
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
	
		lr_think_time(13);
		web_reg_find("Text=Web Tours",LAST);
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
			"Snapshot=t3.inf", 
			"Mode=HTML", 
			LAST);
}

void login() {
	web_revert_auto_header("Sec-Fetch-User");
	
			web_add_auto_header("Sec-Fetch-Dest", 
				"frame");
	
			web_revert_auto_header("Upgrade-Insecure-Requests");
		
			web_add_header("Origin", 
			"http://localhost:1080");
	
			web_add_auto_header("Sec-Fetch-Site", 
			"same-origin");
	
			lr_think_time(6);
			
			web_reg_find("Text=Welcome",LAST);
			
			web_submit_data("login.pl", 
				"Action=http://localhost:1080/cgi-bin/login.pl", 
				"Method=POST", 
				"TargetFrame=body", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
				"Snapshot=t4.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=userSession", "Value={userSession}", ENDITEM, 
				"Name=username", "Value={login}", ENDITEM, 
				"Name=password", "Value={password}", ENDITEM, 
				"Name=login.x", "Value=57", ENDITEM, 
				"Name=login.y", "Value=13", ENDITEM, 
				"Name=JSFormSubmit", "Value=off", ENDITEM, 
			LAST);

}

void go_to_flights_page() {
	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
	
	web_reg_find("Text=Flight Selections",LAST);
	
	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
}


void find_flight() {
	
	web_add_auto_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(4);

/*Correlation comment - Do not change!  Original value='030;251;05/28/2021' Name ='outboundFlight' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=outboundFlight",
		"TagName=input",
		"Extract=value",
		"Name=outboundFlight",
		"Type=radio",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		LAST);
	web_reg_find("Text=Find Flight",LAST);
	web_submit_data("reservations.pl",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={departCity}", ENDITEM,
		"Name=departDate", "Value={departDate}", ENDITEM,
		"Name=arrive", "Value={arriveCity}", ENDITEM,
		"Name=returnDate", "Value={returnDate}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatPref", "Value={seatPreference}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=findFlights.x", "Value=31", ENDITEM,
		"Name=findFlights.y", "Value=5", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		"Name=departCity", "Value=", ENDITEM,
		"Name=departCity", "Value=Zurich", ENDITEM,
		LAST);
}

void reserve_flight() {
	web_reg_find("Text=hank you for booking through Web Tours",LAST);
	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(7);

	web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t7.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={firstName}", ENDITEM,
		"Name=lastName", "Value={lastName}", ENDITEM,
		"Name=address1", "Value={adress}", ENDITEM,
		"Name=address2", "Value={adress}", ENDITEM,
		"Name=pass1", "Value={lastName} {lastName}", ENDITEM,
		"Name=creditCard", "Value={creditCard}", ENDITEM,
		"Name=expDate", "Value={expDate}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPreference}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=buyFlights.x", "Value=30", ENDITEM,
		"Name=buyFlights.y", "Value=12", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		LAST);
		
}

void sign_off() {
	

		web_reg_find("Text=Welcome to the Web Tours site.", LAST);
	
	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
}

void go_to_sign_up_page() {
	web_reg_find("Text=First time registering? Please complete the form below.",LAST);
	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(17);
}

// Generate RANDOM GUID example "lrGUID = D30A251E".
int lr_guid_gen()
{
    typedef struct _GUID
    {
        unsigned long Data1;
        unsigned short Data2;
        unsigned short Data3;
        unsigned char Data4[32];
    } GUID;

    GUID m_guid;
    char buf[50];

    lr_load_dll ("ole32.dll");

    CoCreateGuid(&m_guid);

    sprintf (buf, "%08lX",
    m_guid.Data1, m_guid.Data2, m_guid.Data3,
    m_guid.Data4[0], m_guid.Data4[1], m_guid.Data4[2], m_guid.Data4[3]);

    lr_save_string(buf, "lrGUID");

    return 0;
}

void fill_sign_up() {
		
		lr_save_int(lr_guid_gen(), "randomUser"); // Почему без это строчки не работает? Не могу понять
		web_reg_find("Text=Thank you",LAST);
		web_submit_data("login.pl_2", 
			"Action=http://localhost:1080/cgi-bin/login.pl", 
			"Method=POST", 
			"TargetFrame=info", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/login.pl", 
			"Snapshot=t5.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=username", "Value={lrGUID}", ENDITEM, 
			"Name=password", "Value={lrGUID}", ENDITEM, 
			"Name=passwordConfirm", "Value={lrGUID}", ENDITEM, 
			"Name=firstName", "Value={lrGUID}", ENDITEM, 
			"Name=lastName", "Value={lrGUID}", ENDITEM, 
			"Name=address1", "Value={adress}", ENDITEM, 
			"Name=address2", "Value={adress}", ENDITEM, 
			"Name=register.x", "Value=73", ENDITEM, 
			"Name=register.y", "Value=6", ENDITEM, 
			LAST);

	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
}


void go_to_itinerary_page() {
	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
	
	lr_think_time(72);
	
	web_reg_save_param_regexp(
		"ParamName=flightNumber_original",
		"RegExp=input type=\"checkbox\" name=\"(.*?)\"",
		"Group=1",
		"Ordinal=all",
		SEARCH_FILTERS,
		LAST);

	
	web_reg_find("Text=User wants the intineraries",
		LAST);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t19.inf", 
		LAST);
}

void delete_flight() {
	web_add_header("Origin", 
		"http://127.0.0.1:1080");
	

	lr_think_time(72);

	web_reg_save_param_regexp(
		"ParamName=flightNumber",
		"RegExp=input type=\"checkbox\" name=\"(.*?)\"",
		"Group=1",
		"Ordinal=all",
		SEARCH_FILTERS,
		LAST);

	web_reg_find("Text=Flight #1 ",
		LAST);
	
	web_submit_form("itinerary.pl", 
		"Snapshot=t20.inf", 
		ITEMDATA, 
		"Name={flightNumber_original_1}", "Value=on", ENDITEM,
		"Name=removeFlights.x", "Value=59", ENDITEM,
		"Name=removeFlights.y", "Value=11", ENDITEM,		
		LAST);
	

}


void go_to_itinerary_page_url() {
	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);
}


