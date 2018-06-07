BOLD_CYAN=\033[1;36m
NBLD_CYAN=\033[36m
BOLD_YELL=\033[1;33m
RESET_COLOR=\033[0;0m
unittest:
	make -C exports/ shortre
	@ echo "${BOLD_YELL}Running unit test${RESET_COLOR}"
	@ echo "${NBLD_CYAN}\c"
	exports/okurache.filler <unittest_resources/test_input1.txt > temporary.txt
	@ echo "${BOLD_CYAN}\c"
	@ diff -s unittest_resources/test_output1.txt temporary.txt
	@ rm -f temporary.txt
	@ echo "${RESET_COLOR}\c"
