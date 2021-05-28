Action()
{
lr_start_transaction("S3_UserRegistration");

		
	lr_start_transaction("Welcome_page");

		welcome_page();

	lr_end_transaction("Welcome_page", LR_AUTO);
	
	
	lr_start_transaction("Go_to_sign_up_page");
	
	go_to_sign_up_page();

	lr_end_transaction("Go_to_sign_up_page", LR_AUTO);
	
	lr_start_transaction("Fill_sign_up_values");

	fill_sign_up();

	lr_end_transaction("Fill_sign_up_values", LR_AUTO);

	lr_start_transaction("Welcome_page");

	welcome_page();
	
	lr_end_transaction("Welcome_page", LR_AUTO);


	lr_start_transaction("Sign_off");

		sign_off();
	
	lr_end_transaction("Sign_off", LR_AUTO);



	lr_end_transaction("S3_UserRegistration", LR_AUTO);

	return 0;
}