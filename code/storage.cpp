
vector<Line> parse(vector<string> input) {

    vector<Line> ret;   // the return vector
    
    // (token -> value) map
    unordered_map<string,char> codeMap = { {"ADD",ADD}, {"AND",AND}, {"OR",OR}, {"BEQ",BEQ}, {"SL",SL}, {"SR",SR},{"J",J}, {"MOV",MOV}, {"LW",LW}, {"SW",SW} };
    cout << "created map" << endl;


    // tokenize the input
    for (string s : input) {

        // Tokenize input
        vector<string> token;
        for (auto i = strtok(&s[0], " "); i != NULL; i = strtok(NULL, " "))
            token.push_back(i);

        validateLine(token);


        cout << "created token:" << endl;

        for (string s : token) {
            cout << s << endl;
        }


        // use the tokens to create line objects
        
        Line::arg al[3];
        al[0] = Line::arg(token[1]);
        al[1] = Line::arg(token[2]);
        al[2] = Line::arg(token[3]);
        Line l((byte)codeMap[token[0]], al[0], al[1], al[2]);

        // ret.push_back(Line((byte)codeMap[token[0]], Line::arg(token[1]), Line::arg(token[2]), Line::arg(token[3])));

        ret.push_back(l);

        cout << endl << endl;
    }

    return ret;
}


Line::arg::arg() {
    regFlag = false;
    val = 0;
}

Line::arg::arg(string s) {

    cout << "\nstoi\n" << s << endl << s[0] << endl;

    if (s[0] == '$') {
        cout << "register" << endl;
        regFlag = true;
        val = stoi(s.substr(1, s.size() - 1));
        cout << "stoi check" << endl;
    } else {
        cout << "number" << endl;
        regFlag = false;
        val = stoi(s);
        cout << "stoi check" << endl;
    }
}


Line::Line(byte in, arg a0, arg a1, arg a2) {
    instruction = in;
    al[0] = a0;
    al[1] = a1;
    al[2] = a2;
}

// Line::arg &Line::arg::operator=(const Line::arg &a) {
//     regFlag = a.regFlag;
//     val = a.val;
// }

// void Line::execute() {

//     switch (instruction)
//     {
//     case ADD:
//         reg[ri[0]] = reg[ri[1]] + reg[ri[2]];
//         pc++;
//         break;
    
//     case AND:
//         reg[ri[0]] = reg[ri[1]] & reg[ri[2]];
//         pc++;
//         break;

//     case OR:
//         reg[ri[0]] = reg[ri[1]] | reg[ri[2]];
//         pc++;
//         break;

//     case BEQ:
//         if (reg[ri[1]] == reg[ri[2]]) pc = reg[ri[0]];
//         break;

//     case SL:
//         reg[ri[0]] = reg[ri[1]] << reg[ri[2]];
//         pc++;
//         break;

//     case SR:
//         reg[ri[0]] = reg[ri[1]] >> reg[ri[2]];
//         pc++;
//         break;

//     case J:
//         pc = reg[ri[0]];
//         break;

//     case MOV:
//         reg[ri[0]] = reg[ri[1]];
//         pc++;
//         break;

//     case LW:
//         reg[ri[0]] = mem[reg[1]];
//         pc++;
//         break;

//     case SW:
//         mem[ri[0]] = reg[ri[1]];
//         pc++;
//         break;

//     default:
//         printf("ERROR: Line object created with incorrect instruction name");;
//     }
// }


// void tokenize(string const &str, const char delim, vector<string> &out)
// {
// 	size_t start;
// 	size_t end = 0;

// 	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
// 	{
// 		end = str.find(delim, start);
// 		out.push_back(str.substr(start, end - start));
// 	}
// }




reports any violation of syntax
bool Bite::tokenError(vector<vector<string>> inputTokens) {

    for (size_t i = 0; i < inputTokens.size(); i++) {
        
        // non valid code: return false
        if (codeNum.find(inputTokens[i][0]) == codeNum.end()) {
            cout << "unknown op code \"" << inputTokens[i][0] << "\"" << endl;
            return false;
        }

        // check that all registers and numbers are valid
        for (size_t j = 1; i < inputTokens[i].size(); j++) {
            if (!(isValidReg(inputTokens[i][j]) || isValidNum(inputTokens[i][j]))) {
                cout << "unknown register/number \"" << inputTokens[i][j] << "\"" << endl;
                return false;
            }
        }




        valid code with valid arguments: continue
        switch (codeNum[v[0]])
        {
        case ADD: 
            if (v.size() != 4) { cout << "Unknown expression on line: " << i << endl; }
            break;  
        
        case AND: 

            break;  
        
        case OR:
            
            break;
        case BEQ:

            break;

        default:
            break;
        }
        
        
        for (size_t i = 0; i < v.size(); i++) {

            // if the token is blank or the token is a comment
            if (v[i].compare("") == 0 || (v[i][0] == '/' && v[i][1] == '/')) {
                break;
            }

            // if it's the first token of the line and it doesnt match an op code
            if (i == 0 && codeNum.find(v[i]) == codeNum.end()) {
                cout << "ERROR: unknown token " << v[i] << endl;
                return false;
            } else {
                continue;
            }

            // if it's a register and a valid register
            if (v[i][0] == '$' && strtoi(v[i].substr(1)) < sizeof(reg)) {
                continue;
            }

            // if it's a number below 255
            if (strtoi(v[i]) < 255) {
                continue;
            }

            return false;
        }
     }

    // return true;
}






// helps turn strings into integers
size_t strtoi(string s) {

    size_t ret = 0;

    for (auto i = 0; i < s.size(); i++) {

        cout << "character: " <<s [i] << endl;

        ret *= 10;

        // if a character is not a number
        if (s[i] < 48 || s[i] > 57)
            return SIZE_T_MAX;
        else
            ret += s[i] - 48;
   } 

   return ret;
}




// bool Bite::isValidReg(string token) {
//     if (token[0] == '$' && strtoi(token.substr(1)) < sizeof(reg)) {
       
//         return true;
//     } else {

//          if (token[0] == '$')  
//             cout << "dollar sign check" << endl;
        
//         cout << "substr: " << token.substr(1) << endl;
//         cout << "num check: " << strtoi(token.substr(1)) << endl;
        

//         cout << "reg return false" << endl;
//         return false;
//     }
// }

// bool Bite::isValidNum(string token) {
//     if (strtoi(token) < 255) 
//         return true;
//     else
//         return false;
// }



