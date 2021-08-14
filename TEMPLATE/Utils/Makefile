# t.cpp with LOCAL_PROJECT
default:
	g++ -D LOCAL_PROJECT -Wall -std=c++17 t.cpp -o Out  
	./Out
	@rm Out
	@echo ""

# simulation of t.cpp
s:
	g++ -Wall -std=c++17 t.cpp -o Out  
	./Out
	@rm Out
	@echo ""

# custom file with LOCAL_PROJECT
c:
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

# custom file simulation
cs:
	@tput bold;
	@tput setaf 6; 
	@printf "C++ FILE NAME > "
	@tput sgr0
	@read NAME; \
	g++ -Wall -std=c++17 $$NAME.cpp -o Out  
	./Out
	@tput sgr0
	@rm Out
	@echo ""

# t.py with inputf.in as input
p:
	python3 t.py < inputf.in
	@echo ""
