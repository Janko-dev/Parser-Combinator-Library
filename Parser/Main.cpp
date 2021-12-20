#include <iostream>
#include "Parser.h"

Result term(std::string input);
Result factor(std::string input);

Result p_plus(std::string input) {
	return p_char(input, '+');
}

Result p_times(std::string input) {
	return p_char(input, '*');
}

Result p_openb(std::string input) {
	return p_char(input, '(');
}

Result p_closeb(std::string input) {
	return p_char(input, ')');
}

Result expr(std::string input) {
	return choice(input, { term, p_plus, expr }, term);
}

Result term(std::string input) {
	return choice(input, { factor, p_times, term }, factor);
}

Result factor(std::string input) {
	return choice(input, {p_openb, expr, p_closeb}, p_digits);
}

int main(int argc, char* argv[]) {

	Result r;
	r = expr("1*7*4");
	
	print_result(r);

	
	return 0;
}