Action()
{
	
	lr_start_transaction("S2_FlightReservation");
	
	
		lr_start_transaction("Welcome_page");
	
			welcome_page();
	
		lr_end_transaction("Welcome_page", LR_AUTO);
		
		
		lr_start_transaction("Login");
	
			login();
	
		lr_end_transaction("Login", LR_AUTO);
	
	
		lr_start_transaction("Go_to_flights");
	
			go_to_flights_page();
	
		lr_end_transaction("Go_to_flights", LR_AUTO);
	
		
		lr_start_transaction("Find_flight");
	
			find_flight();
	
		lr_end_transaction("Find_flight", LR_AUTO);
	
	
		lr_start_transaction("Reserve_flight");
	
			reserve_flight();
	
		lr_end_transaction("Reserve_flight", LR_AUTO);
	
	
		lr_start_transaction("Sign_off");
	
			sign_off();
	
		lr_end_transaction("Sign_off", LR_AUTO);



	lr_end_transaction("S2_FlightReservation", LR_AUTO);

	return 0;
}