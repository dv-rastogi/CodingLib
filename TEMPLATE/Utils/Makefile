default:
	@tput bold;
	@tput setaf 6; 
	@printf "C++ FILE NAME > "
	@tput sgr0
	@read NAME; \
	g++ -D LOCAL_PROJECT -Wall -std=c++17 $$NAME.cpp -o Out  
	./Out
	@tput sgr0
	@rm Out
	@echo ""

	
