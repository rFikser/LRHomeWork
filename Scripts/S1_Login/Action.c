Action()
{
	web_set_max_html_param_len("4500");
	
	lr_start_transaction("S1_Go_to_flights");

		web_set_sockets_option("SSL_VERSION", "2&3");
		
		lr_start_transaction("Welcome_page");
			
			welcome_page();
		
		lr_end_transaction("Welcome_page", LR_AUTO);
		
		
		lr_start_transaction("Login");
	
			login();
				
		lr_end_transaction("Login", LR_AUTO);
		
		
		lr_start_transaction("Go_to_itinerary_page");

			go_to_itinerary_page();

		lr_end_transaction("Go_to_itinerary_page", LR_AUTO);
		
		
		lr_start_transaction("Sign_off");
	
			sign_off();
		
		lr_end_transaction("Sign_off", LR_AUTO);
	
		
		lr_end_transaction("S1_Go_to_flights", LR_AUTO);
	return 0;
	

}
