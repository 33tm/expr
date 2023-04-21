#include <iostream>
#include <string>
#include <vector>

struct token {
    std::string type;
    std::string value;
};

bool scan(std::string string, char &input) {
    return string.find(input) != std::string::npos;
}

std::vector<token> lexer(std::string input) {
    std::vector<token> tokens;
    for(int i = 0; i < input.length(); i++) {
        char c = input[i];
        token t;
        if(scan(" ", c)) {
            continue;
        } else if(scan(".,01234568789", c)) {
            t.type = "number";
            while(scan(".,01234568789", input[i]))
                t.value += input[i++];
            i--;
        } else if(scan("()", c)) {
            t.type = "parenthesis";
            t.value = c;
        } else if(scan("+-*/%", c)) {
            t.type = "operator";
            t.value = c;
        } else {
            t.type = "unknown";
            t.value = c;
        }
        tokens.push_back(t);
    }
    return tokens;
}

int main(int argc, char* argv[]) {
    for(const token &t : lexer(std::string(argv[1]))) {
        std::cout << t.type << " : " << t.value << std::endl;
    }
    return 0;
}