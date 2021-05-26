Action()
{
lr_start_transaction("S3_UserRegistration");

		
	lr_start_transaction("welcome_page");

		welcome_page();

	lr_end_transaction("welcome_page", LR_AUTO);
	
	
	lr_start_transaction("go_to_sign_up_page");
	
	go_to_sign_up_page();

	lr_end_transaction("go_to_sign_up_page", LR_AUTO);
	
	lr_start_transaction("fill_sign_up_values");

	fill_sign_up();

	lr_end_transaction("fill_sign_up_values", LR_AUTO);

	lr_start_transaction("welcome_page");

		web_reg_find("Text=Welcome",LAST);
		web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("welcome_page", LR_AUTO);


	lr_start_transaction("sign_off");

		sign_off();
	
	lr_end_transaction("sign_off", LR_AUTO);



	lr_end_transaction("S3_UserRegistration", LR_AUTO);

	return 0;
}