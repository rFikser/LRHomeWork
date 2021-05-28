Action()
{
	
	lr_start_transaction("Welcome_page");

		welcome_page();

	lr_end_transaction("Welcome_page", LR_AUTO);

	
	lr_start_transaction("Login");

		login();

	lr_end_transaction("Login", LR_AUTO);

	
	lr_start_transaction("Go_to_itinerary_page");

		go_to_itinerary_page();

	lr_end_transaction("Go_to_itinerary_page", LR_AUTO);


	lr_start_transaction("Delete_flight");
	
		delete_flight();
		
	lr_end_transaction("Delete_flight", LR_AUTO);

	
	lr_start_transaction("Sign_off");

		sign_off();
	
	lr_end_transaction("Sign_off", LR_AUTO);
	

	return 0;
}